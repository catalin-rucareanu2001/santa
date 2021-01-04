
/// <summary>
/// aici se afla toate functiile din afara int main
/// </summary>
/// 
namespace Executare
{

	string path1 = "txt/";

	/// <summary>
	/// citirea scrisorilor
	/// </summary>
	/// <param name="cop"></param>
	/// <returns> vector <Classes::Scrisoare> copii </returns>
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

				/// <summary>
				/// deoarece in fisierul scrisori.txt se afla valorile introduse sub forma:
				/// nume
				/// prenume
				/// varsta
				/// culoare
				/// oras 
				/// lista cadouri
				/// .
				/// vom citi astfel incat sa atribuim fiecarei valori tipul potrivit de variabila
				/// getline(mf1, nume) citeste o linie pana la endl
				/// citirea cu: mf1 >> age; il pierde pe endl si aceesta v trebui citit intr-o variabila noua
				/// </summary>
				/// <param name="cop"></param>
				/// <returns> vector <Classes::Scrisoare> copii </returns>
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

				/// <summary>
				/// in cazul in care fisierul cu numele indicat nu exista se va arunca o eroare(folosim try,throw,catch) 
				/// </summary>
				/// <param name="cop"></param>
				/// <returns></returns>
				throw fisier;
			}
		}
		catch (string fisier)
		{
			cout << "Nu exista fisierul cu denumirea " << fisier << endl;
			exit(404);
		}

	}

	/// <summary>
	/// citirea oraselor
	/// </summary>
	/// <param name="orasel"></param>
	/// <returns>vector <Classes::Orase> orasele </returns>
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

				/// <summary>
				/// deoarece in fisierul orase.txt se afla valorile introduse sub forma:
				/// nume oras 
				/// distanta Rovaniemi
				/// distanta Abu_Dhabi
				/// distanta Ajman
				/// distanta Dubai
				/// distanta Sharjah
				/// distanta Fujairah
				/// </summary>
				/// <param name="orasel"></param>
				/// <returns>vector <Classes::Orase> orasele </returns>
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

	/// <summary>
	/// fct pt aflarea drumului cel mai scurt
	/// </summary>
	/// <returns>vector <Classes::Drum> drumul</returns>
	vector <Classes::Drum> AflareDrum()
	{
		vector <Classes::Orase> ooo = CitireOrase(ooo);

		/// <summary>
		/// afisarea oraaselor si distantei catre celelalte orase
		/// distanta catre sine este 0
		/// </summary>
		/// <returns>vector <Classes::Drum> drumul</returns>
		for (Classes::Orase o : ooo)
		{
			o.Afis(o);
			cout << endl;
		}

		Classes::Drum dr;
		vector <Classes::Drum> drumul;
		int min, pozm, poz;
		min = ooo.at(0).getDist(0);

		/// <summary>
		/// cautarea distantei minime catre rovaniemi dintre distantele fiecarui oras 
		/// atribuirea numelui acelui oras
		/// verificarea se face pe prima coloana
		/// si se salveaza pozitia (linia) cu valoarea minima in pozm
		/// </summary>
		/// <returns>vector <Classes::Drum> drumul </returns>
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

		/// <summary>
		/// verificarea pe linie a distantei celei mai mici diferite de 0 
		/// de asemenea nu revizitam orasele pe care le-am vizitat deja
		/// astfel verificam daca am vizitat deja acel oras
		/// se salveaza coloana cu dist minima in pozm iar poz va lua valoarea lui pozm la inceputul verificarii unei noi linii
		/// </summary>
		/// <returns>vector <Classes::Drum> drumul</returns>
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

	/// <summary>
	/// citirea jucariilor din inventar
	/// </summary>
	/// <param name="jucarie"></param>
	/// <returns> vector <Classes::Jucarie> juc </returns>
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

				/// <summary>
				/// deoarece in fisierul cadouri.txt se afla valorile introduse sub forma:
				/// nume jucarie
				/// pret jucarie
				/// cantitate in inventar
				/// </summary>
				/// <param name="jucarie"></param>
				/// <returns> vector <Classes::Jucarie> juc </returns>
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

	/// <summary>
	/// citirea denumirii unui cadou pt cei cuminti si unuia pt cei rai
	/// </summary>
	/// <param name="Cadou_naugthy"></param>
	/// <param name="Cadou_good"></param>
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

	/// <summary>
	/// citirea listei lui Mos Craciun
	/// </summary>
	/// <param name="cop"></param>
	/// <returns> vector <Classes::Mosu> lista </returns>
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

				/// <summary>
				/// deoarece in fisierul mosu.txt se afla valorile introduse sub forma:
				/// nume copil
				/// prenume copil
				/// varsta copil
				/// oras copil
				/// cuminte/rau
				/// acest lucru se face pentru a verifica exact daca un copil a fost cuminte
				/// putand sa existe copii care au acelasi nume aceeasi varsta sau acelasi oras dar nu poate sa existe un duplicat al vreunui copil
				/// in acelasi oras
				/// </summary>
				/// <param name="jucarie"></param>
				/// <returns> vector <Classes::Mosu> lista </returns>
				while (getline(mf1, nume))
				{
					getline(mf1, prenume);
					mf1 >> age;
					getline(mf1, line);
					getline(mf1, oras);
					getline(mf1, line);

					if (!line.compare("Naughty"))
					{
						cuminte = 0;
					}
					else
					{
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




	/// <summary>
	/// afisarea cerintelor
	/// </summary>
	void Cerinta()
	{
		cout << "\n\tCERINTA:\n\n";
		cout << "1] Afisati scrisorile copiilor ( minim 5 copii ).\n";
		cout << "2] Sa se afiseze fiecare copil ce cadou va primi.\n";
		cout << "3] Sa se afiseze cate ambalaje pentru fete si cate ambalaje pentru baieti au folosit trolii.\n";
		cout << "4] Sa se afiseze suma extra folosita.\n";
		cout << "5] Sa se afiseze traseul pe care l-a urmat Mos Craciun si distanta parcursa ( minim 4 tari ).\n";
	}

	/// <summary>
	/// afisarea scrisorilor
	/// </summary>
	/// <param name="s"></param>
	void AfisareScrisori(vector <Classes::Scrisoare> s)
	{
		int i = 1;

		for (Classes::Scrisoare c : s)
		{
			cout << " " << i++ << ". ";
			c.Afisare(c);
		}
	}

	/// <summary>
	/// afisarea drumului
	/// </summary>
	/// <param name="drumul"></param>
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

	/// <summary>
	/// afisarea jucariilor
	/// </summary>
	/// <param name="juc"></param>
	void AfisareJucarii(vector <Classes::Jucarie> juc)
	{
		for (Classes::Jucarie j : juc)
		{
			j.Afisare(j);
			cout << endl;
		}
	}

	/// <summary>
	/// afisarea listei Mosului
	/// </summary>
	/// <param name="s"></param>
	void AfisareListaMosu(vector <Classes::Mosu> s)
	{
		for (Classes::Mosu m : s)
		{
			m.Afisare();
		}
	}

	/// <summary>
	/// folosim template pt iseq1 si iseq2
	/// cautam numele jucariei din scrisoare in inventarul elfilor iar in cas ca este gasita verificam daca costul acestei jucarii nu depaseste bugetul actual
	/// si de asemenea si daca mai exista in inventar acea jucarie
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="U"></typeparam>
	/// <typeparam name="V"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <param name="c"></param>
	/// <returns>Classes::Cadou cadoul</returns>
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
					}
				}
			}
		}
		return cadoul;
	}

	/// <summary>
	/// verifica daca numele prenumele orasul si varsta unui copil sunt aceleasi pe lista mosului si pe scrisoarea cu dorinte
	///  desi in cerinta ni s-a spus ca elfi detin lista cu situatia copiilor mi s-a parut mult mai bine daca aceasta ar fi o functie din afara oricarei clase
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <typeparam name="U"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>int de verificare a egalitatii</returns>
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

	/// <summary>
	/// am transmis prin referinta un vector de int deoarece aveam nevoie sa pastram atat valoarea sumelor alocate fiecarui copil cat si lista de cadouri
	/// iar intul a provocat mai putine probleme la rulare
	/// in aceasta functie apeam iseq1 pt a verifica daca am gasit pe lista mosului copilul care are o anumita lista de dorinte
	///  apoi ii acordam o suma pe care elfii trebuie sa o respecte in acordarea cadourilor apoi apelam iseq2
	/// </summary>
	/// <param name="s"></param>
	/// <param name="m"></param>
	/// <param name="jucarie"></param>
	/// <param name="sum"></param>
	/// <returns>vector<Classes::Cadou> cad</returns>
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
					}
					else
					{
						(*sum).at(i) = 10;
					}

					cad.push_back(IsEq2(s.at(i), jucarie, (*sum).at(j)));
				}
			}
		}

		return cad;
	}

}
