#include <iostream>
#include <string>
#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name) {}

bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
	std::cout << m_Name << " busts." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& genericPlayer)
{
	os << genericPlayer.m_Name << ":\t";

	if (!genericPlayer.m_Cards.empty())
	{
		for (auto& card : genericPlayer.m_Cards)
		{
			os << card << "\t";
		}

		if (genericPlayer.GetTotal() != 0)
		{
			std::cout << "(" << genericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}

	return os;
}

GenericPlayer::~GenericPlayer() {}