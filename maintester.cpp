/*
main test
*/


#include "Board.h"


int main()
{

	Board gameTree(20);
	//bool success = false;
	//success = gameTree.insert(2,3,4);
	//success = gameTree.insert(1, 5, 7);
	//success = gameTree.insert(3, 6, 8);
	//success = gameTree.insert(5, 7, 2);
	//success = gameTree.insert(4, 4, 4);


	//gameTree.printbyID();
 //   success = gameTree.insert(4, 5, 7);
	////gameTree.remove(2);
	//gameTree.printbyID();
	//success = gameTree.find(1);
	////cout << "found value: " << success << endl;

	////testing move to 
	//gameTree.moveTo(5, 7, 6);
	//gameTree.printbyID();


	gameTree.insert(1, 3, 2);	// assumed syntax: Insert(ID, x, y)
	gameTree.insert(2, 4, 3);
	gameTree.insert(3, 4, 6);
	gameTree.insert(4, 5, 7);
	gameTree.insert(5, 6, 3);
	gameTree.insert(6, 8, 2);
	gameTree.insert(7, 9, 3);
	gameTree.insert(8, 9, 8);

	gameTree.printbyID();

	gameTree.insert(3, 7, 6);	// should fail because player 3 is already there

	gameTree.insert(10, 9, 8);	// should fail because 9,8 is occupied already

	gameTree.moveTo(4, 9, 3);	//assumed syntax: MoveTo(ID,x,y) // removes 7 in the process
	cout << "\nPlayer 7 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 9, 8);	// removes 8
	cout << "\nPlayer 8 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 6, 3); // should fail because move to 6,3 is from 4's current position is not valid
	gameTree.printbyID();

	gameTree.moveTo(2, 3, 3);
	cout << "\nPlayer 2 moved to 3,3" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 3, 2);	// removes 1
	cout << "\nPlayer 1 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 8, 2);	// removes 6
	cout << "\nPlayer 6 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(5, 3, 3);	// removes 2
	cout << "\nPlayer 2 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 4, 6);	// removes 3
	cout << "\nPlayer 3 should be removed" << endl;
	gameTree.printbyID();

	gameTree.moveTo(5, 4, 3);
	cout << "\nCheck behavior" << endl;
	gameTree.printbyID();

	gameTree.moveTo(4, 4, 3);	// removes 5
	//cout << "\n" << endl;
	gameTree.printbyID();



	return 0;
}
