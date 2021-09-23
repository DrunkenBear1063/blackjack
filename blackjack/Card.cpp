#include "stdafx.h"
#include "Card.h"
#include <iostream>
#include <string>

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_isFaceUp(ifu)
{}

int Card::getValue() const
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

void Card::flip()
{
	m_isFaceUp = !(m_isFaceUp);
}

Card::~Card()
{}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const std::string SUITS[] = { "c", "d", "h", "s" };
	if (aCard.m_isFaceUp)
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
	}
	else
	{
		os << "XX";
	}
	return os;
}