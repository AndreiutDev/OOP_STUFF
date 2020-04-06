#include "Kunde.h"
#include <string>
#include "Auto.h"
Kunde::Kunde(int id1, std::string name1)
{
	id = id1;
	name = name1;
}

int Kunde::GetId()
{
	return id;
}

std::string Kunde::GetName()
{
	return name;
}

void Kunde::SetId(int other)
{
	id = other;
}

void Kunde::SetName(std::string other)
{
	name = other;
}