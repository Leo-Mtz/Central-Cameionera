#include "librerias.h"

int main(){
	
	/*
		
		Uriel Martinez Monreal - 178646
		Leo Auxdei Martinez Sanchez - 177192
		
		Programacion II - Otoño 2022
		
		21 de Octubre de 2022
		
		Proyecto Final
			
	*/
	
	int sigue = 1;
	int id=validaEntero("Ingresa el ID para ingresar: ");
	
	while(sigue==1){
		
		if(id == 178646 || id == 177192){
			
			menuAdmin();
			
		} else {
			
			menuPasajero();
			
		}
				
	}
	
}
