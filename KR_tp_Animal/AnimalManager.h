#include <iostream>
#include <list>
#include <fstream>
#include "Factory.h"

using namespace std;

class AnimalManager
{
		list <Animal*> ani;

	public:
		void Add();
		void SaveToFile(string fcat, string fdog, string fmouse, string fhorse, string fsnake, string ffish);
		void Show();
};

void AnimalManager::Add()
{
	CatFactory cat;   
	DogFactory dog;
	MouseFactory mouse;
	HorseFactory horse;
	SnakeFactory snake;
	FishFactory fish;

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
			default: { throw ("Incorrect type of animal"); break; }
		}

		Animal *ObjectAnimal = CreateAnimal(factory);

		cout<<"Input type of adding data"<<endl
			<<"1-console, 2-file"<<endl
			<<"-> ";
		cin>>c;
		switch (c)
		{
			case 1:
				{
					ObjectAnimal->Read();
					break; 
				}
			case 2:
				{
					string fname;
					cout<<"Input file name -> ";
					cin>>fname;
					ifstream fpin (fname+".txt");
					if (!fpin) throw ("File not found");
					try
					{
						ObjectAnimal->Read(fpin);
					}
					catch (char * err)
					{
						cout<<err<<endl<<"Closing file."<<endl;;
					}
					fpin.close();
					break;
				}
		}

		ani.push_back(ObjectAnimal);

		cout<<"Do you want to add another animal? (0/1) -> ";
		cin>>add;
	} while (add);
}

void AnimalManager::Show()
{
	for (auto v : ani) v->Print(); 
}

void AnimalManager::SaveToFile(string fcat, string fdog, string fmouse, string fhorse, string fsnake, string ffish)
{
	bool clr;
	cout<<"Do you want to clear files first? (0/1) -> ";
	cin>>clr;
	bool clear[6];
	for (int i=0; i<6; i++) clear[i]=clr;

	for (auto v : ani)
	{
		if (v->getType()==animal_type_cat)
		{
			if (clear[animal_type_cat]) { clrFile(fcat); clear[animal_type_cat]=false; }
			ofstream fpout;
			fpout.open(fcat, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_dog)
		{
			if (clear[animal_type_dog]) { clrFile(fcat); clear[animal_type_dog]=false; }
			ofstream fpout;
			fpout.open(fdog, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_mouse)
		{
			if (clear[animal_type_mouse]) { clrFile(fcat); clear[animal_type_mouse]=false; }
			ofstream fpout;
			fpout.open(fmouse, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_horse)
		{
			if (clear[animal_type_horse]) { clrFile(fcat); clear[animal_type_horse]=false; }
			ofstream fpout;
			fpout.open(fhorse, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_snake)
		{
			if (clear[animal_type_snake]) { clrFile(fcat); clear[animal_type_snake]=false; }
			ofstream fpout;
			fpout.open(fsnake, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_fish)
		{
			if (clear[animal_type_fish]) { clrFile(fcat); clear[animal_type_fish]=false; }
			ofstream fpout;
			fpout.open(ffish, ios::app);
			v->Print(fpout);
			fpout.close();
		}
	}
}