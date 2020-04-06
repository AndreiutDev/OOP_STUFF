#include "PKW.h"
#include "Auto.h"
#include <string>

PKW::PKW()
{

}

PKW::PKW(int id1, std::string marke1, std::string modell1, std::string sonderauss1)
{
	id = id1;
	marke = marke1;
	modell = modell1;
	sonderausstattungen = sonderauss1;
}

PKW::~PKW()
{

}