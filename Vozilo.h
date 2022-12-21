#pragma once
#include <istream>
using namespace std;

class Vozilo
{
protected:
	char* naziv, * registarskaOznaka;
	float brzina, potrosnja;
public:
	Vozilo();
	Vozilo(char* naziv, char* registarskaOznaka, float brzina, float potrosnja);
	~Vozilo();

	float getBrzina();
	float getPotrosnja();

	virtual ostream& UpisiUTok(ostream& izlaz);
	virtual istream& CitajIzToka(istream& ulaz);
	virtual bool UporediVozila(Vozilo* V1) = 0;
};