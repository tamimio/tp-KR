#include "Animal.h"

class Factory
{
	public:
		virtual Animal* Create() = 0;
		virtual ~Factory(){}  
};

class CatFactory : public Factory
{
	public:
		Animal* Create(){ return new Cat; }
};

class DogFactory : public Factory
{
	public:
		Animal* Create(){ return new Dog; }
};

class MouseFactory : public Factory
{
	public:
		Animal* Create(){ return new Mouse; }
};

class HorseFactory : public Factory
{
	public:
		Animal* Create(){ return new Horse; }
};

class SnakeFactory : public Factory
{
	public:
		Animal* Create(){ return new Snake; }
};

class FishFactory : public Factory
{
	public:
		Animal* Create(){ return new Fish; }
};

Animal* CreateAnimal(Factory *value)
{
    return value->Create(); 
}