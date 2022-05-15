/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author:  Cesar Davila
 */
#include "tipo.h"
#include "estado.h"


#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
typedef struct
{
    int id;
    char name[20];
    char lastName[20];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
} ePassenger;

#endif /* ARRAYPASSENGER_H_ */


int menu();

int initPassenger(ePassenger* list,int len);//

int addPassenger(ePassenger* list, int len, int id, char name[], char lastName[], float price,int typePassenger, char flycode[], int statusFlight);

int removePassenger(ePassenger list[], int len, eTipo tipos[], int lenTip, eEstado estados[],int lenEst);

int printPassenger (ePassenger* list,int len);//imprime pasajeros de forma encolumnada

int sortPassenger(ePassenger* list, int len, int order);//ordena apellido y tipo de pasajero

int sortPassengerByCode(ePassenger* list, int len, int order);//orden codigo de vuelo y estado

