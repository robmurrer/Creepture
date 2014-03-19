#ifndef _CPG_H_
#define _CPG_H_
#include <math.h>

class CPGNode
{
    public:
        double tau1 = 0.5;       // u1,u2 time constant larger means longer cycle
        double tau2 = 10.6;        // v1,v2 time ...
        double beta = 100.5;        // weight between ui, vi. if beta<1 attenuate; beta>1 causes ipatterns 
        double omega = 1.0;      // weight between flexor, extensor neuron pairs 
        double ue = 8.5;          // external input
        double u1_init = 1.0;     // neuron intial states
        double v1_init = 0.0;     // ...
        double u2_init = 0.0;
        double v2_init = 0.0;
        double motor = 1;

        //const double euler_step = 0.03125;
        //const double euler_step = 0.0625;
        //double euler_step = 0.125;
        double euler_step = 1/60.0;

        // neuron states
        double u1 = u1_init;
        double v1 = v1_init;
        double u2 = u2_init;
        double v2 = v2_init;

        // neuron derivatives
        double u1d = 0.0;
        double v1d = 0.0;
        double u2d = 0.0;
        double v2d = 0.0;

        double y1 = fmax(0.0, u1);
        double y2 = fmax(0.0, u2);
        double voltage = -motor*y1+motor*y2;

        double f1 = 0.0;
        double f2 = 0.0;


        void tick()
        {
            y1 = fmax(0.0, u1);
            y2 = fmax(0.0, u2);

            //f2 = -f1;


            u1d = (-u1 - omega*y2 - beta*v1 + ue + f1) / tau1;
            v1d = (-v1 + y1) / tau2;
            u2d = (-u2 - omega*y1 - beta*v2 + ue + f2) / tau1;
            v2d = (-v2 + y2) / tau2;

            u1 += u1d*euler_step;
            v1 += v1d*euler_step;
            u2 += u2d*euler_step;
            v2 += v2d*euler_step;

            voltage = -motor*y1+motor*y2;

            return;
        };


};
















#endif
