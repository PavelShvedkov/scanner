#include "distributions.h"

#include <cstdlib>
#include <math.h>
#include <ctime>
#include <random>

float gaussian(float mean, float var)
{
    float rMax = RAND_MAX;
    float u = rand()/rMax;
    float v= rand()/rMax;


    float s = u*u + v*v;
    float r = sqrt(-2 * log(s) / s);

    return r * v * var + mean;
}

std::vector<float> gaussian(int n, float mean, float var)
{
    std::vector<float> output;
    float rMax = RAND_MAX;

    float u, v, s, r;


    for(int i = 0 ; i < n; ++i)
    {
        do
        {
            u = rand()/rMax;
            v= rand()/rMax;

            s = u*u + v*v;
        } while(s > 1.0 || s == 0);

        r = sqrt(-2 * log(s) / s);

        output.push_back(u);//r * u * var + mean);

    }

    return output;
}
