
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
