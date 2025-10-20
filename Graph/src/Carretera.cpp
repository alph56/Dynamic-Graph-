#include "Carretera.h"

Carretera::Carretera(){
    this->Nombre=Nombre;
    this->capital=capital;
    this->ID=ID;
    this->No_habitantes=No_habitantes;
    this->Turismo=Turismo;
}

Carretera::Carretera(string, string, int, string, int){
    Nombre="Unknown";
    capital="Unknown";
    ID=0;
    No_habitantes=0;
    Turismo="Unknown";
}

void Carretera::SetID(int ID){
    this->ID=ID;
}

int Carretera::GetID(void){
    return ID;
}

void Carretera::SetTurismo(string Turismo){
    this->Turismo=Turismo;
}

string Carretera::GetTurismo(void){
    return Turismo;
}

void Carretera::SetHabit(int No_habitantes){
    this->No_habitantes=No_habitantes;
}

int Carretera::GetHabit(void){
    return No_habitantes;
}

