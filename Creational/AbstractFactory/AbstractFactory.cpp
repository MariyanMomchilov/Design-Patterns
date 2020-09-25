#include "Animals.cpp"

class AnimalFactory
{
public:
    virtual Animal* makeBear(const char* name, int weight) const = 0;
    virtual Animal* makeHorse(const char* name, int weight) const = 0;
};

class WildFactory: public AnimalFactory
{
public:
    WildBear* makeBear(const char* name, int weight) const override {return new WildBear(name, weight);}
    WildHorse* makeHorse(const char* name, int weight) const override {return new WildHorse(name, weight);}
};

class CircusFactory: public AnimalFactory
{
public:
    CircusBear* makeBear(const char* name, int weight) const override {return new CircusBear(name, weight);}
    CircusHorse* makeHorse(const char* name, int weight) const override {return new CircusHorse(name, weight);}
};
