// cardgenerator.h - randomizes a deck of cards
// written by Brett Esworthy

#include <iostream>
#include <string>
#include <time.h>

#define MAX_FACE 13
#define MAX_SUIT 4

#pragma once
using namespace std;

struct CardGenerator
{
	CardGenerator()
	{
	}

	int GetFace()
	{
		//Reset the random number generator
		srand((int) time(NULL));
		//draw a card
		int face;
		face = (rand() % MAX_FACE) + 1;
		//Display the card face
		return face;
	}
		
	void DisplayFace()
	{
		int face = GetFace();
		cout << "\n--------------------";
		if((face >= 2) && (face <= 9))
			cout << "\n|   " << face <<"  ";
		else if(face == 10)
			cout << "\n|  " << face <<"  ";
		else if(face == 1)
			cout << "\n| Ace  ";
		else if(face == 11)
			cout << "\n| Jack ";
		else if(face == 12)
			cout << "\n| Queen";
		else if(face == 13)
			cout << "\n| King ";
		else
		{
			cout << "Error! Invalid card face." << endl;
			exit(0);
		}
	}
	
	int Suit()
	{
		//Reset the random number generator
		srand((int) time(NULL));
		//draw a card	
		int suit;
		suit = (rand() %MAX_SUIT) + 1;
		//display the card suit
		if(suit == 1)
			cout << " of spades  |";
		else if(suit == 2)
			cout << " of clubs   |";
		else if(suit == 3)
			cout << " of diamonds|";
		else if(suit == 4)
			cout << " of hearts  |";
		else
		{
			cout << "Error! Invalid card suit." << endl;
			exit(0);
		}
		cout << "\n--------------------" << endl;
		return suit;
	}


};
