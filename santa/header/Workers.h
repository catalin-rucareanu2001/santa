
/// <summary>
/// clasa din care celelalte 3 vor mostenii suma de bani folosita.
/// </summary>
namespace Workers
{
	class Worker
	{
	public:
		Worker();

		double getSum()
		{
			return this->sum;
		}

		/// <summary>
		/// virtual void function
		/// </summary>
		virtual void setSum()
		{
			this->sum = 0;
		}

	protected:
		double sum;
	};

	Worker::Worker()
	{
		this->sum = 0;
	}

	/// <summary>
	/// clasa troll
	/// fata de Worker contine si:
	/// nr carbuni, nr ambalaje fete, nr ambalaje baieti
	/// </summary>
	class Troll : public Worker
	{
	public:
		Troll();

		void AfisAmbaleje()
		{
			cout << "Ambaleje pt fete: " << fete << endl;
			cout << "Ambaleje pt baieti: " << baieti << endl;
		}

		void Ambalare( Classes::Scrisoare &sc)
		{
			if (sc.getCuloare().compare("albastru")==0)
			{
				this->baieti++;
			}
			if (sc.getCuloare().compare("roz") == 0)
			{
				this->fete++;
			}
		}

		void Carbune(Classes::Mosu mos)
		{
			if (!mos.IsCuminte())
			{
				this->nrCarbuni++;
			}
		}

		int getCarbune()
		{
			return nrCarbuni;
		}

		/// <summary>
		/// utilizarea funciei virtual void
		/// </summary>
		/// <returns></returns>
		void setSum()
		{
			this->sum = 0.5 * nrCarbuni;
		}

	private:
		int fete;
		int baieti;
		int nrCarbuni;
	};

	Troll::Troll()
	{
		this->baieti = 0;
		this->fete = 0;
		this->nrCarbuni = 0;
	}

	/// <summary>
	/// clasa elf
	/// fata de Worker contine si:
	/// vector cu nr acadele pt fiecare
	/// </summary>
	class Elf : public Worker
	{
	public:
		vector <int> Acadele(vector <Classes::Cadou> cad, vector <int> sum)
		{
			
			for (int i = 0; i < sum.size(); i++)
			{
				this->acad.push_back(sum.at(i) - cad.at(i).getCost());
			}

			return this->acad;
		}

		/// <summary>
		/// utilizarea funciei virtual void
		/// </summary>
		/// <returns></returns>
		void setSum()
		{
			for (int i = 0; i < acad.size(); i++)
			{
				this->sum += acad.at(i);
			}
		}

		int getAcadele()
		{
			int tot=0;

			for (int i = 0; i < acad.size(); i++)
			{
				tot += acad.at(i);
			}

			return tot;
		}
	
	private:
		vector <int> acad;
		
	};





	/// <summary>
	/// clasa MissSanta
	/// fata de Worker contine si:
	/// nr carbuni, nr acadele
	/// </summary>
	class MissSanta : public Worker
	{
	public:
		void setAcad(int acadele)
		{
			this->nrAcadele = acadele;
		}

		void setCarb(int carbuni)
		{
			this->nrCarbuni = carbuni;
		}

		/// <summary>
		/// utilizarea funciei virtual void
		/// </summary>
		/// <param name="e"></param>
		/// <param name="t"></param>
		void setSum(Elf e, Troll t)
		{
			this->sum = t.getSum() + e.getSum();
		}

		int getAcad()
		{
			return this->nrAcadele;
		}

		int getCarb()
		{
			return this->nrCarbuni ;
		}

	private:
		int nrAcadele;
		int nrCarbuni;
	};

	

}
