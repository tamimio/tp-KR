#include <iostream>
#include <string>

using namespace std;

class Animal
{
	public:
		virtual void info() = 0;
		virtual ~Animal() {}

	//	virtual void Print(ostream &os) const;

		virtual void set()
		{
			cout<<"Input poroda -> ";
			cin>>poroda;
			cout<<"Input colour -> ";
			cin>>colour;
			cout<<"Input name -> ";
			cin>>name;
		}

		virtual void set (istream &is)
		{
			getline(is, poroda);
			getline(is, colour);
			getline(is, name);
		}

		virtual void Show()
		{
			cout<<"Type: "<<type<<endl;
			cout<<"Poroda: "<<poroda<<endl;
			cout<<"Colour: "<<colour<<endl;
			cout<<"Name: "<<name<<endl;
		}

		string getType(){return type;}

	protected:
		string type;

		string poroda;
		string colour;
		string name;
		bool gender;

		string ownerName;
		string pitomnik;
		string character;
};

class Cat : public Animal
{
	public:
		void info() {cout<<"Cat"<<endl;}
		//void Print(ostream &os) const;
		void set(){ Animal::set(); type="cat"; } 
		void set(istream &is){ Animal::set(is); type="cat"; } 
};

class Dog : public Animal
{
	public:
		void info() {cout<<"Dog"<<endl;}

		//void Print(ostream &os) const;
};

class Mouse : public Animal
{
	public:
		void info() {cout<<"Mouse"<<endl;}
};

class Horse : public Animal
{
	public:
		void info() {cout<<"Horse"<<endl;}
};

class Snake : public Animal
{
	public:
		void info() {cout<<"Snake"<<endl;}
};

class Fish : public Animal
{
	public:
		void info() {cout<<"Fish"<<endl;}
};







/*
void Animal::Print(ostream &os) const
{
	os << "a: "<<  std::endl;
}

void Cat::Print(ostream &os) const
{
	os << "C: "<<  std::endl;
}
void Dog::Print(ostream &os) const
{
	os << "d: "<<  std::endl;
}

ostream & operator<<(ostream &os, const Animal &a)
{
	a.Print(os);
	return os;
}*/