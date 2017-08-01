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

void Hand::add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::clear()
{
	std::vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear();
}

int Hand::getTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}
	if (m_Cards[0]->getValue() == 0)
	{
		return 0;
	}
	int total = 0;
	std::vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->getValue();
	}
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->getValue() == Card::ACE)
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