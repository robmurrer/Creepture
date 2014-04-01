#ifndef FOOTEST_H
#define FOOTEST_H

#include "simulation.h"

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

const float motor_speed = 370 * DEGTORAD;
class Plugged : public Test
{
    public:
        Simulation *sim;

        Plugged() 
        { 
            sim = new Simulation(5, m_world);
            sim->world->SetGravity(b2Vec2(0.0f, GRAVITY));
        
        } //do nothing, no scene yet

        void Step(Settings* settings)
        {
            //run the default physics and rendering
            Test::Step(settings); 
            //sim->tick();

            m_debugDraw.DrawString(5, m_textLine, "halo");
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
            return new Plugged;
        }
};

#endif
