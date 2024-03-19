#pragma once
#include "Board.h"
#include "MoveCommand.h"
#include "HumanPlayer.h"
class Game
{
public:
	Game();
	~Game();

private:
	Board board;
	HumanPlayer players[2];
};