#ifndef _CPG_H_
#define _CPG_H_
#include <math.h>
#include <vector>

class CPGNode
{
    public:
        double tau1 = 0.05;       // u1,u2 time constant larger means longer cycle
        double tau2 = 0.6;        // v1,v2 time ...
        double beta = 2.0;        // weight between ui, vi. if beta<1 attenuate; beta>1 causes ipatterns 
        double omega = 2.5;      // weight between flexor, extensor neuron pairs 
        double ue = 1.0;          // external input
        double u1_init = 1.0;     // neuron intial states
        double v1_init = 0.0;     // ...
        double u2_init = 0.0;
        double v2_init = 0.0;
        double motor = 1;

        // cpgnet
        double network_feedback_coeef = 1.0;
        double network_feedback1 = 0.0;
        double network_feedback2 = 0.0;

        // approximation
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


            u1d = (-u1 - omega*y2 - beta*v1 + ue + 
                    f1 + (network_feedback_coeef*network_feedback1)) / tau1;
            v1d = (-v1 + y1) / tau2;
            u2d = (-u2 - omega*y1 - beta*v2 + ue + 
                    f2+ (network_feedback_coeef*network_feedback2)) / tau1;
            v2d = (-v2 + y2) / tau2;

            u1 += u1d*euler_step;
            v1 += v1d*euler_step;
            u2 += u2d*euler_step;
            v2 += v2d*euler_step;

            voltage = -motor*y1+motor*y2;

            return;
        };


};

class CPGNet
{
    public:
        std::vector<CPGNode> nodes;
        std::vector<std::vector<int>> weights;
        CPGNet(int size)
        {
            nodes = std::vector<CPGNode>(size);
            weights = std::vector<std::vector<int>>(size);

            // set up adjacency matrix
            for (int i=0; i<size; i++)
                weights[i] = std::vector<int>(size);
        };

        void feedback()
        {
            for (int i=0; i<nodes.size(); i++)
            {
                // calculate weighted sum of all nodes
                double feed1 = 0.0;
                double feed2 = 0.0;
                for (int j=0; j<nodes.size(); j++)
                {
                    // the node itself is not part of the feedback 
                    if (i==j) continue; 
                    feed1 += weights[i][j] * nodes[j].u1;
                    feed2 += weights[i][j] * nodes[j].u2;
                }

                // update feedback in node based on sigmoidal
                nodes[i].network_feedback1 = 2.0 / (1 + exp(-feed1/nodes.size())) - 1.0;
                nodes[i].network_feedback2 = 2.0 / (1 + exp(-feed2/nodes.size())) - 1.0;
            }
        };
        
        void tick()
        {
            feedback();
            for (int i=0; i<nodes.size(); i++)
                nodes[i].tick();
        };


};















#endif
