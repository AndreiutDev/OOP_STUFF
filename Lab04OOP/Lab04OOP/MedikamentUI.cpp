#include "../Lab04Test/pch.h"
#include "MedikamentUI.h"
#include "MedikamentController.h"
#include "MedikamentDomain.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

MedikamentUI::MedikamentUI()
{
   
}

void MedikamentUI::printUI()
{
    printf("\n===================================================================================\n");
    printf("= Press 1 to add a new medicament.                                                =\n");
    printf("= Press 2 to delete a medicament.                                                 =\n");
    printf("= Press 3 to search by substring.                                                 =\n");
    printf("= Press 4 to print the meds which have a quantity less than X (Given by the user) =\n");
    printf("= Press 5 to group by price.                                                      =\n");
    printf("= Press 6 to REDO.                                                                =\n");
    printf("= Press 7 to UNDO.                                                                =\n");
    printf("= Press 8 to print meds.                                                          =\n");
    printf("= Press 9 to quit.                                                                =\n");
    printf("===================================================================================\n\n");

}

void MedikamentUI::main_menu()
{
    // INITIALISE SOME DEFAULT VALUES
    MedikamentDomain m1 = MedikamentDomain("Nurofen", 3.3, 3, 20.9);
    MedikamentDomain m2 = MedikamentDomain("Ibuprofen", 20.3, 30, 25);
    MedikamentDomain m3 = MedikamentDomain("Smecta", 99, 20, 20.9);
    MedikamentDomain m4 = MedikamentDomain("Arsenic", 28, 40, 20.9);
    MedikamentDomain m5 = MedikamentDomain("Nurofen", 20.5, 300, 33);
    MedikamentController controller = MedikamentController();
    controller.addMed(m1, true);
    controller.addMed(m2, true);
    controller.addMed(m3, true);
    controller.addMed(m4, true);
    controller.addMed(m5, true);
	int key = -1;

	bool running = true;
	while (running)
	{
        printUI();
		printf("Choose an option: ");
        std::cin >> key;
		if (key == 1)
		{
            std::cout << "Gib Namen: ";
            std::string name;
            std::cin >> name;

            std::cout << "Gib Konzentration: ";
            double konz;
            std::cin >> konz;

            std::cout << "Gib Menge: ";
            int menge;
            std::cin >> menge;

            std::cout << "Gib Preis: ";
            double preis;
            std::cin >> preis;
            MedikamentDomain m = MedikamentDomain(name, konz, menge, preis);

            controller.addMed(m, true);

            std::cout << '\n';
		}
        else if (key == 2)
        {
            std::cout << "Gib Namen: ";
            std::string name;
            std::cin >> name;

            std::cout << "Gib Konzentration: ";
            double konz;
            std::cin >> konz;

            MedikamentDomain m = MedikamentDomain(name, konz, -1, -1.0);
            controller.deleteMed(m, true);
        }
        else if (key == 3)
        {
            std::string search_str;
            std::cout << "Search for meds: \n";
            std::cin >> search_str;
            std::cout << "The meds that have been found are: \n";
            std::vector<std::string> str_vec = controller.search(search_str);
            std::vector < std::string > ::iterator ptr;
            for (ptr = str_vec.begin(); ptr < str_vec.end(); ptr++)
            {
                std::cout << *ptr << std::endl;
            }
        }
        else if (key == 4)
        {
            std::cout << "Give X: ";
            int X;
            std::cin >> X;
            std::vector <MedikamentDomain> copy = controller.GetKnapp(X);
            printf("The Meds that have a quantity less than %d, are: \n", X);
            std::vector <MedikamentDomain>::iterator ptr;
            for (ptr = copy.begin(); ptr < copy.end(); ptr++)
            {
                std::cout << "Name : " + ptr->GetName() + " ";
                printf("Quantity : %d \n", ptr->GetMenge());
            }

        }
        else if (key == 5)
        {
           std::vector <MedikamentDomain> copy = controller.preisGruppiert();
           std::vector <MedikamentDomain>::iterator ptr;
           for (ptr = copy.begin(); ptr < copy.end(); ptr++)
           {
               std::cout << "Name : " + ptr->GetName() + " ";
               printf("Preis : %f \n", ptr->GetPreis());
           }
        }
        else if (key == 6)
        {
            controller.Redo();
        }
        else if (key == 7)
        {
            controller.Undo();
        }
        else if (key == 8)
        {
            controller.repo.print_meds();
        }
        else if (key == 9)
        {
            running = false;
        }
        else if (key == 10)
        {
            controller.PrintUndoRedoList();
        }
	}
}
