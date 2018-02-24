#include <iostream>

using namespace std;

class Animal
{
	public:
		virtual void info() = 0;
		virtual ~Animal() {}
};

class Cat : public Animal
{
	public:
		void info() {cout<<"Cat"<<endl;}
};

class Dog : public Animal
{
	public:
		void info() {cout<<"Dog"<<endl;}
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