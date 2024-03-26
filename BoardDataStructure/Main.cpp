#include "Board.cpp"
#include <sstream>
#include<fstream>
#include<vector>
#include <utility>
#include <algorithm>

//test bench code
void loadLibrary(std::string& loadPath)
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

	
	for (size_t i = 0; i < vBoard.size(); i++)
	{
			ulli temp = vBoard[i].first;
			temp |= vBoard[i + 1].first << 21;
			temp |= vBoard[i + 2].first << 20;
	
	}

	while (std::getline(in, line, '|'))
	{
		isWhite ? library.whiteStones = std::strtol(line.c_str(), nullptr, 2)
			: library.blackStones = std::strtol(line.c_str(), nullptr, 2);

		if (!isWhite) library.push_back(library);

		isWhite = !isWhite;
	}
	in.close();
}

int main()
{
	//test becnch code
	Board b;
	ulli test = b.hasAllNeighbours(b.begin());
	b.displayBoard();

	
}