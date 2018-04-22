#include <iostream>
#include "AnimalManager.h"

using namespace std;

void showMainMenu()
{
		cout<<"--- Animal Manager ---"<<endl
		<<"1 - Add animals to list"<<endl
		<<"2 - Show animal list"<<endl
		<<"3 - Save list into separate files"<<endl
		<<"0 - Exit"<<endl
		<<"-> ";
}

int main()
{	
    setlocale( LC_ALL,"Russian" );
	AnimalManager Animals;

	showMainMenu();
	int c;
	cin>>c;
	do
	{
		switch (c)
		{
			case 1: { Animals.Add(); cout<<"Animals added."<<endl; break; }
			case 2: { Animals.Show(); cout<<"End of list."<<endl; break; }
			case 3: { Animals.SaveToFile("cat.txt", "dog.txt", "mouse.txt", "horse.txt", "snake.txt", "fish.txt"); cout<<"Saved."<<endl; break; }
			case 0: { return 0; }
		}
		system("pause");
		system ("cls");
		showMainMenu();
		cin>>c;
	} while (c!=0);

	return 0;
}