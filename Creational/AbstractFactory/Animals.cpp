#include <iostream>
#include <cstring>

class Animal
{
protected:
    int weight;
    char name[256];
public:
    Animal(const char* _name, int _weight = 0): weight(_weight) {strcpy(name, _name);}
    int getWeight() const {return weight;}
    void printName() const { std::cout << name << '\n';}
    virtual void action() const = 0;
    virtual void sound() const = 0;
};

class Bear: public Animal
{
public:
    Bear(const char* _name, int _weight): Animal(_name, _weight) {}
    void action() const override = 0;
    void sound() const override {std::cout << "Roarr... \n";}
};

class WildBear: public Bear
{
public:
    WildBear(const char* _name, int _weight): Bear(_name, _weight) {}
    void action() const override {std::cout <<  "Climbing a tree to eat some berries...\n";}
};

class CircusBear: public Bear
{
public:
    CircusBear(const char* _name, int _weight): Bear(_name, _weight) {}
    void action() const override {std::cout <<  "Riding a bike while juggling with 3 apples...\n";}
};

class Horse: public Animal
{
public:
    Horse(const char* _name, int _weight): Animal(_name, _weight) {}
    void action() const override = 0;
    void sound() const override {std::cout << "Horse sound... \n";}
};

class WildHorse: public Horse
{
public:
    WildHorse(const char* _name, int _weight): Horse(_name, _weight) {}
    void action() const override {std::cout <<  "Running in the wild...\n";}
};

class CircusHorse: public Horse
{
public:
    CircusHorse(const char* _name, int _weight): Horse(_name, _weight) {}
    void action() const override {std::cout <<  "Performing air stunts...\n";}
};
