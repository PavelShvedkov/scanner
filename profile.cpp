#include "profile.h"

Profile::Profile()
{

}

Profile::Profile(int counts, float h, float whiteStrip, float blackStrip, float x0, float z0, float minBr, float maxBr)
{
    this -> set(counts, h, whiteStrip, blackStrip, x0, z0, minBr, maxBr);
}

Profile::Profile(Profile &other)
{
    this -> counts = other.getCounts();

    this -> whiteStripWidth = other.getWhiteStripWidth();
    this -> blackStripWidth = other.getBlackStripWidth();


    this -> strips = ((this -> counts) * (this -> h)) / ((this -> whiteStripWidth) + (this -> blackStripWidth)); // refactor

    this -> h = other.getStep();

    this -> x = other.getX();
    this -> z = other.getZ();
    this -> brightness = other.getBrightness();
}

void Profile::set(int counts, float h, float whiteStrip, float blackStrip, float x0, float z0, float minBr = 0, float maxBr = 1)
{
    //TODO: add validation

    if(counts < 0)
    {
        throw "Counts must be non-negative";
    }

    if(whiteStrip <= 0 || blackStrip <= 0)
    {
        throw "Width of black and white strips must be positive";
    }

    if(h <= 0)
    {
        throw "Step must be positive";
    }

    this -> counts = counts;

    this -> strips = (counts * h) / (whiteStrip + blackStrip); // refactor

    this -> whiteStripWidth = whiteStrip;
    this -> blackStripWidth = blackStrip;

    this -> h = h;

    this -> setX(x0);
    this -> setZ(z0);
    this -> setBrightness(minBr, maxBr ,true);
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

void Profile::setBrightness(float minBr, float maxBr, bool noise)
{
    int counts = this -> getCounts();
    float step = this -> getStep();
    float ws = this -> getWhiteStripWidth();
    float bs = this -> getBlackStripWidth();

    std::default_random_engine generator;
    std::normal_distribution<float> uniform(0, 0.1);

    for (int i = 0; i < counts; ++i)
    {
        //variable for work modf()
        float rest, intPart;

        rest = std::modf((i * step) / (ws + bs), &intPart) * (ws + bs);

        if(rest > bs)
        {
            (this -> brightness).push_back(maxBr + uniform(generator));
        }
        else
        {
            (this -> brightness).push_back(minBr + uniform(generator));
        }
    }
}

int Profile::getCounts()
{
    return this -> counts;
}

float Profile::getStep()
{
    return this -> h;
}

float Profile::getWhiteStripWidth()
{
    return this -> whiteStripWidth;
}

float Profile::getBlackStripWidth()
{
    return this -> blackStripWidth;
}

std::vector<float> Profile::getX()
{
    return this -> x;
}

float Profile::getX0()
{
    return this -> x0;
}

float Profile::getZ0()
{
    return this -> z0;
}

std::vector<float> Profile::getZ()
{
    return this -> z;
}

std::vector<float> Profile::getBrightness()
{
    return this -> brightness;
}

void Profile::move(float dx, float dz)
{
    for(int i = 0; i < (this->x).size(); ++i)
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
