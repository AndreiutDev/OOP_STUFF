#include "LKW.h"
#include <string>

LKW::LKW()
{

}
LKW::LKW(int id1, std::string marke1, std::string modell1, std::string bez1, int gesamtgewicht)
{
	id = id1;
	marke = marke1;
	modell = modell1;
	Bezeichnung = bez1;
	Gesamtgewicht = gesamtgewicht;
}

void LKW::load(int l)
{
	Gesamtgewicht += l;
}

void LKW::unload(int l)
{
	if (Gesamtgewicht - l < 0)
		Gesamtgewicht = 0;
	Gesamtgewicht -= l;
}