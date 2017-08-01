#pragma once

#include "Player.h"
#include "Deck.h"
#include "House.h"


class Game
{
public:
	Game(const std::vector<std::string>& names);
	~Game();
	void play();
public:
	Deck m_Deck;
	House m_House;
	std::vector<Player> m_Players;
};
