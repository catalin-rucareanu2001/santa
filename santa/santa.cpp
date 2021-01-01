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
	//using namespace std;


void Cerinta()
{
	cout << "\n\tCERINTA:\n\n";
	cout << "1] Afisati scrisorile a minim 5 copii.\n";
	cout << "2] Sa se afiseze fiecare copil ce cadou va primi.\n";
	cout << "3] Sa se afiseze cate ambalaje pentru fete si cate ambalaje pentru baieti au folosit trolii.\n";
	cout << "4] Sa se afiseze suma totala pentru fiecare copil si suma totala folosita.\n";
	cout << "5] Sa se afiseze traseul pe care l-a urmat Mos Craciun si distanta parcursa.\n";
}
void AfisareScrisori(vector <pornire::Scrisoare> s)
{
	int i = 1;
	for (pornire::Scrisoare c : s)
	{
		cout << " " << i++ << ". ";
		c.Afisare(c);
	}
}

void AfisareDrum(vector <pornire::Drum> drumul)
{
	int total = 0;
	for (pornire::Drum dr : drumul)
	{
		cout << dr.getOras() << " - ";
		total += dr.getDist();
	}
	cout << total << " Km\n";
}
int main()
{
	vector <pornire::Scrisoare> scris = Executare::CitireScrisori(scris);
	Cerinta();
	cout << endl << endl << "\tREZOLVARE:" << endl << endl;
	cout << "1] Scrisorile copiilor sunt:" << endl << endl;

	AfisareScrisori(scris);

	cout << endl << "5] Traseul pe care l-a urmat Mos Craciun este:" << endl << endl;
	vector <pornire::Drum> drumul = Executare::AflareDrum();

	AfisareDrum(drumul);

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
