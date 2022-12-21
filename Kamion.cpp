#include "Kamion.h"
#include <iostream>
using namespace std;

Kamion::Kamion() :Vozilo() {
	this->nosivostKamiona = 10;
}

Kamion::Kamion(char* naziv, char* registarskaOznaka, float brzina, float potrosnja, float nosivostKamiona) :Vozilo(naziv, registarskaOznaka, brzina, potrosnja) {
	this->nosivostKamiona = nosivostKamiona;
}

Kamion::~Kamion() {}

ostream& Kamion::UpisiUTok(ostream& izlaz) {
	Vozilo::UpisiUTok(izlaz);
	izlaz << "Maksimalna nosivost kamiona je: " << this->nosivostKamiona << "t" << endl;
	return izlaz;
}

istream& Kamion::CitajIzToka(istream& ulaz) {
	Vozilo::CitajIzToka(ulaz);
	ulaz >> this->nosivostKamiona;
	return ulaz;
}

bool Kamion::UporediVozila(Vozilo* V1) {
	if (this->potrosnja < V1->getPotrosnja()) {
		return true;
	}
	else {
		return false;
	}
}