#include <iostream>
#include "dgraph.h"

using namespace std;

int main()
{
	dgraph myG;		//0.Declare table object

	myG.fillTable();//1.fillTable()
	myG.displayGraph();//2.displayGraph()
	char x = ' ';
	int tmp;
	cout << "Enter a vertex name or character Z to exit: ";
	cin >> x;							//a.the user will specify which vertex
	while (x != 'Z')//while (the user does not want to stop)
	{
		try
		{
			tmp = myG.findOutDegree(x);		//b.findOutDegree of the vertex and display the result
			cout << tmp << " edges go out to" << endl;
			slist myL;
			myL = myG.findAdjacency(x);			//b.findAdjacency of the vertex and display the result(see Hint)
			myL.displayAll();
		}
		catch (dgraph::BadVertex)//c.catch exception to display error mesg but do not exit
		{
			cout << "No such vertex exists" << endl;
		}
		cout << "Enter a vertex name or character Z to exit: ";
		cin >> x;								//a.the user will specify which vertex
	}
}

/*
Hint:
slist l1;
l1 = G.findAdjacency('a');
// how do you display l1?  Hint: it is an slist from HW6.

*/
