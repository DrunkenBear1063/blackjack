#pragma once

#include "GenericPlayer.h"
#include <string>

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House();
	virtual bool isHitting() const;
	void flipFirstCard();
};