
using namespace std;

namespace Classes
{
	//-------------------------------clasa jucariilor--------------------------------
	///contine un nume o cantitate si un pret

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

		/// <summary>
		/// setters
		/// </summary>
		/// <param name="nume"></param>
		void setName(string nume) { this->nume = nume; }
		void setAmount(int cantitate) { this->cantitate = cantitate; }
		void setPrice(double pret) { this->pret = pret; }

		void removeFromInventory();

		void Afisare(const Jucarie& j);

		/// <summary>
		/// friend class
		/// </summary>
		friend class Cadou;

	};

	/// <summary>
	/// constructor cu parametrii
	/// </summary>
	/// <param name="nume"></param>
	/// <param name="cantitate"></param>
	/// <param name="pret"></param>
	Jucarie::Jucarie(string nume = "", int cantitate = -1, double pret = -1.0)
	{
		this->nume = nume;
		this->cantitate = cantitate;
		this->pret = pret;
	}

	/// <summary>
	/// scaderea numarului de elemente din inventar
	/// </summary>
	void Jucarie::removeFromInventory()
	{
		this->cantitate--;
	}

	/// <summary>
	/// afisarea jucariilor
	/// </summary>
	/// <param name="j"></param>
	void Jucarie::Afisare(const Jucarie& j)
	{
		cout << " nume: " << j.nume << "\n cantitate: " << j.cantitate << "\n pret: " << j.pret << " $\n";
	}

	//---------------------------Copil & elemente derivate--------------------------
	///claasa contine un nume un prenume un oras si o varsta

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

	/// <summary>
	/// overload al unui operator
	/// </summary>
	/// <param name="copy"></param>
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

	/// <summary>
	/// mostenire tip friend de la clasa copil
	/// aceasta clasa contine caracteristicile clasei copil plus:
	/// culoare si lista cadourilor cerute
	/// </summary>
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

	/// <summary>
	/// copy constructor
	/// </summary>
	/// <param name="copy"></param>
	Scrisoare::Scrisoare(const Copil& copy)
	{
		this->nume = copy.nume;
		this->prenume = copy.prenume;
		this->oras = copy.oras;
		this->varsta = copy.varsta;
		this->culoare = "";
		this->lista = {};
	}

	/// <summary>
	/// destructor
	/// </summary>
	Scrisoare::~Scrisoare()
	{
		this->lista.clear();
	}

	/// <summary>
	/// verificarea daca un obiect de clasa scrisoare are aceleasi detalii ca un obiect de clasa copil
	/// </summary>
	/// <param name="c"></param>
	/// <returns> bool </returns>
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

	/// <summary>
	/// afisarea scrisorilor
	/// </summary>
	/// <param name="l"></param>
	void Scrisoare::Afisare(const Scrisoare& l)
	{
		cout << l.nume << " " << l.prenume << " " << l.varsta << " " << l.oras << " " << l.culoare << " ";

		for (int i = 0; i < l.lista.size() - 1; i++)
		{
			cout << l.lista.at(i) << " ";
		}

		cout << l.lista.at(l.lista.size() - 1) << "\n";
	}

	/// <summary>
	/// mostenire tip friend de la clasa copil
	/// aceasta clasa contine caracteristicile clasei copil plus:
	/// culoare, obiecte primite si cost
	/// </summary>
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

		/// <summary>
		/// getters
		/// </summary>
		/// <returns></returns>
		string getColour() { return this->culoare; }
		vector<string> getItems() { return this->items; }
		double getCost() { return this->cost; }

		int ItemSize()
		{
			return this->items.size();
			
		}

		void setColour(string culoare) {  this->culoare=culoare; }

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
		if (this->nume == l.nume && this->prenume == l.prenume && this->oras == l.oras && this->varsta == l.varsta)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// afisarea cadourilor
	/// </summary>
	/// <param name="c"></param>
	void Cadou::Afisare(const Cadou& c)
	{
		cout << "\n" << c.nume << " " << c.prenume << ", " << c.varsta << " ani , din orasul  " << c.oras << " a primit:\n";

		for (Jucarie i : c.items)
		{
			cout << i.getName() << "\n";
		}
	}

	//-------------------Clase pentru Orase si Drum-----------
	///clasa pt oras 
	/// contine nume distante catre celelalte orase si visited care ne ofera posibilitatea de a vedea daca a fost vizitat acest oras
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

	/// <summary>
	/// afisare oras
	/// </summary>
	/// <param name="o"></param>
	void Orase::Afis(const Orase& o)
	{
		cout << " " << o.nume << " ";
		for (int i = 0; i < dist.size(); i++)
		{
			cout << dist.at(i) << " ";
		}

	}

	/// <summary>
	/// clasa drum 
	/// contine drumul final
	/// distanta intre orasul anterior si orasul actual + numele orasului
	/// 
	/// ca o alta optiune care ar putea include si partea de static in functionalitatea programului as fi putut face distanta ca fiind un membru static pe care l-am 
	/// incrementa treptat cu noile valori si am elimina aceasta functionalitate din interiorul Executare::AfisareDrum(drumul); apelat in santa.cpp
	/// </summary>
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

	/// <summary>
	/// static void incr(int d)
	/// {
	/// this->dist+=d;
	/// }
	/// 
	/// static int getDist()
	/// {
	/// return this->dist;
	/// }
	/// </summary>
	
	private:

		/// <summary>
		/// static int dist
		/// </summary>
		int dist;
		string oras;
	};

	//----------------------Mosu---------------------
	///clasa pt Mosu
	///mosteneste din clasa copil numele prenumele orasul si varsta si pe deasuprea mmai contine si un int de verificare a stadiului de cumintenie
	class Mosu : public Copil
	{

	/// <summary>
	/// initial aceasta clasa era intended sa se afle in Workers.hpp dar in momentul cand am mutat-o acolo a facut fite si nu a mai mers programul
	/// </summary>
	public:
		Mosu(string nume, string prenume, string oras, int varsta, int cuminte);

		void Afisare() {
			cout << this->nume << " " << this->prenume << " " << this->oras << " " << this->varsta << " " << this->cuminte << endl;
		}

		int IsCuminte()
		{
			if (cuminte == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	private:
		int cuminte;
	};

	Mosu::Mosu(string nume, string prenume, string oras, int varsta, int cuminte) : Copil{ nume,  prenume,  oras,  varsta }
	{

		/// <summary>
		/// this-> pointer
		/// </summary>
		/// <param name="nume"></param>
		/// <param name="prenume"></param>
		/// <param name="oras"></param>
		/// <param name="varsta"></param>
		/// <param name="cuminte"></param>
		this->cuminte = cuminte;
	}

}