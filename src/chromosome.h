#ifndef _CHROMOSOME_H_
#define _CHROMOSOME_H_
#include <vector>
#include "simulation.h"

#define MAX_TICK    1E3

class Gene
{
    public:
        std::vector<int> adjacency;
        double u1_init = 0;
        double u2_init = 0;
        double v1_init = 0;
        double v2_init = 0;

        Gene(int size)
        {
            adjacency = std::vector<int>(size);
        };

};
       
int rand_adj()
{
    int r = rand()%3;

    if (r == 0) return -1;
    if (r == 1) return  0;
    if (r == 2) return  1;

    return 0;
}

double rand_neuron()
{
    int size = 1E6;
    double r = rand()%size;
    int sign = rand()%2;

    return (sign ? -1 : 1) * (r/size);

}
    

class Chromosome
{
    public:
        std::vector<Gene> genes;
        double fitness;

        Chromosome(int size)
        {
            for (int i=0; i<size; i++)
            {
                genes.push_back(Gene(size));
            }
        };

        void init_rand()
        {
            for (int i=0; i<genes.size(); i++)
                for(int j=0; j<genes.size(); j++)
                {
                    genes[i].adjacency[j] = rand_adj();
                    genes[i].u1_init = rand_neuron();
                    genes[i].u2_init = rand_neuron();
                    genes[i].v1_init = rand_neuron();
                    genes[i].v2_init = rand_neuron();
                }
        };

        void print(FILE * out)
        {
            for (int i=0; i<genes.size(); i++)
            {
                for(int j=0; j<genes.size(); j++)
                {
                    fprintf(out, "%2d ", genes[i].adjacency[j]);
                }
                fprintf(out,"\n");
            }

            for (int i=0; i<genes.size(); i++)
            {
                fprintf(out,"%3.6lf %3.6lf %3.6lf %3.6lf\n", 
                        genes[i].u1_init, genes[i].u2_init, 
                        genes[i].v1_init, genes[i].v2_init);
            }

        };

        void calcFitness()
        {
            // convert chromosome to CPG network
            CPGNet net(genes.size());
            for (int i=0; i<genes.size(); i++)
            {
                for (int j=0; j<genes.size(); j++)
                    net.weights[i][j] = genes[i].adjacency[j];
                 
                net.nodes[i].u1 = genes[i].u1_init;
                net.nodes[i].u2 = genes[i].u2_init;
                net.nodes[i].v1 = genes[i].v1_init;
                net.nodes[i].v2 = genes[i].v2_init;
            }

            Simulation sim(genes.size()/2);
            sim.tick();

            double initial_pos = sim.head->GetPosition().x;

            for (int i=0; i<MAX_TICK; i++)
            {
                // advance CPG network
                net.tick();

                // update sim joint speeds
                for (int j=0; j<genes.size(); j++)
                {
                    double cpg = net.nodes[j].voltage;
                    sim.joints[j]->SetMotorSpeed(cpg*MOTOR_SPEED);
                }

                // advance sim
                sim.tick();
            }


            fitness = sim.head->GetPosition().x - initial_pos;


        };



};

#endif

