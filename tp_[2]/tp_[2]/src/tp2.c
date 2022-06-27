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
#include "ArrayPassenger.h"

#define TAM 2000

int main(void) {

	setbuf(stdout, NULL);

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

	ePassenger pasajeros[TAM];

	initPassenger(pasajeros, TAM);

	do {
		switch (menu()) {
		case 1:
			if (addPassenger(pasajeros, TAM, id, name, lastName, price,
					typePassenger, flycode, &nextId, statusFlight) == 0) {
				printf("Error al dar de alta!!\n");
			} else {
				printf("\nAlta exitosa!!\n");
				flagAltas = 1;
			}
			break;
		case 2:
			if (flagAltas == 0) {
				printf(
						"Error. Para realizar una MODIFICACION, primero debe dar de ALTA!!\n");
			} else {
				modifyPassenger(pasajeros, TAM);
			}
			break;
		case 3:
			if (flagAltas == 0) {
				printf(
						"Error. Para realizar una BAJA, primero debe dar de ALTA!!\n");
			} else {
				removePassenger(pasajeros, TAM, id);
			}
			break;
		case 4:
			if (flagAltas == 0) {
				printf(
						"Error. Para INFORMAR pasajeros, primero debe dar de ALTA!!\n");
			} else {
				printf(
						"______________________________________________________________________________\n");
				printf(
						"|                                                                             |\n");
				printf(
						"|                                    INFORMES                                 |\n");
				printf(
						"|_____________________________________________________________________________|\n");
				printf(
						"|                                                                             |\n");
				printf(
						"| 1- Listado por Apellido y Tipo de pasajero.                                 |\n");
				printf(
						"| 2- Total y promedio de Precios y cuantos pasajeros que superan el promedio. |\n");
				printf(
						"| 3- Listado por codigo de vuelo y vuelos ACTIVOS.                            |\n");
				printf(
						"|_____________________________________________________________________________|\n");

				utn_getInt("Ingrese una opcion: ",
						"Error. Ingrese una opcion valida.", 1, 4, 10,
						&opcion);

				switch (opcion) {
				case 1:
					utn_getInt("Ingrese orden (1 ASC / 0 DESC): ",
							"Error. Ingrese una opcion valida.", 0, 1, 10,
							&orden);
					system("cls");
					sortPassenger(pasajeros, TAM, orden);
					break;

				case 2:
					calcularPromedios(pasajeros, TAM);
					break;

				case 3:
					utn_getInt("Ingrese orden (1 ASC / 0 DESC): ",
							"Error. Ingrese una opcion valida.", 0, 1, 10,
							&orden);
					system("cls");
					sortPassengersByCode(pasajeros, TAM, orden);
					listActivePassenger(pasajeros, TAM);
					break;
				}
			}
			break;
		case 5:
			if (flagAltas == 0) {
			hardcodearPassenger(pasajeros, TAM, 10, &nextId);
			printf("Se agregan los 10 primeros pasajeros\n");
			}
			else
			{
				nextId = pasajeros->id;
				hardcodearPassenger(pasajeros, TAM, 10, &nextId);
				printf("Se agregan 10 pasajeros a los ya existentes\n");
			}
			break;
		case 6:
			salir = 's';
			printf("Salida exitosa!!\n");
			break;
		}

		system("pause");
	} while (salir != 's');

	return EXIT_SUCCESS;
}
