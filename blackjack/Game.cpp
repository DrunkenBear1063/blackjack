#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include "Game.h"

Game::Game(const std::vector<std::string>& names)
{
	for (auto name : names)
	{
		m_Players.push_back(std::make_unique<Player>(name));
	}
   
	m_Deck.Populate();
	m_Deck.Shuffle();
}

void Game::Play()
{
	if (m_Deck.m_Cards.size() <= 20)
	{
		m_Deck.Populate();
		m_Deck.Shuffle();
	}

	while (m_Deck.m_Cards.size() > 20)
	{
		for (int i = 0; i < 2; i++)
		{
			for (auto& player : m_Players)
			{
				m_Deck.Deal(*player);
			}

			m_Deck.Deal(m_House);
		}

		m_House.FlipFirstCard();

		for (auto& player : m_Players)
		{
			std::cout << *player << std::endl;
		}

		std::cout << m_House << std::endl;

		for (auto& player : m_Players)
		{
			m_Deck.AdditionalCards(*player);
		}

		m_House.FlipFirstCard();
		std::cout << std::endl << m_House;

		m_Deck.AdditionalCards(m_House);

		if (m_House.IsBusted())
		{
			for (auto& player : m_Players)
			{
				if (!(player->IsBusted()))
				{
					player->Win();
				}
			}
		}
		else
		{
			for (auto& player : m_Players)
			{
				if (!(player->IsBusted()))
				{
					if (player->GetTotal() > m_House.GetTotal())
					{
						player->Win();
					}
					else if (player->GetTotal() < m_House.GetTotal())
					{
						player->Lose();
					}
					else
					{
						player->Push();
					}
				}
			}
		}

		for (auto& player : m_Players)
		{
			player->Clear();
		}

		m_House.Clear();
	}
}

Game::~Game() {}