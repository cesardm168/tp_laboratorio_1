/*
 * estado.c
 *
 *  Created on: 11 may. 2022
 *      Author: Cesar Davila
 */


#include <stdio.h>
#include <stdlib.h>
#include "estado.h"
#include <string.h>
#include "ArrayPassenger.h"


int listarEstado(eEstado estados[], int tam)
{
    int todoOk = 0;

    if(estados != NULL && tam > 0)
    {
        system("cls");
        printf("________________________________________\n");
        printf("|                                       |\n");
        printf("|   *** Lista de Estados de Vuelo   *** |\n");
        printf("|_______________________________________|\n");
        printf("|                                       |\n");
        printf("|      Id      |  Descripcion           |\n");
        printf("|_______________________________________|\n");
                for(int i=0; i < tam; i++)
        {
        printf("|    %4d      |   %12s         |\n", estados[i].id, estados[i].descripcion);
        }
        printf("|_______________________________________|\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionEstado(eEstado estados[], int tam, int id, char descripcion[])
{
    int todoOk = 0;
    int indice;

    buscarEstado(estados,tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {

        strcpy(descripcion, estados[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int validarEstado(eEstado estados[], int tam, int id){
    int esValido=0;
    int indice;

    buscarEstado(estados, tam, id , &indice);

    if (indice != -1){
        esValido = 1;
    }

    return esValido;
}

int buscarEstado (eEstado estados[],int tam, int id, int* pIndice)
{
    int todoOk = 0;

    if(estados != NULL && tam > 0 && pIndice != NULL )
    {
        *pIndice= - 1;
        for(int i=0; i < tam; i++)
        {
            if(estados[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;

}


