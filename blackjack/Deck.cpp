#include "stdafx.h"
#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <random>

Deck::Deck()
{
	m_Cards.reserve(52);
	populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
	clear();

	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
      add(Card{ static_cast<Card::rank>(r), static_cast<Card::suit>(s) });
		}
	}
}

void Deck::shuffle()
{
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(m_Cards.begin(), m_Cards.end(), g);
}

void Deck::deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
    std::cout << "Out of cards. Unable to deal." << std::endl;
	}
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;

	while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
	{
		deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;
		if (aGenericPlayer.isBusted())
		{
			aGenericPlayer.bust();
		}
	}
}
