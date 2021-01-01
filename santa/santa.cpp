// santa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Executare.h"

//citire din fisier
	/*
	ifstream mf1("Mosu1.txt");
	string line;
	if (mf1.is_open())
	{
		while (getline(mf1, line))
		{

			cout << line << endl;

		}
	}
	else
	{
		cout << "nu exista\n";
	}
	*/
using namespace std;


int main()
{
	vector <pornire::Drum> drumul = Executare::AflareDrum();
	int total = 0;
	for (pornire::Drum dr : drumul)
	{
		cout << dr.getOras() << " - ";
		total += dr.getDist();
	}
	cout << total << " Km\n";
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
