#pragma once
#include "Player.h"
class CurrentPlayer
{
public:
	static CurrentPlayer& getCurrentPlayer();
	void setTracker(bool _tracker);
	void flipTracker();
	bool isWhite();
private:
	CurrentPlayer();
	bool tracker;
};