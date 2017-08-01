#include "stdafx.h"
#include "GenericPlayer.h"
#include <iostream>
#include <string>

GenericPlayer::GenericPlayer(const std::string& name) : m_Name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::isBusted() const
{
	return (getTotal() > 21);
}

void GenericPlayer::bust() const
{
	std::cout << m_Name << " busts.\n";
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.m_Name << ":\t";
	std::vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty())
	{
		for (pCard = aGenericPlayer.m_Cards.begin(); pCard != aGenericPlayer.m_Cards.end(); ++pCard)
		{
			os << *(*pCard) << "\t";
		}
		if (aGenericPlayer.getTotal() != 0)
		{
			std::cout << "(" << aGenericPlayer.getTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}
	return os;
}


