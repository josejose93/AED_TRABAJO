#ifndef lista_h
#define lista_h
#include <iostream>
#include <string>

using namespace std;

class nodo_j
{
public:
    int camiseta;
    string apellido;
    string edad;
    string seleccion;
    string posicion;
    int id;
    nodo_j *sig;
    nodo_j(int camiseta_x, string apellido_x, string edad_x, string seleccion_x, string posicion_x)
    {
        camiseta = camiseta_x;
        apellido = apellido_x;
        edad = edad_x;
        seleccion = seleccion_x;
        posicion = posicion_x;
        sig = NULL;
    }
};

class lista_j
{
public:
    lista_j() {}
    ~lista_j() {}
    nodo_j *head = NULL;
    
    bool buscar(nodo_j **&p);
    bool buscar(int id, nodo_j **&p);
    bool buscar_B(int camiseta_x, string apellido_x, string edad_x, string seleccion_x, string posicion_x, nodo_j **&p);
    //bool insertar(int camiseta, string apellido, int edad, string seleccion, string posicion);
    bool insertar(int camiseta, string apellido, string edad, string seleccion, string posicion, nodo_j **&p);
    bool borrar(int camiseta_x, string apellido_x, string edad_x, string seleccion_x, string posicion_x, nodo_j **&p);
    bool borrar(int id_);
    bool mostrar();
    
    int cont = 0;
};

bool lista_j::buscar(nodo_j **&p)
{
    p = &head;
    while (*p)
    {
        p = &((*p)->sig);
    }
    return 0;
}

bool lista_j::buscar(int id_, nodo_j **&p)
{
    
    /*
     p = &head;
     while (*p && id<(*p)->id)
     {
     p = &((*p)->sig);
     }*/
    //cout<<"llega el buscar antes del for? :"<<endl;
    for (p = &head; *p && id_>(*p)->id; p = &((*p)->sig));
    
    // cout<<"llega el buscar despeus del for? :"<<(*p)->id<<endl;
    if ((*p) && id_ == (*p)->id)
        return 1;
    
    return 0;
    
}

bool lista_j::buscar_B(int camiseta_x, string apellido_x, string edad_x, string seleccion_x, string posicion_x, nodo_j **&p)
{
    p = &head;
    while (*p && (*p)->apellido != apellido_x && (*p)->seleccion != seleccion_x && (*p)->edad != edad_x && (*p)->posicion != posicion_x && (*p)->camiseta != camiseta_x)
    {
        p = &((*p)->sig);
    }
    if (*p && (*p)->apellido == apellido_x && (*p)->seleccion == seleccion_x && (*p)->edad == edad_x && (*p)->posicion == posicion_x && (*p)->camiseta == camiseta_x)
    {
        return 1;
    }
    return 0;
}

bool lista_j::insertar(int camiseta, string apellido, string edad, string seleccion, string posicion, nodo_j **&p)
{
    //nodo_j **p;
    buscar(p);
    nodo_j *j = new nodo_j(camiseta, apellido, edad, seleccion, posicion);
    //j->sig = *p;
    *p = j;
    cont++;
    j->id = cont;
    return 1;
}

bool lista_j::borrar(int camiseta_x, string apellido_x, string edad_x, string seleccion_x, string posicion_x, nodo_j **&p)
{
    //nodo_j **p;
    if (!buscar_B(camiseta_x, apellido_x, edad_x, seleccion_x, posicion_x, p))
    {
        return 0;
    }
    
    return 1;
}

bool lista_j::borrar(int id_)
{
    nodo_j ** p;
    if (!buscar(id_, p)) {
        return 0;
    }
    nodo_j *t = *p;
    
    
    *p = (*p)->sig;
    delete t;
    return 1;
    
    return 0;
}

bool lista_j::mostrar()
{
    nodo_j **p = &head;
    cout<<endl;
    while (*p)
    {
        //cout << "--------------jugador:" << endl;
        cout<< "ID:  "<<(*p)->id<<"\tCAMISETA:  "<< (*p)->camiseta<<"\tAPELLIDO:  "<<(*p)->apellido<<
        "\tPOSICION:  "<<(*p)->posicion<<"\tEDAD:  "<<(*p)->edad<<"\tSELECCION:  "<<(*p)->seleccion<< endl;
        //cout << (*p)->seleccion << endl;
        p = &((*p)->sig);
    }
    cout<<endl;
    return 0;
}
#endif /* lista_h */
