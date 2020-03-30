#pragma once
#include "Auto.h"
class PKW :
	public	Auto		
{
public:
		std::string sonderausstattungen;
		PKW();
		PKW(int id, std::string marke, std::string modell, std::string sonderauss);
		~PKW();
};

