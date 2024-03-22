#include "SetStoneCommand.h"

SetStoneCommand::SetStoneCommand(std::pair<int, int> position, HumanPlayer _player)
{
}

SetStoneCommand::~SetStoneCommand()
{
}

bool SetStoneCommand::execute(Board& board)
{
	board.setStone(position, player);

	return false;
}

bool SetStoneCommand::undo(Board& board)
{
	return false;
}
