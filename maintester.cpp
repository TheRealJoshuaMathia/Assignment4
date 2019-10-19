/*
main test
*/


#include "Board.h"


int main()
{

	Board gameTree(10);
	bool success = false;
	success = gameTree.insert(2,3,4);
	success = gameTree.insert(1, 5, 7);
	success = gameTree.insert(3, 6, 8);
	success = gameTree.insert(5, 7, 2);
	success = gameTree.insert(4, 4, 4);


	gameTree.printbyID();
    success = gameTree.insert(4, 5, 7);
	//gameTree.remove(2);
	gameTree.printbyID();
	success = gameTree.find(1);
	//cout << "found value: " << success << endl;




	return 0; 
}
