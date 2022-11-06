void archivoEscrituraEstacion(Estacion *primeroE){
	
	Estacion *aux = primeroE;
	
	ofstream archivo("estaciones.xls");
	
	while(aux!=NULL){
		
		archivo<<aux->idRuta<<"\t";
		archivo<<aux->estacion<<endl;	
			
		ultimoE = aux;
		aux = aux->sigE;
			
	}
	
	archivo.close();
	
}

Estacion *archivoLecturaEstacion(){
	
	Estacion *primeroE = NULL;
	Estacion *ultimoE = NULL;
	Estacion *nuevo = NULL;
	
	ifstream arch("estaciones.xls");
	string linea, c;
		
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	
	else {
		
		while (getline(arch, linea)){
			
			nuevo = new Estacion;
			stringstream lee(linea);

			lee>>nuevo->idRuta;
			getline(lee, c, '\t');
			getline(lee, nuevo->estacion, '\n');
			
			nuevo->sigE = NULL;
			
			if(primeroE == NULL){
				
				primeroE = nuevo;
				ultimoE = nuevo;
				
			} else {
				
				ultimoE->sigE = nuevo;
				ultimoE = nuevo;
				
			}
			
		}
		
	}
	
	arch.close();
	return primeroE;
	
}

Estacion *registroEstacion(){
	
	Estacion *nuevo = new Estacion;
	
	nuevo->idRuta = validaEntero("Ruta a la que pertenece la estacion: ");	
	cout<<"Ingresa una estacion: ";
	getline(cin, nuevo->estacion);

	nuevo->sigE = NULL;
	
	return nuevo;
	
}

void agregarEstacion(){
	
	Estacion *nuevo = registroEstacion();
	
	if(primeroE == NULL){
		
		primeroE = nuevo;
		ultimoE = nuevo;
		
	} else {
		
		ultimoE->sigE = nuevo;		
		ultimoE = nuevo;
		
	}
	
}

void ordenaSeleccionEstacion(Estacion *primeroE){
	
	Estacion *aux = primeroE;
	Estacion *actual, *min;
	Estacion *pivote1 = new Estacion;
	Estacion *pivote2 = new Estacion;
	
	while (aux != NULL){
		
		min = aux;
		actual = aux->sigE;
		
		while (actual != NULL){
			
			if(min->idRuta > actual->idRuta){
				
				min = actual;
				
			}
			
			actual = actual->sigE;
			
		}
		
		pivote1->idRuta = aux->idRuta;
		pivote1->estacion = aux->estacion;

		pivote2->idRuta = aux->idRuta;
		pivote2->estacion = aux->estacion;
		
		min->idRuta = pivote1->idRuta;
		min->estacion = pivote1->estacion;
		
		aux->idRuta = pivote2->idRuta;
		aux->estacion = pivote2->estacion;	
		
		aux = aux->sigE;
		 
	}
	
}

void mostrarEstaciones(){
	
	Estacion *aux;
	
	primeroE = archivoLecturaEstacion();
	aux = primeroE;
	
	cout<<endl<<endl<<"Mostrando la lista de ESTACIONES"<<endl;
	cout<<"Ruta"<<setw(20);
	cout<<"Estaciones"<<endl;
	
	while(aux != NULL){
		
		cout<<aux->idRuta<<setw(20);
		cout<<aux->estacion<<endl;
	
		aux = aux->sigE;
		
	}		
}

//agregar estacion leer archivo
