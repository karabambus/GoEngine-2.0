#include "LibraryLoader.h"
#include <sstream>
#include <iostream>
#include <charconv>

LibraryLoader::LibraryLoader(std::string& _path)
{
	std::ifstream in(_path);
	std::string line;
	bool isWhite = true;
	Library library;

	if (!in)
	{
		std::cerr << "error" << std::endl;
	}

	int i = 0;
	while (std::getline(in, line))
	{
		
		if (i == 13)
		{
			isWhite = !isWhite;
		}
		else
		{
			parseLibrary(library, line, isWhite);
			boardLibrary.push_back(library);
		}
		i++;
	}
	in.close();
}

LibraryLoader::~LibraryLoader()
{
}
//not working
void LibraryLoader::parseLibrary(Library& library, std::string& line, bool isWhite)
{
	//std::stringstream ss(line);
	std::string temp;
	isWhite ? library.whiteStones = std::from_chars(temp, nullptr, 2) : library.blackStones = std::from_chars(temp, nullptr, 2);
}

std::vector<Library> LibraryLoader::getBoardLibrary()
{
	return boardLibrary;
}
