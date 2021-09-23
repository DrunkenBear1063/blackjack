#include "stdafx.h"
#include "Hand.h"
#include <vector>

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	clear();
}

void Hand::add(Card pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::clear()
{
	m_Cards.clear();
}

int Hand::getTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}
	if (m_Cards[0].getValue() == 0)
	{
		return 0;
	}
	int total = 0;

  for (auto card : m_Cards)
  {
    total += card.getValue();
  }
   
	bool containsAce = false;
	for (auto card : m_Cards)
	{
		if (card.getValue() == Card::ACE)
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