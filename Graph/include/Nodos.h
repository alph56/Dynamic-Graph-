#ifndef NODOS_H
#define NODOS_H
#include "Carretera.h"

class NodoArista;

class NodoVertice{
    public:
        Carretera dato;

        NodoVertice*SigVertice;
        NodoArista*HArista;

        NodoVertice(){
            dato.capital="Unknown";
            dato.Nombre="Unknown";
            SigVertice=nullptr;
            HArista=nullptr;
        };

        NodoVertice(Carretera dato,NodoVertice*SigVertice,NodoArista*HArista){
            this->dato=dato;
            this->HArista=HArista;
            this->SigVertice=SigVertice;
        }
};

class NodoArista{
    public:
        int costo;
        NodoArista*SigArista;
        NodoVertice*destino;

        NodoArista(){
            costo=0;
            SigArista=nullptr;
            destino=nullptr;
        }

        NodoArista(int costo,NodoArista*SigArista,NodoVertice*destino){
            this->costo=costo;
            this->SigArista=SigArista;
            this->destino=destino;
        }
};

#endif // NODOS_H
