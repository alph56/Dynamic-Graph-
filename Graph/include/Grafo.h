#ifndef GRAFO_H
#define GRAFO_H
#include "Nodos.h"
#include<locale.h>
#include <windows.h>
#include <fstream> //guardar fichero
#include<cstdlib>

class Grafo{
    public:
        NodoVertice*HGrafo;
        Grafo();

        ///Otros
        Carretera Ingreso(void);
        void ImprimirVer(NodoVertice*);
        void ImprimirArist(NodoArista*);
        void GuardarVer(NodoVertice*);
        void GuardarArist(NodoVertice*,NodoArista*);

        ///Sub-menús
        void menu01(Grafo*);
        void menu02(Grafo*);
        void menu03(Grafo*);
        void menu04(Grafo*);
        void menudefault(Grafo*,int);


        ///Métodos
        void InsertarVertice(Carretera);

        void InsertarArista(string,string,int);
        NodoVertice* BuscarVertice(string);

        void MostrarGrafo(void);
        void MostrarGrafoProp(void);

        void EliminarVertice(string);

        void EliminarArista(string,string);
        void EliminarAllarista(NodoVertice*);

        void EliminarTodoGrafo(void);

        ///Archivos
        void ToFile(void);
        void LeerVertices(void);
        void LeerAristas(void);
};

#endif // GRAFO_H
