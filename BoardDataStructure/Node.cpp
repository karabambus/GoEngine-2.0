#pragma once
#include <sstream>
#include "Node.h"

Node::Node()
{
	data.whiteStones = 0x0010000100000010;
	data.blackStones = 0x0000000000000000;
	data.liberties = 0x1000010000100001;
	next = NULL;
	prev = NULL;
};

std::string Node::toString()
{
	std::stringstream ss;

	for (size_t i = 0; data.liberties; i++)
	{
		switch (i)
		{
		case 0:
			break;
		case  20:
			ss << std::endl;
			break;
		case 40:
			ss << std::endl;
			break;
		case 60:
			ss << std::endl;
			break;
		default:
			if ((data.whiteStones & 1) == 1)
				ss << "W ";
			else if((data.blackStones & 1) == 1)
				ss << "B ";
			else
				ss << "0 ";
			break;
		}
		data.liberties >>= 1;
		data.whiteStones >>= 1;
		data.blackStones >>= 1;
	}

	return ss.str();
}