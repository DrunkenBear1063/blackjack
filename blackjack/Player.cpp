#include "stdafx.h"
#include "Player.h"
#include <string>
#include <iostream>

Player::Player(const std::string& name) : GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
	std::cout << m_Name << " . Do you want a hit? (Y/N): ";
	char responce;
	std::cin >> responce;
	return (responce == 'y' || responce == 'Y');
}

void Player::win() const
{
	std::cout << m_Name << " wines.\n";
}

void Player::lose() const
{
	std::cout << m_Name << " loses.\n";
}

void Player::push() const
{
	std::cout << m_Name << " pushes.\n";
}
