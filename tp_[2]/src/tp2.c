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
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "tipo.h"
#include "estado.h"

#define TAM 2000
#define TAMT 4
#define TAME 4

int main(void) {
	setbuf(stdout, NULL);
	char salir = 'n';
	int proximoId = 6000;
	int flagPassenger = 0;
	int flagDos=0;

	ePassenger pasajeros[TAM];

	eTipo tipos[TAMT] = {
			{ 5000, "Primera Clase" },
			{ 5001, "Turista" },
			{ 5002, "Economica" },
			{ 5003, "Ejecutiva" },
	};

	eEstado estados[TAME] = {
			{ 7000, "Activo" },
			{ 7001, "Demorado" },
			{ 7002, "Reprogramado" },
			{ 7003, "Cancelado" }, };

	initPassenger(pasajeros, TAM);

	do {
		switch (menu()) {
		case 1:
			if (loadPassenger(pasajeros, TAM, tipos, TAMT, estados, TAME, &proximoId)) {
				printf("Pasajero agregado con exito!!!\n");
			} else {
				printf("Problema al hacer el alta de Pasajero");
			}
			flagPassenger = 1;
			break;
		case 2:
			 if(flagPassenger ){
			if (modifyPassenger(pasajeros, TAM, tipos, TAMT, estados, TAM)== 0) {
				printf("Problema al hacer la baja de Pasajero\n");
				flagDos=1;
			}
			 }else{
				 printf("No se cargo ningun Pasajero\n");
			 }

			break;
		case 3:
			 if(flagDos){
				if (removePassenger(pasajeros, TAM, tipos, TAMT, estados, TAM)== 0) {
					printf("Problema al hacer la baja de Pasajero\n");
				 }
			flagPassenger=1;
			flagDos = 1;
						 }else{
							 printf("No se cargo ningun Pasajero\n");
		    }
			break;
		case 4:
			if(flagPassenger ||flagDos){
			reportPassenger(pasajeros,TAM);
			}else{
			 printf("No se cargo ningun Pasajero\n");
			}
			break;
		case 5:
			hardcodePassengers(pasajeros, TAM,10, &proximoId);
			break;

		case 10:
			salir = 's';
			break;
		default:
			printf("La Opcion ingresada es incorrecta\n");
		}
		system("pause");
	} while (salir != 's');

}
