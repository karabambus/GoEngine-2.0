#include "Board.h"
#include "CurrentPlayer.h"
//TODO: optimize vectors
Board::Board()
{
}

Board::Board(int _boardSize)
{
	Library temp;
	/*temp.whiteStones = 1;
	temp.blackStones = 1;*/
	boardSize = _boardSize + 2;
	for (size_t i = 0; i < boardSize; i++)
	{
		library.push_back(temp);
	}
	clearBoard();
}

Board::~Board()
{
}

void Board::initBoard()
{
	Library temp;
	//temp.whiteStones = pow(2, boardSize);
	for (size_t i = 0; i < boardSize; i++)
	{
		library.push_back(temp);
	}
	clearBoard();
}

void Board::setSize(int _boardSize)
{
	boardSize = _boardSize;
}

void Board::clearBoard()
{
	for (auto& i : library)
	{
		i.whiteStones = 0;
		i.blackStones = 0;
		i.liberties = 0;
	}
}

void Board::updateLiberties()
{
	int temp = pow(2, boardSize + 1);
	temp = temp + 1;

	int temp2 = pow(2, boardSize + 2);
	temp2--;
	/*for (auto& i : library)
	{
		i.liberties = i.blackStones | i.whiteStones;
		i.liberties |= temp;
	}*/
	library[0].liberties = temp2;
	for (size_t i = 1; i < boardSize - 2; i++)
	{
		library[i].liberties = library[i].blackStones | library[i].whiteStones;
		library[i].liberties |= temp;
	}
	library[boardSize-1].liberties = temp2;
}

bool Board::updateBoard()
{
	updateLiberties();
	//prepare vectors
	std::vector<unsigned int> noLibertiesGroup;
	std::vector<unsigned int> libertiesGroup;
	std::vector<unsigned int> suicideCheckGroup;

	if (CurrentPlayer::getCurrentPlayer().isWhite())
		for (auto& i : library)
		{
			noLibertiesGroup.push_back(i.blackStones);
			libertiesGroup.push_back(i.blackStones);
			suicideCheckGroup.push_back(i.whiteStones);
		}
	else
		for (auto& i : library)
		{
			noLibertiesGroup.push_back(i.whiteStones);
			libertiesGroup.push_back(i.whiteStones);
			suicideCheckGroup.push_back(i.blackStones);
		}

	//fill liberties and no liberties group
	for (size_t i = 0; i < boardSize; i++)
	{
		//horizontal liberties check
		noLibertiesGroup[i] &= (library[i].liberties << 1);
		noLibertiesGroup[i] &= (library[i].liberties >> 1);
		
		//vertical librety check
		if (i < (boardSize - 1))
			noLibertiesGroup[i] &= library[i + 1].liberties;

		if (i >= 1)
			noLibertiesGroup[i] &= library[i - 1].liberties;
		
		//fill liberties group
		libertiesGroup[i] ^= noLibertiesGroup[i];
	}

	//check noLibertiesGroup horizontal
	for (size_t i = 0; i < boardSize; i++)
	{
		int temp = 0;
		while (libertiesGroup[i])
		{
			libertiesGroup[i] |= (noLibertiesGroup[i] & (libertiesGroup[i] << 1));
			libertiesGroup[i] |= (noLibertiesGroup[i] & (libertiesGroup[i] >> 1));
			
			if (temp == libertiesGroup[i])
				break;
			else 
				temp = libertiesGroup[i];
		}
	}

	//check noLibertiesGroup vertical & update library(finalCheck)
	if (CurrentPlayer::getCurrentPlayer().isWhite())
	{
		for (size_t i = 0; i < boardSize - 1; i++)
		{
			libertiesGroup[i + 1] |= noLibertiesGroup[i + 1] & libertiesGroup[i];
			libertiesGroup[i] |= noLibertiesGroup[i] & libertiesGroup[i + 1];

			library[i].blackStones = libertiesGroup[i];
		}
		library[boardSize - 1].blackStones = libertiesGroup[boardSize - 1];
	}
	else
	{
		for (size_t i = 0; i < boardSize - 1; i++)
		{
			libertiesGroup[i + 1] |= noLibertiesGroup[i + 1] & libertiesGroup[i];
			libertiesGroup[i] |= noLibertiesGroup[i] & libertiesGroup[i + 1];

			library[i].whiteStones = libertiesGroup[i];
		}
		library[boardSize - 1].whiteStones = libertiesGroup[boardSize - 1];
	}

	//KO or suicide check
	updateLiberties();
	for (size_t i = 0; i < boardSize; i++)
	{
		//horizontal liberties check
		suicideCheckGroup[i] &= library[i].liberties << 1;
		suicideCheckGroup[i] &= library[i].liberties >> 1;

		//vertical librety check
		if (i < (boardSize - 1))
			suicideCheckGroup[i] &= library[i + 1].liberties;

		if (i >= 1)
			suicideCheckGroup[i] &= library[i - 1].liberties;
	}

	//has suicide happened (if suicide both stones are in same position as before last move)
	if ((lastMove.first & suicideCheckGroup[lastMove.second]) == lastMove.first)
	{
		CurrentPlayer::getCurrentPlayer().isWhite() ? (library[lastMove.second].whiteStones ^= lastMove.first) : (library[lastMove.second].blackStones ^= lastMove.first);
		updateLiberties();
		return false;
	}
	else
	{
		return true;
	}
}

void Board::setBoard(Board &_board)
{
	library = _board.library;
	lastMove = _board.lastMove;
	boardSize = _board.boardSize;
}

void Board::setLibrary(std::vector<Library>& _library)
{
	library = _library;
}

bool Board::setStone(std::pair<int, int>& position, HumanPlayer player)
{
	if (((position.first < boardSize - 2)) && ((position.second < boardSize - 2) && (position.second >= 1)))
	{
		position.first = pow(2, position.first - 1);
		//position.second++;
		lastMove = position;
		player.isWhite() ? library[position.second].whiteStones |= (position.first << 1) : library[position.second].blackStones |= (position.first << 1);
		//lastMove.first = lastMove.first << 1;
		return true;
	}
	
	return false;
}

std::string Board::printBoard()
{
	std::stringstream ss;
	for (auto& i : library)
	{
		int whiteStonesTemp = i.whiteStones;
		int blackStonesTemp = i.blackStones;
		
		int j = 0;
		while (j < boardSize)
		{
			int binTemp = (whiteStonesTemp & 1);
			if (binTemp == 1) ss << 'w' << " ";
			else
			{
				binTemp = (blackStonesTemp & 1);
				if (binTemp == 1) ss << 'b' << " ";
				else ss << '0' << " ";
			}
			whiteStonesTemp = (whiteStonesTemp >> 1);
			blackStonesTemp = (blackStonesTemp >> 1);
			j++;
		}
		ss << std::endl;
	}
	return ss.str();
}

