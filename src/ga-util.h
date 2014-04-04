#ifndef _GA_UTIL_H_
#define _GA_UTIL_H_

// turns a probabiity into a true or false value
// based on the RNG
bool prob_to_rand(double p)
{
    // extreme cases
    if (p >= 100.0) return true;
    if (p <= 0.0) return false;

    // default to favorable prob >.50
    bool favor = true;
    if (p < .50) favor = false;

    // convert favorable prob to loss prob
    if (favor) p = 1 - p;

    // random number generator bound
    int bound = (int) 1 / p;

    // check if a hit, return ~favor
    if (rand()%bound == 0) return !(favor);
    
    // no hit
    return favor;
}

#endif
