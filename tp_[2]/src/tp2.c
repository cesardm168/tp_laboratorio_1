/*
 ============================================================================
 Name        : tp2.c
 Author      : cesar davila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "utn_validaciones.h"
#include "arrayPassenger.h"

#define TAM 2000

int main(void) {

	    setbuf(stdout,NULL);

		char salir = 'n';
	    int flagAltas = 0;
	    int nextId = 10000;

	    int id = 0;
	    char name[51];
	    char lastName[51];
	    float price = 0;
	    char flycode[10];
	    int typePassenger = 0;
	    int statusFlight = 0;

	    int orden;
	    int opcion;

	    ePassenger pasajeros[TAM] =
	    {
	        {10000,"lucas", "Viatri",14500,"qwert12345",1,1,0},
	        {10001,"Rogelio", "funes",200000,"poiuyt987",2,2,0},
	        {10002,"felipe", "niksevich",600000,"d2d32d375d",1,3,0},
	        {10003,"valentin", "costa",400000,"b3b2bbbb5b",1,3,0},
	        {10004,"yanzon", "nicolas",100000,"e2e3ee45ee",3,2,0},
	        {10005,"telma", "malano",300000,"f3f376ff8f",2,1,0}
	    };

	    initPassenger(pasajeros, TAM);



	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            if(addPassenger(pasajeros, TAM,id,name,lastName,price,typePassenger,flycode,&nextId,statusFlight)==0)
	            {
	                printf("Error al dar de alta!!\n");
	            }
	            else
	            {
	                printf("\nAlta exitosa!!\n");
	                flagAltas = 1;
	            }
	            break;
	        case 2:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para realizar una MODIFICACION, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	                modifyPassenger(pasajeros, TAM);
	            }
	            break;
	        case 3:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para realizar una BAJA, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	                removePassenger(pasajeros,TAM,id);
	            }
	            break;
	        case 4:
	            if(flagAltas == 0)
	            {
	                printf("Error. Para INFORMAR pasajeros, primero debe dar de ALTA!!\n");
	            }
	            else
	            {
	            	printf("______________________________________________________________________________\n");
	            	printf("|                                                                             |\n");
	            	printf("|                                    INFORMES                                 |\n");
	            	printf("|_____________________________________________________________________________|\n");
	            	printf("|                                                                             |\n");
	            	printf("| 1- Listado por Apellido y Tipo de pasajero.                                 |\n");
	                printf("| 2- Total y promedio de Precios y cuantos pasajeros que superan el promedio. |\n");
	                printf("| 3- Listado por codigo de vuelo y vuelos ACTIVOS.                            |\n");
	                printf("|_____________________________________________________________________________|\n");

	                utn_getInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida.",1,4,100, &opcion);

	                switch(opcion)
	                {
	                case 1:
	                    utn_getInt("Ingrese orden (1 ASC / 0 DESC): ", "Error. Ingrese una opcion valida.",0,1,100, &orden);
	                    system("cls");
	                    sortPassenger(pasajeros, TAM,orden);
	                    break;

	                case 2:
	                    calcularPromedios(pasajeros, TAM);
	                    break;

	                case 3:
	                    utn_getInt("Ingrese orden (1 ASC / 0 DESC): ", "Error. Ingrese una opcion valida.",0,1,100, &orden);
	                    system("cls");
	                    sortPassengersByCode(pasajeros,TAM,orden);
	                    listActivePassenger(pasajeros, TAM);
	                    break;
	                }
	            }
	            break;
	        case 5:
	            salir = 's';
	            printf("Salida exitosa!!\n");
	            break;
	        }

	        system("pause");
	    }
	    while(salir != 's');

	return EXIT_SUCCESS;
}
