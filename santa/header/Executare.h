
namespace Executare
{
	string path1 = "txt/";
	
	vector <Classes::Scrisoare> CitireScrisori(const vector <Classes::Scrisoare>& cop)
	{
		vector < Classes::Scrisoare> copii;
		string fisier = path1+"Scrisori.txt";
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
					Classes::Scrisoare cop(nume, prenume, oras, age, culoare);
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

	vector <Classes::Orase> CitireOrase(const vector <Classes::Orase>& orasel)
	{
		vector <Classes::Orase> orasele;
		Classes::Orase  oras;
		string fisier = path1 + "Orase.txt";
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

	vector <Classes::Drum> AflareDrum()
	{
		vector <Classes::Orase> ooo = CitireOrase(ooo);
		for (Classes::Orase o : ooo)
		{
			o.Afis(o);
			cout << endl;
		}
		Classes::Drum dr;
		vector <Classes::Drum> drumul;
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

	vector <Classes::Jucarie> CitireJucarii(const vector <Classes::Jucarie>& jucarie)
	{
		string fisier = path1 + "Cadouri.txt";
		vector <Classes::Jucarie> juc;
		Classes::Jucarie j;
		ifstream mf1(fisier);
		string line;
		int nr;
		try
		{
			if (mf1.is_open())
			{
				while (getline(mf1, line))
				{
					j.setName(line);
					mf1 >> nr;
					j.setPrice(nr);
					mf1 >> nr;
					j.setAmount(nr);
					getline(mf1, line);
					juc.push_back(j);
				}
			}
			else
			{
				throw fisier;
			}
			return juc;
		}
		catch (string fisier)
		{
			cout << "Nu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}
	}

	void CitireBasic( string* Cadou_naugthy, string* Cadou_good)
	{
		string fisier = path1 + "Basic.txt";
		ifstream mf1(fisier);
		try
		{
			if (mf1.is_open())
			{
				getline(mf1, *Cadou_good);
				getline(mf1, *Cadou_naugthy);
			}
			else
			{
				throw fisier;
			}
		}
		catch (string fisier)
		{
			cout << "\nNu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}
	}

	vector <Classes::Mosu> CitireMosu(const vector <Classes::Mosu>& cop)
	{
		vector <Classes::Mosu> lista;
		string fisier = path1 + "Mosu.txt";
		ifstream mf1(fisier);
		string nume;
		string prenume;
		int age;

		string oras;
		string line;
		int cuminte;

		try
		{
			if (mf1.is_open())
			{
				while (getline(mf1, nume))
				{
					getline(mf1, prenume);
					mf1 >> age;
					getline(mf1, line);
					getline(mf1, oras);
					getline(mf1, line);
					if (!line.compare("Naughty"))
					{
						//cout << " Naughty";
						cuminte = 0;
					}
					else
					{
						//cout << " Good";
						cuminte = 1;
					}
					Classes::Mosu cop(nume, prenume, oras, age, cuminte);
					lista.push_back(cop);

				}

			}
			else
			{
				throw fisier;
			}
			return lista;
		}
		catch (string fisier)
		{
			cout << "Nu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}
	}





	void Cerinta()
	{
		cout << "\n\tCERINTA:\n\n";
		cout << "1] Afisati scrisorile copiilor ( minim 5 copii ).\n";
		cout << "2] Sa se afiseze fiecare copil ce cadou va primi.\n";
		cout << "3] Sa se afiseze cate ambalaje pentru fete si cate ambalaje pentru baieti au folosit trolii.\n";
		cout << "4] Sa se afiseze suma totala pentru fiecare copil si suma totala folosita.\n";
		cout << "5] Sa se afiseze traseul pe care l-a urmat Mos Craciun si distanta parcursa ( minim 4 tari ).\n";
	}

	void AfisareScrisori(vector <Classes::Scrisoare> s)
	{
		int i = 1;
		for (Classes::Scrisoare c : s)
		{
			cout << " " << i++ << ". ";
			c.Afisare(c);
		}
	}

	void AfisareDrum(vector <Classes::Drum> drumul)
	{
		int total = 0;
		for (Classes::Drum dr : drumul)
		{
			cout << dr.getOras() << " - ";
			total += dr.getDist();
		}
		cout << total << " Km\n";
	}

	void AfisareJucarii(vector <Classes::Jucarie> juc)
	{
		for (Classes::Jucarie j : juc)
		{
			j.Afisare(j);
			cout << endl;
		}
	}

	void AfisareListaMosu(vector <Classes::Mosu> s)
	{
		
		for (Classes::Mosu m : s)
		{
			m.Afisare();
		}
	}

	template<class  T, class  U, typename V>
	Classes::Cadou IsEq2(T a, U b, V c)
	{

		Classes::Cadou cadoul(a.getName(), a.getSurname(), a.getCity(), a.getAge());
		string l;
		cadoul.setColour(a.getCuloare());

		for (int k = 0; k < a.getLista().size(); k++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (a.getLista().at(k).compare(b.at(j).getName()) == 0)
				{
					if (cadoul.getCost() + b.at(j).getPrice() <= c && b.at(j).getAmount() - 1 >= 0)
					{
						cadoul.addToItems(b.at(j));
						b.at(j).removeFromInventory();
						//cout << c<<" ";
					}

				}
			}
			//cout <<  " \n";
		}
		return cadoul;
	}

	template<class  T, class  U>
	int IsEq1(T a, U b)
	{
		if (a.getCity().compare(b.getCity()) == 0 && a.getName().compare(b.getName()) == 0 && a.getSurname().compare(b.getSurname()) == 0 && a.getAge() == b.getAge())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	vector<Classes::Cadou> Verificare(vector <Classes::Scrisoare> s, vector <Classes::Mosu> m, vector <Classes::Jucarie> jucarie , vector<int> *sum)
	{
		(*sum).push_back(1);
		(*sum).push_back(1);
		(*sum).push_back(1);
		(*sum).push_back(1);
		(*sum).push_back(1);
		vector<Classes::Cadou> cad;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < m.size(); j++)
			{
				if (IsEq1(s.at(i), m.at(j)))
				{
					if (m.at(j).IsCuminte())
					{
						(*sum).at(i) = 100;
						//cout << sum.at(i) << endl;
					}
					else
					{
						(*sum).at(i) = 10;
					}
					//cout << "copilul :" << m.at(i).getName() << " " << m.at(i).getSurname() << " \n";
					cad.push_back(IsEq2(s.at(i), jucarie, (*sum).at(j)));
				}
			}
		}
		for (Classes::Cadou c : cad)
		{
			c.Afisare(c);
			cout << endl;
		}
		return cad;
	}
}
