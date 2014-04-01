#include <stdio.h>
#include <stdlib.h>
#include <Box2D/Box2D.h>
#include "dbh.h"
#include "cpg.h"
#include "simulation.h"

bool test_cpg_sim()
{
    Simulation sim(1);
    FILE *log = fopen("../log/double-cpg-net.txt", "r");
    int step;
    double cpg1, cpg2;

    printf("Start Head: %f, Tail: %f\n",
            sim.head->GetPosition().x, sim.tail->GetPosition().x);

    while(fscanf(log, "%d%lf%lf", &step, &cpg1, &cpg2) != EOF)
    {
        //printf("%d %lf %lf\n", step, cpg1, cpg2);
        sim.joints[0]->SetMotorSpeed(cpg1*MOTOR_SPEED);
        sim.joints[1]->SetMotorSpeed(cpg2*MOTOR_SPEED);
        sim.tick();
    }
    fclose(log);


    printf("End Head: %f, Tail: %f\n",
            sim.head->GetPosition().x, sim.tail->GetPosition().x);

    return true;
}

bool test_world()
{
    int segments = 5;
    Simulation sim(segments);
    printf("Head: %f, Tail: %f\n",
            sim.head->GetPosition().x, sim.tail->GetPosition().x);

    int i;
    for (i=0; i<1E5; i++) 
    {
        if (!sim.tail->IsAwake()) break;
        sim.tick();
    }


    printf("Head: %f, Tail: %f i:%d \n",
            sim.head->GetPosition().x, sim.tail->GetPosition().x, i);

    return true;
}

bool test_cpgnet()
{
    CPGNet net(2);

    net.weights[0][1] = -1;
    net.weights[1][0] = -1;

    net.nodes[1].u1 = 0.1;
    //net.nodes[1].u2 = 0.0;
    //net.nodes[1].v1 = 1.0;
    //net.nodes[1].v2 = 0.0;


    FILE *log = fopen("../log/double-cpg-net.txt", "w");
    for (int i=0; i<1E3; i++)
    {
        fprintf(log, "%d\t%lf\t%lf\n", i+1, 
                net.nodes[0].voltage, net.nodes[1].voltage);
        net.tick();
    }
    fclose(log);


    return true;
}

bool test_cpgnode()
{
    CPGNode cpg;
    //cpg.tau2 = 10.0;

    FILE *log = fopen("../log/single-cpg-node.txt", "w");
    for (int i=0; i<1E3; i++)
    {
        fprintf(log, "%d\t%f\n", i+1, cpg.voltage);
        cpg.tick();
    }

    return true;
}

bool test_box2d()
{
    //B2_NOT_USED(argc);
    //B2_NOT_USED(argv);

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    b2Vec2 position;
    // This is our little game loop.
    for (int32 i = 0; i < 60; ++i)
    {
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	world.Step(timeStep, velocityIterations, positionIterations);

	// Now print the position and angle of the body.
        position = body->GetPosition();
        //float32 angle = body->GetAngle();

        //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }

    check_debug((int)position.y == 1, "Box never hit ground");
    return true;
error:
    return false;
}

bool test_test()
{

    check_debug(1 == 1, "The universe is eating itself, 1 != 1");
    return true;

error:
    return false;
}



bool (*tests[])() = 
{ 
    test_test,
    test_box2d,
    test_cpgnode,
    test_cpgnet,
    test_world,
    test_cpg_sim,
    NULL
};
      

void run_tests()
{
    int i = 0;
    while(tests[i] != NULL)
    {
        if (!(*tests[i++])())
        {
            printf("*** TEST %d FAILED ***\n", i+1);
        }
    }
        
}

