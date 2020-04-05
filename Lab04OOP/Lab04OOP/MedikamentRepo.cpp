#include "MedikamentRepo.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include "../Lab04Test/pch.h"
MedikamentRepo::MedikamentRepo()
{

}

void MedikamentRepo::print_meds()
{
	std::vector<MedikamentDomain>::iterator ptr;
	for (ptr = medikamente.begin(); ptr < medikamente.end(); ptr++)
	{
		std::cout << ptr->GetName() << " : Menge: " << ptr->GetMenge() << " Preis: " << ptr->GetPreis() << " Konzentration: " << ptr->GetKonzentration() << "\n";
	}
}