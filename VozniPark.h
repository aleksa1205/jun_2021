#pragma once
#include "Vozilo.h"

class VozniPark : public Vozilo
{
private:
	Vozilo** Spisak;
	int maksimalanBrojVozila;
	char* tipParka;

	bool UporediVozila(Vozilo* V1);
public:
	VozniPark();
	VozniPark(int brojVozila, char* tip);
	~VozniPark();

	void DodajVozilo(Vozilo* V1);
	void UpisiUFajl(char* putanja);
	void UcitajUSpisak(char* putanja);
	void Sortiraj();
};