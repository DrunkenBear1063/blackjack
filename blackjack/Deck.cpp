#include <iostream>
#include <random>
#include "Deck.h"

Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

void Deck::Populate()
{
	Clear();

	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			Add(Card{ static_cast<Card::Rank>(r), static_cast<Card::Suit>(s) });
		}
	}
}

void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_Cards.begin(), m_Cards.end(), g);
}

void Deck::Deal(Hand& hand)
{
	if (!m_Cards.empty())
	{
		hand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		std::cout << "Out of cards. Unable to deal." << std::endl;
	}
}

void Deck::AdditionalCards(GenericPlayer& genericPlayer)
{
	std::cout << std::endl;

	while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
	{
		Deal(genericPlayer);
		std::cout << genericPlayer << std::endl;

		if (genericPlayer.IsBusted())
		{
			genericPlayer.Bust();
		}
	}
}

Deck::~Deck() {}