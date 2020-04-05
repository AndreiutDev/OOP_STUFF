#include "MedikamentDomain.h"
#include "../Lab04Test/pch.h"
MedikamentDomain::MedikamentDomain(std::string name, double konzentration, int menge, double preis)
{
	this->name = name;
	this->konzentration = konzentration;
	this->menge = menge;
	this->preis = preis;
}

// RETURNS THE NAME OF THE MED
std::string MedikamentDomain::GetName()
{
	return name;
}

// RETURNS THE CONCENTRATION OF THE MED
double MedikamentDomain::GetKonzentration()
{
	return konzentration;
}

// RETURNS THE QUANTITY OF THE MED
int  MedikamentDomain::GetMenge()
{
	return menge;
}

// RETURNS THE PRICE OF THE MED
double MedikamentDomain::GetPreis()
{
	return preis;
}

// SET THE NAME OF A CERTAIN MED
void MedikamentDomain::SetName(std::string other)
{
	name = other;
}

// SET THE CONCENTRATION OF A CERTAIN MED
void MedikamentDomain::SetKonzentration(double other)
{
	konzentration = other;
}

// SET THE QUANTITY OF A CERTAIN MED
void MedikamentDomain::SetMenge(int other)
{
	menge = other;
}

// SET THE PRICE OF A CERTAIN MED
void MedikamentDomain::SetPreis(double other)
{
	preis = other;
}