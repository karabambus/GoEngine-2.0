#include "MoveCommand.h"
#include "Board.h"
#include "Command.h"
#include "CommandHistory.h"
#include <iostream>

MoveCommand::MoveCommand(HumanPlayer& _player, std::pair<int, int>& _position)
{
    position = _position;
    player = _player; 
}

MoveCommand::~MoveCommand()
{
}

bool MoveCommand::execute(Board &board)
{
    std::cout << board.setStone(position, player) << std::endl;
    CommandHistory::getCommandHistory().addToList({ position, player });
    return board.updateBoard();
}

bool MoveCommand::undo(Board& board)
{
    board = CommandHistory::getCommandHistory().getPrevBoard();


    return false;
}




