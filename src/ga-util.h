#ifndef _GA_UTIL_H_
#define _GA_UTIL_H_

// turns a probabiity into a true or false value
bool prob_to_rand(double p)
{
    // extreme cases
    if (p >= 100.0) return true;
    if (p <= 0.0) return false;

    bool favor = true;
    if (p < .50) favor = false;

    if (favor) p = 1 - p;

    int bound = (int) 1 / p;

    if (rand()%bound == 0)
    {
        return !(favor);
    }

    return favor;
}

#endif
