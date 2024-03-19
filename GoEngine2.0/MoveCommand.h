#pragma once
#include <utility>
#include "Player.h"
#include "Command.h"

class MoveCommand : Command
{
public:

	MoveCommand(HumanPlayer& _player, std::pair<int, int>& _position);
	~MoveCommand();
	bool execute(Board& board) override;
	bool undo() override;
private:
	 std::pair<int, int> position;
	 HumanPlayer player;
};