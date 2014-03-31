#ifndef FOOTEST_H
#define FOOTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

const float motor_speed = 370 * DEGTORAD;
class Multiple : public Test
{
    public:
        b2RevoluteJoint* lseg_joint;
        b2RevoluteJoint* rseg_joint;

        Multiple() 
        { 
            // floor
            b2BodyDef myBodyDef;
            b2FixtureDef myFixtureDef;
            b2EdgeShape edgeShape;
            edgeShape.Set( b2Vec2(-1500,0), b2Vec2(1500,0) );
            myFixtureDef.shape = &edgeShape;
            myFixtureDef.friction = 1;
            myBodyDef.type = b2_staticBody; //change body type
            myBodyDef.position.Set(0,0); //middle, bottom
            b2Body* floor = m_world->CreateBody(&myBodyDef);
            floor->CreateFixture(&myFixtureDef); //add a fixture to the body

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

            for (int i=0; i<5; i++)
            {
                // center beam
                myBodyDef.type = b2_dynamicBody;
                myBodyDef.position.Set(beam_x_pos,beam_y_pos);
                myBodyDef.angle = 0;
                beam = m_world->CreateBody(&myBodyDef);
                boxShape.SetAsBox(beam_x_rad,beam_y_rad);
                myFixtureDef.shape = &boxShape;
                myFixtureDef.density = 1;
                beam->CreateFixture(&myFixtureDef);

                int rseg_x_pos = beam_x_pos + beam_x_rad + beam_joint_offset + seg_joint_offset;
                int rseg_y_pos = beam_y_pos;

                // right segment
                myBodyDef.position.Set(rseg_x_pos, rseg_y_pos);
                rseg = m_world->CreateBody(&myBodyDef);
                b2CircleShape circleShape;
                circleShape.m_p.Set(0,0);
                circleShape.m_radius = seg_rad;
                myFixtureDef.shape = &circleShape;
                myFixtureDef.friction = seg_fric;
                rseg->CreateFixture(&myFixtureDef);

                int lseg_x_pos = beam_x_pos - beam_x_rad - beam_joint_offset - seg_joint_offset;
                int lseg_y_pos = beam_y_pos;

                // left segment
                myBodyDef.position.Set(lseg_x_pos, lseg_y_pos);
                lseg = m_world->CreateBody(&myBodyDef);
                circleShape.m_p.Set(0,0);
                circleShape.m_radius = seg_rad;
                myFixtureDef.shape = &circleShape;
                lseg->CreateFixture(&myFixtureDef);

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
                rseg_joint = (b2RevoluteJoint*) m_world->CreateJoint(&revoluteJointDef);

                // left
                revoluteJointDef.bodyB = lseg;
                revoluteJointDef.localAnchorA.Set(-beam_x_rad + beam_joint_offset, 0);
                revoluteJointDef.localAnchorB.Set(seg_joint_offset,0);
                revoluteJointDef.referenceAngle = 0;
                revoluteJointDef.enableLimit = true;
                revoluteJointDef.lowerAngle = -90 * DEGTORAD;
                revoluteJointDef.upperAngle = 90 * DEGTORAD;
                lseg_joint = (b2RevoluteJoint*) m_world->CreateJoint(&revoluteJointDef);

                // fuse to last segment only if segment proceeds
                if (i != 0)
                {
	            jd.Initialize(oseg, lseg, b2Vec2(lseg_x_pos - seg_rad, lseg_y_pos));
	            m_world->CreateJoint(&jd);
	        }

                // connecting pointer
                oseg = rseg;
                beam_x_pos += 2*(beam_x_rad - beam_joint_offset + 2*seg_rad);
            }

        
        } //do nothing, no scene yet

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 

            //m_debugDraw.DrawString(5, m_textLine, "lseg: %lf, rseg: %lf",
                    //lseg_joint->GetMotorSpeed(), rseg_joint->GetMotorSpeed());
	    //m_textLine += DRAW_STRING_NEW_LINE;



        }

        void Keyboard(unsigned char key)
        {
            switch(key)
            {
                case '2':
                    //lseg_joint->SetMotorSpeed(-1*motor_speed);
                    break;
                case '1':
                    //lseg_joint->SetMotorSpeed(motor_speed);
                    break;      
                case '4':
                    //rseg_joint->SetMotorSpeed(-1*motor_speed);
                    break;
                case '3':
                    //rseg_joint->SetMotorSpeed(motor_speed);
                    break;
                default:
                    Test::Keyboard(key);
            }
        }

        static Test* Create()
        {
            return new Multiple;
        }
};

#endif
