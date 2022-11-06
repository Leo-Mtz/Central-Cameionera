void archivoEscrituraUsuario(Usuario *primeroU, int id){
	
	Usuario *aux = primeroU;
	char arch[20];
	itoa(id, arch, 10);
	strcat (arch, ".xls");
	
	ofstream archivo(arch);
	
	while(aux!=NULL){
		
		archivo<<aux->user<<"\t";
		archivo<<aux->pass<<"\t";
		archivo<<aux->estadoUsuario<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->edad<<"\t";
		archivo<<aux->direccion<<"\t";
		archivo<<aux->telefono<<"\n";		

		ultimoU = aux;
		aux = aux->sigU;
			
	}
	
	archivo.close();
	
}

Usuario *archivoLecturaUsuario(int id){
	
	Usuario *primeroU = NULL;
	Usuario *ultimoU = NULL;
	Usuario *nuevo = NULL;
	char archivo[20];
	itoa(id, archivo, 10);
	strcat (archivo, ".xls");
	
	ifstream arch(archivo);
	string linea, c;
	
	cout<<id<<endl;
	
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	
	else {
		
		while (getline(arch, linea)){
			
			nuevo = new Usuario;
			stringstream lee(linea);
			lee>>nuevo->idUsuario;
			getline(lee, c, '\t');
			getline(lee, nuevo->user, '\t');
			getline(lee, nuevo->pass, '\t');
			getline(lee, nuevo->estadoUsuario, '\t');									
			getline(lee, nuevo->nombre, '\t');									
			lee>>nuevo->edad;
			getline(lee, c, '\t');
			getline(lee, nuevo->direccion, '\t');
			getline(lee, nuevo->telefono, '\t');
			getline(lee, c, '\n');
			
			nuevo->sigU = NULL;
			
			if(primeroU == NULL){
				
				primeroU = nuevo;
				ultimoU = nuevo;
				
			} else {
				
				ultimoU->sigU = nuevo;
				ultimoU = nuevo;
				
			}
			
		}
		
	}
	
	arch.close();
	return primeroU;
	
}

void escrituraListaUsuario(){
	
	ListaUsuario *aux = primListaUsuario;
	
	ofstream archivo("ListaDeUsuario.xls");
	
	while(aux!=NULL){
		
		archivo<<aux->idListaUsuario<<"\n";
		
		aux = aux->sig;
		
	}
	
	archivo.close();
	
}

//lista de lista va a ser el idusuario y quitarlo de la estructura

void lecturaListaUsuario(){
	
	ListaUsuario *nuevo = NULL;
	
	ifstream arch("ListaDeUsuario.xls");
	string linea,c;
	
	if(arch.fail()) cerr<<"No se encuentra ninguna lista"<<endl;
	
	else {
		
		while (getline(arch, linea)){
			
			nuevo = new ListaUsuario;
			stringstream lee(linea);
			
			lee>>nuevo->idListaUsuario;
			getline(lee, c, '\n');
			
			nuevo->listaUsuario = archivoLecturaUsuario(nuevo->idListaUsuario);
			
			nuevo->sig = NULL;
			
			if(primListaUsuario == NULL){
				
				primListaUsuario = nuevo;
				ultListaUsuario = nuevo;
				
			} else {
				
				ultListaUsuario->sig = nuevo;
				ultListaUsuario = nuevo;
				
			}
			
		}
		
	}
	
	arch.close();
	
}

Usuario *registroUsuario(){
	
	Usuario *nuevo = new Usuario;
	
	nuevo->idUsuario = validaEntero("Ingresa de nuevo tu ID: ");
	
	cout<<"Username: ";
	getline(cin, nuevo->user);
	
	cout<<"Contraseña: ";
	getline(cin, nuevo->pass);
	
	cout<<"Estado del usuario (1: Activo - 2: Inactivo):";
	getline(cin, nuevo->estadoUsuario);			
	
	cout<<"Nombre: ";
	getline(cin, nuevo->nombre);
	
	cout<<"Apellido: ";
	getline(cin, nuevo->apellido);	
	
	nuevo->edad = validaEntero("Ingresa edad del usuario: ");

	cout<<"Sexo: ";
	getline(cin, nuevo->sexo);
		
	cout<<"Direccion: ";
	getline(cin, nuevo->direccion);

	cout<<"Telefono: ";
	getline(cin, nuevo->telefono);
		
	nuevo->sigU = NULL;
	
	return nuevo;
	
}

void agregarUsuario(){
	
	Usuario *nuevo = registroUsuario();
	
	if(primeroU == NULL){
		
		primeroU = nuevo;
		ultimoU = nuevo;
		
	} else {

		ultimoU->sigU = nuevo;		
		ultimoU = nuevo;
		
	}
	
}


void mostrarUsuario(Usuario *primeroU){
	
	struct Usuario *aux = primeroU;
	
	cout<<endl<<endl<<"Mostrando la lista de USUARIOS"<<endl;
	cout<<"Ubicacion"<<setw(10);
	cout<<"IdUsuario"<<setw(10);
	cout<<"Username"<<setw(10);
	cout<<"Estado"<<setw(10);		
	cout<<"Nombre"<<setw(10);
	cout<<"Apellido"<<setw(10);	
	cout<<"Edad"<<setw(10);
	cout<<"Sexo"<<setw(10);	
	cout<<"Direccion"<<setw(10);
	cout<<"Telefono"<<setw(10);
	cout<<"Siguiente"<<endl;
	
	while(aux != NULL){
		
		cout<<aux<<setw(10);
		cout<<aux->idUsuario<<setw(10);		
		cout<<aux->user<<setw(10);
		cout<<aux->estadoUsuario<<setw(10);
		cout<<aux->nombre<<setw(10);
		cout<<aux->apellido<<setw(10);		
		cout<<aux->edad<<setw(10);
		cout<<aux->sexo<<setw(10);		
		cout<<aux->direccion<<setw(10);
		cout<<aux->telefono<<setw(10);
		
		cout<<aux->sigU<<endl;
		aux = aux->sigU;
		
	}
	
		cout<<endl<<"Primer NODO "<<primeroU;
		cout<<endl<<"Ultimo NODO "<<ultimoU;
		
}

void mostrarListas(){
	
	struct ListaUsuario *aux = primListaUsuario; 
	struct Usuario *aux1 = NULL;
	

	while(aux!=NULL){
		cout<<"\n\nUbicacion Nodo"<<setw(15);
		cout<<"Id Lista"<<setw(30);
		cout<<"Listita (Primer nodo)"<<setw(20);
		cout<<"Siguiente"<<endl;
		cout<<aux<<setw(20);	
		cout<<aux->idListaUsuario<<setw(30);
		cout<<aux->listaUsuario<<setw(20);
		cout<<aux->sig<<endl;
		
		aux1 = aux->listaUsuario;
		
		mostrarUsuario(aux1);
		
		aux = aux->sig;
		
	}
	
	cout<<endl<<"Primer LISTA: "<<primListaUsuario;
	cout<<endl<<"Ultima LISTA: "<<ultListaUsuario<<"\n";
	
}

void agregarListaUsuarios(){
	
	ListaUsuario *nuevo = new ListaUsuario;
	int sigue = 1;
	
	cout<<"Agregando Usuario a la LISTA"<<endl;
	nuevo->idListaUsuario = validaEntero("Dame Id Usuario: ");

	primeroU = NULL;
	ultimoU = NULL;
	archivoLecturaUsuario(nuevo->idListaUsuario);
	
	agregarUsuario();
	
	nuevo->sig = NULL;
	nuevo->listaUsuario = primeroU;
	archivoEscrituraUsuario(primeroU, nuevo->idListaUsuario);
	
	if(primListaUsuario == NULL){
		
		primListaUsuario = nuevo;
		ultListaUsuario = nuevo;
		
	} else {
		
		ultListaUsuario->sig = nuevo;
		ultListaUsuario = nuevo;
		
	}

	//ordenaSeleccion(primero);
		
}
