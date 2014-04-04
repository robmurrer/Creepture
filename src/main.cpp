#include <stdio.h>
#include "test.h"

#define CHROMO_SIZE         2
#define POP_SIZE            100
#define MAX_GEN             300
#define ELITES              0.1
#define XOVER_RATE          0.5
#define MUT_RATE            0.05
#define MUT_RANGE           0.10
//#define SEED                0
#define SEED                time(0) 

int main()
{
    //run_tests();
    srand(SEED);
    Population pop(POP_SIZE, CHROMO_SIZE);

    int num_elites = (int) (POP_SIZE * ELITES);

    for (int i=0; i<MAX_GEN; i++)
    {
        pop.calcFitness();
        pop.sort();

        // help out weaker members of population
        for (int j=0; j<num_elites; j++)
            pop.list[POP_SIZE - (j+1)].crossover(1.0, pop.list[j]);

        // crossover and mutate rest of population
        for (int j=num_elites; j<POP_SIZE; j++)
        {
            pop.list[j].crossover(XOVER_RATE, pop.list[rand()%POP_SIZE]);
            pop.list[j].mutate(MUT_RANGE, MUT_RANGE);
        }
    }
    
    pop.calcFitness();
    pop.sort();
    pop.print(stdout);

    FILE *out = fopen("../log/chromosomes/test.txt", "w");
    pop.list[0].print(out);
    fclose(out);



    return 0;
}


