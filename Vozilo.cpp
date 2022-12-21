#include "Vozilo.h"
#include <iostream>
using namespace std;

Vozilo::Vozilo() {
	this->naziv = new char[7];
	strcpy(this->naziv, "vozilo");
	this->registarskaOznaka = new char[5];
	strcpy(this->registarskaOznaka, "0000");
	this->brzina = 150;
	this->potrosnja = 10;
}

Vozilo::Vozilo(char* naziv, char* registarskaOznaka, float brzina, float potrosnja) {
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->registarskaOznaka = new char[strlen(registarskaOznaka) + 1];
	strcpy(this->registarskaOznaka, registarskaOznaka);
	this->brzina = brzina;
	this->potrosnja = potrosnja;
}

Vozilo::~Vozilo() {
	if (this->naziv != nullptr) {
		delete[] this->naziv;
		delete[] this->registarskaOznaka;
	}
	this->naziv = nullptr;
	this->registarskaOznaka = nullptr;
}

float Vozilo::getBrzina() {
	return this->brzina;
}

float Vozilo::getPotrosnja() {
	return this->potrosnja;
}

ostream& Vozilo::UpisiUTok(ostream& izlaz) {
	izlaz << "Naziv vozila : " << this->naziv << endl;
	izlaz << "Registarska oznaka vozila: " << this->registarskaOznaka << endl;
	izlaz << "Karakteristike vozila: " << endl;
	izlaz << "Potrosnja: " << this->potrosnja << " l/100km" << endl;
	izlaz << "Maksimalna brzina: " << this->brzina << " km/h" << endl;
	return izlaz;
}

istream& Vozilo::CitajIzToka(istream& ulaz) {
	ulaz >> this->naziv;
	ulaz >> this->registarskaOznaka;
	ulaz >> this->potrosnja;
	ulaz >> this->brzina;
	return ulaz;
}

bool Vozilo::UporediVozila(Vozilo* V1) {
	return true;
}