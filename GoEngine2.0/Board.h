#pragma once
#include "HumanPlayer.h"
#include "Library.h"
#include <vector>
#include <sstream>
class Board
{
public:
	Board();
	Board(int _boardSize);
	~Board();
	void clearBoard();
	bool updateBoard();
	void updateLiberties();
	void initBoard();
	void setSize(int _boardSize);
	void setBoard(Board &_board);
	void setLibrary(std::vector<Library>& _library);
	bool setStone(std::pair<int, int>& position, HumanPlayer player);
	std::string printBoard();
private:
	std::vector<Library> library;
	short int boardSize;
	std::pair<int, int> lastMove;
};