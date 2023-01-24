#include "profile.h"
#include <string>

Profile::Profile()
{

}

Profile::Profile(int counts, float h, float whiteStrip, float blackStrip, float x0, float z0, float minBr, float maxBr)
{
    this -> set(counts, h, whiteStrip, blackStrip, x0, z0, minBr, maxBr);
}

Profile::Profile(const Profile &other)
{
    this -> counts = other.getCounts();

    this -> whiteStripWidth = other.getWhiteStripWidth();
    this -> blackStripWidth = other.getBlackStripWidth();

    this -> strips = ((this -> counts) * (this -> h)) / ((this -> whiteStripWidth) + (this -> blackStripWidth)); // refactor

    this -> h = other.getStep();

    this -> maxBrightness = other.getMaxBrightness();
    this -> minBrightness = other.getMinBrightness();

    this -> x = other.getX();
    this -> z = other.getZ();
    this -> brightness = other.getBrightness();
}

void Profile::set(int counts, float h, float whiteStrip, float blackStrip, float x0, float z0, float minBr = 0, float maxBr = 1)
{
    if(counts < 0)
    {
        throw "Counts must be non-negative";
    }

    if(whiteStrip <= 0 || blackStrip <= 0)
    {
        throw "Width of black and white strips must be positive";
    }

    this -> counts = counts;

    this -> strips = (counts * h) / (whiteStrip + blackStrip); // refactor

    this -> whiteStripWidth = whiteStrip;
    this -> blackStripWidth = blackStrip;

    this -> setStep(h);

    this -> setX(x0);
    this -> setZ(z0);
    this -> setBrightnessWithNoise(minBr, maxBr);
}

void Profile::setX(float x0)
{
    this -> x0 = x0;

    if(!(this -> x).empty())
    {
        x.clear();
    }

    int counts = this -> getCounts();

    for(int i = 0; i < counts; ++i)
    {
        (this -> x).push_back(x0 + i*h);
    }
}

void Profile::setZ(float z0)
{
    this -> z0 = z0;

    if(!(this -> z).empty())
    {
        z.clear();
    }

    int counts = this -> getCounts();

    for(int i = 0; i < counts; ++i)
    {
        (this -> z).push_back(z0);
    }
}

void Profile::setBrightness(float minBr = 0, float maxBr = 1)
{
    if(minBr < 0)
    {
        throw "Min brightness must be non-negative";
    }

    if(maxBr <= 0)
    {
        throw "Max brightness must be positive";
    }

    if(minBr >= maxBr)
    {
        throw "Min brightness must be greater than max";
    }

    if(!(this -> brightness).empty())
    {
        brightness.clear();
    }

    int counts = this -> getCounts();
    float step = this -> getStep();
    float ws = this -> getWhiteStripWidth();
    float bs = this -> getBlackStripWidth();

    for (int i = 0; i < counts; ++i)
    {
        //variable for work modf()
        float rest, intPart;

        rest = std::modf((i * step) / (ws + bs), &intPart) * (ws + bs);

        if(rest > bs)
        {
            (this -> brightness).push_back(maxBr);
        }
        else
        {
            (this -> brightness).push_back(minBr);
        }
    }
}

void Profile::setBrightnessWithNoise(float minBr, float maxBr)
{
    if(minBr < 0)
    {
        throw "Min brightness must be non-negative";
    }

    if(maxBr + 4 * NOISE_VAR < 0)
    {
        throw "Max brightness must be positive";
    }

    //TODO придумать проверку предельных значений шума с учётом шума
    /*if(minBr >= maxBr + 4 * NOISE_VAR )
    {
        throw "Min brightness must be greater than max";
    }*/

    if(!(this -> brightness).empty())
    {
        brightness.clear();
    }

    this -> minBrightness = minBr;
    this -> maxBrightness = maxBr;

    int counts = this -> getCounts();
    float step = this -> getStep();
    float ws = this -> getWhiteStripWidth();
    float bs = this -> getBlackStripWidth();

    std::normal_distribution<float> norm(NOISE_MEAN, NOISE_VAR);
    std::mt19937 generator(std::rand());

    for (int i = 0; i < counts; ++i)
    {
        //variable for work modf()
        float rest, intPart;

        rest = std::modf((i * step) / (ws + bs), &intPart) * (ws + bs);

        if(rest > bs)
        {
            (this -> brightness).push_back(maxBr + norm(generator));
        }
        else
        {
            (this -> brightness).push_back(minBr + norm(generator));
        }
    }
}

void Profile::setStep(float h)
{
    if(h <= 0)
    {
        throw "Step must be positive";
    }

    this -> h = h;
}

int Profile::getCounts () const
{
    return this -> counts;
}

float Profile::getStep() const
{
    return this -> h;
}

float Profile::getWhiteStripWidth() const
{
    return this -> whiteStripWidth;
}

float Profile::getBlackStripWidth() const
{
    return this -> blackStripWidth;
}

float Profile::getMaxBrightness() const
{
    return this -> maxBrightness;
}

float Profile::getMinBrightness() const
{
    return this -> minBrightness;
}

std::vector<float> Profile::getX() const
{
    return this -> x;
}

float Profile::getX0() const
{
    return this -> x0;
}

float Profile::getZ0() const
{
    return this -> z0;
}

std::vector<float> Profile::getZ() const
{
    return this -> z;
}

std::vector<float> Profile::getBrightness() const
{
    return this -> brightness;
}

void Profile::move(float dx, float dz)
{
    for(int i = 0; i < (this -> x).size();  ++i)
    {
        (this -> x)[i] += dx;
        (this -> z)[i] += dz;
    }
}

void Profile::print()
{
    std::vector<float> x = this -> getX();
    std::vector<float> z = this -> getZ();
    std::vector<float> bright = this -> getBrightness();

    for(int i = 0; i < x.size(); ++i)
    {   std::string buffer = std::to_string(x[i]) + ", " + std::to_string(z[i]) + ", " + std::to_string(bright[i]);
        std::cout << buffer << std::endl;
    }
}

std::vector<float> Profile::operator [](int index)
{
    int maxIndex = (this -> getX()).size();

    if(index >= maxIndex || index < 0)
    {
        throw "Index out of range!";
    }

    std::vector<float> buffer = {(this->getX())[index], (this->getZ())[index], (this->getBrightness())[index]};

    return buffer;
}

Profile& Profile::operator=(const Profile &other)
{
    this -> set(other.getCounts(), other.getStep(),
                 other.getWhiteStripWidth(),
                 other.getBlackStripWidth(),
                 other.getX0(),
                 other.getZ0(),
                 other.getMinBrightness(),
                 other.getMaxBrightness());

    return *this;
}
