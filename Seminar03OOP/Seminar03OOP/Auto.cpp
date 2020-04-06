#include "Auto.h"

Auto::Auto()
{

}

Auto::Auto(int id1, std::string marke1, std::string modell1)
{
	id = id1;
	marke = marke1;
	modell = modell1;
}

int Auto::GetId(void)
{
	return id;
}

std::string Auto::GetMarke(void)
{
	return marke;
}

std::string Auto::GetModell(void)
{
	return modell;
}

void Auto::SetId(int x)
{
	id = x;
}

void Auto::setMarke(std::string x)
{
	marke = x;
}

void Auto::SetModell(std::string x)
{
	modell = x;
}