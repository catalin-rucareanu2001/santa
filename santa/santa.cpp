// santa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header/IncNecesar.h"

int main()
{
	int choice;
	Executare::Cerinta();
	cout << endl << endl << "\tREZOLVARE:" << endl << endl;

	cout << "1] Scrisorile copiilor sunt:" << endl << endl;

	vector <Classes::Scrisoare> scris = Executare::CitireScrisori(scris);
	Executare::AfisareScrisori(scris);

	cout << endl << "Doriti sa vedeti inventarul elfilor?\n1]Da\n2]Nu" << endl << endl;
	cin >> choice;

	vector <Classes::Jucarie> juc = Executare::CitireJucarii(juc);

	if (choice == 1)
	{
		cout << endl << "Lista jucariilor din inventar:" << endl << endl;
		Executare::AfisareJucarii(juc);
	}

	cout << endl << "Doriti sa vedeti Lista Mosului?\n1]Da\n2]Nu" << endl << endl;
	cin >> choice;

	vector <Classes::Mosu> mos = Executare::CitireMosu(mos);

	if (choice == 1)
	{
		cout << endl << "Lista jucariilor din inventar:" << endl << endl;
		Executare::AfisareListaMosu(mos);
	}


	cout << endl << "5] Traseul pe care l-a urmat Mos Craciun este:" << endl << endl;

	vector <Classes::Drum> drumul = Executare::AflareDrum();
	Executare::AfisareDrum(drumul);

	string c_naugthy, c_good;
	Executare::CitireBasic(&c_naugthy, &c_good);
	//cout << "\nCadou pt copiii cuminti: " << c_good << "\nCadou pt copiii obraznici: " << c_naugthy<<"\n";


	




	mos.clear();
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
