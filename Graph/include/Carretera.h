#ifndef CARRETERA_H
#define CARRETERA_H
#include <iostream>

using namespace std;

class Carretera{
    public:
        Carretera();
        Carretera(string,string,int,string,int);

        string Nombre;
        string capital;

        void SetID(int);
        int GetID(void);

        void SetTurismo(string);
        string GetTurismo(void);

        void SetHabit(int);
        int GetHabit(void);
    private:
        int ID;
        string Turismo;
        int No_habitantes;

};

#endif // CARRETERA_H
