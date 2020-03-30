#include "OOP_Seminar02_EX060708.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

Konto::Konto()
{
    Sold = 3000;
    infoCount = 0;
    infoArr = new Info[30];
}

void Konto::Bezahlen(const double& Betrag)
{
    char s[3] = "IN";
    Sold = Sold - Betrag;
    infoArr[infoCount].total = Sold;
    strcpy_s(infoArr[infoCount].typ, s);
    infoArr[infoCount].betrag = Betrag;
    infoCount++;
}

void Konto::Einzahlung(const double& Betrag)
{
    char s[4] = "OUT";
    Sold = Sold + Betrag;
    infoArr[infoCount].total = Sold;
    strcpy_s(infoArr[infoCount].typ, s);
    infoArr[infoCount].betrag = Betrag;
    infoCount++;
}

double Konto::Kontostand()
{
    return Sold;
}

void Konto::printDatei()
{
    std::ofstream myfile;
    myfile.open("input.txt");
    int index;
    for (index = 0; index < infoCount; index++)
    {
        myfile << infoArr[index].typ << " " << infoArr[index].betrag << " " << infoArr[index].total << "\n";
    }
}

void Konto::einlesenDatei()
{
    std::string line;
    std::string item;
    std::ifstream myfile;
    myfile.open("input.txt");
    std::cout << "Die eingelesene Transaktionen sind: \n" << std::endl;
    while (!myfile.eof())
    {
        myfile >> item;
        line = item + " ";
        myfile >> item;
        line = line + item + " ";
        myfile >> item;
        line = line + item + " ";
        std::cout << line << "\n";
    }
}

/*int main()
{
    Konto m;
    m.Bezahlen(10.33);
    m.Bezahlen(10.33);
    m.Bezahlen(10.33);
    m.Einzahlung(30.33);
    m.printDatei();
    m.einlesenDatei();
}*/