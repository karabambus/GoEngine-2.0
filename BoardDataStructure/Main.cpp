#pragma once
#include "Board.h"
#include<vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

//test bench code
void loadLibrary(Board &newBoard, std::string loadPath)
{
	//load
	std::ifstream in(loadPath);
	std::string line;
	bool isWhite = true;
	std::vector<std::pair<int, int>> vBoard;

	if (!in)
	{
		std::cerr << "error" << std::endl;
	}

	//parser
	while (std::getline(in, line, '|'))
	{
		int tempW;
		int tempB;
		isWhite ? tempW = std::strtol(line.c_str(), nullptr, 2)
			: tempB = std::strtol(line.c_str(), nullptr, 2);

		if (!isWhite) vBoard.push_back({tempW, tempB});

		isWhite = !isWhite;
	}

	
	for (size_t i = 0; i < vBoard.size() - 3; i += 3)
	{
			RowLibrary row;

			ulli tempW = vBoard[i].first;
			tempW <<= 21;
			tempW |= vBoard[i + 1].first;
			tempW <<= 20;
			tempW |= vBoard[i + 2].first;

			ulli tempB = vBoard[i].second;
			tempB <<= 21;
			tempB |= vBoard[i + 1].second;
			tempB <<= 20;
			tempB |= vBoard[i + 2].second;

			row.whiteStones = tempW;
			row.blackStones = tempB;
			
			newBoard.insertFront(row);
	}
}

int main()
{
	//test becnch code
	Board b;

	loadLibrary(b, "testboard2.txt");
	b.updateLiberties();
	b.displayBoard();

	
}