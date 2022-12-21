#pragma once
#include "Vozilo.h"

class Kamion : public Vozilo
{
private:
	float nosivostKamiona;
public:
	Kamion();
	Kamion(char* naziv, char* registarskaOznaka, float brzina, float potrosnja, float nosivostKamiona);
	~Kamion();

	ostream& UpisiUTok(ostream& izlaz);
	istream& CitajIzToka(istream& ulaz);
	bool UporediVozila(Vozilo* V1);
};