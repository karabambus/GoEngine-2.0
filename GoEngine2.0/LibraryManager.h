#pragma once
#include "Library.h"
#include <fstream>
#include <vector>
class LibraryManager
{
public:
	void loadLibrary(std::string& _path);
	void saveLibrary(std::vector<Library>& _boardLibrary);
	~LibraryManager();
	std::vector<Library> getBoardLibrary();

private:
	//unsigned int boardSize;
	std::vector<Library> boardLibrary;
	std::string path;
};
