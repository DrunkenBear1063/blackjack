#include <vector>
#include "Hand.h"

Hand::Hand()
{
	m_Cards.reserve(7);
}

void Hand::Add(Card pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}

	if (m_Cards[0].GetValue() == 0)
	{
		return 0;
	}

	int total = 0;

	for (auto card : m_Cards)
	{
		total += card.GetValue();
	}
   
	bool containsAce = false;

	for (auto card : m_Cards)
	{
		if (card.GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 11)
	{
		total += 10;
	}

	return total;
}

Hand::~Hand()
{
	Clear();
}