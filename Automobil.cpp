#include "Automobil.h"
#include <iostream>
using namespace std;

Automobil::Automobil() :Vozilo() {
	this->maxBrojPutnika = 3;
}

Automobil::Automobil(char* naziv, char* registarskaOznaka, float brzina, float potrosnja, int maxBrojPutnika) :Vozilo(naziv, registarskaOznaka, brzina, potrosnja) {
	this->maxBrojPutnika = maxBrojPutnika;
}

Automobil::~Automobil() {}

ostream& Automobil::UpisiUTok(ostream& izlaz) {
	Vozilo::UpisiUTok(izlaz);
	izlaz << "Maksimalan broj putnika po registraciji: " << this->maxBrojPutnika << endl;
	return izlaz;
}

istream& Automobil::CitajIzToka(istream& ulaz) {
	Vozilo::CitajIzToka(ulaz);
	ulaz >> this->maxBrojPutnika;
	return ulaz;
}

bool Automobil::UporediVozila(Vozilo* V1) {
	if (this->brzina > V1->getBrzina()) {
		return true;
	}
	else {
		return false;
	}
}