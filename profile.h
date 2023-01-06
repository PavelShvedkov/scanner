#ifndef PROFILE_H
#define PROFILE_H

#include <vector>
#include <iostream>
#include <math.h>
#include <random>

class Profile
{
public:
    Profile();
    Profile(int, float, float, float, float, float, float = 0, float = 1);
    Profile(Profile &);

    void set(int, float, float, float, float, float, float, float);
    void setX(float);
    void setZ(float);
    void setBrightness(float, float);
    void setBrightness(float, float, bool);

    int getCounts();
    float getStep();
    float getInitStep();
    float getWhiteStripWidth();
    float getBlackStripWidth();
    float getMaxBrightness();
    float getMinBrightness();

    std::vector<float> getX();
    float getX0();
    float getZ0();
    std::vector<float> getZ();
    std::vector<float> getBrightness();

    void move(float dx, float dz, bool noise);

    void print();

    std::vector<float> operator[](int other);
    Profile operator=(Profile);

private:
    int counts; //количество точек
    float whiteStripWidth;
    float blackStripWidth; //ширина белой и чёрной полосок
    int strips; //число чёрных полосок

    float h0; //шаг измерения в z0
    float h; //шаг измерения в z_i
    float x0;
    float z0; //начальные значения x и z

    const float DISTANCE_TO_TARGET = 1;

    float maxBrightness;
    float minBrightness;

    std::vector<float> x;
    std::vector<float> z;
    std::vector<float> brightness;
};

#endif // PROFILE_H
