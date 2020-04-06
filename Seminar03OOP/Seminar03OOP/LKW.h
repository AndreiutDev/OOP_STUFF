#pragma once
#include "Auto.h"
class LKW :
	public Auto
{
	private:
		int Gesamtgewicht;
		std::string Bezeichnung;
public:
	LKW();
	LKW(int id1, std::string marke1, std::string modell1, std::string bez1, int gesamtgewicht);
	void load(int l);
	void unload(int l);
};

