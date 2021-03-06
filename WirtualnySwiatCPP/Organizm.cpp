#include <iostream>
#include <random>
#include "Organzim.h"
using namespace std;
Organizm::Organizm(pair<int, int> pos, int sila, int inicjatywa, char znak, string nazwa, Swiat& swiat) : pos(pos), sila(sila), inicjatywa(inicjatywa), znak(znak), nazwa(nazwa), swiat(swiat) {

}
void Organizm::rysowanie() {
    this->swiat.getPlansza()[this->getPosY()][this->getPosX()] = this->getZnak();
}
int Organizm::getSila() {
    return this->sila;
}
int Organizm::getInicjatywa() {
    return this->inicjatywa;
}
int Organizm::getPosX() {
    return this->pos.first;
}
int Organizm::getPosY() {
    return this->pos.second;
}
int Organizm::getWiek() {
    return this->wiek;
}
bool Organizm::getZywy() {
    return this->jestZywy;
}
char Organizm::getZnak() {
    return this->znak;
}
string Organizm::getNazwa() {
    return this->nazwa;
}
Swiat& Organizm::getSwiat() {
    return this->swiat;
}
void Organizm::setPosX(int x) {
    this->pos.first = x;
}
void Organizm::setPosY(int y) {
    this->pos.second = y;
}
void Organizm::setZywy(bool jestZywy) {
    this->jestZywy = jestZywy;
}
void Organizm::setWiek(int wiek) {
    this->wiek = wiek;
}
void Organizm::setSila(int sila) {
    this->sila = sila;
}
vector<pair<int, int>> Organizm::wolnePola() {
    vector<pair<int, int>> wolnePozycje;
    pair <int, int> ruchy[4] = {
        {this->getPosX(),this->getPosY()+1},{this->getPosX(),this->getPosY()-1},{this->getPosX()+1,this->getPosY()},{this->getPosX()-1,this->getPosY()}
    };
    for (int i = 0; i < 4; i++) {
        if (this->getSwiat().getOrganizm(ruchy[i]) == nullptr && this->czySieMiesci(ruchy[i])) {
            wolnePozycje.push_back(ruchy[i]);
        }
    }
    return wolnePozycje;
}
pair <int, int> Organizm::wybierzWolnePole(vector<pair<int, int>> wektorPol) {
    if (!wektorPol.empty()) {
        uniform_int_distribution<int> dist(0, wektorPol.size()-1);
        int index = dist(this->getSwiat().getMt());
        return wektorPol[index];
    }
    else {
        return pair<int, int> {ERRORPOLE, ERRORPOLE};
    }
}
bool Organizm::czySieMiesci(pair <int, int> proposed) {
    return (proposed.first >= 0 && proposed.second >= 0 && proposed.first < this->swiat.getSzerkosc() && proposed.second < this->swiat.getWysokosc());
}
void Organizm::rozmnazajSie() {
    vector<pair<int, int>> wolnePola = this->wolnePola();
    pair<int, int> wskPole = this->wybierzWolnePole(wolnePola);
    if (wskPole != pair<int, int> {ERRORPOLE, ERRORPOLE}) {
        this->utworzOrganizm(wskPole, this->getSwiat());
    }
}
pair <int, int> Organizm::proponowanaPozycja(int kierunek) {
    pair <int, int> ruchy[4] = {
        {0,-1},{0,1},{-1,0},{1,0}
    };
    pair <int, int> pair = { (this->getPosX() + ruchy[kierunek].first),(this->getPosY() + ruchy[kierunek].second) };
    return pair;
}
Organizm::~Organizm() {

}