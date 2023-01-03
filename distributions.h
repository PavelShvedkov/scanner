#ifndef DISTRIBUTIONS_H
#define DISTRIBUTIONS_H

#include <vector>

float gaussian(float mean=0, float var=1);
std::vector<float> gaussian(int n, float mean=0, float var=1);

#endif // DISTRIBUTIONS_H
