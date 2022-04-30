#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class card_Deck {
	// Private objects
private:
	int rank;
	int suit;

	// Public functions
public:
	card_Deck() {
		srand(time(NULL));
		rank = (1 + (rand() % (int)(13)));	// 13 ranks
		suit = (1 + (rand() % (int)(4)));	// 4 suits
	}

	int getRank() {
		return rank;
	}

	// Assign random-generated numbers to card ranks
	string getRankString() {
		if (rank == 1) return "Ace";
		if (rank == 2) return "Two";
		if (rank == 3) return "Three";
		if (rank == 4) return "Four";
		if (rank == 5) return "Five";
		if (rank == 6) return "Six";
		if (rank == 7) return "Seven";
		if (rank == 8) return "Eight";
		if (rank == 9) return "Nine";
		if (rank == 10) return "Ten";
		if (rank == 11) return "Jack";
		if (rank == 12) return "Queen";
		if (rank == 13) return "King";
		else return "Unknown rank";
	}

	int getSuit() {
		return suit;
	}

	// Assign random-generated numbers to card suits
	string getSuitString() {
		if (suit == 1) return "Clubs";
		if (suit == 2) return "Diamonds";
		if (suit == 3) return "Spades";
		if (suit == 4) return "Hearts";
		else return "Unknown suit";
	}
};