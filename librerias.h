#include <stdlib.h> //malloc, free
#include <conio.h> //getch()
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <iostream> //cout, cin, endl, fixed
#include <iomanip> //setw, setprecision
#include <string> //string
#include <sstream>
#include <fstream>

using namespace std;

struct Usuario{
	
	int idUsuario;
	string user;
	string pass;
	string estadoUsuario;	
	string nombre;
	string apellido;	
	int edad;
	string sexo;	
	string direccion;
	string telefono;

	struct Usuario *sigU;
	
}*primeroU, *ultimoU;

struct Pasajero{
	
	int idPasajero;
	int idRuta;
	int origen;
	int destino;
	int dia;
	int hora;
	int estadoAutobus;
	
	struct Pasajero *sigP;
	
}*primeroP, *ultimoP;

struct Estacion{
	
	int idRuta;
	string estacion;
	
	struct Estacion *sigE;
	
}*primeroE, *ultimoE;

struct Ruta{

	int idRuta;
	
	string estado;
	string origen;
	string destino;
	
	string horariosalida;
	string horariollegada;
	
	struct Ruta *sigR;

}*primeroR, *ultimoR;

struct ListaUsuario{
	
	int idListaUsuario;
	Usuario *listaUsuario;
	ListaUsuario *sig;
	
}*primListaUsuario, *ultListaUsuario;

struct ListaRuta{
	
	int idListaRuta;
	Ruta *listaRuta;
	ListaRuta *sig;
	
}*primListaRuta, *ultListaRuta;

#include "validaciones.h"
#include "archivosRuta.h"
#include "archivosUsuario.h"
#include "archivosEstacion.h"
#include "archivosPasajero.h"
#include "admin.h"

