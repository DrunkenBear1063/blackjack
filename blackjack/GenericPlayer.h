#pragma once

#include "Hand.h"
#include <string>
#include <iostream>

class GenericPlayer : public Hand
{
	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const std::string& name = "");
	virtual ~GenericPlayer();
	virtual bool isHitting() const = 0;
	bool isBusted() const;
	void bust() const;
public:
	std::string m_Name;
};
