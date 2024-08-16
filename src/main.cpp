#include <stdio.h>
#include "test.h"

#define VERSION             801
#define CHROMO_SIZE         2 
#define POP_SIZE            100 
#define MAX_GEN             15
#define ELITES              0.7
#define XOVER_RATE          0.7
#define MUT_RATE            0.05
#define MUT_RANGE           0.01
#define SEED                time(0) 

int main()
{
    //run_tests();
    
    srand(SEED);
    int distance = 0.0;

    Population pop(POP_SIZE, CHROMO_SIZE);

    int num_elites = (int) (POP_SIZE * ELITES);

    printf("Creepture Started\n");
    printf("Chromosome Size: %d\n", CHROMO_SIZE);
    printf("Population Size: %d\n", POP_SIZE);
    printf("Max Generations: %d\n", MAX_GEN);
    printf("Elites: %d\n", num_elites);
    printf("Crossover Rate: %lf\n", XOVER_RATE);
    printf("Mutation Rate: %lf\n", MUT_RATE);
    printf("Mutation Range: %lf\n", MUT_RANGE);
    printf("RNG Seed: %d\n", (int)SEED);
    printf("Generation\tBest Fitness\tAvg Fitness\n");

    FILE *log = fopen("../log/gatmp/generations.txt", "w");

    for (int i=0; i<MAX_GEN; i++)
    {
        pop.calcFitness();
        pop.sort();

        fprintf(stdout, "%d\t\t%lf\t%lf\n", i+1, pop.list[0].fitness, pop.avgFitness);
        fprintf(log, "%d\t%lf\t%lf\n", i+1, pop.list[0].fitness, pop.avgFitness);
        fflush(stdout);

        // crossover and mutate everyone with the elites
        for (int j=num_elites; j<POP_SIZE; j++)
        {
            pop.list[j].crossover(XOVER_RATE, pop.list[rand()%num_elites]);
            pop.list[j].mutate(MUT_RANGE, MUT_RANGE);
        }

    }

    fclose(log);
        

    printf("\nGA run done\n");
    pop.calcFitness();
    pop.sort();
    pop.print(stdout);

    FILE *title = fopen("../log/gatmp/title.txt", "w");
    fprintf(title, "V%d-%d_Chromo-%d_Pop-%d_Elite-%.3lf_Mutrate-%.3lf_Mutrange-%.3lf_XRate-%d_Seed-%.3lf_Distance-%d_MGen",
            VERSION, CHROMO_SIZE, POP_SIZE, num_elites, 
            MUT_RATE, MUT_RANGE, XOVER_RATE, (int)SEED, 
            pop.list[0].distance, MAX_GEN);
    fclose(title);

    FILE *out = fopen("../log/gatmp/chromosome.txt", "w");
    pop.list[0].print(out);
    fclose(out);
    

    return 0;
}


