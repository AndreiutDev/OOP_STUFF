#pragma once
#include <vector>
#include "MedikamentDomain.h"
class MedikamentRepo
{
	friend class MedikamentController;
	private:
		std::vector<MedikamentDomain> medikamente;
	public:
		// MEDICAMENT REPOSITORY
		
		// CONSTRUCTOR
		MedikamentRepo();
		// SHOW ALL MEDS
		void print_meds();
};

