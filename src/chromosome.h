#ifndef _CHROMOSOME_H_
#define _CHROMOSOME_H_
#include <vector>

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

        Chromosome(int size)
        {
            for (int i=0; i<size; i++)
            {
                genes.push_back(Gene(size));
            }
        };

};

#endif

