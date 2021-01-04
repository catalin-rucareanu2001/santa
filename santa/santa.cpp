// santa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header/IncNecesar.h"

int main()
{
	int choice;
	Executare::Cerinta();
	cout << endl << endl << "\tREZOLVARE:" << endl << endl;
	/// <summary>
	/// ex 1
	/// </summary>
	/// <returns></returns>
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
		cout << endl << "Lista Mosului:" << endl << endl;
		cout << "Good = 1\nNaughty = 0\n";
		Executare::AfisareListaMosu(mos);
	}
	
	string c_naugthy, c_good;
	Executare::CitireBasic(&c_naugthy, &c_good);

	cout << endl << "Doriti sa vedeti cadourile default?\n1]Da\n2]Nu" << endl << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "\nCadou pt copiii cuminti: " << c_good << "\nCadou pt copiii obraznici: " << c_naugthy << "\n";
	}
	/// <summary>
	/// ex 2
	/// </summary>
	/// <returns></returns>
	cout << "\n2] Cadourile primite de copii sunt:" << endl << endl;

	vector<int> sum, poz;
	vector<Classes::Cadou> cad;
	cad = Executare::Verificare(scris, mos, juc, &sum);

	for (int i=0;i<cad.size();i++)
	{
		if (cad.at(i).ItemSize()==0)
		{
			for (int j = 0; j < juc.size(); j++)
			{
				if (mos.at(i).IsCuminte())
				{
					if (juc.at(j).getName().compare(c_good)==0)
					{
						cad.at(i).addToItems(juc.at(j));
					}
				}
				else
				{
					if (juc.at(j).getName().compare(c_naugthy) == 0)
					{
						cad.at(i).addToItems(juc.at(j));
						poz.push_back(i);
					}
				}
			}
			
		}
		cad.at(i).Afisare(cad.at(i));
		for (int l:poz)
		{
			if (i == l)
			{
				cout << "+1 Carbune\n";
			}
		}
		cout << endl;
	}

	Workers::Elf elful;
	vector <int> acadele = elful.Acadele(cad, sum);
	for (int i = 0; i < acadele.size(); i++)
	{
		cout << acadele.at(i) << " acadele primeste: "<<scris.at(i).getName()<<" "<< scris.at(i).getSurname()<<"\n";
	}
	elful.setSuma();
	/// <summary>
	/// ex 3
	/// </summary>
	/// <returns></returns>
	cout << "\n3] Numarul de ambalaje fete/baieti + nr carbuni sunt: \n";
	Workers::Troll  trolul;

	for (int i = 0; i < scris.size(); i++)
	{
		trolul.Ambalare(scris.at(i));
		trolul.Carbune(mos.at(i));
	}
	cout << endl;
	trolul.AfisAmbaleje();
	trolul.setSum();
	cout << "Nr carbuni folositi: " << trolul.getCarbune() << endl;
	/// <summary>
	/// ex 4
	/// </summary>
	/// <returns></returns>
	cout << "\n4] Suma extra folosita de Doamna Craciun: \n";
	Workers::MissSanta msSanta;
	msSanta.setAcad(elful.getAcadele());
	msSanta.setCarb(trolul.getCarbune());
	msSanta.setSuma(elful, trolul);

	cout<<"\nDoamna Craciun produce : "<<msSanta.getAcad()<<" acadele si : "<< msSanta.getCarb()<<" carbuni\n";
	cout << "Suma extra este: " << msSanta.getSum()<<" $\n";
	/// <summary>
	/// ex 5
	/// </summary>
	/// <returns></returns>
	cout << endl << "5] Traseul pe care l-a urmat Mos Craciun este:" << endl << endl;

	vector <Classes::Drum> drumul = Executare::AflareDrum();
	Executare::AfisareDrum(drumul);

	

	
	
	
	
	acadele.clear();
	poz.clear();
	cad.clear();
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
