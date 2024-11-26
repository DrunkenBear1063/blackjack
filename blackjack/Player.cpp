#include <string>
#include <iostream>
#include "Player.h"

Player::Player(const std::string& name) : GenericPlayer(name) {}

bool Player::IsHitting() const
{
	std::cout << m_Name << " . Do you want a hit? (Y/N): ";
	char responce;
	std::cin >> responce;
	return (responce == 'y' || responce == 'Y');
}

void Player::Win() const
{
	std::cout << m_Name << " wines." << std::endl;
}

void Player::Lose() const
{
	std::cout << m_Name << " loses.\n" << std::endl;
}

void Player::Push() const
{
	std::cout << m_Name << " pushes.\n" << std::endl;
}

Player::~Player() {}
