#pragma once
#include <string>
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House();

	bool IsHitting() const override;
	void FlipFirstCard();
};