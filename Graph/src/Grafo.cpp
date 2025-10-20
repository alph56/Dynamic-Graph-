#include "Grafo.h"

Grafo::Grafo(){
    HGrafo=nullptr;
}

Carretera Grafo::Ingreso(void){
    Carretera c1;
    int nuevID,nuevH;
    string nuevTur;

    system("cls");
    system("Color c0");
    cout<<"Ingrese el Nombre del país: ";
    cin>>c1.Nombre;
    cout<<"Ingrese el nombre alguna ciudad del país: ";
    cin>>c1.capital;
    cout<<"Ingrese el ID: ";
    cin>>nuevID;
    c1.SetID(nuevID);
    cout<<"Ingrese una atracción turistica de la ciudad: ";
    cin>>nuevTur;
    c1.SetTurismo(nuevTur);
    cout<<"Ingrese el número de habitantes: ";
    cin>>nuevH;
    c1.SetHabit(nuevH);

    return c1;
}

void Grafo::menu02(Grafo*Grafito){
    string tmpdestino, tmpOrig;
    int tmpCost;
    unsigned save;
        system("cls");
        system("Color 04");
        cout<<"1.-Insertar nueva carretera"<<endl;
        cout<<"2.-Ingresar nueva conexión entre carreteras"<<endl;
        cout<<"3.-Regresar al menú anterior"<<endl;
        cout<<"---->Inserte una opción: ";
        cin>>save;
        switch(save){
            case 1:
                Grafito->InsertarVertice(Ingreso());
                system("pause");
                break;
            case 2:
                system("cls");
                cout<<"Ingrese la Carretera de Origen: ";
                cin>>tmpOrig;
                cout<<"\nIngrese la Carretera de Destino ";
                cin>>tmpdestino;
                cout<<"\nIngrese el costo: ";
                cin>>tmpCost;
                Grafito->InsertarArista(tmpOrig,tmpdestino,tmpCost);
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Regresando...."<<endl;
                system("pause");
                break;
            default:
                system("cls");
                cout<<"opción no válida"<<endl;
                system("pause");
                break;
        };
}

void Grafo::menu03(Grafo*Grafito){
    unsigned opc;
    string eliminarVer,tmpOrig,eliminardestino;
    system("cls");
    system("Color 0d");
    cout<<"1.-Eliminar origen de una Carretera"<<endl;
    cout<<"2.-Eliminar Conexión de un País"<<endl;
    cout<<"3.-Regresar al menú anterior: "<<endl;
    cout<<"Ingrese una opción: ";
    cin>>opc;
    switch(opc){
        case 1:
            system("cls");
            cout<<"Ingrese el país de origen: ";
            cin>>eliminarVer;
            Grafito->EliminarVertice(eliminarVer);
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"Ingrese el país de origen: ";
            cin>>tmpOrig;
            cout<<"Ingrese el país de Conexión a eliminar: ";
            cin>>eliminardestino;
            Grafito->EliminarArista(tmpOrig,eliminardestino);
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"Regresando...."<<endl;
            system("pause");
            break;
        default:
            system("cls");
            cout<<"opción no válida"<<endl;
            system("pause");
            break;
    };
}

void Grafo::menu04(Grafo*Grafito){
    unsigned answer;
    system("cls");
    system("Color 03");
    cout<<"1.-Ver Grafo de manera simple"<<endl;
    cout<<"2.-Ver Grafo con todas sus propiedades"<<endl;
    cout<<"3.-Regresar al menú anterior"<<endl;
    cout<<"--->Ingrese una opción: ";
    cin>>answer;
    switch(answer){
        case 1:
            system("cls");
            cout<<"---->Grafo simple\n"<<endl;
            Grafito->MostrarGrafo();
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"---->Grafo complejo\n"<<endl;
            Grafito->MostrarGrafoProp();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"Regresando...."<<endl;
            system("pause");
            break;
        default:
            system("cls");
            cout<<"Opción NO válida"<<endl;
            system("pause");
            break;
    };
}

void Grafo::menudefault(Grafo*Grafito,int opcion){
    system("cls");
    system("Color 08");
        switch(opcion){
            case 2:
                system("cls");
                //cout<<"Trabajo en procedimiento (ver archivos)"<<endl;
                Grafito->LeerVertices();
                Grafito->LeerAristas();
                system("pause");
                break;
            case 3:
                system("cls");
                cout<<"Fin del programa...."<<endl;
                system("pause");
                break;
            default:
                system("cls");
                cout<<"Opción No válida"<<endl;
                system("pause");
                break;
        };
}

void Grafo::menu01(Grafo*Grafito){
    unsigned answer;
    do{
        system("cls");
        cout<<"\t\tMenú Guardar"<<endl;
        cout<<"1.-Dar de Alta"<<endl;
        cout<<"2.-Dar de Baja"<<endl;
        cout<<"3.-Consultar"<<endl;
        cout<<"4.-Regresar al menú principal"<<endl;
        cout<<"\nNota:Al regresar al menú principal los datos se guardarán en archivos txt automaticamente"<<endl;
        cout<<"---->Inserte una opción: ";
        cin>>answer;
        switch(answer){
            case 1:
                Grafito->menu02(Grafito);
                break;
            case 2:
                Grafito->menu03(Grafito);
                break;
            case 3:
                Grafito->menu04(Grafito);
                break;
            case 4:
                system("cls");
                cout<<"---->Regresando al menú principal"<<endl;
                system("pause");
                cout<<"\n--->Guardando datos en archivos de texto"<<endl;
                Grafito->ToFile();
                system("pause");
                break;
            default:
                system("cls");
                cout<<"Opción NO válida"<<endl;
                system("pause");
                break;
        };
    }while(answer!=4);
}


void Grafo::InsertarVertice(Carretera c1){
    NodoVertice*tmp=new NodoVertice(c1,nullptr,nullptr);
    if(!HGrafo)
        HGrafo=tmp;
    else{
        NodoVertice*aux=HGrafo;
        while(aux->SigVertice){
          aux=aux->SigVertice;
        }
        aux->SigVertice=tmp;
    }
}

void Grafo::InsertarArista(string origen, string destino, int costo){
    NodoVertice*auxVer=HGrafo;
    bool band=true;
    if(auxVer){
        while(auxVer and band){
            if(auxVer->dato.Nombre==origen)
                band=false;
            else
                auxVer=auxVer->SigVertice;
        }
        if(!auxVer)
            cout<<"Origen not found"<<endl;
        else{
            NodoVertice*verticeDestino=BuscarVertice(destino);

            if(!verticeDestino)
                cout<<"Destino not found"<<endl;
            else{
                NodoArista*auxArista=auxVer->HArista;
                NodoArista*tmpArista=new NodoArista(costo,nullptr,verticeDestino);
                if(!auxArista)
                    auxVer->HArista=tmpArista;
                else{
                    while(auxArista->SigArista)
                        auxArista=auxArista->SigArista;

                    auxArista->SigArista=tmpArista;
                }
            }
        }
    }
}

NodoVertice* Grafo::BuscarVertice(string destino){
    NodoVertice*aux=HGrafo;
    bool band=true;
    if(aux){
        while(aux and band){
            if(aux->dato.Nombre==destino)
                band=false;
            else
                aux=aux->SigVertice;
        }
    }
    return aux;
}

void Grafo::MostrarGrafo(void){
    if(!HGrafo)
        cout<<"Grafo Vacio"<<endl;
    else{
        NodoVertice*auxVer=HGrafo;
        while(auxVer){
              cout<<"Vertice: ";
              cout<<auxVer->dato.Nombre<<endl;
              cout<<"\n";
              if(auxVer->HArista){
                NodoArista*tmpArista=auxVer->HArista;
                cout<<"Aristas: "<<endl;
                while(tmpArista!=nullptr){
                    cout<<"---->"<<tmpArista->destino->dato.Nombre<<endl;
                    tmpArista=tmpArista->SigArista;
                }
              }
              else{
                cout<<"Este vertice no tiene aristas\n"<<endl;
              }
              cout<<"\n";
              auxVer=auxVer->SigVertice;
        }
    }
}

void Grafo::ImprimirVer(NodoVertice*auxVer){
    cout<<"Nombre del País: "<<auxVer->dato.Nombre<<endl;
    cout<<"Capital del País: "<<auxVer->dato.capital<<endl;
    cout<<"ID: "<<auxVer->dato.GetID()<<endl;
    cout<<"Lugar Turistico: "<<auxVer->dato.GetTurismo()<<endl;
    cout<<"No. Habitantes: "<<auxVer->dato.GetHabit()<<endl;
}

void Grafo::GuardarVer(NodoVertice*auxVer){
    ofstream guardarVer;
    if(auxVer){
        while(auxVer){
            guardarVer.open("vertices.txt",ios::app);
            guardarVer<<auxVer->dato.Nombre<<"|"<<auxVer->dato.capital<<"|"<<auxVer->dato.GetTurismo()
            <<"|"<<auxVer->dato.GetHabit()<<"|"<<auxVer->dato.GetID()<<"*"<<endl;
            auxVer=auxVer->SigVertice;
        }
    }
    guardarVer.close();
}

void Grafo::GuardarArist(NodoVertice*auxVer,NodoArista*auxArist){
    ofstream guardarArist;
    if(auxVer->HArista){
        auxArist=auxVer->HArista;
        while(auxArist){
            guardarArist.open("aristas.txt",ios::app);
            guardarArist<<auxVer->dato.Nombre<<"|"<<auxArist->destino->dato.Nombre<<"|"<<auxArist->destino->dato.capital
            <<"|"<<auxArist->destino->dato.GetTurismo()<<"|"<<auxArist->destino->dato.GetHabit()
            <<"|"<<auxArist->destino->dato.GetID()<<"|"<<auxArist->costo<<"*"<<endl;
            auxArist=auxArist->SigArista;
        }
        auxVer=auxVer->SigVertice;
    }
    guardarArist.close();
}


void Grafo::ImprimirArist(NodoArista*auxArist){
    cout<<"Nombre del País: "<<auxArist->destino->dato.Nombre<<endl;
    cout<<"Capital del País: "<<auxArist->destino->dato.capital<<endl;
    cout<<"ID: "<<auxArist->destino->dato.GetID()<<endl;
    cout<<"Lugar Turistico: "<<auxArist->destino->dato.GetTurismo()<<endl;
    cout<<"No. Habitantes: "<<auxArist->destino->dato.GetHabit()<<endl;
}

void Grafo::MostrarGrafoProp(void){
    if(!HGrafo)
        cout<<"Grafo Vacio"<<endl;
    else{
        NodoVertice*auxVer=HGrafo;
        while(auxVer){
              cout<<"Vertice: "<<endl;
              ImprimirVer(auxVer);
              cout<<"\n";
              if(auxVer->HArista){
                NodoArista*tmpArista=auxVer->HArista;
                cout<<"Aristas: "<<endl;
                while(tmpArista!=nullptr){
                    cout<<"---->"<<tmpArista->destino->dato.Nombre<<endl;
                    ImprimirArist(tmpArista);
                    tmpArista=tmpArista->SigArista;
                }

              }
              else{
                cout<<"Este vertice no tiene aristas\n"<<endl;
              }
              cout<<"\n";
              auxVer=auxVer->SigVertice;
        }
    }
}

void Grafo::EliminarVertice(string eliminarVer){
    NodoVertice*VerticeAnt=nullptr;
    NodoVertice*VerticeLocal=HGrafo;
    bool band=true;

    if(VerticeLocal){
        while(VerticeLocal and band){
            if(VerticeLocal->dato.Nombre==eliminarVer)
                band=false;
            else{
                VerticeAnt=VerticeLocal;
                VerticeLocal=VerticeLocal->SigVertice;
            }
        }
    }

    if(VerticeLocal==nullptr)
        cout<<"Origen no válido"<<endl;
    else if(VerticeLocal==HGrafo){
        EliminarAllarista(VerticeLocal);
        HGrafo=HGrafo->SigVertice;
        delete VerticeLocal;
    }
    else if(!VerticeLocal->SigVertice){
        EliminarAllarista(VerticeLocal);
        VerticeAnt->SigVertice=nullptr;
        delete VerticeLocal;
    }
    else{
        EliminarAllarista(VerticeLocal);
        VerticeAnt->SigVertice=VerticeLocal->SigVertice;
        delete VerticeLocal;
    }
}

void Grafo::EliminarAllarista(NodoVertice*auxVert){
    if(!auxVert->HArista){
        cout<<"No hay aristas disponibles"<<endl;
    }
    else{
        NodoArista*auxArist;
        while(auxVert->HArista){
            auxArist=auxVert->HArista;
            auxVert->HArista=auxVert->HArista->SigArista;
            delete auxArist;
        }
    }
}


void Grafo::EliminarTodoGrafo(void){
    if(!HGrafo)
        cout<<"Grafo vácio"<<endl;
    else{
        NodoVertice*auxVert=nullptr;
        while(HGrafo){
            auxVert=HGrafo;
            EliminarAllarista(auxVert);
            HGrafo=HGrafo->SigVertice;
            delete auxVert;
        }
    }
}

void Grafo::EliminarArista(string origen, string eliminardestino){
    NodoVertice*Verticelocal=BuscarVertice(origen);
    if(Verticelocal==nullptr)
        cout<<"Origen no válido"<<endl;
    else{
        NodoArista*antArist=nullptr;
        NodoArista*auxArist=Verticelocal->HArista;
        bool band=true;
        if(auxArist){
            while(auxArist and band){
                if(auxArist->destino->dato.Nombre==eliminardestino)
                    band=false;
                else{
                    antArist=auxArist;
                    auxArist=auxArist->SigArista;
                }
            }
        }
        if(!auxArist)
            cout<<"Destino a eliminar no válido"<<endl;
        else if(auxArist==Verticelocal->HArista){
            Verticelocal->HArista=Verticelocal->HArista->SigArista;
            delete auxArist;
        }
        else if(!auxArist->SigArista){
            antArist->SigArista=nullptr;
            delete auxArist;
        }
        else{
            antArist->SigArista=auxArist->SigArista;
            delete auxArist;
        }
    }
}

void Grafo::ToFile(void){
    NodoVertice*auxVer=HGrafo;
    if(auxVer){
        GuardarVer(auxVer);
        GuardarArist(auxVer,auxVer->HArista);
    }
}

void Grafo::LeerVertices(void){
    ifstream leerVer;
    leerVer.open("vertices.txt");
    if(!leerVer.is_open()){
        cout<<"Error al abrir el archivo de vertices"<<endl;
        return;
    }
    cout<<"---->Lista de Vertices:"<<endl;
    string cadena;
    int i = 1;
    system("Color 0A");
    do {
        cout << "Registro num: " << i << endl;
        getline(leerVer, cadena, '|');
        cout << "\tPaís: "<< cadena << endl;
        getline(leerVer, cadena, '|');
        cout << "\tCiudad: "<< cadena << endl;
        getline(leerVer, cadena, '|');
        cout << "\tAtracción: "<< cadena << endl;
        getline(leerVer, cadena, '|');
        cout << "\tNo° Habitantes: "<< cadena << endl;
        getline(leerVer, cadena, '*');
        cout << "\tID: "<< cadena << endl;
        getline(leerVer,cadena,'\n');
        cout<<endl;
        i++;
    }while(!leerVer.eof());
    leerVer.close();
    system("pause");
}

void Grafo::LeerAristas(void){
    ifstream leerArist;
    leerArist.open("aristas.txt");
    if(!leerArist.is_open()){
        cout<<"Error al abrir el archivo de aristas"<<endl;
        return;
    }
    system("cls");
    system("Color 09");
    cout<<"\n---->Lista de Aristas:"<<endl;
    string cadena;
    int i = 1;
    do {
        cout << "Registro num: " << i << endl;
        getline(leerArist, cadena, '|');
        cout <<"\tOrigen: " << cadena << "\n" << endl;
        getline(leerArist, cadena, '|');
        cout << "\tPaís: " << cadena << endl;
        getline(leerArist, cadena, '|');
        cout << "\tCiudad: " << cadena << endl;
        getline(leerArist, cadena, '|');
        cout << "\tAtracción: " << cadena << endl;
        getline(leerArist, cadena, '|');
        cout << "\tNo° Habitantes: " << cadena << endl;
        getline(leerArist, cadena, '|');
        cout << "\tID: " << cadena << endl;
        getline(leerArist, cadena, '*');
        cout << "\tCosto: " << cadena << endl;
        getline(leerArist,cadena,'\n');
        cout<<endl;
        i++;
    }while(!leerArist.eof());
    leerArist.close();
}
