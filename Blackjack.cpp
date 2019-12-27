// Vimanga V. Umange
//blackjack.cpp

#include <iostream>
#include <stdlib.h>
#include <time.h> // needed for random fucntion
using namespace std;


bool checkbusted(int cardtotal); // checks to see if the dealer had gone above 21 
int gameSimulation(); 
void simulategame(int n);
int RandomCard();

int main() {
	cout << " Welcome to the game of Blackjack" << endl << endl;
	int n;
	cout << " How many games of Blackjack would you like to simulate" << endl; // Takes user inuput to determine the amount of times the game should simulate
	srand(time(NULL));
	cin >> n; // the game is simulated n times accrding to user 
	simulategame(n);
	return 0;

}

bool checkbusted(int cardtotal) {	// function to check if the dealer is busted
	return cardtotal >= 22 or cardtotal >= 17; // checks to see if the player is busted
}

void simulategame(int n) {
	int i;
	int hold = 0;
	int busted = 0;
	for (i = 0; i < n; i++) {	// simulating the game
		int cardtotal = gameSimulation();
		if (cardtotal >= 22)
			busted += 1;	// if busted then busted counter icrease by 1

		else
			hold += 1;	// if not busted the hold counter is increased by 1
	}
	cout << " Out of a total of " << n << " games " << busted << " were busted" << endl;
}

	int RandomCard()	// random card generator
	{
	int randNum = rand() % ((13));
	return randNum;
		
	}

int gameSimulation() {	// This function detrmines the total of the card given that the dealer or player have not been busted yet
	int cardtotal = 0;
	int cardscore[13] = { 2,3,4,5,6,7,8,9,10,10,10,11 }; // Jack, Queen and King all 3 have a face value of 10 and ace is 11
	while (checkbusted(cardtotal) == false) {	// do while loop while dealer is not busted
		int temp = cardscore[RandomCard()];
		if (cardtotal >= 17)
			break;
		if (temp != 11) {
			cardtotal = cardtotal + temp;
		}
		else if (temp == 11 and (cardtotal >= 6 and cardtotal <= 10))
			cardtotal = cardtotal + 11;
		else
			cardtotal = cardtotal + 1; // if card total has gone over ace is only worth 1 point
	}
	return cardtotal;
}





	




