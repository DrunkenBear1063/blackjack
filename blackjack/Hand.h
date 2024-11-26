#pragma once
#include <vector>
#include "Card.h"

class Hand
{
public:
	std::vector<Card> m_Cards;

	Hand();
	virtual ~Hand();

	void Add(Card card);
	void Clear();
	int GetTotal() const;
};