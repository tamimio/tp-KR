#include <iostream>
#include "Factory.h"

using namespace std;

int main()
{
	CatFactory cat;   
	DogFactory dog;
	MouseFactory mouse;
	HorseFactory horse;
	SnakeFactory snake;
	FishFactory fish;
 
	Factory *ptr1 = &cat;
	Factory *ptr2 = &dog;
	Factory *ptr3 = &mouse;
	Factory *ptr4 = &horse;
	Factory *ptr5 = &snake;
	Factory *ptr6 = &fish;
 
	Animal *ObjectNature1 = foo(ptr1);
	Animal *ObjectNature2 = foo(ptr2);
	Animal *ObjectNature3 = foo(ptr3);
	Animal *ObjectNature4 = foo(ptr4);
	Animal *ObjectNature5 = foo(ptr5);
	Animal *ObjectNature6 = foo(ptr6);
 
	ObjectNature1->info();
	ObjectNature2->info();
	ObjectNature3->info();
	ObjectNature4->info();
	ObjectNature5->info();
	ObjectNature6->info();
 
	delete ObjectNature1;
	delete ObjectNature2;
	delete ObjectNature3;
	delete ObjectNature4;
	delete ObjectNature5;
	delete ObjectNature6; 
}