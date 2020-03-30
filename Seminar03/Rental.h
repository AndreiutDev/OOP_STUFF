
#include "Auto.h"
#include "Kunde.h"
#include <vector>
class Rental
{
private:
	std::vector<Auto> autos;
	std::vector<Kunde> clients;
public:

	Rental();

	void add_client(Kunde client);

	void add_auto(Auto aut);

	void delete_auto(Auto aut);

	void delete_client(Kunde client);

	void update_client(Kunde client);

	void show_clients();

	void show_autos();
};