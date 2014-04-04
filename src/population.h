#ifndef _POPULATION_H_
#define _POPULATION_H_ 

#include <vector>
#include "chromosome.h"

class Population
{

    public:
        std::vector<Chromosome> list;

        Population(int size_population, int size_chromosome)
        {
            for (int i=0; i<size_population; i++)
            {
                list.push_back(Chromosome(size_chromosome));
                list[i].init_rand();
            }
        };

        void print(FILE *file)
        {
            for (int i=0; i<list.size(); i++)
            {
                fprintf(file, "%d: %lf\n", i+1, list[i].fitness);
            }
        };

        void calcFitness()
        {
            for (int i=0; i<list.size(); i++)
            {
                list[i].calcFitness();
            }
        };

        void sort()
        {
            std::sort(list.begin(), list.end());
        };


            
};

#endif
