#pragma once
#include "Library.h"
#include <fstream>
#include <vector>
class LibraryLoader
{
public:
	LibraryLoader(std::string& _path);
	~LibraryLoader();
	void parseLibrary(Library& library, std::string& line, bool isWhite);
	std::vector<Library> getBoardLibrary();

private:
	//unsigned int boardSize;
	std::vector<Library> boardLibrary;
	std::string path;
};
