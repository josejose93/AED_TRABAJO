#ifndef LOrdenada_h
#define LOrdenada_h
#include <iostream>
#include "lista.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class nodo_LO
{
public:
    int dato;
    nodo_LO *sig;
    nodo_j *jugador_ptr;
    nodo_LO(int x, nodo_j **&jugador)
    {
        dato = x;
        jugador_ptr = *jugador;
        sig = NULL;
    }
};

class lista_LO
{
public:
    lista_LO();
    ~lista_LO();
    nodo_LO *head;
    
    bool buscar(int x, nodo_LO **&p);
    bool insertar(int x, nodo_j **&k);
    bool buscar_id(int x, nodo_LO **&p);
    bool borrar_id(int id_);
    bool mostrar();
protected:
};

lista_LO::lista_LO()
{
    head = NULL;
}

lista_LO::~lista_LO()
{
}

bool lista_LO::buscar(int x, nodo_LO **&p)
{
    p = &head;
    while (*p && (*p)->dato < x)
    {
        p = &((*p)->sig);
    }
    /*if( *p && (*p)->dato == x )
     {
     return 1;
     }*/
    //cout<<*p<<endl;
    return 0;
}

bool lista_LO::insertar(int x, nodo_j **&k)
{
    nodo_LO **p;
    if (buscar(x, p))
    {
        return 0;
    }
    nodo_LO *t = new nodo_LO(x, k);
    t->sig = *p;
    *p = t;
    //t->jugador_ptr = *k;
    return 1;
}


bool lista_LO::buscar_id(int x, nodo_LO **& p)
{
    //p= &head;
    /*
     while (*p && (*p)->jugador_ptr->id > x )
     {
     p = &((*p)->sig);
     }*/
    for (p = &head; *p && x>(*p)->jugador_ptr->id; p = &((*p)->sig));
    
    if ((*p) && x == (*p)->jugador_ptr->id)
    {
        return 1;
    }
    /*if( *p && (*p)->dato == x )
     {
     return 1;
     }*/
    //cout<<*p<<endl;
    return 0;
}


bool lista_LO::borrar_id(int id_)
{
    nodo_LO **p;
  //  cout << "aqui" << endl;
    if (!buscar_id(id_, p)) {
        return 0;
    }
    
    nodo_LO *t = *p;
    //cout << "Borrar Lista_Or: " << mostrar() << endl;
    //cout << "jugador Lista_Or: " << t->dato << endl;
    *p = (*p)->sig;
    
    delete t;
    //cout << "jugador Lista_Or: " << (*p)->dato << endl;
    return 1;
}

bool lista_LO::mostrar()
{
    nodo_LO **p = &head;
    //cout << head << endl;
    int i = 0;
    while (*p)
    {
        cout << "Camiseta:\t"<< (*p)->dato << endl;
        cout << "Apellido:\t" << (*p)->jugador_ptr->apellido << endl;
        cout << "Posicion:\t" << (*p)->jugador_ptr->posicion << endl;
        cout << "Pais:\t" << (*p)->jugador_ptr->seleccion << endl;
        cout << "Edad:\t" << (*p)->jugador_ptr->edad << endl;
        cout << "----------" << endl;
        p = &((*p)->sig);
    }
    return 0;
}
#endif /* LOrdenada_h */
