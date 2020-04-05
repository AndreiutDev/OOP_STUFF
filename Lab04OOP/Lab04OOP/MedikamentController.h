#pragma once
#include <vector>
#include "MedikamentRepo.h"
// UNDO/REDO STRUCTURE
typedef struct N
{
	int ID; // unique ID for each command (used only for debugging)
	bool add_or_delete; // true if it is added, false  if deleted
	bool insert_or_add_quantity;// true if a new element was inserted, false if the element exists and quantity is added
	// MEDIKAMENT DOMAIN INFORMATION
	int quantity;
	double konz;
	double price;
	std::string name;
} n;

class MedikamentController
{
	friend class MedikamentUI;
private:
	MedikamentRepo repo;
	long int totalMeds;//THE TOTAL MED QUANTITY
	int distinctMeds;//THE NUMBER OF DISTINCT MED TYPES
public:
	// INIT OF A MED WITH VALUES AND RETURN IT
	MedikamentDomain initMeds(std::string name, double konz, int menge, double preis);
	
	n undo_redo_list[1000]; //Here will be stored the information regarding the undo-redo commands
	int index;// Indicates which command must be undone/ redone
	int max_index_size;// the size of the command stack
	// initialise an element of the undo/redo stack
	n initUndoRedoElement(bool add_delete, bool insertq_or_normal, std::string name, double konz, int menge, double preis);
	
	//INSERTS AN ELEMENT INTO THE UNDO/REDO STACK
	void insertElementAtACertainPos(n element);

	// prints the undo/redo list
	void PrintUndoRedoList();

	//constructor
	MedikamentController();

	// RETURN TOTAL MED QUANTITY
	int GetTotalMeds() { return totalMeds; }

	// RETURN THE NUMBER OF DISTINCT MED TYPES
	int GetDistinctMeds() { return distinctMeds; }

	// ADDS A NEW MED
	void  addMed(MedikamentDomain other, bool undo_redo);

	// DELETES A MED
	void deleteMed(MedikamentDomain other, bool undo_redo);

	// SEARCHES FOR MEDS AND RETURNS A VECTOR CONTAINING THE NAME AND CONCENTRATION OF THE MEDS GIVEN A CERTAIN PATTERN
	std::vector < std::string> search(std::string search_str);

	// SEARCHES FOR MEDS THAT HAVE A QUANTITY LESS THAN "X" AND RETURN A VECTOR OF THE FOUND MEDICAMENTS
	std::vector<MedikamentDomain> GetKnapp(int X);

	// RETURNS A VECTOR OF THE MEDICAMENTS GROUPED BY PRICE
	std::vector < MedikamentDomain > preisGruppiert();

	//REDO OPERATION
	void Redo();

	//UNDO OPERATION
	void Undo();
};

