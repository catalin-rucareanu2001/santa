
#include "pornire.h"

namespace Executare
{
	vector <pornire::Scrisoare> CitireScrisori(const vector <pornire::Scrisoare>& cop)
	{
		vector < pornire::Scrisoare> copii;
		string fisier = "Scrisori.txt";
		ifstream mf1(fisier);
		string nume;
		string prenume;
		int age;
		string culoare;
		string oras;
		string line;
		vector <string> list;
		try
		{
			if (mf1.is_open())
			{
				while (getline(mf1, nume))
				{
					getline(mf1, prenume);
					mf1 >> age;
					getline(mf1, line);
					getline(mf1, culoare);
					getline(mf1, oras);
					getline(mf1, line);
					while (line != ".")
					{
						list.push_back(line);
						getline(mf1, line);
					}
					pornire::Scrisoare cop(nume, prenume, oras, age, culoare);
					cop.setCuloare(culoare);
					cop.setLista(list);
					list.clear();
					copii.push_back(cop);
				}
				return copii;
			}
			else
			{
				throw fisier;
			}
		}
		catch (string fisier)
		{
			cout << "Nu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}

	}

	vector <pornire::Orase> CitireOrase(const vector <pornire::Orase>& orasel)
	{
		vector <pornire::Orase> orasele;
		pornire::Orase  oras;
		string fisier = "Orase.txt";
		ifstream mf1(fisier);
		string name;
		int d;
		vector <int> di;
		try
		{
			if (mf1.is_open())
			{
				while (getline(mf1, name))
				{

					oras.setNume(name);
					for (int i = 0; i < 6; i++)
					{
						mf1 >> d;
						di.push_back(d);
					}
					oras.setDist(di);
					di.clear();
					oras.setVisited(0);
					getline(mf1, name);
					orasele.push_back(oras);

				}
				return orasele;
			}
			else
			{
				throw fisier;
			}
		}
		catch (string fisier)
		{
			cout << "Nu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}

	}

	vector <pornire::Drum> AflareDrum()
	{
		vector <pornire::Orase> ooo = CitireOrase(ooo);
		for (pornire::Orase o : ooo)
		{
			o.Afis(o);
			cout << endl;
		}
		pornire::Drum dr;
		vector <pornire::Drum> drumul;
		int min, pozm, poz;
		min = ooo.at(0).getDist(0);
		for (int i = 1; i < ooo.size(); i++)
		{
			if (min > ooo.at(i).getDist(0))
			{
				min = ooo.at(i).getDist(0);
				pozm = i;
			}
		}
		dr.SetOras("Rovaniemi");
		dr.SetDist(0);
		drumul.push_back(dr);
		dr.SetOras(ooo.at(pozm).getNume());
		dr.SetDist(ooo.at(pozm).getDist(0));
		ooo.at(pozm).setVisited(1);
		drumul.push_back(dr);
		int vis = 1;
		cout << endl;
		while (vis < ooo.size())
		{
			poz = pozm;
			if (ooo.at(poz).getDist(1) != 0)
			{
				min = ooo.at(poz).getDist(1);
			}
			else {
				min = ooo.at(poz).getDist(2);
			}
			for (int i = 0; i < 5; i++)
			{
				if (ooo.at(poz).getDist(i + 1) != 0)
				{
					if (!ooo.at(i).getVisited())
					{
						if (ooo.at(poz).getDist(i + 1) <= min)
						{
							min = ooo.at(poz).getDist(i + 1);
							pozm = i;
							ooo.at(poz).setVisited(1);
						}
					}
				}
			}
			dr.SetOras(ooo.at(pozm).getNume());
			dr.SetDist(ooo.at(poz).getDist(pozm + 1));
			drumul.push_back(dr);
			vis++;
		}
		return drumul;
	}
}
