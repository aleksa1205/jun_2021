#include "Vozilo.h"
#include "Automobil.h"
#include "Kamion.h"
#include "VozniPark.h"
#include <iostream>
using namespace std;

void main() {
	VozniPark* vp = new VozniPark();
	Automobil* ap = new Automobil((char*)"audi", (char*)"NININI", 200, 12, 5);
	Automobil* pb = new Automobil();
	Automobil* sk = new Automobil((char*)"au", (char*)"SKSKS", 300, 20, 2);
	vp->DodajVozilo(ap);
	vp->DodajVozilo(pb);
	vp->DodajVozilo(sk);
	vp->UpisiUFajl((char*)"fajlau.txt");
	vp->Sortiraj();
	vp->UpisiUFajl((char*)"fajlas.txt");
	return;
}