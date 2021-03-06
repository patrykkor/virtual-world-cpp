#pragma once
#include "Swiat.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <random>
#include <functional>
#define ERRORPOLE -99
class Swiat;

class Organizm {
protected:
	std::pair <int, int> pos;
	int sila;
	int inicjatywa;
	int wiek = 0;
	bool jestZywy = 1;
	char znak;
	std::string nazwa;
	Swiat& swiat;
public:
	Organizm(std::pair<int,int> pos, int sila, int inicjatywa, char znak, std::string nazwa, Swiat& swiat);
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* atakujacy) = 0;
	virtual bool czyTenSamGatunek(Organizm* inny) = 0;
	virtual void utworzOrganizm(std::pair<int, int> pole, Swiat& swiat) = 0;
	virtual std::pair <int, int> proponowanaPozycja(int kierunek);
	void rysowanie();
	int getSila();
	int getInicjatywa();
	int getPosX();
	int getPosY();
	int getWiek();
	bool getZywy();
	void rozmnazajSie();
	char getZnak();
	Swiat& getSwiat();
	std::string getNazwa();
	std::vector <std::pair<int, int>> wolnePola();
	std::pair <int, int> wybierzWolnePole(std::vector<std::pair<int,int>> wektorPol);
	void setZywy(bool jestZywy);
	void setPosY(int y);
	void setPosX(int x);
	void setWiek(int wiek);
	void setSila(int sila);
	bool czySieMiesci(std::pair <int, int> proposed);
	~Organizm();
};