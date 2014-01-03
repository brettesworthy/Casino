// roulette.h - class declaration and implementation for roulette game
// written by Brett Esworthy

#include <iostream>
#include <string>
#include <time.h>

#define MAX_RANGE 36

using namespace std;
#pragma once


struct Roulette
{
	int currentcash;

	Roulette(){};
		
	Roulette ( int cash )
	{
		currentcash = cash;
	}

	int Play()
	{
		srand( (int) time( NULL ) );
		int random, total;
		char entry;
		cout << "Welcome to roulette!\n"
         << "Please bet on Odd, Even, or Zero using\n"
         << "E, O, or Z. Each bet is 5 dollars.\n"
         << "Landing on Zero is worth 50 dollars!\n"
         << "Hit Q to quit or else the game automatically\n"
	     << "quits when you are out of money.\n";

		do
	{
		random = rand() % MAX_RANGE;

		cout << "\nBet on Even(E),Odd(O),Zero(Z),Or Quit(Q): ";
		cin >> entry;

        //If statement for Even; cash gets substracted or added; wins and loses are accounted for
		if( entry == 'E' || entry == 'e' )
		{
			cout << "The wheel came up as: " << random << endl; 
			if( random %2 == 0 && random != 0)
			{
				currentcash+=5;
				//wins+=1;
				cout <<"You win! You now have: " << currentcash << " dollars.\n";
			}
			else
			{
				currentcash-=5;
				//loses+=1;
				cout <<"Sorry you lose. You now have: " << currentcash << " dollars.\n";
			}

		}
		//Same statement but for odd
		else if( entry == 'O' || entry == 'o' )
		{
			cout << "The wheel came up as: " << random << endl; 
			if( random %2 != 0 && random != 0)
			{
				currentcash+=5;
				//wins+=1;
				cout <<"You win! You now have: " << currentcash << " dollars.\n";
			}
			else
			{
				currentcash-=5;
				//loses+=1;
				cout <<"Sorry you lose. You now have: $" << currentcash << " dollars.\n";
			}
		}
		//Again, the same statment but user can win 50 but only lose 5
		else if( entry == 'Z' || entry == 'z' )
		{
			cout << "The wheel came up as: " << random << endl
				; 
			if( random == 0)
			{
				currentcash+=50;
				//wins+=1;
				cout <<"You win 50 dollars! You now have: $" << currentcash << " dollars.\n";
			}
			else
			{
				currentcash-=5;
				//loses+=1;
				cout<<"Sorry you lose. You now have: $" << currentcash << " dollars.\n";
			}

		}
		//If the user decides to quit
		else if( entry != 'q' && entry != 'Q' )
		{
			cout << "You have entered an invalid choice.\n";
		}
		
	}while( entry != 'q' && entry != 'Q' && currentcash != 0 );
	return currentcash;
	}
};
