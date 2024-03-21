#include "CommandHistory.h"
//TODO: 
CommandHistory& CommandHistory::getCommandHistory()
{
	static CommandHistory* commandHistory = new CommandHistory;
	return *commandHistory;
}

Board CommandHistory::getPrevBoard()
{
	for (auto it = positionHistory.begin(); it != end; it++)
	{
		board.setStone(it->first, it->second);
		board.updateBoard();
	}
	prevIterator();
}

bool CommandHistory::empty()
{
	return positionHistory.empty();
}

void CommandHistory::updateIterator()
{
	end = positionHistory.end();
}

void CommandHistory::prevIterator()
{
	end = std::prev(end);
}
