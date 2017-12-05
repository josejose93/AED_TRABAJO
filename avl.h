#ifndef avl_h
#define avl_h

#include <iostream>
#include <string>
#include <vector>
#include "lista.h"
#include "LOrdenada.h"

using namespace std;

class Nodo
{
public:
    Nodo(string x)
    {
        m_dato = x;
        m_nodos[0] = NULL;
        m_nodos[1] = NULL;
        //jugador_lista = NULL;
    }
    Nodo *m_nodos[2]; //0 es izquierda 1 es derecha
    string m_dato;
    lista_LO jugador_l;
    //nodo<int> *jugador_lista;
};

//template <class T>
class avl
{
public:
    avl()
    {
        m_root = NULL;
    }
    ~avl();
    
    Nodo *m_root;
    
    bool buscar(string x, Nodo ** &p);
    //bool insertar(string x);
    bool insertar(string x, int camiseta, nodo_j **&jugador);
    bool borrar(string x);
    bool borrarD(string x);
    void imprimir_rango(string inicio, string fin);
    void imprimir(Nodo *p);
    
    int h(Nodo *p); //altura
    int equilibrio(Nodo *p);
    bool eq(Nodo ** p);
    
    bool rotar_derecha(Nodo *q);
    bool rotar_izquierda(Nodo *q);
    
    Nodo **rep(Nodo ** p);
    int maximo(int, int);
};

//template <class T>
avl::~avl()
{
    string x;
    while (m_root != NULL)
    {
        x = m_root->m_dato;
        borrarD(x);
    }
}

//template <class T>
bool avl::buscar(string x, Nodo **&p)
{
    for (p = &m_root; *p && (*p)->m_dato != x;p = &(*p)->m_nodos[x>(*p)->m_dato]);
    
    if ((*p) && (*p)->m_dato == x)
    {
        return 1;
    }
    return 0;
}

//template <class T>
bool avl::insertar(string x, int camiseta, nodo_j **&jugador)
{
    Nodo **p;
    if (!buscar(x, p))
    {
        Nodo *n = new Nodo(x);
        (*p) = n;
        //(*p)->jugador_l.insertar(camiseta, jugador);
        //cout << ((*p)->jugador_l.head)->jugador_ptr->apellido << endl;
        //return 0;
    }
    (*p)->jugador_l.insertar(camiseta, jugador);
    
    
    //equilibrar
    eq(&m_root);
    return 1;
}

//bool avl::insertar(string x)
//{
//	Nodo **p;
//	if (buscar(x, p)) { return 0; }
//	Nodo *n = new Nodo(x);
//	(*p) = n;
//
//	//equilibrar
//	eq(&m_root);
//
//	return 1;
//}

//template <class T>
bool avl::borrar(string x)
{
    Nodo **p;
    if (!buscar(x, p)) return 0;
    if ((*p)->m_nodos[0] && (*p)->m_nodos[1])
    {
        Nodo **q = rep(p);
        (*p)->m_dato = (*q)->m_dato;
        p = q;
    }
    Nodo *t = *p;
    *p = (*p)->m_nodos[(*p)->m_nodos[1] != 0];
    delete t;
    
    //equilibrar
    eq(&m_root);
    return 1;
}

//template<class T>
bool avl::borrarD(string x)
{
    Nodo **p;
    if (!buscar(x, p)) return 0;
    if ((*p)->m_nodos[0] && (*p)->m_nodos[1])
    {
        Nodo **q = rep(p);
        (*p)->m_dato = (*q)->m_dato;
        p = q;
    }
    Nodo *t = *p;
    *p = (*p)->m_nodos[(*p)->m_nodos[1] != 0];
    delete t;
    return 1;
}

void avl::imprimir_rango(string inicio, string fin)
{
    //if (buscar(inicio));
}

//template<class T>
void avl::imprimir(Nodo*p)
{
    if (p)
    {
        cout << p->m_dato << "  ";
        //cout << endl;
        imprimir(p->m_nodos[0]);
        imprimir(p->m_nodos[1]);
    }
}

//template <class T>
Nodo** avl::rep(Nodo ** p)
{
    p = &(*p)->m_nodos[0]; //1 derecha 0 izq
    while ((*p)->m_nodos[1] != NULL)
        p = &(*p)->m_nodos[1];
    return p;
}

//funciones equilibrio altura
//template <class T>
int avl::h(Nodo *p)
{
    if (!p)return 0;
    
    return maximo(h(p->m_nodos[0]) + 1, h(p->m_nodos[1]) + 1);
}

//template <class T>
int avl::maximo(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

//template <class T>
int avl::equilibrio(Nodo *p)
{
    return h(p->m_nodos[1]) - h(p->m_nodos[0]);
}
//--------------------funcion para el reequilibrio------////

//template <class T>
bool avl::eq(Nodo **p)
{
    if (!(*p)->m_nodos[0] && !(*p)->m_nodos[1]) return 0;
    int r, h;
    r = equilibrio(*p); // r es el padre
    h = equilibrio((*p)->m_nodos[r>0]); // h es el hijo donde esta el desequilibrio
    while (h != -1 && h != 0 && h != 1)
    {
        p = &(*p)->m_nodos[r>0];
        r = equilibrio(*p);
        h = equilibrio((*p)->m_nodos[r>0]);
    }
    if (r != -1 && r != 0 && r != 1)
    {
        //casos
        if (r>0)
        {
            if (h>0)rotar_izquierda(*p);
            else
            {
                rotar_derecha((*p)->m_nodos[1]);
                rotar_izquierda(*p);
            }
        }
        else
        {
            if (h<0)rotar_derecha(*p);
            else
            {
                rotar_izquierda((*p)->m_nodos[0]);
                rotar_derecha(*p);
            }
        }
    }
    if ((*p)->m_nodos[0])
        eq(&(*p)->m_nodos[0]);
    if ((*p)->m_nodos[1])
        eq(&(*p)->m_nodos[1]);
    return 1;
}

//template <class T>
bool avl::rotar_derecha(Nodo *q)
{
    Nodo **p;
    buscar(q->m_dato, p);
    *p = q->m_nodos[0];
    if (!!q->m_nodos[0]->m_nodos[1])
        q->m_nodos[0] = q->m_nodos[0]->m_nodos[1];
    else
        q->m_nodos[0] = NULL;
    (*p)->m_nodos[1] = q;
    return 1;
}

//template <class T>
bool avl::rotar_izquierda(Nodo *q)
{
    Nodo **p;
    buscar(q->m_dato, p);
    *p = q->m_nodos[1];
    if (!!q->m_nodos[1]->m_nodos[0])
        q->m_nodos[1] = q->m_nodos[1]->m_nodos[0];
    else
        q->m_nodos[1] = NULL;
    (*p)->m_nodos[0] = q;
    return 1;
}




#endif /* avl_h */
