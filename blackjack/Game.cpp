#include "stdafx.h"
#include "Game.h"
#include <ctime>
#include <vector>
#include <string>
#include <iostream>


Game::Game(const std::vector<std::string>& names)
{
  for (auto name : names)
  {
    m_Players.push_back(Player{ name });
  }
   
	m_Deck.populate();
	m_Deck.shuffle();
}

Game::~Game()
{}

void Game::play()
{
	for (int i = 0; i < 2; i++)
	{
		for (auto& player : m_Players)
		{
			m_Deck.deal(player);
		}
		m_Deck.deal(m_House);
	}

	m_House.flipFirstCard();

	for (auto& player : m_Players)
	{
		std::cout << player << std::endl;
	}

	std::cout << m_House << std::endl;

	for (auto& player : m_Players)
	{
		m_Deck.additionalCards(player);
	}

	m_House.flipFirstCard();
	std::cout << std::endl << m_House;

	m_Deck.additionalCards(m_House);
	if (m_House.isBusted())
	{
		for (auto& player : m_Players)
		{
			if (!(player.isBusted()))
			{
        player.win();
			}
		}
	}
	else
	{
		for (auto& player : m_Players)
		{
			if (!(player.isBusted()))
			{
				if (player.getTotal() > m_House.getTotal())
				{
          player.win();
				}
				else if (player.getTotal() < m_House.getTotal())
				{
          player.lose();
				}
				else
				{
          player.push();
				}
			}
		}
	}

	for (auto& player : m_Players)
	{
    player.clear();
	}
	m_House.clear();
}
