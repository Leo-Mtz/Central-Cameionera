void menuAdmin(){

	int opc = 0;
	int op1=0;
	
	do{
		
		printf("0.- Salir\n");
		printf("1.- Agregar un Usuario\n");
		printf("2.- Agregar un Ruta\n");
		printf("3.- Modificar Usuarios\n");
		printf("4.- Modificar Rutas\n");		
		printf("5.- Mostrar Usuarios\n");
		printf("6.- Mostrar Rutas\n");	
		printf("7.- Consultar registros de pasajeros del programa\n");
		opc = validaEntero("Que desea realizar? ");
		
	
		switch(opc){
			
			case 0:
					
					exit(0);
					
					break;
			case 1:
					
					agregarListaUsuarios();
					escrituraListaUsuario();
					break;
								
			case 2:
			
					{
						
						int sigue = 1;
						
						archivoLecturaRuta();	
						agregarRuta();						
						archivoEscrituraRuta(primeroR);
												
						archivoLecturaEstacion();
						
						while(sigue==1){
						
							agregarEstacion();	
							sigue = validaEntero("Ingresar otra estacion? 1.- SI ");	
						}
						
						//ordenaSeleccionEstacion(primeroE);
						archivoEscrituraEstacion(primeroE);
						
						break;
					
					}	
						
			case 3:
			
					//modificarUsuario(); cambiar a inactivo, no ingresar estado de ruta o usuario
					
					break;
			
			case 4: 
			
					modificarRuta();			
					
					break;
					
			case 5:
				
					lecturaListaUsuario();
					mostrarListas();
					
					break;
			
			case 6: 
			
					archivoLecturaRuta();
					mostrarRuta();			
					
					break;
					
			case 7:
							
					menuConsultas();		
					break;			
										
		}
		
	} while(opc<7);
	
}

void menuConsultas(){
	
		do{
		
		system("cls");
		printf("Cómo desea consultar los registros de pasajeros");
		printf("1.- ID de pasajero\n");
		printf("2.- Rutas menos solicitadas\n");
		printf("3.- Rutas más socilitadas\n");		
		printf("4.- Pasajeros que tomaron el autobus\n");
		printf("5.- Pasajeros que no tomaron el autobus\n");	
		printf("6.- Pasajeros que se bajaron del autobus\n");
		printf("7.- Regresar al menu principal");
		op1 = validaEntero("Que desea realizar? ");
		
		
		
	
		switch(op1)
		{
			case 1:
					
					printf("ID");
					break;
								
			case 2:
			
			
						
			case 3:
			
					//modificarUsuario(); cambiar a inactivo, no ingresar estado de ruta o usuario
					
					break;
			
			case 4: 
			
					modificarRuta();			
					
					break;
					
			case 5:
				
					lecturaListaUsuario();
					mostrarListas();
					
					break;
			
			case 6: 
			
					archivoLecturaRuta();
					mostrarRuta();			
					
					break;
					
			case 7:
							
					menuAdmin();		
					break;			
										
		
		}
		} while(op1<7);	
}




void consultaID(Pasajero *aux){
	
	Factura *aux = primero;
	Factura *actual, *previo, *otro;
	actual=primero;
	previo=actual;
	int id=0, op;
	bool bandera;
	             
	
	id=validaEntero("Num de Factura a consultar: ");

	while(actual!=NULL){
		if(id==actual->idfactura){
			//system("cls");1
			bandera=true;
		
				 		 	
			cout<<"Pasajero consultado\n"<<endl;
			cout<<"idPasajero"<<setw(10);
			cout<<"Ruta de autobus tomada"<<setw(10);
			cout<<"Estacion desde donde toma el autobus"<<setw(10);
			cout<<"Baja del autobus(1=si/2=no): "<<setw(10);
			cout<<""<<setw(10);
			cout<<"CP de receptor"<<setw(10);
			cout<<"RFC de receptor"<<setw(10);
			printf(" \t");
			cout<<endl;
			
			cout<<endl;
			
			cout<<actual->idfactura<<setw(10);
			cout<<actual->emisor<<setw(10);
			cout<<actual->cpemisor<<setw(10);
			cout<<actual->RFCemisor<<setw(10);
			cout<<aux->receptor<<setw(10);
			cout<<aux->cpreceptor<<setw(10);
			cout<<aux->RFCreceptor<<setw(10);
			
			cout<<endl;
			break;
		}

		else{
			previo=actual;
			actual=previo->sig;
			actual->ant = previo;
		}
	
	if(bandera==false){
		cout<<"El numero de factura no existe"<<endl;
	}
	getch();

}
}

void consultarxmenossolicitada()
{
	
}

void consultarxmas(){
}

void pasajerostomaron(){
	
}

void pasajerosnotomaron(){
	
}

void pasajerosbajaron(){
	
}















/*void agregarListaRutas(){
	
	ListaRuta *nuevo = new ListaRuta;
	int sigue = 1;
	
	cout<<"Agregando Ruta a la LISTA"<<endl;
	nuevo->idListaRuta = validaEntero("Dame Id Ruta: ");
	
	primeroR = NULL;
	ultimoR = NULL;
	
	archivoLecturaUsuario(primeroU->idUsuario);
	
	agregarRuta();
		
/*	while (sigue == 1){
		
		agregarUsuario();
		sigue = validaEntero("Teclea 1 para agregar otro: ");
		
	}
	
	nuevo->sig = NULL;
	nuevo->listaRuta = primeroR;
	archivoEscrituraRuta(primeroR, nuevo->idListaRuta);
	
	if(primListaRuta == NULL){
		
		primListaRuta = nuevo;
		ultListaRuta = nuevo;
		
	} else {
		
		ultListaRuta->sig = nuevo;
		ultListaRuta = nuevo;
		
	}
		
}*/
