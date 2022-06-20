/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Cesar Davila
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "arrayPassenger.h"
#include "utn_validaciones.h"


int initPassenger(ePassenger* pasajeros, int tam)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            pasajeros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int searchFree(ePassenger* pasajeros, int tam, int* pIndex)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int  addPassenger(ePassenger* pasajeros, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int* pNextId, int statusFlight)
{
    int todoOk = 0;
    int indice;

    if(pasajeros!=NULL && tam>0 && pNextId!=NULL)
    {
        if(searchFree(pasajeros, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n\n");
            }
            else
            {
                utn_getString("Ingrese Nombre: ", "Error. Ingrese Nombre valido. ", 51, 100, name);

                utn_getString("Ingrese Apellido: ", "Error. Ingrese Apellido valido. ", 51, 100, pasajeros[indice].lastName);

                utn_getFloat("Ingrese precio del vuelo: ", "Error. Ingrese un precio valido. ", 1, 30000000, 100, &price);

                printf("Ingrese codigo de vuelo (numeros y letras. 10 caracteres en total): ");
                fflush(stdin);
                gets(flycode);
                while(strlen(flycode)!=10)
                {
                    printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 10 caracteres): ");
                    fflush(stdin);
                    gets(flycode);
                }

                printf("___________________________________________\n");
                printf("|                                          |\n");
                printf("|           Tipo de pasajeros              |\n");
                printf("|__________________________________________|\n");
                printf("|                                          |\n");
                printf("| 1- Ejecutiva                             |\n");
                printf("| 2- Premium                               |\n");
                printf("| 3- Turista                               |\n");
                printf("|__________________________________________|\n");

                utn_getInt("Ingrese Tipo de Pasajero: ", "Error. Ingrese un Tipo de Pasajero valido.",1,3,100, &typePassenger);

                printf("___________________________________________\n");
                printf("|                                          |\n");
                printf("|             Estado de Vuelo              |\n");
                printf("|__________________________________________|\n");
                printf("|                                          |\n");
                printf("| 1- Activo                                |\n");
                printf("| 2- Retrasado                             |\n");
                printf("| 3- Cancelado                             |\n");
                printf("|__________________________________________|\n");

                utn_getInt("Ingrese Estado del Vuelo: ", "Error. Ingrese un Estado de Vuelo valido.",1,3,100, &statusFlight);

                id = *pNextId;
                (*pNextId)++;

                pasajeros[indice].id = id;

                strcpy(pasajeros[indice].name, name);
                //strcpy(pasajeros[indice].apellido, apellido);

                pasajeros[indice].price = price;

                strcpy(pasajeros[indice].flycode, flycode);

                pasajeros[indice].typePassenger = typePassenger;

                pasajeros[indice].statusFlight = statusFlight;

                pasajeros[indice].isEmpty = 0;

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros!!\n\n");
        }
    }
    return todoOk;
}

int showPassenger(ePassenger unPasajero)
{
    int todoOk = 0;

    if(unPasajero.isEmpty == 0)
    {
        printf("| %5d     %-10s  %-10s  %.2f   %-10s    %3d      %3d  |\n", unPasajero.id, unPasajero.name, unPasajero.lastName, unPasajero.price, unPasajero.flycode,
               unPasajero.typePassenger, unPasajero.statusFlight);

        todoOk = 1;
    }
    return todoOk;
}

int listPassenger(ePassenger* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;
    if(pasajeros != NULL && tam>0)
    {
    	printf("___________________________________________________________________________\n");
    	printf("|                                                                          |\n");
    	printf("|                       Listado de Pasajeros                               |\n");
    	printf("|__________________________________________________________________________|\n");
    	printf("|                                                                          |\n");
        printf("| Id       Nombre       Apellido    Precio      Codigo     Tipo    Estado  |\n");
        printf("|__________________________________________________________________________|\n");
        printf("|                                                                          |\n");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
                showPassenger(pasajeros[i]);
                flag++;
                todoOk = 1;
            }
        }
        printf("|__________________________________________________________________________|\n");
        if(flag == 0)
        {
            printf("No hay pasajeros en el sistema!!\n");
        }
    }

    return todoOk;
}

int modifyPassengerMenu()
{
    int opcion;

    printf("__________________________________________\n");
    printf("|                                         |\n");
    printf("|            Campos a Modificar           |\n");
    printf("|_________________________________________|\n");
    printf("|                                         |\n");
    printf("| 1- Nombre                               |\n");
    printf("| 2- Apellido                             |\n");
    printf("| 3- Precio                               |\n");
    printf("| 4- Tipo de Pasajero                     |\n");
    printf("| 5- Codigo de Vuelo                      |\n");
    printf("| 6- Salir                                |\n");
    printf("|_________________________________________|\n");

    utn_getInt("Ingrese una opcion: ", "Error. Opcion invalida.",1,6,100,&opcion);

    return opcion;
}

int searchPassenger(ePassenger* pasajeros, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(pasajeros!=NULL && tam>0 && pIndex!=NULL && id > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modifyPassenger(ePassenger* pasajeros, int tam)
{
    int todoOk = 0;
    int indice;
    char salir = 'n';

    int id;
    char auxName[51];
    char auxLastName[51];
    float auxPrice;
    int auxTypePassenger;
    char auxFlycode[10];



    if(pasajeros!=NULL && tam>0)
    {
        listPassenger(pasajeros, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(searchPassenger(pasajeros,tam,id,&indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                showPassenger(pasajeros[indice]);
                do
                {
                    switch(modifyPassengerMenu())
                    {
                    case 1:
                        utn_getString("Ingrese nuevo Nombre: ", "Error. Ingrese un nombre valido.",51,100,auxName);

                        strcpy(pasajeros[indice].name, auxName);
                        printf("Nombre modificado con exito!!\n\n");
                        break;
                    case 2:
                        utn_getString("Ingrese nuevo apellido: ", "Error. Ingrese un apellido valido.",51,100,auxLastName);

                        strcpy(pasajeros[indice].lastName, auxLastName);
                        printf("Apellido modificado con exito!!\n\n");
                        break;
                    case 3:
                        utn_getFloat("Ingrese nuevo precio: ", "Error. Ingrese un precio valido.",1,30000000,100, &auxPrice);

                        pasajeros[indice].price = auxPrice;
                        printf("Precio modificado con exito!!\n\n");
                        break;
                    case 4:

                        printf("___________________________________________\n");
                        printf("|                                          |\n");
                        printf("|           Tipo de pasajeros              |\n");
                        printf("|__________________________________________|\n");
                        printf("|                                          |\n");
                        printf("| 1- Ejecutiva                             |\n");
                        printf("| 2- Premium                               |\n");
                        printf("| 3- Turista                               |\n");
                        printf("|__________________________________________|\n");
                        utn_getInt("Ingrese nuevo tipo de pasajero: ", "Error. Ingrese un tipo de pasajero valido.",1,3,100,&auxTypePassenger);

                        pasajeros[indice].typePassenger = auxTypePassenger;
                        printf("Tipo de pasajero modificado con exito!!\n\n");
                        break;
                    case 5:
                        printf("Ingrese nuevo codigo de vuelo (numeros y letras. 10 caracteres en total): ");
                        fflush(stdin);
                        gets(auxFlycode);
                        while(strlen(auxFlycode)!=10)
                        {
                            printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 10 caracteres): ");
                            fflush(stdin);
                            gets(auxFlycode);
                        }

                        strcpy(pasajeros[indice].flycode, auxFlycode);
                        printf("Codigo de vuelo modificado con exito!!\n\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int removePassenger(ePassenger* pasajeros, int tam, int id)
{
    int todoOk = 0;
    int indice;
    char confirma;

    if(pasajeros!=NULL && tam>0)
    {
        listPassenger(pasajeros, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(searchPassenger(pasajeros,tam,id,&indice))
        {
            if(indice == -1)
            {
                printf("No hay un pasajero con id %d\n", id);
            }
            else
            {
                showPassenger(pasajeros[indice]);
                printf("Confirma baja?(s/n): ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario!!\n");
                }
                else
                {
                    pasajeros[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!\n\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar pasajero!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int sortPassenger(ePassenger* pasajeros, int tam, int orden)
{
    int todoOk = 0;
    ePassenger auxPasajero;

    if(pasajeros!=NULL && tam>0 && orden>=0 && orden<=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(((pasajeros[i].typePassenger > pasajeros[j].typePassenger) && orden == 1)
                        || ((pasajeros[i].typePassenger < pasajeros[j].typePassenger) && orden == 0)
                        || ((pasajeros[i].typePassenger == pasajeros[j].typePassenger) && (strcmp(pasajeros[i].lastName, pasajeros[j].lastName)>0) && orden == 1)
                        || ((pasajeros[i].typePassenger == pasajeros[j].typePassenger) && (strcmp(pasajeros[i].lastName, pasajeros[j].lastName)<0) && orden == 0))
                {
                    auxPasajero = pasajeros[i];
                    pasajeros[i] = pasajeros[j];
                    pasajeros[j] = auxPasajero;
                }
            }
        }
        listPassenger(pasajeros,tam);

        todoOk = 1;
    }
    return todoOk;
}

int calcularPromedios(ePassenger* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;
    int cantPasajeros = 0;
    int cantPasajerosArribaPromedio = 0;
    float acumPrecio = 0;
    float promedioPrecios;

    if(pasajeros!=NULL && tam>0)
    {
        system("cls");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0)
            {
                cantPasajeros++;
                acumPrecio = acumPrecio + pasajeros[i].price;
                flag = 1;
            }
        }

        if(flag == 1)
        {
            promedioPrecios = acumPrecio / cantPasajeros;
        }


        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].price > promedioPrecios)
            {
                cantPasajerosArribaPromedio++;
            }
        }
        printf("El total de los precios es de %.2f y El promedio es %.2f\n", acumPrecio, promedioPrecios);
        printf("La cantidad de pasajeros que superan el precio promedio es %d\n", cantPasajerosArribaPromedio);

        todoOk = 1;
    }

    return todoOk;
}

int listActivePassenger(ePassenger* pasajeros, int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(pasajeros!=NULL && tam>0)
    {
    	printf("___________________________________________________________________________\n");
    	printf("|                                                                          |\n");
    	printf("|                       Listado de Pasajeros                               |\n");
	    printf("|__________________________________________________________________________|\n");
       	printf("|                                                                          |\n");
        printf("| Id       Nombre     Apellido    Precio        Codigo     Tipo    Estado  |\n");
        printf("|__________________________________________________________________________|\n");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty == 0 && pasajeros[i].statusFlight == 1)
            {
                showPassenger(pasajeros[i]);
                flag++;
                todoOk = 1;
            }
        }
        printf("|__________________________________________________________________________|\n");
        if(flag == 0)
        {
            printf("No hay pasajeros en el sistema!!\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int sortPassengersByCode(ePassenger* pasajeros, int tam, int orden)
{
    int todoOk = 0;
    ePassenger auxPasajero;

    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(((pasajeros[i].statusFlight > pasajeros[j].statusFlight) && orden == 1)
                        || ((pasajeros[i].statusFlight < pasajeros[j].statusFlight) && orden == 0)
                        || ((pasajeros[i].statusFlight == pasajeros[j].statusFlight) && (strcmp(pasajeros[i].flycode, pasajeros[j].flycode)>0) && orden == 1)
                        || ((pasajeros[i].statusFlight == pasajeros[j].statusFlight) && (strcmp(pasajeros[i].flycode, pasajeros[j].flycode)<0) && orden == 0))
                {
                    auxPasajero = pasajeros[i];
                    pasajeros[i] = pasajeros[j];
                    pasajeros[j] = auxPasajero;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int menu(){
    int opcion;

    system("cls");

    printf("_________________________________________________\n");
    printf("|                                                |\n");
    printf("|               Aerolineas UTN                   |\n");
    printf("|        Administracion de Pasajeros             |\n");
    printf("|________________________________________________|\n");
    printf("|                                                |\n");
    printf("| 1- ALTAS                                       |\n");
    printf("| 2- MODIFICAR                                   |\n");
    printf("| 3- BAJA                                        |\n");
    printf("| 4- INFORMES                                    |\n");
    printf("| 5- SALIR                                       |\n");
    printf("|                                                |\n");
    printf("|________________________________________________|\n");

    utn_getInt("Elija una opcion: ", "Error, Ingrese una opcion valida!!", 1, 5, 100, &opcion);

    system("cls");

    return opcion;

}
