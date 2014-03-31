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
        joints = std::vector<b2RevoluteJoint*>(2*segment_count);
        world = new b2World(b2Vec2(0.0f, GRAVITY));
        floor_init();
        creature_init();

    };

    ~Simulation()
    {
        delete world;
    };

    void floor_init()
    {
        b2BodyDef myBodyDef;
        b2FixtureDef myFixtureDef;
        b2EdgeShape edgeShape;
        edgeShape.Set( b2Vec2(-GROUND_SIZE,0), b2Vec2(GROUND_SIZE,0) );
        myFixtureDef.shape = &edgeShape;
        myFixtureDef.friction = GROUND_FRICTION;
        myBodyDef.type = b2_staticBody; //change body type
        myBodyDef.position.Set(0,0); //middle, bottom
        b2Body* floor = world->CreateBody(&myBodyDef);
        floor->CreateFixture(&myFixtureDef); //add a fixture to the body
    };

    void creature_init()
    {
        b2BodyDef myBodyDef;
        b2FixtureDef myFixtureDef;

        const int beam_y_pos = 2;
        const int beam_x_rad = 2;
        const int beam_y_rad = 1;
        const int seg_rad = 2;
        const float seg_fric = 1;
        b2Body *beam;
        b2Body *rseg;
        b2Body *lseg;
        b2Body *oseg;
        b2PolygonShape boxShape;

        const float beam_joint_offset = 0.25;
        const float seg_joint_offset = seg_rad/2.0;
        const float motor_torque = 500.0;

        b2RevoluteJointDef  revoluteJointDef;
	b2WeldJointDef jd;

        int beam_x_pos = 0;

        for (int i=0; i<joints.size()-1; i++)
        {
            // center beam
            myBodyDef.type = b2_dynamicBody;
            myBodyDef.position.Set(beam_x_pos,beam_y_pos);
            myBodyDef.angle = 0;
            beam = world->CreateBody(&myBodyDef);
            boxShape.SetAsBox(beam_x_rad,beam_y_rad);
            myFixtureDef.shape = &boxShape;
            myFixtureDef.density = 1;
            beam->CreateFixture(&myFixtureDef);

            int rseg_x_pos = beam_x_pos + beam_x_rad + beam_joint_offset + seg_joint_offset;
            int rseg_y_pos = beam_y_pos;

            // right segment
            myBodyDef.position.Set(rseg_x_pos, rseg_y_pos);
            rseg = world->CreateBody(&myBodyDef);
            b2CircleShape circleShape;
            circleShape.m_p.Set(0,0);
            circleShape.m_radius = seg_rad;
            myFixtureDef.shape = &circleShape;
            myFixtureDef.friction = seg_fric;
            rseg->CreateFixture(&myFixtureDef);

            // keep track of head
            if (i == joints.size()-2) head = rseg;

            int lseg_x_pos = beam_x_pos - beam_x_rad - beam_joint_offset - seg_joint_offset;
            int lseg_y_pos = beam_y_pos;

            // left segment
            myBodyDef.position.Set(lseg_x_pos, lseg_y_pos);
            lseg = world->CreateBody(&myBodyDef);
            circleShape.m_p.Set(0,0);
            circleShape.m_radius = seg_rad;
            myFixtureDef.shape = &circleShape;
            lseg->CreateFixture(&myFixtureDef);

            // keep track of tail
            if (i==0) tail = lseg;

            // joints
            // right
            revoluteJointDef.bodyA = beam;
            revoluteJointDef.bodyB = rseg;
            revoluteJointDef.localAnchorA.Set(beam_x_rad - beam_joint_offset, 0);
            revoluteJointDef.localAnchorB.Set(-seg_joint_offset,0);
            revoluteJointDef.referenceAngle = 0;
            revoluteJointDef.enableLimit = true;
            revoluteJointDef.lowerAngle = -90 * DEGTORAD;
            revoluteJointDef.upperAngle = 90 * DEGTORAD;
            revoluteJointDef.motorSpeed = 0;
            revoluteJointDef.maxMotorTorque = motor_torque;
            revoluteJointDef.enableMotor = true;
            joints[i+1] = (b2RevoluteJoint*) world->CreateJoint(&revoluteJointDef);

            // left
            revoluteJointDef.bodyB = lseg;
            revoluteJointDef.localAnchorA.Set(-beam_x_rad + beam_joint_offset, 0);
            revoluteJointDef.localAnchorB.Set(seg_joint_offset,0);
            revoluteJointDef.referenceAngle = 0;
            revoluteJointDef.enableLimit = true;
            revoluteJointDef.lowerAngle = -90 * DEGTORAD;
            revoluteJointDef.upperAngle = 90 * DEGTORAD;
            joints[i] = (b2RevoluteJoint*) world->CreateJoint(&revoluteJointDef);

            // fuse to last segment only if segment proceeds
            if (i != 0)
            {
	        jd.Initialize(oseg, lseg, b2Vec2(lseg_x_pos - seg_rad, lseg_y_pos));
	        world->CreateJoint(&jd);
	    }

            // connecting pointer
            oseg = rseg;
            beam_x_pos += 2*(beam_x_rad - beam_joint_offset + 2*seg_rad);
        }

    };

    void tick()
    {
        world->Step(STEP_SIZE, VEL_ITERATIONS, POS_ITERATIONS);
    };


};

#endif
        



