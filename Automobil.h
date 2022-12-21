#pragma once
#include "Vozilo.h"

class Automobil : public Vozilo
{
private:
	int maxBrojPutnika;
public:
	Automobil();
	Automobil(char* naziv, char* registarskaOznaka, float brzina, float potrosnja, int maxBrojPutnika);
	~Automobil();

	ostream& UpisiUTok(ostream& izlaz);
	istream& CitajIzToka(istream& ulaz);
	bool UporediVozila(Vozilo* V1);
};