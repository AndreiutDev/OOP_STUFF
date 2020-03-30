#pragma once
class Konto
{
        //DO NOT CHANGE THIS PART
    private:
        typedef struct info
        {
            char typ[4];
            double betrag;
            double total;
        }Info;
        Info* infoArr;
        int infoCount;
        float Sold;
    public:
        Konto();
        void Bezahlen(const double& Betrag);
        void Einzahlung(const double& Betrag);
        double Kontostand(void);
        void  printDatei(void);
        void  einlesenDatei(void);
};

