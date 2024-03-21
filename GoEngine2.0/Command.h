#pragma once
#include "Board.h"
#include "Player.h"

class Command
{
public:
	Command() {};
	virtual bool execute(Board& _board) = 0;
	virtual bool undo(Board& board) = 0;
protected:
	
};
