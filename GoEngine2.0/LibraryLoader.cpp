#include "LibraryManager.h"
#include <sstream>
#include <iostream>
#include <charconv>
#include <bitset>

void LibraryManager::loadLibrary(std::string& _path)
{
	//load
	std::ifstream in(_path);
	std::string line;
	bool isWhite = true;
	Library library;
	
	if (!in)
	{
		std::cerr << "error" << std::endl;
	}
	//parser
	while (std::getline(in, line, '|'))
	{
		isWhite ? library.whiteStones = std::strtol(line.c_str(), nullptr, 2) 
				: library.blackStones = std::strtol(line.c_str(), nullptr, 2);
		
		if (!isWhite) boardLibrary.push_back(library);
		
		isWhite = !isWhite;
	}
	in.close();
}

void LibraryManager::saveLibrary(std::vector<Library>& _boardLibrary)
{
	std::ofstream out(path);
	const int size = _boardLibrary.size();
	int temp;
	for (auto& i : _boardLibrary)
	{
		temp = i.whiteStones;
		for (size_t j = 0; j < size; j++)
		{
			if ((temp & 1) == 0)
			{
				out << '0';
			}
			else
			{
				out << '1';
			}
			temp = temp >> 1;
		}
		temp = i.blackStones;
		out << '|';
		for (size_t j = 0; j < size; j++)
		{
			if ((temp & 1) == 0)
			{
				out << '0';
			}
			else
			{
				out << '1';
			}
			temp = temp >> 1;
		}
		out << '|' << std::endl;
	}
}

LibraryManager::~LibraryManager()
{
}

std::vector<Library> LibraryManager::getBoardLibrary()
{
	return boardLibrary;
}
