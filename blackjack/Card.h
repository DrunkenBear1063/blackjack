#pragma once
#include <iostream>

class Card
{
public:
	enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

	Rank m_Rank;
	Suit m_Suit;
	bool m_isFaceUp;

	Card(Rank r = ACE, Suit s = SPADES, bool isFaceUp = true);
	~Card();

	friend std::ostream& operator<<(std::ostream& os, const Card& card);

	int GetValue() const;
	void Flip();
};