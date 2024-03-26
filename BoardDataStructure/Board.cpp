#include <sstream>
#include <iostream>

#define ulli unsigned long long int 

struct RowLibrary
{
    ulli whiteStones = 0;
    ulli blackStones = 0;
    ulli liberties = 0x1000010000100001;
};

class Node {
public:
    RowLibrary data;
    Node* next;
    Node* prev;

	Node()
	{
		data.whiteStones = 0;
		data.blackStones = 0;
		data.liberties = 0x1000010000100001;
		next = NULL;
		prev = NULL;
	};

	std::string toString()
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
				if ((data.liberties & 1) == 1)
					data.whiteStones & 1 ? ss << "W " : ss << "B ";
				else
					ss << "0 ";
				break;
			}
			data.liberties >>= 1;
		}

		return ss.str();
	}
};

class Board
{
public:
	Board();
	~Board();
	void insertFront(RowLibrary new_data);
	void displayBoard();
	ulli hasAllNeighbours(Node* node);
	Node* begin();
private:
	Node* head;
	Node* tail;
};

Board::Board()
{
	RowLibrary row;

	for (size_t i = 0; i < 6; i++) 
		insertFront(row);
	//insert last one
	row.liberties = 0x100001; 
	insertFront(row);
}

Board::~Board()
{
	while (tail != NULL)
	{
		
	}
}


void Board::insertFront(RowLibrary new_data)
{
	//allocate memory for New node
	Node* newNode = new Node;

	//assign data to new node
	newNode->data = new_data;

	//new node is head and previous is null, since we are adding at the front
	newNode->next = head;
	newNode->prev = NULL;

	//previous of head is new node
	if (head != NULL)
		head->prev = newNode;

	//head points to new node
	head = newNode;
}

// This function prints contents of linked list
void Board:: displayBoard() {
	Node* last;
	last = head;
	while (last != NULL) {
		std::cout << last->toString();
		last = last->next;
	}
}

//returns stones that have all 4 neighbouring intersections occupied (by: white stones, black stones or border)
ulli Board::hasAllNeighbours(Node* node)
{
	/*got to fix the*/

	//horizontal check
	ulli modifiedRow = node->data.whiteStones;
	modifiedRow &= (node->data.liberties << 1);
	modifiedRow &= (node->data.liberties >> 1);

	//vertical check
	//0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001
	//														 0000 0000 0000 0000 0001
	if (node->next != NULL)
		modifiedRow &= ((node->next->data.liberties << 43) >> 43);
	//0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001
	//0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001
	modifiedRow &= (node->data.liberties << 20);
	//0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001
	//                         0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001 						   						   	  				   
	modifiedRow &= (node->data.liberties >> 20);
	//0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001 0000 0000 0000 0000 0001
	//0000 0000 0000 0000 0001
	if (node->prev != NULL)
		modifiedRow &= (node->prev->data.liberties >> 40);

	return modifiedRow;
}

Node* Board::begin()
{
	return head;
}

