#include <iostream>
#include <list>
#include <fstream>
#include "AnimalManager.h"

using namespace std;

void showMainMenu()
{
		cout<<"--- Animal Manager ---"<<endl
		<<"1 - Add animals to list"<<endl
		<<"2 - Show animal list"<<endl
		<<"3 - Save animal list into separate files"<<endl
		<<"0 - Exit"<<endl
		<<"-> ";
}

int main()
{
	AnimalManager Animals;

	showMainMenu();
	int c;
	cin>>c;
	do
	{
		switch (c)
		{
			case 1: { Animals.Add(); cout<<"Done"<<endl; break; }
			case 2: { Animals.Show(); cout<<"Done"<<endl; break; }
			case 3: { Animals.SaveToFile("cat.txt", "dog.txt", "mouse.txt", "horse.txt", "snake.txt", "fish.txt"); cout<<"Done"<<endl; break; }
			case 0: { cout<<"Exiting program..."<<endl; return 0; }
		}
		system("pause");
		system ("cls");
		showMainMenu();
		cin>>c;
	} while (c!=0);

	return 0;
}
/*
int main()
{
	// clear cat, dog txt

	CatFactory cat;   
	DogFactory dog;
	MouseFactory mouse;
	HorseFactory horse;
	SnakeFactory snake;
	FishFactory fish;

	list <Animal*> ani;


	bool add=1;
	do
	{
		Factory *factory;

		cout<<"Input type of animal"<<endl
			<<"0-cat, 1-dog, 2-mouse, 3-horse, 4-snake, 5-fish"<<endl
			<<"-> ";
		int c;
		cin>>c;
		switch (c)
		{
			case animal_type_cat: { factory = &cat; break; }
			case animal_type_dog: { factory = &dog; break; }
			case animal_type_mouse: { factory = &mouse; break; }
			case animal_type_horse: { factory = &horse; break; }
			case animal_type_snake: { factory = &snake; break; }
			case animal_type_fish: { factory = &fish; break; }
			default: { throw ("Incorrect type of animal"); break;}
		}

		Animal *ObjectAnimal = CreateAnimal(factory);

		cout<<"Input type of adding data"<<endl
			<<"1-console, 2-file"<<endl
			<<"-> ";
		cin>>c;
		switch (c)
		{
			case 1: { ObjectAnimal->Read(); break; }
			case 2:
				{
					string fname;
					cout<<"Input file name -> ";
					cin>>fname;
					ifstream fpin (fname);
					if (!fpin) throw ("File not found");
					ObjectAnimal->Read(fpin);
					fpin.close();
				}
		}

		ani.push_back(ObjectAnimal);

		cout<<"Do you want to add another animal? (0/1) -> ";
		cin>>add;
	} while (add);
	



	for (auto v : ani)
	{
		v->Print();
		if (v->getType()=="cat")
		{
			ofstream fpout;
			fpout.open("cat.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()=="dog")
		{
			ofstream fpout;
			fpout.open("dog.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()=="mouse")
		{
			ofstream fpout;
			fpout.open("mouse.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()=="horse")
		{
			ofstream fpout;
			fpout.open("horse.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()=="snake")
		{
			ofstream fpout;
			fpout.open("snake.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()=="fish")
		{
			ofstream fpout;
			fpout.open("fish.txt", ios::app);
			v->Print(fpout);
			fpout.close();
		}
	}


}*/