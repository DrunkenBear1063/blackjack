#pragma once

#include "Card.h"
#include <vector>

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void add(Card pCard);
	void clear();
	int getTotal() const;
public:
	std::vector<Card> m_Cards;
};