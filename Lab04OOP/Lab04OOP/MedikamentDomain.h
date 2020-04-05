#pragma once
#include <string>
class MedikamentDomain
{
	private:
		std::string name;
		double konzentration;
		int menge;
		double preis;
	public:
		//constructor
		MedikamentDomain(std::string name, double konzentration, int menge, double preis);

		// RETURNS THE NAME OF THE MED
		std::string GetName();

		// RETURNS THE CONCENTRATION OF THE MED
		double GetKonzentration();

		// RETURNS THE QUANTITY OF THE MED
		int  GetMenge();

		// RETURNS THE PRICE OF THE MED
		double GetPreis();

		// SET THE NAME OF A CERTAIN MED
		void SetName(std::string other);

		// SET THE CONCENTRATION OF A CERTAIN MED
		void SetKonzentration(double other);

		// SET THE QUANTITY OF A CERTAIN MED
		void SetMenge(int other);

		// SET THE PRICE OF A CERTAIN MED
		void SetPreis(double other);
};

