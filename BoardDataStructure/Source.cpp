#include <sstream>
#include <list>
#include <iostream>

//3*19 = 57;
class Rows
{
public:
	Rows();
	~Rows();
	virtual int check() = 0;
	void updateLiberties()
	{
	   liberties = whiteStones | blackStones;
	}
	virtual std::string toString()
	{
		std::stringstream ss;

		for (size_t i = 0; liberties; liberties >>= 1, i++)
		{
			switch (i)
			{
			case 0 || 18 || 37 || 56:
				ss << std::endl;
				break;
			default:
				if (liberties == 1)
					whiteStones & 1 ? ss << "W" : ss << "B";
				else
					ss << "0";
				break;
			}
		}

		return ss.str();
	}
private:
	unsigned long long int liberties = 0x1000010000100001;
	//0x0000000000000000
	unsigned long long int whiteStones = 0;
	unsigned long long int blackStones = 0;
};


class ThreeRows : Rows
{
private:
	unsigned long long int liberties = 0x1000010000100001;
	//0x0000000000000000
	unsigned long long int whiteStones = 0;
	unsigned long long int blackStones = 0;
	ThreeRows* next;
	ThreeRows* prev;
public:
	void updateLiberties()
	{
		liberties = whiteStones | blackStones;
	}

	int check () override
	{
		int noLibertiesGroup = whiteStones;
		noLibertiesGroup &= (liberties << 1);
		noLibertiesGroup &= (liberties >> 1);
		
		noLibertiesGroup &= ((next->liberties << 36) >> 36);
		noLibertiesGroup &= (liberties << 18);
		noLibertiesGroup &= (liberties >> 18);
		noLibertiesGroup &= (prev->liberties >> 36);

		return noLibertiesGroup;
	}

	virtual std::string toString()
	{
		std::stringstream ss;

		for (size_t i = 0; liberties; liberties >>= 1, i++)
		{
			switch (i)
			{
			case 0 || 18 || 37 || 56:
				ss << std::endl;
				break;
			default:
				if (liberties == 1)
					whiteStones & 1 ? ss << "W" : ss << "B";
				else
					ss << "0";
				break;
			}
		}

		return ss.str();
	}
};

class Head
{
public:
	Head();
	~Head();

	void updateLiberties()
	{
		liberties = whiteStones | blackStones;
	}

	int check() override
	{
		int noLibertiesGroup = whiteStones;
		noLibertiesGroup &= (liberties << 1);
		noLibertiesGroup &= (liberties >> 1);

		noLibertiesGroup &= ((next->liberties << 36) >> 36);
		noLibertiesGroup &= (liberties << 18);
		noLibertiesGroup &= (liberties >> 18);
		noLibertiesGroup &= (prev->liberties >> 36);

		return noLibertiesGroup;
	}

	virtual std::string toString()
	{
		std::stringstream ss;

		for (size_t i = 0; liberties; liberties >>= 1, i++)
		{
			switch (i)
			{
			case 0 || 18 || 37 || 56:
				ss << std::endl;
				break;
			default:
				if (liberties == 1)
					whiteStones & 1 ? ss << "W" : ss << "B";
				else
					ss << "0";
				break;
			}
		}

		return ss.str();
	}

private:
	unsigned long long int liberties = 0x1000010000100001;
	//0x0000000000000000
	unsigned long long int whiteStones = 0;
	unsigned long long int blackStones = 0;
	ThreeRows* next;
};

int main()
{
	ThreeRows tr;
	return 0;
}

////////////////////
