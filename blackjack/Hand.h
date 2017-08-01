#pragma once

#include "Card.h"
#include <vector>

class Hand
{
public:
	Hand();
	virtual ~Hand();
	//добавляет карту в руку
	void add(Card* pCard);
	//очищает руку от карт
	void clear();
	//получает сумму очков карт в руке
	int getTotal() const;
public:
	std::vector<Card*> m_Cards;
};