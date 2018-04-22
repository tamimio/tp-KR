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
		void SaveToFile(string fcat, string fdog, string fmouse,
						string fhorse, string fsnake, string ffish);
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
		bool del=false;
		Factory *factory;

		cout<<"Input type of animal"<<endl
			<<"0-cat, 1-dog, 2-mouse, 3-horse, 4-snake, 5-fish"<<endl
			<<"-> ";
		int choice_animal;
		cin>>choice_animal;
		switch (choice_animal)
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
			<<"c - console, f - file"<<endl
			<<"-> ";
		char choice_input;
		cin>>choice_input;
		switch (choice_input)
		{
			case 'c':
				{
					ObjectAnimal->Read();
					break; 
				}
			case 'f':
				{
					string fname;
					cout<<"Input file name -> ";
					cin>>fname;
					ifstream fpin (fname+".txt");
					try
					{
						if (!fpin) throw ("File not found");
						ObjectAnimal->Read(fpin);
					}
					catch (char * err)
					{
						cout<<err<<endl<<"Closing file."<<endl;
						del=true;
					}
					fpin.close();
					break;
				}
			default:
				{
					cout<<"Incorrect symbol."<<endl;
					del=true;
				}
		}

		ani.push_back(ObjectAnimal);

		if (del)
		{
			cout<<"Deleting this animal."<<endl;
			ani.pop_back(); 
			del=false;
		}
		
		cout<<"Do you want to add another animal? (0/1) -> ";
		cin>>add;
	} while (add);
}

void AnimalManager::Show()
{
	for (auto v : ani)
	{
		cout<<"--------------------"<<endl;
		v->Print(); 
		cout<<"--------------------"<<endl;
	}
}

void AnimalManager::SaveToFile(string fcat, string fdog, string fmouse,
							   string fhorse, string fsnake, string ffish)
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
			if (clear[animal_type_dog]) { clrFile(fdog); clear[animal_type_dog]=false; }
			ofstream fpout;
			fpout.open(fdog, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_mouse)
		{
			if (clear[animal_type_mouse]) { clrFile(fmouse); clear[animal_type_mouse]=false; }
			ofstream fpout;
			fpout.open(fmouse, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_horse)
		{
			if (clear[animal_type_horse]) { clrFile(fhorse); clear[animal_type_horse]=false; }
			ofstream fpout;
			fpout.open(fhorse, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_snake)
		{
			if (clear[animal_type_snake]) { clrFile(fsnake); clear[animal_type_snake]=false; }
			ofstream fpout;
			fpout.open(fsnake, ios::app);
			v->Print(fpout);
			fpout.close();
		}
		else if (v->getType()==animal_type_fish)
		{
			if (clear[animal_type_fish]) { clrFile(ffish); clear[animal_type_fish]=false; }
			ofstream fpout;
			fpout.open(ffish, ios::app);
			v->Print(fpout);
			fpout.close();
		}
	}
}