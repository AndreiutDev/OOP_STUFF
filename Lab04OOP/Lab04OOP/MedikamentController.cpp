#include "MedikamentController.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include "../Lab04Test/pch.h"
MedikamentController::MedikamentController()
{
	this->repo = MedikamentRepo();
	index = -1;
	max_index_size = -1;
	totalMeds = 0;
	distinctMeds = 0;
}

n MedikamentController::initUndoRedoElement(bool add_delete, bool insertq_or_normal, std::string name, double konz, int menge, double preis)
{
	n element;
	element.ID = max_index_size + 2;
	element.add_or_delete = add_delete;
	element.insert_or_add_quantity = insertq_or_normal;
	element.name = name;
	element.quantity = menge;
	element.konz = konz;
	element.price = preis;
	return element;
}

void MedikamentController::insertElementAtACertainPos(n element)
{
	index++;
	undo_redo_list[index] = element;
	max_index_size = index;
}

void  MedikamentController::addMed(MedikamentDomain other, bool undo_redo)
{
	
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
	{
		if (ptr->GetName() == other.GetName() && ptr->GetKonzentration() == other.GetKonzentration())
		{
			totalMeds += other.GetMenge();
			ptr->SetMenge(ptr->GetMenge() + other.GetMenge());
			if (undo_redo == true)
			{
				n element = initUndoRedoElement(true, true, other.GetName(), other.GetKonzentration(), other.GetMenge(), other.GetPreis());
				insertElementAtACertainPos(element);
			}
			return;
		}
	}
	distinctMeds++;
	totalMeds += other.GetMenge();
	if (undo_redo == true)
	{
		n element = initUndoRedoElement(true, false, other.GetName(), other.GetKonzentration(), other.GetMenge(), other.GetPreis());
		insertElementAtACertainPos(element);
	}
	repo.medikamente.push_back(other);
}

void MedikamentController::PrintUndoRedoList()
{
	printf(" The current index is : %d\n", index);
	printf(" The max size is : %d\n", max_index_size);
	for (int i = 0; i <= index; i++)
		printf("%d %d %d\n", undo_redo_list[i].ID, undo_redo_list[i].add_or_delete, undo_redo_list[i].insert_or_add_quantity);
}

void MedikamentController::deleteMed(MedikamentDomain other, bool undo_redo)
{
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
	{
		if (ptr->GetName() == other.GetName() && ptr->GetKonzentration() == other.GetKonzentration())
		{
			distinctMeds--;
			totalMeds -= ptr->GetMenge();
			int menge = ptr->GetMenge();
			double price = ptr->GetPreis();
			repo.medikamente.erase(ptr);
			if (undo_redo == true)
			{
				n element = initUndoRedoElement(false, false, other.GetName(), other.GetKonzentration(), menge, price);
				insertElementAtACertainPos(element);
			}
			return;
		}
	}
	totalMeds -= other.GetMenge();
	distinctMeds--;
	printf("The item has not been found!\n");
}

std::vector<std::string> MedikamentController::search(std::string search_str)
{
	std::string current_str;
	std::vector<MedikamentDomain> cpy;
	std::vector<std::string> str_vec;
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
	{
		current_str = ptr->GetName();
		if (current_str.find(search_str) != -1)
		{
			current_str = current_str + " with the concentration " + std::to_string(ptr->GetKonzentration()) + "%";
			str_vec.push_back(current_str);
		}
	}
	sort(str_vec.begin(), str_vec.end());
	return str_vec;
}

std::vector<MedikamentDomain> MedikamentController::GetKnapp(int X)
{
	std::vector<MedikamentDomain> cpy;
	std::vector<MedikamentDomain>::iterator ptr;
	for (ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
	{
		if (ptr->GetMenge() < X)
		{
			cpy.push_back(*ptr);
		}
	}
	return cpy;
}

MedikamentDomain MedikamentController::initMeds(std::string name, double konz, int menge, double preis)
{
	MedikamentDomain m = MedikamentDomain(name, konz, menge, preis);
	return m;
}
//OPPOSITE OF UNDO
void MedikamentController::Redo()
{
	if (index == max_index_size)
	{
		printf("Nothing can be redone!\n");
		return;
	}
	else if (undo_redo_list[index].add_or_delete == true && undo_redo_list[index].insert_or_add_quantity == true)
	{
		MedikamentDomain m = initMeds(undo_redo_list[index + 1].name, undo_redo_list[index + 1].konz, undo_redo_list[index + 1].quantity, undo_redo_list[index + 1].price);
		for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
		{
			if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration())
			{
				totalMeds += m.GetMenge();
				ptr->SetMenge(ptr->GetMenge() + m.GetMenge());
				index++;
				return;
			}
		}
	}
	else if (undo_redo_list[index + 1].add_or_delete == true)//ADD WHOLE MED
	{
		MedikamentDomain m = initMeds(undo_redo_list[index + 1].name, undo_redo_list[index + 1].konz, undo_redo_list[index + 1].quantity, undo_redo_list[index + 1].price);
		index++;
		addMed(m, false);
	}
	else// DELETE MED
	{
		MedikamentDomain m = initMeds(undo_redo_list[index + 1].name, undo_redo_list[index + 1].konz, undo_redo_list[index + 1].quantity, undo_redo_list[index + 1].price);
		index++;
		deleteMed(m, false);
	}
}

void MedikamentController::Undo()
{
	if (index == -1)//NOTHING TO BE UNDONE
	{
		printf("Nothing can be undone!\n");
		return;
	}
	else if (undo_redo_list[index].add_or_delete == true && undo_redo_list[index].insert_or_add_quantity == true)//IF THE OPERATION WAS SIMPLY "ADD QUANTITY", THE UNDO OPERATION WILL NOT DELETE, BUT SUBSTRACT
	{
		MedikamentDomain m = initMeds(undo_redo_list[index].name, undo_redo_list[index].konz, undo_redo_list[index].quantity, undo_redo_list[index].price);
		for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
		{
			if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration())
			{
				totalMeds -= ptr->GetMenge();
				ptr->SetMenge(ptr->GetMenge() - m.GetMenge());
				return;
			}
		}
	}
	else if (undo_redo_list[index].add_or_delete == true)// IF THE OPERATION WAS "ADD", THE UNDO OPERATION WILL BE "DELETE"
	{
		MedikamentDomain m = initMeds(undo_redo_list[index].name, undo_redo_list[index].konz, undo_redo_list[index].quantity, undo_redo_list[index].price);
		index--;
		deleteMed(m, false);
	}
	else// IF THE OPERATION WAS "DELETE", THE UNDO OPERATION WILL BE "ADD"
	{
		MedikamentDomain m = initMeds(undo_redo_list[index].name, undo_redo_list[index].konz, undo_redo_list[index].quantity, undo_redo_list[index].price);
		index--;
		addMed(m, false);
	}
}

std::vector < MedikamentDomain > MedikamentController::preisGruppiert()
{
	std::vector<MedikamentDomain> cpy;
	std::vector<MedikamentDomain>::iterator ptr;
	for (ptr = repo.medikamente.begin(); ptr < repo.medikamente.end(); ptr++)
	{
		cpy.push_back(*ptr);
	}
	std::vector<MedikamentDomain>::iterator ptr1;
	std::vector<MedikamentDomain>::iterator ptr2;
	MedikamentDomain m = MedikamentDomain("", -1, -1, -1);
	for (ptr1 = cpy.begin(); ptr1 < cpy.end(); ptr1++)
	{
		for (ptr2 = ptr1; ptr2 < cpy.end(); ptr2++)
		{
			if (ptr1->GetPreis() <= ptr2->GetPreis())
			{
				m = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = m;
			}
		}
	}
	return cpy;
}