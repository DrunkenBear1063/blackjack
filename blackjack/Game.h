#pragma once
#include "Player.h"
#include "Deck.h"
#include "House.h"

class Game
{
public:
	Deck m_Deck;
	House m_House;
	std::vector <std::unique_ptr<Player>> m_Players;

	Game(const std::vector<std::string>& names);
	~Game();

	void Play();
};
