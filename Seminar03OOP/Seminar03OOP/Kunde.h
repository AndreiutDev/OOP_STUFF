#pragma once
#include <string>
class Kunde
{
	private:
		int id;
		std::string name;
	public:
		Kunde(int id, std::string name);

		int GetId();

		std::string GetName();

		void SetId(int other);

		void SetName(std::string other);

};

