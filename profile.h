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
    void setBrightnessWithNoise(float, float);
    void setStep(float);

    int getCounts();
    float getStep();
    float getWhiteStripWidth();
    float getBlackStripWidth();
    float getMaxBrightness();
    float getMinBrightness();
    float getX0();
    float getZ0();

    std::vector<float> getX();
    std::vector<float> getZ();
    std::vector<float> getBrightness();

    void move(float dx, float dz);
    void print();

    std::vector<float> operator[](int other);
    Profile operator=(Profile);

private:
    int counts; //количество точек
    float whiteStripWidth;
    float blackStripWidth; //ширина белой и чёрной полосок
    int strips; //число чёрных полосок

    float h; //шаг
    float x0;
    float z0; //начальные значения x и z

    float maxBrightness;
    float minBrightness;

    std::vector<float> x;
    std::vector<float> z;
    std::vector<float> brightness;

    const float NOISE_MEAN = 0;
    const float NOISE_VAR = 0.01;
};

#endif // PROFILE_H
