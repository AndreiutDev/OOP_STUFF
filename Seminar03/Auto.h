#pragma once
#include <string>

class Auto
{
	protected:
		Auto();
		int id;
		std::string marke;
		std::string modell;
	public:
		Auto(int id1, std::string marke1, std::string modell1);
		int GetId(void);

		std::string GetMarke(void);

		std::string GetModell(void);

		void SetId(int x);

		void setMarke(std::string x);

		void SetModell(std::string x);

};

