Pasajero *registroPasajero(){
	
	Pasajero *nuevo = new Pasajero;
	
	nuevo->idPasajero = validaEntero("Ingresa tu Id: ");
	
	nuevo->idRuta = validaEntero("Que ruta de autobus tomaras?: ");
	
	nuevo->origen = validaEntero("Desde donde tomas el autobus?: ");
	nuevo->destino = validaEntero("Donde bajas del autobus?: ");

	nuevo->dia = validaEntero("Ingresa el dia del viaje: ");
	nuevo->hora = validaEntero("Ingresa la hora del viaje: ");
	
	nuevo->estadoAutobus = validaEntero("Tomo el autobus?: ");
	
	nuevo->sigP = NULL;
	
	return nuevo;
	
}

void agregarPasajero(){
	
	Pasajero *nuevo = registroPasajero();
	
	if(primeroP == NULL){
		
		primeroP = nuevo;
		ultimoP = nuevo;
		
	} else {
		
		ultimoP->sigP = nuevo;	
		ultimoP = nuevo;
		
	}
	
}

void menuPasajero(){

	cout<<endl<<"1.- Registrar un viaje"<<endl;
	cout<<"2.- Eliminar un viaje"<<endl;
	cout<<"3.- Modificar un viaje"<<endl;
	int opc = validaEntero("Ingresa una opcion: ");
	
	switch(opc){
		
		case 1: 
				
				archivoLecturaEstacion();
				mostrarEstaciones();
				registroPasajero();
				
				break;
				
		case 2:
		
				//eliminarPasajero();
				
				break;
				
		case 3:
		
				//modificarPasajero();		
			
				break;
		
	}
	
}
