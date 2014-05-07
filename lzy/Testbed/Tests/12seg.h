#ifndef CHROMOFROMFILE12_H
#define CHROMOFROMFILE12_H

#include "../../../src/simulation.h"
#include "../../../src/chromosome.h"
#include "../../../src/cpg.h"


class ChromoFromFile12 : public Test
{
    public:
        Simulation *sim;
        CPGNet *net;
        int size;
        double start_pos;
        double tick;


        ChromoFromFile12() 
        { 
            char filename[] = "../../../log/chromosomes/12-chromosome.txt";
            FILE *file = fopen(filename, "r");
            fscanf(file, "%d", &size);
            fclose(file);

            sim = new Simulation(size/2, m_world);
            Chromosome chromo(filename);
            net = chromo.toCPGNet();
            start_pos = sim->head->GetPosition().x;
            tick = 0.0;

        
        } //do nothing, no scene yet

        void Step(Settings* settings)
        {
            
            //run the default physics and rendering
            Test::Step(settings); 

            net->tick();

            tick++;

            // update sim joint speeds
            for (int j=0; j<size; j++)
            {
                double cpg = net->nodes[j].voltage;
                sim->joints[j]->SetMotorSpeed(cpg*MOTOR_SPEED);
            }


            m_debugDraw.DrawString(5, m_textLine, "sec: %f, distance: %f", 
                    tick / 60.0, sim->head->GetPosition().x - start_pos );
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
            return new ChromoFromFile12;
        }
};

#endif
