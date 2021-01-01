// santa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "IncNecesar.h"

int main()
{
	
	Executare::Cerinta();
	cout << endl << endl << "\tREZOLVARE:" << endl << endl;

	cout << "1] Scrisorile copiilor sunt:" << endl << endl;

	vector <Classes::Scrisoare> scris = Executare::CitireScrisori(scris);
	Executare::AfisareScrisori(scris);

	cout << endl << "Lista jucariilor din inventar:" << endl << endl;

	vector <Classes::Jucarie> juc = Executare::CitireJucarii(juc);
	Executare::AfisareJucarii(juc);

	cout << endl << "5] Traseul pe care l-a urmat Mos Craciun este:" << endl << endl;

	vector <Classes::Drum> drumul = Executare::AflareDrum();
	Executare::AfisareDrum(drumul);

	




	juc.clear();
	scris.clear();
	drumul.clear();
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
