#include "CurrentPlayer.h"
#include "Game.h"
#include "Board.h"
#include "MoveCommand.h"
#include "LibraryManager.h"
#include <iostream>
int main()
{
	Board board(13);
	HumanPlayer player;
	HumanPlayer player2;
	player2.changeColor();
	std::string path = "testBoard.txt";
	LibraryManager lm;
	lm.loadLibrary(path);
	std::vector<Library> l = lm.getBoardLibrary();
	/*for (auto& i : l)
	{
		std::cout << i.blackStones << std::endl;
	}*/
	board.setLibrary(l);
	board.updateLiberties();
	board.updateBoard();
	/*for (size_t i = 0; i < ll.getBoardLibrary().size(); i++)
	{
		std::cout << l[i].blackStones << std::endl;
	}*/

	std::cout << board.printBoard() << std::endl;

	
	
	/*while (true)
	{
		int row;
		std::cout << "Enter column: ";
		std::cin >> row;
		std::cin.ignore();

		int column;
		std::cout << "Enter row: ";
		std::cin >> column;
		std::cin.ignore();
		std::pair<int, int> position{ column, row };
		
		MoveCommand move(player, position);
		move.execute(board);
		std::cout << board.printBoard() << std::endl;
		CurrentPlayer::getCurrentPlayer().flipTracker();
		
		int row2;
		std::cout << "Enter column: ";
		std::cin >> row2;
		std::cin.ignore();
		int column2;
		std::cout << "Enter row: ";
		std::cin >> column2;
		std::cin.ignore();
		std::pair<int, int> position2 = { column2, row2 };

		MoveCommand moveP2(player2, position2);
		moveP2.execute(board);
		std::cout << board.printBoard() << std::endl;
		CurrentPlayer::getCurrentPlayer().flipTracker();
	}*/


}