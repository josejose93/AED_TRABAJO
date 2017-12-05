#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "avl.h"
#include "lista.h"
#include "jugador.h"
#include "LOrdenada.h"

using namespace std;

int tam(char b[]){
	int i = 0;
	while (b[i] != '\0')
		i++;
	return i;
}

string arc_load(char * dir, string d, string n, string e, string pa, string po, jugador &j)
{
	string sal;
    char buf [1000];
	ifstream arc;
    arc.open(dir);
    while(arc)
    {
        arc.getline(buf,1000,'.');
        //arc>>buf;
		//cout<<buf<<" ";
		int i = 0, x = 0, t = tam(buf);
		//cout<< t;
		while (i < t){
			if (buf[i] == ' '){
				x++;
				i++;
			}
			if (x == 0)
				d+=buf[i];
			if (x == 1)
				n+=buf[i];
			if (x == 2)
				e+=buf[i];
			if (x == 3)
				pa+=buf[i];
			if (x == 4)
				po+=buf[i];
			i++;
		}
		int value = atoi(d.c_str());
		j.insertar_j(value, n, e, pa, po);
		d="";
		n="";
		e="";
		pa="";
		po="";
    }
    arc.close();
    return sal;
}
int main(int argc, const char* argcv[])
{
    
    jugador k;
    int opcion = -1;
    string d = "";
    string n = "";
    string e = "";
    string pa = "";
    string po = "";
    arc_load("jugadores.txt", d, n, e, pa, po, k);
    cout << "-----------------------------------------------------------------------" << endl;
    cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
    cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
    cout<< "2. Mostrar jugadores por seleccion." << endl;
    cout<< "3. Mostrar jugadores por posicion." << endl;
    cout<< "4. Mostrar jugadores por rango de edades." << endl;
    cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
    cout<< "6. Salir"<< endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cin>> opcion;
    while (opcion != 6){
        if (opcion == 1){
            k.mostrar_jugadores();
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
        else if (opcion == 2){
            int opcion_s;
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Peru" << endl;
            cout<< "2. Argentina" << endl;
            cout<< "3. Colombia" << endl;
            cin>> opcion_s;
            if (opcion_s == 1)
                k.mostrar_selecion("Peru");
            if (opcion_s == 2)
                k.mostrar_selecion("Argentina");
            if (opcion_s == 3)
                k.mostrar_selecion("Colombia");
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
        else if (opcion == 3){
            int opcion_p;
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Portero" << endl;
            cout<< "2. Defensa" << endl;
            cout<< "3. Mediocampista" << endl;
            cout<< "4. Delantero" << endl;
            cin>> opcion_p;
            if (opcion_p == 1)
                k.mostrar_posicion("Portero");
            if (opcion_p == 2)
                k.mostrar_posicion("Defensa");
            if (opcion_p == 3)
                k.mostrar_posicion("Mediocampista");
            if (opcion_p == 4)
                k.mostrar_posicion("Delantero");
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
        else if (opcion == 4){
            string mayor, menor;
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "INGRESE EL RANGO MAYOR: "<< endl;
            cin>> mayor;
            cout<< "INGRESE EL RANGO MENOR: "<< endl;
            cin>> menor;
            k.mostrar_edad(mayor, menor);
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
        else if (opcion == 5){
            int opcion_i;
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. AGREGAR JUGADOR" << endl;
            cout<< "2. BORRAR JUGADOR" << endl;
            cin>> opcion_i;
            if (opcion_i == 1){
                int i_c;
                string i_n, i_e, i_p, i_po;
                cout << "-----------------------------------------------------------------------" << endl;
                cout<< "INGRESE LA CAMISETA: "<< endl;
                cin>> i_c;
                cout<< "INGRESE EL APELLIDO: "<< endl;
                cin>> i_n;
                cout<< "INGRESE LA EDAD: "<< endl;
                cin>> i_e;
                cout<< "INGRESE EL PAIS: "<< endl;
                cin>> i_p;
                cout<< "INGRESE LA POSICION: "<< endl;
                cin>> i_po;
                k.insertar_j(i_c, i_n, i_e, i_p, i_po);
            }
            if (opcion_i == 2){
                int i_c;
                cout << "-----------------------------------------------------------------------" << endl;
                cout<< "INGRESE EL ID A BORRAR: "<< endl;
                cin>> i_c;
                k.borrar_jv2(i_c);
            }
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
        else if (opcion == 6){
            break;
        }
        else {
            cout<< "Opcion no valida.."<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cout<< "SELECCIONE LA OPCION DESEADA: "<< endl;
            cout<< "1. Mostrar jugadores por orden de ingreso." << endl;
            cout<< "2. Mostrar jugadores por seleccion." << endl;
            cout<< "3. Mostrar jugadores por posicion." << endl;
            cout<< "4. Mostrar jugadores por rango de edades." << endl;
            cout<< "5. Mostrar jugadores agregar o eliminar jugadores." << endl;
            cout<< "6. Salir"<< endl;
            cout << "-----------------------------------------------------------------------" << endl;
            cin>> opcion;
        }
    }
    //system("pause");
    return 0;
}
