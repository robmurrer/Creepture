#ifndef _CHROMOSOME_H_
#define _CHROMOSOME_H_
#include <vector>
#include "simulation.h"
#include "cpg.h"
#include "ga-util.h"

#define MAX_TICK    2E3

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
    int size = 1E3;
    double r = rand()%size;
    int sign = rand()%2;

    return (sign ? -1 : 1) * (r/size);

}
    
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
       

class Chromosome
{
    public:
        std::vector<Gene> genes;
        double fitness = 0.0;

        Chromosome(int size)
        {
            for (int i=0; i<size; i++)
            {
                genes.push_back(Gene(size));
            }
        };

        Chromosome(char *filename)
        {
            FILE *file = fopen(filename, "r");
            int size;

            // size of chromosome
            fscanf(file, "%d", &size);

            // cread adj matrix
            for (int i=0; i<size; i++)
            {
                genes.push_back(Gene(size));
            }

            // read in adjacency matrix
            for (int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    int tmp;
                    fscanf(file, "%d ", &tmp);
                    genes[i].adjacency[j] = tmp;
                }
            }

            for (int i=0; i<size; i++)
            {
                fscanf(file,"%lf %lf %lf %lf\n", 
                        &genes[i].u1_init, &genes[i].u2_init, 
                        &genes[i].v1_init, &genes[i].v2_init);
            }

            fclose(file);
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
            fprintf(out, "%d\n", (int)genes.size());

            for (int i=0; i<genes.size(); i++)
            {
                for(int j=0; j<genes.size(); j++)
                {
                    fprintf(out, "%d ", genes[i].adjacency[j]);
                }
                fprintf(out,"\n");
            }

            for (int i=0; i<genes.size(); i++)
            {
                fprintf(out,"%lf %lf %lf %lf\n", 
                        genes[i].u1_init, genes[i].u2_init, 
                        genes[i].v1_init, genes[i].v2_init);
            }

        };

        CPGNet* toCPGNet()
        {
            CPGNet *net = new CPGNet(genes.size());

            for (int i=0; i<genes.size(); i++)
            {
                for (int j=0; j<genes.size(); j++)
                    net->weights[i][j] = genes[i].adjacency[j];
                 
                net->nodes[i].u1 = genes[i].u1_init;
                net->nodes[i].u2 = genes[i].u2_init;
                net->nodes[i].v1 = genes[i].v1_init;
                net->nodes[i].v2 = genes[i].v2_init;
            }

            return net;
        };

        void calcFitness()
        {
            // convert chromosome to CPG network
            CPGNet *net = toCPGNet();

            Simulation sim(genes.size()/2);

            sim.tick();

            double initial_pos = sim.tail->GetPosition().x;

            for (int i=0; i<MAX_TICK; i++)
            {
                // advance CPG network
                net->tick();

                // update sim joint speeds
                for (int j=0; j<genes.size(); j++)
                {
                    double cpg = net->nodes[j].voltage;
                    sim.joints[j]->SetMotorSpeed(cpg*MOTOR_SPEED);
                }

                // advance sim
                sim.tick();
            }


            fitness = sim.tail->GetPosition().x - initial_pos;

            delete net;


        };


        bool operator<(const Chromosome& rhs) const
        {
            if ((fitness - rhs.fitness) <= 0) return false;
            else return true;
        };


        void mutate(double prob, double percent)
        {

            for (int i=0; i<genes.size(); i++)
            {
                // mutate adjacency
               for (int j=0; j<genes.size(); j++)
               {
                   if (prob_to_rand(prob))
                   {
                       genes[i].adjacency[j] = rand_adj();
                   }
               }

               // mutate neurons
               if (prob_to_rand(prob))
                {
                    genes[i].u1_init = mutate_range(
                            genes[i].u1_init, -1.0, 1.0, percent);
                }

               if (prob_to_rand(prob))
                {
                    genes[i].u2_init = mutate_range(
                            genes[i].u2_init, -1.0, 1.0, percent);
                }

               if (prob_to_rand(prob))
                {
                    genes[i].v1_init = mutate_range(
                            genes[i].v1_init, -1.0, 1.0, percent);
                }

               if (prob_to_rand(prob))
                {
                    genes[i].v2_init = mutate_range(
                            genes[i].v2_init, -1.0, 1.0, percent);
                }
            }

        };

        void crossover(double prob, const Chromosome& partner)
        {

            for (int i=0; i<genes.size(); i++)
            {
                // crossover adjacency
               for (int j=0; j<genes.size(); j++)
               {
                   if (prob_to_rand(prob))
                   {
                       genes[i].adjacency[j] = partner.genes[i].adjacency[j]; 
                   }
               }

               // crossover neurons
               if (prob_to_rand(prob))
                {
                    genes[i].u1_init = partner.genes[i].u1_init;
                }

               if (prob_to_rand(prob))
                {
                    genes[i].u2_init = partner.genes[i].u2_init;
                }

               if (prob_to_rand(prob))
                {
                    genes[i].v1_init = partner.genes[i].v1_init;
                }

               if (prob_to_rand(prob))
                {
                    genes[i].v2_init = partner.genes[i].v2_init;
                }
            }
        };

};

#endif

