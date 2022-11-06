void menuAdmin(){

	int opc = 0;
	
	do{
		
		printf("0.- Salir\n");
		printf("1.- Agregar un Usuario\n");
		printf("2.- Agregar un Ruta\n");
		printf("3.- Modificar Usuarios\n");
		printf("4.- Modificar Rutas\n");		
		printf("5.- Mostrar Usuarios\n");
		printf("6.- Mostrar Rutas\n");	
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
			
					menuPasajero();
					
					break;			
										
		}
		
	} while(opc<5);
	
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
