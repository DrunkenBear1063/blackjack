#include "stdafx.h"
#include "Game.h"
#include <ctime>
#include <vector>
#include <string>
#include <iostream>


Game::Game(const std::vector<std::string>& names)
{
	std::vector<std::string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(Player(*pName));
	}
	srand(static_cast<unsigned int>(time(0)));
	m_Deck.populate();
	m_Deck.shuffle();
}

Game::~Game()
{}

void Game::play()
{
	std::vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; i++)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.deal(*pPlayer);
		}
		m_Deck.deal(m_House);
	}

	m_House.flipFirstCard();

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		std::cout << *pPlayer << std::endl;
	}

	std::cout << m_House << std::endl;

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.additionalCards(*pPlayer);
	}

	m_House.flipFirstCard();
	std::cout << std::endl << m_House;

	m_Deck.additionalCards(m_House);
	if (m_House.isBusted())
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->isBusted()))
			{
				pPlayer->win();
			}
		}
	}
	else
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->isBusted()))
			{
				if (pPlayer->getTotal() > m_House.getTotal())
				{
					pPlayer->win();
				}
				else if (pPlayer->getTotal() < m_House.getTotal())
				{
					pPlayer->lose();
				}
				else
				{
					pPlayer->push();
				}
			}
		}
	}

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		pPlayer->clear();
	}
	m_House.clear();
}
