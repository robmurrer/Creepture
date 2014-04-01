#ifndef CPGTest_H
#define CPGTest_H

#include "simulation.h"

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class CPGTest : public Test
{
    public:
        Simulation *sim;
        FILE *log;

        CPGTest() 
        { 
            sim = new Simulation(1, m_world);
            sim->world->SetGravity(b2Vec2(0.0f, GRAVITY));

            log = fopen("../../../log/double-cpg-net.txt", "r");

            //todo figure out a way not to have these hardcoded
            //the following doesn't work because settings is available to be
            //modified or I can't find where it is
            //settings->velocityIterations = VEL_ITERATIONS;
            //settings->positionIterations = POS_ITERATIONS;
        
        } //do nothing, no scene yet

        void Step(Settings* settings)
        {
            int step;
            double cpg1;
            double cpg2;

            if (fscanf(log, "%d%lf%lf", &step, &cpg1, &cpg2) != EOF)
            {
                sim->joints[0]->SetMotorSpeed(cpg1*MOTOR_SPEED);
                sim->joints[1]->SetMotorSpeed(cpg2*MOTOR_SPEED);
            }
            

            //run the default physics and rendering
            Test::Step(settings); 

            //make tick be a simple update or cpg?
            //sim->tick();

            m_debugDraw.DrawString(5, m_textLine, "head: %f, tail: %f", 
                    sim->head->GetPosition().x, sim->tail->GetPosition().x);
            m_textLine += DRAW_STRING_NEW_LINE;



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
            return new CPGTest;
        }
};

#endif
