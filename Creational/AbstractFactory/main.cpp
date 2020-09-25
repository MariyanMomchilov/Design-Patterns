#include "AbstractFactory.cpp"
#include <vector>


int main()
{
    CircusFactory circusFactory;

    AnimalFactory* abstractFactory = new WildFactory();
    
    std::vector<Animal*> animalContainer;

    animalContainer.push_back(abstractFactory->makeBear("Jim", 250));
    animalContainer.push_back(abstractFactory->makeHorse("Tim", 150));

    delete abstractFactory;

    abstractFactory = new CircusFactory();

    animalContainer.push_back(abstractFactory->makeBear("Jim", 250));
    animalContainer.push_back(abstractFactory->makeHorse("Tim", 150));

    delete abstractFactory;

    for (int i = 0; i < animalContainer.size(); i++)
    {
        animalContainer[i]->printName();
        std::cout << animalContainer[i]->getWeight() << '\n';
        animalContainer[i]->sound();
        animalContainer[i]->action();
        std::cout << '\n';
        delete animalContainer[i];
    }
    return 0;

}