#pragma once
#include <stack>
#include <queue>
#include <utility>
#include "Command.h"

class CommandHistory
{
	std::stack<Command> commandHistory;
	std::queue<std::pair<int, int>> positionHistory;
};
