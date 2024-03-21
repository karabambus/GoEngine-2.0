#pragma once
#include <utility>
#include "Player.h"
#include "Command.h"

class MoveCommand : Command
{
public:
	//TODO: Human player must be player
	MoveCommand(HumanPlayer& _player, std::pair<int, int>& _position);
	~MoveCommand();
	bool execute(Board& board) override;
	bool undo(Board& board) override;
private:
	 std::pair<int, int> position;
	 HumanPlayer player;
};