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
	public:
		virtual ~Animal() {}
		
		virtual void Read (istream &is=cin);
		virtual void Print(ostream &os=cout);

		string getType(){return type;}

	protected:
		string type;

		string poroda;
		string colour;
		string name;

		bool gender;
		//Date birthDate();
		//Razmery razm;

		string ownerName;
		string pitomnik;
		string character;
};


void Animal::Read (istream &is)
{
	if (is==cin) cout<<"Input poroda -> ";
	is>>poroda;
	if (is==cin) cout<<"Input colour -> ";
	is>>colour;
	if (is==cin) cout<<"Input name -> ";
	is>>name;

	if (is==cin) cout<<"Input gender (f/m) ->";
	char c;
	is>>c;
	if (c=='f') gender=gen_fem;
	else if (c=='m') gender=gen_male;

	if (is==cin) cout<<"Input owner's name ->";
	is>>ownerName;
	if (is==cin) cout<<"Input name of pitomnik ->";
	is>>pitomnik;
	if (is==cin) cout<<"Input character ->";
	is>>character;
}
void Animal::Print(ostream &os)
{
	if(os==cout) { cout<<"Type: "; cout<<type<<endl;}
	if(os==cout) cout<<"Poroda: ";
		os<<poroda<<endl;
	if(os==cout) cout<<"Colour: ";
		os<<colour<<endl;
	if(os==cout) cout<<"Name: ";
		os<<name<<endl;
	if(os==cout) cout<<"Gender: ";
	if (gender==gen_fem) os<<"f"<<endl; else os<<"m"<<endl;
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
		void Read(istream &is=cin) { Animal::Read(is); type="cat"; }
};

class Dog : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type="dog"; }
};

class Mouse : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type="mouse"; }
};

class Horse : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type="horse"; }
};

class Snake : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type="snake"; }
};

class Fish : public Animal
{
	public:
		void Read(istream &is=cin) { Animal::Read(is); type="fish"; }
};

