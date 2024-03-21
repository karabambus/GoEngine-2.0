#pragma once
#include "Command.h"
class SetStoneCommand : Command
{
public:
	SetStoneCommand(std::pair<int, int> _position, HumanPlayer _player);
	~SetStoneCommand();
	bool execute(Board& board) override;
	bool undo(Board& board) override;
private:
	std::pair<int, int> position;
	HumanPlayer player;
};