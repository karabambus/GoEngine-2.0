#include "HumanPlayer.h"

HumanPlayer::HumanPlayer()
{
	whiteStone = true;
}

bool HumanPlayer::isWhite()
{
	return whiteStone;
}

bool HumanPlayer::isHuman()
{
	return true;
}

void HumanPlayer::changeColor()
{
	whiteStone = !whiteStone;
}

HumanPlayer::~HumanPlayer()
{
}
