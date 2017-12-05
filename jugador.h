#ifndef jugador_h
#define jugador_h
#include <iostream>
#include <string>
#include "lista.h"
#include "avl.h"
#include "LOrdenada.h"

using namespace std;

//numero camiseta
//apellido
//edad
//seleccion
//posicion

class jugador
{
public:
    jugador();
    ~jugador();
    
    bool insertar_j(int camiseta, string apellido, string edad, string seleccion, string posicion);
    bool borrar_j(int camiseta, string apellido, string edad, string seleccion, string posicion);
    bool borrar_jv2(int id);
    void mostrar_jugadores();
    void mostrar_selecion(string seleccion);
    void mostrar_posicion(string posicion);
    void mostrar_edad(string edad_max, string edad_min);
    
    //bool borrar_seleccion(int camiseta);
    //bool borrar_posicion();
    //bool borrar_edad();
    
    lista_j j;
    avl pais_avl; //por seleccion
    avl posicion_avl; //por posicion de juego
    avl edad_avl; // por edad de los jugadores
};

jugador::jugador()
{
    //lista_j j;
    //avl<string> pais; //por seleccion
    //avl<string> posicion; //por posicion de juego
    //avl<string> edad; // por edad de los jugadores
}

jugador::~jugador()
{
}

bool jugador::insertar_j(int camiseta, string apellido, string edad, string seleccion, string posicion)
{
    nodo_j **p; //puntero al nodo que estoy insertando
    j.insertar(camiseta, apellido, edad, seleccion, posicion, p);
    
    pais_avl.insertar(seleccion, camiseta, p);
    posicion_avl.insertar(posicion, camiseta, p);
    edad_avl.insertar(edad, camiseta, p);
    
    return 0;
}

bool jugador::borrar_jv2(int id)
{
    nodo_j **p;
    nodo_j **ptr_posicion;
    nodo_j **ptr_edad;
    Nodo **k;
    Nodo **ktr_posicion;
    Nodo **ktr_edad;
    
    j.buscar(id, p);
    ptr_posicion = p;
    ptr_edad = p;
    
    pais_avl.buscar((*p)->seleccion, k);
    posicion_avl.buscar((*ptr_posicion)->posicion, ktr_posicion);
    edad_avl.buscar((*ptr_edad)->edad, ktr_edad);
    //cout << "aqui" << (*ktr_edad)->m_dato << endl;
    
    (*k)->jugador_l.borrar_id(id);
    
    (*ktr_posicion)->jugador_l.borrar_id(id);
    
    (*ktr_edad)->jugador_l.borrar_id(id);
    //cout << "aqui" << endl;
    
    j.borrar(id);
    
    return 1;
}

bool jugador::borrar_j(int camiseta, string apellido, string edad, string seleccion, string posicion)
{
    Nodo **p_pais;
    Nodo **p_posicion;
    Nodo **p_edad;
    pais_avl.buscar(seleccion, p_pais);
    posicion_avl.buscar(posicion, p_posicion);
    edad_avl.buscar(edad, p_edad);
    //(*p_pais)->jugador_l.borrar();
    //(*p_posicion)->jugador_l.borrar();
    //(*p_edad)->jugador_l.borrar();
    return 0;
}

void jugador::mostrar_jugadores()
{
    j.mostrar();
    cout << "-------------------------" << endl;
}

void jugador::mostrar_selecion(string seleccion)
{
    //pais.imprimir(pais.m_root);
    Nodo **p;
    pais_avl.buscar(seleccion, p);
    cout << "---------------*****SELECCION*****------------------------" << endl;
    (*p)->jugador_l.mostrar();
}

void jugador::mostrar_posicion(string posicion)
{
    Nodo **p;
    posicion_avl.buscar(posicion, p);
    cout << "---------------*****POSICION*****------------------------" << endl;
    (*p)->jugador_l.mostrar();
}

void jugador::mostrar_edad(string edad_max, string edad_min)
{
    Nodo **p;
    //cout << "aqui" << endl;
    int f = atoi(edad_max.c_str());
    int i = atoi(edad_min.c_str());
    cout << "---------------*****EDADES*****------------------------" << endl;
    for (i;i<=f;i++)
    {
        if(edad_avl.buscar(to_string(i), p))
            (*p)->jugador_l.mostrar();
    }
    /*edad_avl.buscar(edad_min, p);
     (*p)->jugador_l.mostrar();*/
}
#endif /* jugador_h */
