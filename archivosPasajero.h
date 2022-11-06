Pasajero *registroPasajero(){

Pasajero *nuevo = new Pasajero;
	
	nuevo->idPasajero = validaEntero("Ingresa tu Id: ");
	
	
	nuevo->estadoAutobus = validaEntero("Tomo el autobus?(1=Si/ 2=No): ");
	
	if(nuevo->estadoAutobus==1){
	
		nuevo->idRuta = validaEntero("Que ruta de autobus tomaras?: ");
	
		nuevo->origen = validaEntero("Desde donde tomas el autobus?: ");
		nuevo->bajar=ValidaEntero("Bajas del autobus? (1=Si/ 2=NO): ");
		if(nuevo->bajar==1){
			
			nuevo->destino = validaEntero("Donde bajas del autobus?: ");

		}else{
		
		
	nuevo->dia = validaEntero("Ingresa el dia del viaje: ");
	nuevo->hora = validaEntero("Ingresa la hora del viaje: ");
		}
	}
	
	printf("Registro completado :)")
	
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
