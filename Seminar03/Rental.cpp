#include "Rental.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "PKW.h"
#include "LKW.h"
Rental::Rental()
{

}

void Rental::add_client(Kunde client)
{
	std::vector<Kunde>::iterator ptr;
	for (ptr = clients.begin(); ptr < clients.end(); ptr++)
	{
		if (client.GetId() == ptr->GetId())
		{
			std::cout << "User already exists.\n";
			return;
		}
	}
	clients.push_back(client);
}

void Rental::show_autos()
{
	std::vector<Auto>::iterator ptr;
	std::cout << "Auto list: \n";
	for (ptr = autos.begin(); ptr < autos.end(); ptr++)
	{
		std::cout << ptr->GetMarke() << "\n";
	}
}

void Rental::delete_client(Kunde client)
{
	std::vector<Kunde>::iterator ptr;
	for (ptr = clients.begin(); ptr < clients.end(); ptr++)
	{
		if (client.GetId() == ptr->GetId())
		{
			clients.erase(ptr, ptr);
		}
	}
}

void Rental::show_clients()
{
	std::vector<Kunde>::iterator ptr;
	std::cout << "Client list: \n";
	for (ptr = clients.begin(); ptr < clients.end(); ptr++)
	{
		std::cout << ptr->GetName() << "\n";
	}
}

void Rental::update_client(Kunde client)
{
	bool ok = false;
	std::vector<Kunde>::iterator ptr;
	for (ptr = clients.begin(); ptr < clients.end(); ptr++)
	{
		if (client.GetId() == ptr->GetId())
		{
			std::cout << "Change your name\n";
			std::string name;
			std::cin >> name;
			ptr->SetName(name);
			ok = true;
			return;
		}
	}
	if (ok == false)
	{
		std::cout << "Client not found.\n";
	}
}

void Rental::add_auto(Auto aut)
{
	std::vector<Auto>::iterator ptr;
	for (ptr = autos.begin(); ptr < autos.end(); ptr++)
	{
		if (aut.GetId() == ptr->GetId())
		{
			std::cout << "User already exists.\n";
			return;
		}
	}
	autos.push_back(aut);
}

void Rental::delete_auto(Auto aut)
{
	std::vector<Auto>::iterator ptr;
	for (ptr = autos.begin(); ptr < autos.end(); ptr++)
	{
		if (aut.GetId() == ptr->GetId())
		{
			autos.erase(ptr, ptr);
		}
	}
}

int main()
{
		Rental rental = Rental();

		Kunde k1 = Kunde(1, "Bob");
		Kunde k2 = Kunde(2, "Andrei");
		Kunde k3 = Kunde(3, "Cioaba");

		//Test Rental add client
		rental.add_client(k1);
		rental.add_client(k2);
		rental.add_client(k3);
		//rental.add_client(k1);

		rental.show_clients();

		//Test Rental update
		//aici se cere un name, de tip string
		rental.update_client(k1);
		rental.show_clients();

		//Test Rental delete client
		rental.delete_client(k1);
		rental.show_clients();

		//Test Rental add auto
		Auto a1 = Auto(1, "Audi", "TT");
		Auto a2 = Auto(2, "Ford", "Focus");
		rental.add_auto(a1);
		rental.add_auto(a2);

		rental.show_autos();

		//Test Rental delete auto
		rental.delete_auto(a1);
		rental.show_autos();

		//Test PKW
		PKW p1 = PKW(3, "PKW1", "MOSDa", "AK47");
		rental.add_auto(p1);

		rental.show_autos();

		//TEST LKW, load, unload
		LKW l1 = LKW(4, "LKW1", "asd1", "Viel", 33);
		l1.load(100);
		//l1.show_Gesamtgewicht();
		l1.unload(50);
		//l1.show_Gesamtgewicht();
		l1.unload(51);


		rental.add_auto(l1);
		rental.show_autos();
}