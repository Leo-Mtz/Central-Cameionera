void archivoEscrituraRuta(Ruta *primeroR){
	
	Ruta *aux = primeroR;
	
	ofstream archivo("rutas.xls");
	
	while(aux!=NULL){
		
		archivo<<aux->idRuta<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->origen<<"\t";
		archivo<<aux->destino<<"\t";	
		archivo<<aux->horariosalida<<"\t";
		archivo<<aux->horariollegada<<endl;	
			
		ultimoR = aux;
		aux = aux->sigR;
			
	}
	
	archivo.close();
	
}

Ruta *archivoLecturaRuta(){
	
	Ruta *primeroR = NULL;
	Ruta *ultimoR = NULL;
	Ruta *nuevo = NULL;
	
	ifstream arch("rutas.xls");
	string linea, c;
		
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	
	else {
		
		while (getline(arch, linea)){
			
			nuevo = new Ruta;
			stringstream lee(linea);

			getline(lee, nuevo->estado, '\t');			
			lee>>nuevo->idRuta;
			getline(lee, c, '\t');
			getline(lee, nuevo->origen, '\t');
			getline(lee, nuevo->destino, '\t');

			lee>>nuevo->horariosalida;
			getline(lee, c, '\t');
			lee>>nuevo->horariollegada;
			getline(lee, c, '\n');
			
			nuevo->sigR = NULL;
			
			if(primeroR == NULL){
				
				primeroR = nuevo;
				ultimoR = nuevo;
				
			} else {
				
				ultimoR->sigR = nuevo;
				ultimoR = nuevo;
				
			}
			
		}
		
	}
	
	arch.close();
	return primeroR;
	
}

Ruta *registroRuta(){
	
	int sigue = 1;
	Ruta *nuevo = new Ruta;

	nuevo->idRuta = validaEntero("Ingresa el numero de Ruta: ");
	
	cout<<"La ruta esta activa? (1: Activo - 2: Inactivo): ";
	getline(cin, nuevo->estado);
		
	cout<<"Punto de salida de la ruta: ";
	getline(cin, nuevo->origen);
	
	cout<<"Donde termina la Ruta del camion?: ";
	getline(cin, nuevo->destino);
	
	cout<<"Hora de salida: ";
	getline(cin, nuevo->horariosalida);	
	cout<<"Hora de llegada: ";
	getline(cin, nuevo->horariollegada);	
	
	nuevo->sigR = NULL;
	
	return nuevo;
	
}

void agregarRuta(){
	
	Ruta *nuevo = registroRuta();
	
	if(primeroR == NULL){
		
		primeroR = nuevo;
		ultimoR = nuevo;
		
	} else {
		
		ultimoR->sigR = nuevo;
		ultimoR = nuevo;
		
	}
		
}

void modificarRuta(){
	
	Ruta *actual, *previo;
	
	primeroR = archivoLecturaRuta();
	
	actual = primeroR;
	
	bool bandera = true;
	int pos = 0;
	
	int elem;	
	
	if(primeroR==NULL){
		
		cout<<endl<<"No hay elementos en la lista";
		
	} else {
		
		printf("\n");
		elem = validaEntero("Que Id quieres modificar?");
		
		actual = primeroR;
		
		while(elem != actual->idRuta){
			
			previo = actual;
			actual = actual->sigR;
			
		}
		
		if(actual != NULL){
			
			cout<<"La ruta esta activa? (1: Activo - 2: Inactivo): ";
			getline(cin, actual->estado);
				
			cout<<"Punto de salida de la ruta: ";
			getline(cin, actual->origen);
			
			cout<<"Donde termina la Ruta del camion?: ";
			getline(cin, actual->destino);
			
			cout<<"Nueva hora de salida: ";
			cin>>actual->horariosalida;
			cout<<"Nueva hora de llegada: ";
			cin>>actual->horariollegada;				
			
		}
			
	}	
	
	archivoEscrituraRuta(primeroR);
	
}

void mostrarRuta(){
	
	Ruta *aux;
	
	primeroR = archivoLecturaRuta();
	
	aux = primeroR;
	
	cout<<endl<<endl<<"Mostrando la lista de RUTAS"<<endl;
	cout<<"Ubicacion"<<setw(10);
	cout<<"Ruta"<<setw(10);
	cout<<"Estado"<<setw(10);
	cout<<"Origen"<<setw(10);
	cout<<"Destino"<<setw(10);	
	cout<<"Salida"<<setw(10);
	cout<<"Llegada"<<setw(10);
	cout<<"Siguiente"<<endl;
	
	while(aux != NULL){
		
		cout<<aux<<setw(10);
		cout<<aux->idRuta<<setw(10);
		cout<<aux->estado<<setw(10);
		cout<<aux->origen<<setw(10);
		cout<<aux->destino<<setw(10);					
		cout<<aux->horariosalida<<setw(10);
		cout<<aux->horariollegada<<setw(10);
		cout<<aux->sigR<<endl;

		aux = aux->sigR;
		
	}
	
		cout<<endl<<"Primer NODO "<<primeroR;
		cout<<endl<<"Ultimo NODO "<<ultimoR<<endl<<endl;
		
}

//registar ruta leer archivo para agregar
