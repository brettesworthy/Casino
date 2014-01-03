// main.cpp - main menu for casino
// written by Brett Esworthy

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include "Roulette.h"
#include "HighLow.h"

#define START_MONEY 100
using namespace std;

void main()
{
	int userinput = 0;
	int cash = START_MONEY;
	Roulette token_one;
	token_one.currentcash = cash;
	HighLow token_two;
	token_two.currentcash = cash;
	cout << "Welcome to Brett's casino." << endl
		 << "Your starting wage will be $100." << endl;
		 
	cout << "Loading"; Sleep(1000); cout << " ."; Sleep(1000);
	cout << " ."; Sleep(1000); cout << " ."; Sleep(1000);
    cout << " ."; Sleep(1000); cout << " . " << endl;
	do
	{
		// main menu for the casino
		// provides selections of games if
		// the user does not quit or if the user has ran out of money
		cout << "Please make a selection for type of game to play.\n" << endl
			 << "---------------------------------" << endl
			 << "|\t 1.) Roulette\t\t|\n"
			 << "|\t 2.) High/Low\t\t|\n"
		     << "|\t 3.) BlackJack\t\t|\n"
		     << "|\t 4.) Slots   \t\t|\n"
			 << "|\t 5.) Stats   \t\t|\n"
			 << "|\t 6.) Quit    \t\t|\n"
			 << "---------------------------------" << endl;
		cout << "\tSelection: ";
		cin >> userinput;
		cout << endl << endl;
		if (userinput == 1)
		{
			cash = token_one.Play();
			cout << endl;
		}
		else if (userinput == 2)
		{
			cash = token_two.Play();
			cout << endl;
		}
		else if(userinput == 5)
		{
			cout << "Your current cash is: $" << cash << endl
				 << endl;
		}
		else if(userinput == 6)
			break;
		else
		{
			cout << "You have entered an invalid choice, try again."
				 << endl << endl;
		}

	}
	while(cash != 0);

	cout << "Thank you for playing Brett's Casino!\n"
		 << "Please play again!\n"; Sleep(1000);

	system("pause");
}
