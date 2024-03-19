#pragma once
#include "Player.h"
class HumanPlayer : Player
{
public:
	HumanPlayer();
	bool isWhite();
	bool isHuman();
	void changeColor();
	~HumanPlayer();

private:
	bool whiteStone;
};