#include <iostream>
#include"Grafo.h"

int main(){
    ///Idioma:Español
    setlocale(LC_CTYPE, "Spanish");
    ///OBJETOS
    Grafo*Grafito=new Grafo();

    ///Interacciones
    unsigned opcion;

    do{
        system("cls");
        cout<<"\t\t\tRegistro de Carreteras"<<endl;
        cout<<"\t\tMen� Principal"<<endl;
        cout<<"1.-Guardar en archivo"<<endl;
        cout<<"2.-Cargar archivo"<<endl;
        cout<<"3.-Salir"<<endl;
        cout<<"Inserte una opci�n: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                Grafito->menu01(Grafito);
                break;
            case 2:
                Grafito->menudefault(Grafito,opcion);
                break;
            case 3:
                Grafito->menudefault(Grafito,opcion);
                break;
            default:
                Grafito->menudefault(Grafito,opcion);
                break;
        };
    }while(opcion!=3);

    return 0;
}
