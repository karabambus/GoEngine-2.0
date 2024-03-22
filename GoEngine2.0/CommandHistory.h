#pragma once
#include <stack>
#include <list>
#include <queue>
#include <utility>
#include "Command.h"
#include "Board.h"

class CommandHistory
{
public:
	static CommandHistory& getCommandHistory();
	Board getPrevBoard();
	bool empty();
	void addToList(std::pair<std::pair<int, int>, HumanPlayer> moveInfo);
private:
	CommandHistory();
	void prevIterator();
	void updateIterator();
	//std::list<Command> commandHistory;
	std::list<std::pair<std::pair<int, int>, HumanPlayer>> positionHistory;
	std::list<std::pair<std::pair<int, int>, HumanPlayer>>::iterator end;
	Board board;
};
