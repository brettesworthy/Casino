// HighLow.h - highlow game class declaration and implementation
// written by Brett Esworthy

#include <iostream>
#include <string>
#include <time.h>
#include "CardGenerator.h"

#pragma once
using namespace std;

struct HighLow
{
	int currentcash;

	HighLow(){};

	HighLow( int cash )
	{
		currentcash = cash;
	}

	int Play()
	{
		srand((unsigned) time(NULL));
		char entry;
		cout << "Welcome to High/Low!\n"
			 << "Each round is a bet of $5.\n"
			 << "Guess if the next card is higher or lower.\n"
			 << "Type H for higher, L for lower, and Q to quit.\n"
			 << "This game will automatically end if you run out\n"
			 << "of money.\n" << endl;
		CardGenerator cards;

		do
		{
			int currentface = 0;
			int nextface = 0;
			cout << "The card is:";
			cards.DisplayFace();
			cards.Suit();
			currentface = cards.GetFace();
			cout << "Bet on Higer(H), Lower(L), or Quit(Q): ";
			cin >> entry;
			if( currentface == 1)
			{
				currentface = 14;
			}
			if(entry == 'h' || entry == 'H')
			{
				cout << "The next card is:";
				cards.DisplayFace();
				cards.Suit();
				nextface = cards.GetFace();

				if(nextface > currentface)
				{
					currentcash += 5;
					cout << "The guess is correct! You now have: $" << currentcash << endl;
				}
				else if(nextface == currentface)
				{
					cout << "Draw! You have: $" << currentcash << endl;
				}
				else
				{
					currentcash -= 5;
					cout << "The guess incorrect! You now have: $" << currentcash << endl;
				}
			}
			else if(entry == 'l' || entry == 'L')
			{
				cout << "The next card is:";
				cards.DisplayFace();
				cards.Suit();
				nextface = cards.GetFace();
				if(nextface < currentface)
				{
					currentcash += 5;
					cout << "The guess is correct! You now have: $" << currentcash << endl;
				}
				else if(nextface == currentface)
				{
					cout << "Draw! You have: $" << currentcash << endl;
				}
				else
				{
					currentcash -= 5;
					cout << "The guess is incorrect! You now have: $" << currentcash << endl;
				}
			}
			else if(entry != 'q' && entry != 'Q')
			{
				cout << "You have entered an invalid choice.\n";
			}	
			
		}
		while(entry != 'q' && entry != 'Q' && currentcash != 0 );
		return currentcash;

	}



};
