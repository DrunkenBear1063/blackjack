#pragma once
#include <string>
#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
public:
	std::string m_Name;

	GenericPlayer(const std::string& name = "");
	virtual ~GenericPlayer();

	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& genericPlayer);

	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	void Bust() const;
};
