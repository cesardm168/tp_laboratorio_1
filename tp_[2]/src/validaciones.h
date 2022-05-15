/*
 * validaciones.h
 *
 *  Created on: 14 may. 2022
 *      Author:  Cesar Davila
 */
#include "ArrayPassenger.h"
#include "tipo.h"
#include "estado.h"



#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

int searchPassengerFree( ePassenger list[], int len, int* pIndex);

int findPassengerById(ePassenger* list, int len, int id);

int menuReporte();

int reportPassenger(ePassenger list[],int len);

int loadPassenger(ePassenger list[], int len, eTipo tipos[], int lenTip,	eEstado estados[], int lenEst, int *pIdPasajero);

int modifyPassenger(ePassenger list[], int len, eTipo tiposs[], int lenTip, eEstado estados[], int lenEst);

int menuModify();

int searchPassenger(ePassenger list[], int len,int id, int* pIndex);

int listPassenger(ePassenger list[], int len,  eTipo tipos[], int lenTip, eEstado estados[], int lenEst);

int showPassenger(ePassenger p, eTipo tipos[],eEstado estados[], int len);

int hardcodePassengers(ePassenger list[], int len, int cant, int* pId);

int totalPromedioPrecios(ePassenger list[], int len);

int informarTotalPromedioPrecios(ePassenger list[], int len, float totalPrecios, float promedio, int arribaDePromedio);
