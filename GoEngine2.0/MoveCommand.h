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
	bool undo(Board& board) override;
	bool undoByPosition(std::pair<int, int>& position) override;
private:
	 std::pair<int, int> position;
	 HumanPlayer player;
};