#pragma once
#include "RowLibrary.h"
#include <sstream>
class Node {
public:
	RowLibrary data;
	Node* next;
	Node* prev;

	std::string toString();
	Node();
};