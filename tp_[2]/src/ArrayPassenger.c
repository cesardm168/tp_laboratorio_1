/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Cesar Davila
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"

int menu() {
	int opcion;
	system("cls");
	printf("________________________________________\n");
	printf("|                                       |\n");
	printf("|       ***  Aerolineas UTN     **      |\n");
	printf("|_______________________________________|\n");
	printf("|                                       |\n");
	printf("| 1.-  Altas de Pasajeros               |\n");
	printf("| 2.-  Modificar Pasajeros              |\n");
	printf("| 3.-  Eliminar  Pasajeros              |\n");
	printf("| 4.-  Informes                         |\n");
	printf("| 5.-  Carga Forzada                    |\n");
	printf("| 10.-  Salir                           |\n");
	printf("|_______________________________________|\n");
	printf(" Ingrese Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int initPassenger(ePassenger* list, int len)
{
    int todoOk = 0;
    if(list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int addPassenger(ePassenger* list, int len, int id, char name[], char lastName[], float price,int typePassenger, char flyCode[], int statusFlight)
{
	   int todoOk = 0;
	    int pIndex;

	    if( searchPassengerFree(list, len, &pIndex) ){
	        list[pIndex].id = id;
	        strcpy(list[pIndex].name, name);
	        strcpy(list[pIndex].lastName, lastName);
	        list[pIndex].price = price;
	        strcpy(list[pIndex].flyCode, flyCode);
	        list[pIndex].typePassenger = typePassenger;
	        list[pIndex].statusFlight = statusFlight;
	        list[pIndex].isEmpty = 0;

	        todoOk = 1;
	        }

	    return todoOk;

}

int removePassenger(ePassenger list[], int len, eTipo tipos[], int lenTip, eEstado estados[],int lenEst){

	    int todoOk = 0;
	    int indice;
	    int id;
	    char confirma;
	    if(list != NULL && len > 0)
	    {
	        listPassenger(list, len, tipos, lenTip, estados,lenEst);
	        printf("Ingrese id: ");
	        scanf("%d", &id);
	        if( searchPassenger(list, len, id, &indice))
	        {
	            if(indice == -1)
	            {
	                printf("No hay un Pasajero con  ese id %d\n", id);
	            }
	            else
	            {
	                showPassenger(list[indice], tipos,  estados,len);
	                printf("Confirma baja?: s o n ");
	                fflush(stdin);
	                scanf("%c", &confirma);
	                if(confirma != 'S' && confirma != 's')
	                {
	                    printf("Baja cancelada por el usuario\n");
	                }
	                else
	                {
	                    list[indice].isEmpty = 1;
	                    printf("Baja realizada con el exito!!!\n");
	                    todoOk = 1;
	                }
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

int sortPassenger(ePassenger* list, int len, int order){// Si order == 1 retorna Orden Ascendente, Si order == 0 Retorna Descendente
    int todoOk = 0;
    ePassenger auxPassenger;

    if(list != NULL && len > 0 && order > -1 && order < 2)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
                if( ((((strcmp(list[i].lastName, list[j].lastName) > 0) && (list[i].typePassenger > list[j].typePassenger))
                || ((list[i].typePassenger != list[j].typePassenger) &&(list[i].typePassenger > list[j].typePassenger))) && order)
                ||  ((((strcmp(list[i].lastName, list[j].lastName) < 0) && (list[i].typePassenger < list[j].typePassenger))
                || ((list[i].typePassenger != list[j].typePassenger) &&(list[i].typePassenger < list[j].typePassenger))) && !order))
                {
                    auxPassenger = list[i];
                    list[i] = list[j];
                    list[j] = auxPassenger;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}


int printPassenger(ePassenger* list, int length){
    int todoOk = 0;
	int bandera = 0;

    if(list != NULL && length > 0){
    	printf("______________________________________________________________________________________________\n");
        printf("|                                                                                             |\n");
    	printf("|                                *** Lista de Pasajeros  ***                                  |\n");
    	printf("|_____________________________________________________________________________________________|\n");
    	printf("|                                                                                             |\n");
    	printf("|  Id    |   Nombre   | Apellido   | Precio  | Codigo Vuelo  |  Tipo Pasajero |  Estado Vuelo |\n");
    	printf("|_____________________________________________________________________________________________|\n");        for(int i = 0; i<length; i++){
            if(!list[i].isEmpty)
            {
                if(list != NULL){
                	printf("|  %4d   %10s   %10s    %9.2f    %10s     %13s    %12s|\n",
                    list[i].id,
                    list[i].name,
                    list[i].lastName,
                    list[i].price,
                    list[i].flyCode,
                    list[i].typePassenger,
                    list[i].statusFlight
                );
                }
                bandera = 1;
            }
        }
        if(bandera == 0){
            printf("\nNo hay Pasajeros en el Sistema\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

int sortPassengerByCode(ePassenger* list, int len, int order){
    int todoOk = 0;
    ePassenger auxPassenger;

    if(list != NULL && len > 0 && order > -1 && order < 2)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
              if( ((((strcmp(list[i].flyCode, list[j].flyCode) > 0) && (list[i].statusFlight > list[j].statusFlight))
                || ((list[i].statusFlight != list[j].statusFlight) &&(list[i].statusFlight > list[j].statusFlight))) && order)
                ||  ((((strcmp(list[i].flyCode, list[j].flyCode) < 0) && (list[i].statusFlight < list[j].statusFlight))
                || ((list[i].statusFlight != list[j].statusFlight) &&(list[i].statusFlight < list[j].statusFlight))) && !order))
                {
                    auxPassenger = list[i];
                    list[i] = list[j];
                    list[j] = auxPassenger;
                }



            }
        }
        todoOk = 1;
    }

    return todoOk;
}

