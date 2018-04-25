#include <iostream>
#include "AnimalManager.h"

using namespace std;

void showMainMenu()
{
		cout<<"--- Animal Manager ---"<<endl
		<<"0 - Exit"<<endl
		<<"1 - Add animals to list"<<endl
		<<"2 - Show animal list"<<endl
		<<"3 - Show number of animals in list"<<endl	
		<<"4 - Save list into separate files"<<endl
		<<"-> ";
}

int main()
{	
    setlocale( LC_ALL,"Russian" );
	AnimalManager Animals;

	showMainMenu();
	int c;
	do
	{
		cin>>c;
		switch (c)
		{
			case 1: { Animals.Add(); cout<<"Animals added."<<endl; break; }
			case 2: { cout<<"Top of list."<<endl; Animals.Show(); cout<<"End of list."<<endl; break; }
			case 3: { cout<<"Number of animals in list: "<<Animals.Number()<<endl; break;}					
			case 4: { Animals.SaveToFile("cat.txt", "dog.txt", "mouse.txt", "horse.txt", "snake.txt", "fish.txt"); cout<<"Saved."<<endl; break; }
			case 0: { cout<<"Exiting program."<<endl; return 0; }
		}
		system("pause");
		system ("cls");
		showMainMenu();		
	} while (1);

	return 0;
}