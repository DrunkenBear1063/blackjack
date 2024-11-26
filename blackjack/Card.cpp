#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

Card::Card(Rank r, Suit s, bool isFaceUp) : m_Rank(r), m_Suit(s), m_isFaceUp(isFaceUp) {}

int Card::GetValue() const
{
	int value = 0;

	if (m_isFaceUp)
	{
		value = m_Rank;

		if (value > 10)
		{
			value = 10;
		}
	}

	return value;
}

void Card::Flip()
{
	m_isFaceUp = !(m_isFaceUp);
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	const std::vector<std::string> Ranks = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const std::vector<std::string> Suits = { "c", "d", "h", "s" };

	if (card.m_isFaceUp)
	{
		os << Ranks[card.m_Rank] << Suits[card.m_Suit];
	}
	else
	{
		os << "XX";
	}

	return os;
}

Card::~Card() {}