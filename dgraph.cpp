#include <iostream>
#include <fstream>
#include "dgraph.h"

using namespace std;

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
	Gtable->vertexName = ' ';
	Gtable->visit = 0;
	countUsed = 0;
}
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
					// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
	el_t x;
	int i = 0;
	while (i < countUsed)
	{
		for (int b = 0; b < Gtable[countUsed].outDegree; b++)
		{
			Gtable[countUsed].adjacentOnes.deleteFront(x);
		}
		i++;
		Gtable[countUsed].outDegree = 0;
		Gtable[countUsed].vertexName = ' ';
	}
	cout << "DELETED" << endl;
}
void dgraph::fillTable()  // make sure to read from table.txt file
{
	string fname = "table.txt";
	ifstream fin(fname.c_str(), ios::in); // declare and open

	el_t x;

	while (fin >> Gtable[countUsed].vertexName) //If could read name 
	{											//Now read the next item, which is the outDegree.     
		fin >> Gtable[countUsed].outDegree;
		Gtable[countUsed].visit = 0;
		for (int a = 0; a < Gtable[countUsed].outDegree; a++)
		{
			fin >> x;										 // Read an adjacent vertex name, add to list         
			Gtable[countUsed].adjacentOnes.addRear(x);       // addRear is an slist function from slist class   
		}
		countUsed++;
	}
	fin.close();
}
void dgraph::displayGraph() // make sure to display	
							// in a really nice format -- all columns
{
	for (int i = 0; i < countUsed; i++)
	{
		cout << Gtable[i].vertexName << " ";			//display the vertex name
		cout << Gtable[i].outDegree << " ";				//display the outDegree
		cout << Gtable[i].visit << " ";					//display the visit number
		if (Gtable[i].outDegree == 0)					//check if the slist is empty or not
			cout << " [ empty ]" << endl;				//if empty display empty
		else
			Gtable[i].adjacentOnes.displayAll();		//if not empty, display list
	}
}
int dgraph::findOutDegree(char V)// throws exception
								 // does not use a loop
{
	int tmp;			//holds index of char V
	tmp = V - 65;		//get index
	if (tmp < countUsed)//check if index is less than slots in countUsed
		return Gtable[tmp].outDegree;	//return outdegree of V
	else
		throw BadVertex();//throw exception
}
slist dgraph::findAdjacency(char V)	// throws exception
									// does not use a loop
{
	slist tmp;			//holds slist to return
	int tmp2;			//holds index of V
	tmp2 = V - 65;		//get index
	if (tmp2 < countUsed)//check if index is greater than countUsed
	{
		tmp = Gtable[tmp2].adjacentOnes;//tmp equals adjacentones
		return tmp;
	}
	else
		throw BadVertex();//throw exception if true
	//return tmp;//return tmp
}