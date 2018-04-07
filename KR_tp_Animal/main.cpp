#include <iostream>
#include <list>
#include <fstream>
#include "Factory.h"

using namespace std;

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
	//for (int i=0; i<1; i++)
	{
		Factory *ptr;
		int c;
		cout<<"Input animal 1,2 ";
		cin>>c;
		switch (c)
		{
		case 1: { ptr = &cat; break; }
		case 2: { ptr = &dog; break; }
		default: { ptr = &cat; break;}
		}

			Animal *ObjectNature = foo(ptr);

			cout<<"Input type of inp ";
			cin>>c;
			if (c==1) ObjectNature->set();
			else 
				{
					string fname;
					cout<<"Input file name -> ";
					cin>>fname;
					ifstream fpin (fname);
					if (!fpin) cout << "File not found" << endl;

					ObjectNature->set(fpin);
					fpin.close();
			}

			ani.push_back(ObjectNature);

			// do you want to add animal
			cout<<"Do you want to add another animal? (0\1) -> ";
			cin>>add;
	} while (add);
	
	  for (auto v : ani)
	  {
		v->info(); v->Show();
		if (v->getType()=="cat")
		{
			ofstream fpout;
			fpout.open("cat.txt", ios::app);
			//fpout<<
			fpout.close();
		}
		else if (v->getType()=="dog")
		{
			ofstream fpout;
			fpout.open("dog.txt", ios::app);
			//fpout<<
			fpout.close();
		}
	  }



}