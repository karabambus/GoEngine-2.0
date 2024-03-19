#pragma once
class Player
{
public:
	virtual bool isWhite() = 0;
	virtual bool isHuman() = 0;
	virtual void changeColor() = 0;

private:
	bool whiteStone;
};

