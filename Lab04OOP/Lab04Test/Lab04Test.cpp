#include "pch.h"
#include "..\Lab04OOP\MedikamentController.h"
#include "..\Lab04OOP\MedikamentDomain.h"
#include "..\Lab04OOP\MedikamentRepo.h"
#include "..\Lab04OOP\MedikamentController.cpp"
#include "..\Lab04OOP\MedikamentDomain.cpp"
#include "..\Lab04OOP\MedikamentRepo.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab04Test
{
	TEST_CLASS(Lab04Test)
	{
	public:
		TEST_METHOD(AddTest)//ADDS 700 DISTINCT MEDS AND CHECKS IF THEY HAVE BEEN ADDED CORRECTLY
		{
			int difMeds = 0; // THE AMOUNT OF MED TYPES
			int totalMeds = 0; // THE GENERAL QUANTITY OF MEDS

			MedikamentController controller;
			for (int i = 0; i < 100; i++)
			{
				difMeds++;
				totalMeds += 20;
				MedikamentDomain m = MedikamentDomain("Ibuprofen", float(i), 20, 20);
				controller.addMed(m, true);
			}
			
			difMeds++;
			for (int i = 0; i < 600; i++)
			{
				totalMeds += i;
				MedikamentDomain m = MedikamentDomain("Nurofen", 40, i, 20);
				controller.addMed(m, true);
			}
			Assert::AreEqual(controller.GetTotalMeds(), totalMeds);
			Assert::AreEqual(controller.GetDistinctMeds(), difMeds);
		}
		TEST_METHOD(RemoveTest)
		{
			int difMeds = 0; // THE AMOUNT OF MED TYPES
			int totalMeds = 0; // THE GENERAL QUANTITY OF MEDS

			MedikamentController controller;

			for (int i = 0; i < 100; i++)
			{
				difMeds++;
				totalMeds += 20;
				MedikamentDomain m = MedikamentDomain("Ibuprofen", float(i), 20, 20);
				controller.addMed(m, true);
			}
			difMeds++;
			for (int i = 0; i < 600; i++)
			{
				totalMeds += i;
				MedikamentDomain m = MedikamentDomain("Nurofen", 40, i, 20);
				controller.addMed(m, true);
			}
			for (int i = 30; i < 70; i++)
			{
				if (i % 3 == 0)
				{
					difMeds--;
					totalMeds -= 20;
					MedikamentDomain m = MedikamentDomain("Ibuprofen", float(i), 20, 20);
					controller.deleteMed(m, true);
				}
			}
			Assert::AreEqual(controller.GetTotalMeds(), totalMeds);
			Assert::AreEqual(controller.GetDistinctMeds(), difMeds);
		}

		TEST_METHOD(UndoRedoTest)
		{
			MedikamentDomain m = MedikamentDomain("Ibuprofen", 1, 20, 20);
			MedikamentDomain m1 = MedikamentDomain("Smecta", 1, 20, 20);
			MedikamentDomain m2 = MedikamentDomain("Anvar", 1, 20, 20);
			MedikamentDomain m3 = MedikamentDomain("Ibuprofen", 1, 20, 20);

			MedikamentController controller;
			controller.addMed(m, true);
			Assert::AreEqual(controller.GetDistinctMeds(), 1);
			Assert::AreEqual(controller.GetTotalMeds(), 20);
			controller.Undo();
			Assert::AreEqual(controller.GetDistinctMeds(), 0);
			Assert::AreEqual(controller.GetTotalMeds(), 0);
			controller.addMed(m1, true);
			controller.addMed(m2, true);
			controller.addMed(m3, true);
			controller.Undo();
			controller.Undo();
			Assert::AreEqual(controller.GetDistinctMeds(), 1);
			Assert::AreEqual(controller.GetTotalMeds(), 20);
			controller.Redo();
			controller.Redo();
			Assert::AreEqual(controller.GetDistinctMeds(), 3);
			Assert::AreEqual(controller.GetTotalMeds(), 60);
		}

		TEST_METHOD(SearchTest)
		{
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
			std::vector<std::string> str_vec = controller.search("fen");
			std::string strTest1 = "Nurofen with the concentration " + std::to_string(3.3) + "%";
			std::string strTest2 = "Nurofen with the concentration " + std::to_string(20.5) + "%";
			std::string strTest3 = "Ibuprofen with the concentration " + std::to_string(20.3) + "%";
			Assert::AreEqual(strTest2, str_vec[1]);
			Assert::AreEqual(strTest1, str_vec[2]);
			Assert::AreEqual(strTest3, str_vec[0]);
		}

		TEST_METHOD(KnappTest)
		{
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
			std::vector<MedikamentDomain> vec = controller.GetKnapp(21);
			Assert::AreEqual(vec[0].GetMenge(), 3);
			Assert::AreEqual(vec[1].GetMenge(), 20);
		}

		TEST_METHOD(PreisTest)
		{
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
			std::vector<MedikamentDomain> vec = controller.preisGruppiert();
			std::string stringTest1 = vec[2].GetName();
			std::string stringTest2 = "Arsenic";
			std::string stringTest3 = vec[1].GetName();
			std::string stringTest4 = "Ibuprofen";
			std::string stringTest5 = vec[0].GetName();
			std::string stringTest6 = "Nurofen";
			std::string stringTest7 = vec[3].GetName();
			std::string stringTest8 = "Smecta";
			Assert::AreEqual(stringTest1, stringTest2);
			Assert::AreEqual(stringTest4, stringTest3);
			Assert::AreEqual(stringTest5, stringTest6);
			Assert::AreEqual(stringTest8, stringTest7);
		}
	};
}
