#include "VozniPark.h"
#include <iostream>
#include <fstream>
using namespace std;

VozniPark::VozniPark() {
	this->maksimalanBrojVozila = 10;
	this->Spisak = new Vozilo*[this->maksimalanBrojVozila];
	for (int i = 0; i < this->maksimalanBrojVozila; i++) {
		this->Spisak[i] = nullptr;
	}
	this->tipParka = new char[11];
	strcpy(this->tipParka, "automobila");
}

VozniPark::VozniPark(int brojVozila, char* tip) {
	this->maksimalanBrojVozila = brojVozila;
	this->Spisak = new Vozilo* [this->maksimalanBrojVozila];
	for (int i = 0; i < this->maksimalanBrojVozila; i++) {
		this->Spisak[i] = nullptr;
	}
	this->tipParka = new char[strlen(tip) + 1];
	strcpy(this->tipParka, tip);
}

VozniPark::~VozniPark() {
	if (this->Spisak != nullptr) {
		delete[] this->tipParka;
		for (int i = 0; i < this->maksimalanBrojVozila; i++) {
			delete[] this->Spisak[i];
			this->Spisak[i] = nullptr;
		}
		delete[] this->Spisak;
	}
	this->Spisak = nullptr;
	this->tipParka = nullptr;
}

//Proveri
void VozniPark::DodajVozilo(Vozilo* V1) {
	int n = 0;
	while (this->Spisak[n] != nullptr) { n++; }
	if (n == this->maksimalanBrojVozila) {
		int m = this->maksimalanBrojVozila;
		this->maksimalanBrojVozila += this->maksimalanBrojVozila / 2;
		for (int i = m; i < this->maksimalanBrojVozila; i++) {
			this->Spisak[i] = nullptr;
		}
	}
	this->Spisak[n] = V1;
	return;
}

void VozniPark::UpisiUFajl(char* putanja) {
	ofstream izlaz;
	izlaz.open(putanja);
	int i = 0;
	while (this->Spisak[i] != nullptr && i < this->maksimalanBrojVozila) {
		this->Spisak[i]->UpisiUTok(izlaz);
		i++;
	}
	izlaz.close();
	return;
}

void VozniPark::UcitajUSpisak(char* putanja) {
	ifstream ulaz;
	ulaz.open(putanja);
	Vozilo* A;
	int i = 0;
	while (i < this->maksimalanBrojVozila && ulaz.peek() != EOF) {
		this->Spisak[i]->CitajIzToka(ulaz);
		i++;
	}
	return;
}

void VozniPark::Sortiraj() {
	int max = 0;
	int n = 0;
	while (this->Spisak[n] != nullptr && n != this->maksimalanBrojVozila) { n++; }
	for (int j = max; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			if (this->Spisak[j]->UporediVozila(this->Spisak[i]) == false) {
				Vozilo* V = this->Spisak[j];
				this->Spisak[j] = this->Spisak[i];
				this->Spisak[i] = V;
			}
		}
	}
	/*
	while (max < this->maksimalanBrojVozila - 1 && this->Spisak[max] != nullptr) {
		while (i < this->maksimalanBrojVozila && this->Spisak[i] != nullptr) {
			if (this->Spisak[max]->UporediVozila(this->Spisak[i]) == false) {
				Vozilo* V = this->Spisak[max];
				this->Spisak[max] = this->Spisak[i];
				this->Spisak[i] = V;
			}
			i++;
		}
		max++;
	}
	return;
	 */
}

bool VozniPark::UporediVozila(Vozilo* V1) {
	return true;
}