#pragma once
#include "Node.h"
#include "RowLibrary.h" 

class Board
{
public:
	Board();
	~Board();
	void insertFront(RowLibrary new_data);
	void displayBoard();
	void updateLiberties();
	ulli hasAllNeighbours(Node* node);
	Node* begin();
private:
	Node* head;
	Node* tail;
};