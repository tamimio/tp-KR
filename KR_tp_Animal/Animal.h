#include <iostream>
#include <string>

#include "Add.h"

using namespace std;

#define gen_fem 0
#define gen_male 1

#define animal_type_cat 0
#define animal_type_dog 1
#define animal_type_mouse 2
#define animal_type_horse 3
#define animal_type_snake 4
#define animal_type_fish 5

class Animal
{
	protected:
		int type;
	private:
		string poroda;
		string colour;
		string name;
		bool gender;
		Date birthDate;
		Razmery razm;
		string ownerName;
		string pitomnik;
		string character;

		string type2str();

	public:
		virtual ~Animal() {}

		virtual void Read (istream &is=cin);
		virtual void Print(ostream &os=cout);

		int getType(){ return type; }
};

string Animal::type2str()
{
	switch (type)
	{
		case animal_type_cat: return "cat";
		case animal_type_dog: return "dog";
		case animal_type_mouse: return "mouse";
		case animal_type_horse: return "horse";
		case animal_type_snake: return "snake";
		case animal_type_fish: return "fish";
	}
}
void Animal::Read (istream &is)
{
	if (is==cin) cout<<"Input poroda -> ";
	is>>poroda;
	if (is==cin) cout<<"Input colour -> ";
	is>>colour;
	if (is==cin) cout<<"Input name -> ";
	is>>name;

	for (int i=0; i<1; ++i)
	{
		if (is==cin) cout<<"Input gender (f/m) -> ";
		char c;
		is>>c;
		if (c=='f') gender=gen_fem;
		else if (c=='m') gender=gen_male;
		else
		{
			if (is==cin) {system("cls"); cout<<"Incorrect gender. Try again."<<endl; i--;}
			else throw ("Error reading file. Incorrect gender.");
		}
	}

	for (int i=0; i<1; ++i)
	try
	{
		if (is==cin) cout<<"Input birth date (dd.mm.yyyy) -> ";
		is>>birthDate;
	}
	catch(char * err)
	{
		cout<<err<<endl;
		if (is==cin) {cout<<"Try again."<<endl; i--;}
			else throw ("Error reading file. Incorrect date.");
	}
	if (is==cin) cout<<"Input razmery (len hei wei) -> ";
	is>>razm;

	if (is==cin) cout<<"Input owner's name -> ";
	is>>ownerName;
	if (is==cin) cout<<"Input name of pitomnik -> ";
	is>>pitomnik;
	if (is==cin) cout<<"Input character -> ";
	is>>character;
}
void Animal::Print(ostream &os)
{
	if(os==cout) { cout<<"Type: "; cout<<type2str()<<endl;}
	if(os==cout) cout<<"Poroda: ";
		os<<poroda<<endl;
	if(os==cout) cout<<"Colour: ";
		os<<colour<<endl;
	if(os==cout) cout<<"Name: ";
		os<<name<<endl;
	if(os==cout) cout<<"Gender: ";
	if (gender==gen_fem) os<<"f"<<endl; else os<<"m"<<endl;
	if(os==cout) cout<<"Birth date: ";
		os<<birthDate<<endl;
	if(os==cout) cout<<"Razmery: ";
		os<<razm<<endl;
	if(os==cout) cout<<"Owner name: ";
		os<<ownerName<<endl;
	if(os==cout) cout<<"Pitomnik: ";
		os<<pitomnik<<endl;
	if(os==cout) cout<<"Character: ";
		os<<character<<endl;
}


//-----------------------------------------------------------------------------

class Cat : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_cat; }
};

class Dog : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_dog; }
};

class Mouse : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_mouse; }
};

class Horse : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_horse; }
};

class Snake : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_snake; }
};

class Fish : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type=animal_type_fish; }
};

