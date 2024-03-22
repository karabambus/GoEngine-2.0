#include "CommandHistory.h"

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
	return board;
}

bool CommandHistory::empty()
{
	return positionHistory.empty();
}

void CommandHistory::addToList(std::pair<std::pair<int, int>, HumanPlayer> moveInfo)
{
	positionHistory.push_back(moveInfo);
}

void CommandHistory::updateIterator()
{
	end = positionHistory.end();
}

CommandHistory::CommandHistory()
{
	
}

void CommandHistory::prevIterator()
{
	end = std::prev(end);
}
