#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

namespace Classes
{
	//-------------------------------Elemente din --------------------------------
	class Jucarie
	{
	private:
		string nume;
		int cantitate;
		double pret;

	public:
		Jucarie(string nume, int cantitate, double pret);

		string getName() { return this->nume; }
		int getAmount() { return this->cantitate; }
		double getPrice() { return this->pret; }

		void removeFromInventory();

		friend class Cadou;

	};

	Jucarie::Jucarie(string nume = "", int cantitate = -1, double pret = -1.0)
	{
		this->nume = nume;
		this->cantitate = cantitate;
		this->pret = pret;
	}

	void Jucarie::removeFromInventory()
	{
		this->cantitate--;
	}
	//---------------------------Copil & elemente derivate--------------------------
	class Copil
	{
	public:
		Copil(string nume, string prenume, string oras, int varsta);

		string getName() { return this->nume; }
		string getSurname() { return this->prenume; }
		string getCity() { return this->oras; }
		int getAge() { return this->varsta; }

		void operator =(const Copil& copy);

		void Afisare(const Copil& copy);

		friend class DataComparator;
		friend class Scrisoare;
		friend class Cadou;

	protected:
		string nume;
		string prenume;
		string oras;
		int varsta;

	};

	Copil::Copil(string nume = "", string prenume = "", string oras = "", int varsta = -1)
	{
		this->nume = nume;
		this->prenume = prenume;
		this->oras = oras;
		this->varsta = varsta;
	}

	void Copil::operator =(const Copil& copy)
	{
		this->nume = copy.nume;
		this->prenume = copy.prenume;
		this->oras = copy.oras;
		this->varsta = copy.varsta;
	}

	void Copil::Afisare(const Copil& copy)
	{
		cout << copy.nume << " " << copy.prenume << " " << copy.varsta << " " << copy.oras << "\n";
	}

	class Scrisoare : public Copil
	{
	public:
		Scrisoare(string nume, string prenume, string oras, int varsta, string culoare);
		Scrisoare(const Copil& copy);

		~Scrisoare();

		string getCuloare() { return this->culoare; }
		vector<string> getLista() { return this->lista; }

		void setLista(vector<string> lista) { this->lista = lista; }
		void setCuloare(string culoare) { this->culoare = culoare; }

		bool operator ==(const Copil& c);

		void Afisare(const Scrisoare& s);

		friend class Present;

	private:
		string culoare;
		vector<string> lista;
	};

	Scrisoare::Scrisoare(string nume = "", string prenume = "", string oras = "", int varsta = -1, string culoare = "") : Copil{ nume, prenume, oras, varsta }
	{
		this->culoare = culoare;
	}

	Scrisoare::Scrisoare(const Copil& copy)
	{
		this->nume = copy.nume;
		this->prenume = copy.prenume;
		this->oras = copy.oras;
		this->varsta = copy.varsta;
		this->culoare = "";
		this->lista = {};
	}

	Scrisoare::~Scrisoare()
	{
		this->lista.clear();
	}

	bool Scrisoare::operator ==(const Copil& c)
	{
		if (this->nume == c.nume && this->prenume == c.prenume && this->oras == c.oras && this->varsta == c.varsta)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Scrisoare::Afisare(const Scrisoare& l)
	{
		cout << l.nume << " " << l.prenume << " " << l.varsta << " " << l.oras << " " << l.culoare << " ";
		for (int i = 0; i < l.lista.size() - 1; i++)
		{
			cout << l.lista.at(i) << " ";
		}
		cout << l.lista.at(l.lista.size() - 1) << "\n";
	}

	class Cadou : public Copil
	{
	private:
		string culoare;
		vector<string> items;
		double cost;

	public:
		Cadou(string nume, string prenume, string oras, int varsta);
		Cadou(const Copil& copy);

		~Cadou();

		string getColour() { return this->culoare; }
		vector<string> getItems() { return this->items; }
		double getCost() { return this->cost; }

		void setColour(string culoare) { this->culoare = culoare; }

		void addToItems(Jucarie new_item);

		void operator =(const Cadou& copy);
		bool operator ==(const Scrisoare& l);

		void Afisare(const Cadou& c);
	};

	Cadou::Cadou(string nume = "", string prenume = "", string oras = "", int varsta = -1) : Copil{ nume, prenume, oras, varsta }
	{
		this->culoare = "";
		this->cost = 0.0;
	}

	Cadou::Cadou(const Copil& copy)
	{
		this->nume = copy.nume;
		this->prenume = copy.prenume;
		this->oras = copy.oras;
		this->varsta = copy.varsta;
		this->culoare = "";
		this->cost = 0.0;
	}

	Cadou::~Cadou()
	{
		this->items.clear();
	}

	void Cadou::addToItems(Jucarie new_item)
	{
		this->items.push_back(new_item.nume);
		this->cost += new_item.pret;
	}

	void Cadou::operator =(const Cadou& copy)
	{
		this->nume = copy.nume;
		this->prenume = copy.prenume;
		this->oras = copy.oras;
		this->varsta = copy.varsta;
		this->culoare = copy.culoare;
		this->items = copy.items;
		this->cost = copy.cost;
	}

	bool Cadou::operator ==(const Scrisoare& l)
	{
		if (this->nume == l.nume && this->prenume == l.prenume && this->oras == l.oras && this->varsta == l.varsta) return true;
		else return false;
	}
	void Cadou::Afisare(const Cadou& c)
	{
		cout << "\n" << c.nume << " " << c.prenume << ", " << c.varsta << ", din orasul  " << c.oras << " a primit:\n";

		for (Jucarie i : c.items)
		{
			cout << i.getName() << "\n";
		}
	}

	class DataComparator
	{
	public:
		bool operator ()(const Copil& c1, const Copil& c2)
		{
			if (c1.varsta < c2.varsta || c1.oras.compare(c2.oras) < 0 || c1.prenume.compare(c2.prenume) < 0 || c1.nume.compare(c2.nume) < 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
	//-------------------Clase pentru Orase si Drum
	class Orase
	{
	public:
		void setNume(string nm) {
			this->nume = nm;
		}
		string getNume() {
			return nume;
		}
		void setDist(vector <int> dt) {
			{
				this->dist = dt;
			}
		}
		int getDist(int i)
		{
			return dist.at(i);
		}
		void setVisited(int vs) {
			this->visited = vs;
		}
		int getVisited()
		{
			return visited;
		}
		void Afis(const Orase& o);

	private:
		string nume;
		vector <int> dist;
		int visited;
	};

	void Orase::Afis(const Orase& o)
	{
		cout << " " << o.nume << " ";
		for (int i = 0; i < dist.size(); i++)
		{
			cout << dist.at(i) << " ";
		}

	}

	class Drum
	{
	public:
		void SetOras(string city)
		{
			this->oras = city;
		}
		void SetDist(int dist)
		{
			this->dist = dist;
		}
		string getOras()
		{
			return oras;
		}
		int getDist()
		{
			return dist;
		}

	private:
		int dist;
		string oras;
	};
}