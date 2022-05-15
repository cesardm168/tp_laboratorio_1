/*
 * validaciones.c
 *
 *  Created on: 14 may. 2022
 *      Author:  Cesar Davila
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"
#include "tipo.h"
#include "estado.h"
#include "ArrayPassenger.h"

int searchPassengerFree(ePassenger list[], int len, int *pIndex) {
	int todoOk = 0;

	if (list != NULL && len > 0 && pIndex != NULL) {
		*pIndex = -1;

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty) {
				*pIndex = i;
				break;
			}
		}

		todoOk = 1;
	} else {
		printf("\nNo hay lugar dispoible\n");
	}

	return todoOk;
}

int findPassengerById(ePassenger *list, int len, int id) {
	int todoOk = -1;
	if (list != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].id == id) {
				todoOk = i;

				break;
			}
		}
	}

	return todoOk;
}

int menuReporte() {
	int opcion;
	system("cls");
	printf("________________________________________\n");
	printf("|                                       |\n");
	printf("| *** Formularios de Ordenamiento  **   |\n");
	printf("|_______________________________________|\n");
	printf("|                                       |\n");
	printf("| 1.- Ordenados por Apellido y Tipo     |\n");
	printf("| 2.- Ordenados por Columna             |\n");
	printf("| 3.- Ordenados por Codigo y Estado     |\n");
	printf("| 4.-  Salir                            |\n");
	printf("|_______________________________________|\n");
	printf(" Ingrese Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}


int reportPassenger(ePassenger list[], int len) {
	int orden;
	int todoOk = 0;
	int salir = 'n';

	if (list != NULL && len > 0) {
		do {
			switch (menuReporte()) {
			case 1:
				printf("Elija el Orden (1-Ascendente, 0-Descendente): ");

				scanf("%d", &orden);
				sortPassenger(list, len, orden);
				printPassenger(list, len);

				break;
			case 2:
				totalPromedioPrecios(list, len);

				break;
			case 3:
				printf("Elija el orden (1-ascendente, 0-descendente): ");
				scanf("%d", &orden);
				sortPassengerByCode(list, len, orden);
				printPassenger(list, len);

				break;
			case 4:
				salir = 's';

				break;

			default:
				printf("\nLa opcion ingresada no esta disponible\n");
			}

		} while (salir != 's');

		todoOk = 1;
	} else {
		printf("Ocurrio un problema al ordenar pasajeros\n");
	}

	return todoOk;
}


int loadPassenger(ePassenger list[], int len, eTipo tipos[], int lenTip,	eEstado estados[], int lenEst, int *pIdPasajero) {
	int todoOk = 0;
	int indice;
	char auxCad[100];
	ePassenger nuevoPasajero;

	if (list != NULL && len > 0 && pIdPasajero != NULL) {
		if (searchPassengerFree(list, len, &indice)) {

			if (indice == -1) {
				printf("No hay lugar en el sistema\n");
			} else {
				printf("Ingrese el Nombre del Pasajero: ");
				fflush(stdin);
				gets(auxCad);

				while (strlen(auxCad) >= 20) {
					printf("Nombre demasiado largo. Reingrese nombre: ");
					fflush(stdin);
					gets(auxCad);
				}
				strcpy(nuevoPasajero.name, auxCad);

				printf("Ingrese el Apellido del Pasajero: ");
				fflush(stdin);
				gets(auxCad);

				while (strlen(auxCad) >= 20) {
					printf("Apellido demasiado largo. Reingrese Apellido: ");
					fflush(stdin);
					gets(auxCad);
				}
				strcpy(nuevoPasajero.lastName, auxCad);

				printf("Ingrese Precio: ");
				fflush(stdin);
				scanf("%f", &nuevoPasajero.price);

				listarTipo(tipos, lenTip);

				printf("Ingrese Id Tipo de Vuelo: ");
				scanf("%d", &nuevoPasajero.typePassenger);

				while (!validarTipo(tipos, lenTip, nuevoPasajero.typePassenger)) {
					printf("Tipo de Vuelo  invalido.Ingrese Id Tipo: ");
					scanf("%d", &nuevoPasajero.typePassenger);
				}

				printf("Ingrese el Codigo del Pasajero: ");
				fflush(stdin);
				gets(auxCad);

				while (strlen(auxCad) >= 10) {
					printf("Codigo demasiado largo. Reingrese Codigo: ");
					fflush(stdin);
					gets(auxCad);
				}
				strcpy(nuevoPasajero.flyCode, auxCad);

				listarEstado(estados, lenEst);

				printf("Ingrese Id del Estado de Vuelo: ");
				scanf("%d", &nuevoPasajero.statusFlight);

				while (!validarEstado(estados, lenEst, nuevoPasajero.statusFlight)) {
					printf("Estado de vuelo invalido.Ingrese Id Estado: ");
					scanf("%d", &nuevoPasajero.statusFlight);
				}

				nuevoPasajero.isEmpty = 0;
				nuevoPasajero.id = *pIdPasajero;
				*pIdPasajero = *pIdPasajero + 1;
				list[indice] = nuevoPasajero;
				todoOk = 1;
			}
		} else {
			printf("Ocurrio un problema con los parametros\n");
		}
	}
	return todoOk;
}


int modifyPassenger(ePassenger list[], int len, eTipo tipos[], int lenTip, eEstado estados[], int lenEst)
{
    int todoOk = 0;
    int indice;
    int id;
    char salir = 'n';
    char auxCad[100];

    if(list != NULL && len > 0)
    {
       listPassenger(list, len, tipos, lenTip, estados, lenEst);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if( searchPassenger(list, len, id, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un Pasajero con ese id %d\n", id);
            }
            else
            {
                showPassenger(list[indice], tipos, estados,len);


                do
                {
                    switch(menuModify())
                    {

                    case 1:
                        printf("Ingrese nuevo Nombre: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(list[indice].name, auxCad);
                        printf("Se ha modificado el nombre\n");
                        break;

                    case 2:
                    	 printf("Ingrese nuevo Apellido: ");
                    	 fflush(stdin);
                    	 gets(auxCad);
                    	 strcpy(list[indice].lastName, auxCad);
                    	 printf("Se ha modificado el Apellido\n");
                        break;

                    case 3:
                        printf("Ingrese nuevo Precio: ");
                        scanf("%f", &list[indice].price);
                        printf("Se ha modificado el precio\n");
                        break;

                        break;
                    case 4:
                        printf("Ingrese nuevo Codigo de Vuelo: ");
                        fflush(stdin);
                        gets(auxCad);
                        strcpy(list[indice].flyCode, auxCad);
                        printf("Se ha modificado el Codigo de vuelo\n");
                        break;

                        break;
                    case 5:
                    	listarTipo(tipos, lenTip);
                        printf("Ingrese Id de Tipo de pasajero: ");
                        scanf("%d", &list[indice].typePassenger);
                        printf("Se ha modificado el Tipo del pasajero\n");

                        break;
                    case 6:
                    	listarEstado(estados, lenEst);
                    	printf("Ingrese Id de Estado de Vuelo: ");
                    	scanf("%d", &list[indice].statusFlight);
                        printf("Se ha modificado el Estado de vuelo\n");
                        break;
                    case 7:
                        salir = 's';
                        break;
                    }
                    system("pause");

                }
                while(salir != 's');
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int listPassenger(ePassenger list[], int len,  eTipo tipos[], int lenTip, eEstado estados[], int lenEst)
{
    int todoOk = 0;
    int flag = 0;


    if(list != NULL && len > 0)
    {
        system("cls");
       			printf("______________________________________________________________________________________________\n");
                printf("|                                                                                             |\n");
                printf("|                                *** Lista de Pasajeros  ***                                  |\n");
                printf("|_____________________________________________________________________________________________|\n");
                printf("|                                                                                             |\n");
                printf("|  Id    |   Nombre   | Apellido   | Precio  | Codigo Vuelo  |  Tipo Pasajero |  Estado Vuelo |\n");
                printf("|_____________________________________________________________________________________________|\n");
        for(int i = 0 ; i < len ; i++)
        {
            if( !list[i].isEmpty )
            {
            	showPassenger(list[i],tipos, estados ,len);
                flag++;
            }
        }
        printf("|_____________________________________________________________________________________________|\n");
        if(flag == 0)
        {
            printf("       No hay Pasajeros en el sistema  ");
        }

        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}

int showPassenger(ePassenger p, eTipo tipos[],eEstado estados[], int len)
{
    int todoOk = 0;
    char descTipo[20];
    char descEstado[20];
    if((tipos != NULL && len > 0) || (estados !=NULL && len >0) )
    {
        cargarDescripcionTipo( tipos, len, p.typePassenger , descTipo);
        cargarDescripcionEstado(estados, len , p.statusFlight, descEstado);

        printf("|  %4d   %10s   %10s    %9.2f    %10s     %13s    %12s|\n",
               p.id,
               p.name,
               p.lastName,
               p.price,
               p.flyCode,
               descTipo,
               descEstado
              );
        todoOk = 1;
    }
    return todoOk;
}


int findPassengerByID(ePassenger* list, int len,int id)
{
    int todoOk =-1;
    if(list != NULL && len > 0 &&  id > 0)
    {
       for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 0 &&  list[i].id == id )
            {
                todoOk= i;
                break;
            }
        }

    }
    return todoOk;
}

int menuModify(){

	  int opcion;
	printf("_______________________________________________________________________\n");
	printf("|                                                                      |\n");
	printf("|                   ***Modificar Empleados  ***                        |\n");
	printf("|______________________________________________________________________|\n");
	printf("|                                                                      |\n");
	printf("| 1.- Nombre                                                           |\n");
	printf("| 2.- Apellido                                                         |\n");
	printf("| 3.- Precio                                                           |\n");
	printf("| 4.- Codigo de Vuelo                                                  |\n");
	printf("| 5.- Tipo de Pasajero                                                 |\n");
	printf("| 6.- Estado de Vuelo                                                  |\n");
	printf("| 7.- Salir                                                            |\n");
	printf("|______________________________________________________________________|\n");
	 printf("Ingrese opcion: ");
	 scanf("%d", &opcion);
	 return opcion;
}



int searchPassenger(ePassenger list[], int len,int id, int* pIndex)
{
    int todoOk = 0;
    if(list != NULL && len > 0 && pIndex != NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty == 0 &&  list[i].id == id )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int hardcodePassengers(ePassenger list[], int len, int cant, int* pId){
    int todoOk = 0;

    ePassenger nuevoPasajero[] = {
		{0, "Muriel", "Cordoba", 120000, "AD0001", 5001, 7001, 0},
		{0, "Corina", "Lopez", 80000, "AD0002", 5000, 7003, 0},
		{0, "Ruben", "Wash", 155000, "CD00003", 5001, 7000, 0},
		{0, "Estaban", "Quito", 36000, "CD0004", 5002, 7002, 0},
		{0, "Lamo", "Nada", 69000, "BC00005", 5000, 7001, 0},
		{0, "Javier", "Milei", 71000, "UX00005", 5001, 7000, 0},
		{0, "Pablo", "Serna", 110000, "a000005", 5002, 7002, 0},
		{0, "Lucas", "Paz", 55000, "UX00005", 5003, 7003, 0},
		{0, "Sofia", "Cortez", 92000, "a000005", 5001, 7000, 0},
		{0, "Saul", "Paredes", 102000, "BC00005", 5002, 7000, 0},
	};


	if(list != NULL && len > 0 && pId != NULL && cant > 0 && cant <= len)
    {

        for(int i=0; i < cant; i++)
        {
            list[i] = nuevoPasajero[i];
            list[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }

	return todoOk;
}

int totalPromedioPrecios(ePassenger list[], int len){
    int todoOk;
    float totalPrecios = 0;
    float promedio;
    float cantPrecios = 0;
    int arribaDePromedio = 0;

    if(list != NULL && len > 0){
        for(int i=0; i < len; i++){
            if(list[i].isEmpty == 0){
            totalPrecios = totalPrecios + list[i].price;
               cantPrecios++;
            }
        }

        promedio = totalPrecios / cantPrecios;

        for(int i=0; i < len; i++){
            if(list[i].price > promedio){
               arribaDePromedio++;
            }
        }

        informarTotalPromedioPrecios(list, len, totalPrecios, promedio, arribaDePromedio);

        todoOk = 1;
    }

    return todoOk;
}

int informarTotalPromedioPrecios(ePassenger list[], int len, float totalPrecios, float promedio, int arribaDePromedio){
    int todoOk = 0;

    if(list != NULL && len > 0){
        printf("\n\nTotal precios: %.2f", totalPrecios);
        printf("\nPromedio de precios: %.2f", promedio);
        printf("\nPasajeros que exceden el promedio: %d\n\n", arribaDePromedio);

        todoOk = 1;
    }

    return todoOk;
}
