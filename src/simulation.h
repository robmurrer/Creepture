#ifndef _SIMULATION_H_
#define _SIMULATION_H_
#include <math.h>
#include <vector>
#include <new>
#include <Box2D/Box2D.h>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

// World Settings
#define GRAVITY -9.8f
#define GROUND_FRICTION 1.0f
#define GROUND_SIZE 150.0f
#define STEP_SIZE 1.0f / 60.0f
#define POS_ITERATIONS 6
#define VEL_ITERATIONS 2

// Creature Settings
#define MOTOR_SPEED 720
#define MOTOR_TORQUE = 500.0f
#define SEG_FRICTION = 1.0f

class Simulation
{
    public:
    b2World *world;
    std::vector<b2RevoluteJoint*> joints;
    b2Body *head;
    b2Body *tail;

    Simulation(int segment_count)
    {
        joints = std::vector<b2RevoluteJoint*>(segment_count);
        b2Vec2 gravity(0.0f, GRAVITY);
        world = new b2World(gravity);

        // floor
        b2BodyDef myBodyDef;
        b2FixtureDef myFixtureDef;
        b2EdgeShape edgeShape;
        edgeShape.Set( b2Vec2(-1500,0), b2Vec2(1500,0) );
        myFixtureDef.shape = &edgeShape;
        myFixtureDef.friction = 1;
        myBodyDef.type = b2_staticBody; //change body type
        myBodyDef.position.Set(0,0); //middle, bottom
        b2Body* floor = world->CreateBody(&myBodyDef);
        floor->CreateFixture(&myFixtureDef); //add a fixture to the body

    };

    ~Simulation()
    {
        delete world;
    };

    void creature_init()
    {

    };

    void tick()
    {
        world->Step(STEP_SIZE, VEL_ITERATIONS, POS_ITERATIONS);
    };


};

#endif
        



