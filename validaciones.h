float validaFlotante(const char mensaje[]){
	int continuar=0;
	float flotante=0;
	
	do{
		
		printf("\n%s", mensaje);
		continuar = scanf("%f", &flotante);
		fflush(stdin);
		
	}while (continuar !=1);
	
	return flotante;
}

int validaEntero(const char mensaje[]){
	int continuar=0;
	int entero=0;
	
	do{

		printf("%s", mensaje);
		continuar = scanf("%i", &entero);
		fflush(stdin);	
	}while (continuar != 1);
	
	return entero;
}

void validaCadena(const char mensaje[], char cadena[]){

	bool bandera = true;
	
	while(bandera){
		
		printf("%s", mensaje);
		scanf("%[^\n]", cadena);
		fflush(stdin);
		if(strlen(cadena)>19){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i]) || cadena [i]==' '){
					if (i== (strlen(cadena)-1)){
						bandera=false;
					}
				}else{
					break;
				}
			}
		}
	}
}

/*int repetirIdUsuario(){
	
	//archivoLecturaUsuario(int id)
	
	Usuario *aux = primeroU;
	int id=0, continuar = 1;
		
		while(continuar == 1){
			
			continuar = 0;
			
			aux = primeroU;
			
			id = validaEntero("Id. Usuario: ");
	
			while(aux != NULL){
				
				if(id == aux->idUsuario){
					
					continuar = 1;
					break;
					
				} else {
					
					continuar = 0;
					
				}
				
				aux = aux->sigU;
					
			}
				
		}
				
	return id;
		
}

int repetirIdRuta(){
	
	//archivoLecturaRuta(int id)
	
	Ruta *aux = primeroR;
	int id=0, continuar = 1;
		
		while(continuar == 1){
			
			continuar = 0;
			
			aux = primeroR;
			
			id = validaEntero("Id. Ruta: ");
	
			while(aux != NULL){
				
				if(id == aux->idRuta){
					
					continuar = 1;
					break;
					
				} else {
					
					continuar = 0;
					
				}
				
				aux = aux->sigR;
					
			}
				
		}
				
	return id;
		
}*/
