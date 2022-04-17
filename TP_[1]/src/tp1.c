/*
 ============================================================================
 Name        : tp1.c
 Author      : cesar davila
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "operacionesdemenu.h"

int main(void) {
	setbuf(stdout, NULL);
	char salir = 'n';
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	float debito;
	float credito;
	float bitcoin;
	float precioKm;
	float debito2;
	float credito2;
	float bitcoin2;
	float precioKm2;
	int diferenciaPrecio = 0;
	int flagKm = 0;
	int flagVuelos =0;

	do {

		switch (menu()) {

		case 1:

			printf("Ingrese los Kilometros: ");
			kilometros = ingresoDeDatos(kilometros);
			flagKm = 1;
			break;

		case 2:
			if (flagKm){
			printf("Precio vuelo Aerolineas:  ");
			precioAerolineas = ingresoDeDatos(precioAerolineas);

			printf("Precio vuelo Latam:  ");
			precioLatam = ingresoDeDatos(precioLatam);
			flagVuelos=1;
			}
			else
			{
				printf("Para ingresar los precios primero ingrese kilometros\n");
			}
			break;

		case 3:
			if(flagVuelos){
			costosDeVuelo(precioAerolineas, kilometros, &debito, &credito,
					&bitcoin, &precioKm);
			costosDeVuelo(precioLatam, kilometros, &debito2, &credito2,
					&bitcoin2, &precioKm2);
			diferenciaPrecio = precioAerolineas - precioLatam;
			printf("Costos Calculados\n");
			flagKm=1;
			flagVuelos=1;
			}
			else if (flagVuelos){
				printf("antes de calcular hay que ingresar km\n");
			}
			else{
				printf("como vamos a calcular si aun no ingresamos los precios de los vuelos\n");
			}
			break;

		case 4:
			if (flagKm || flagVuelos){
			printf("Aerolineas:\n\n");
			informarCostos(debito, credito, bitcoin, precioKm);
			printf("Latam:\n ");
			informarCostos(debito2, credito2, bitcoin2, precioKm2);
			printf("La diferencia de precio es : %d\n", diferenciaPrecio);
			}
			else{
				printf("No se pueden mostrar resultados si no se ingresaron datos\n");
			}
			break;

		case 5:

			printf("Aerolineas:\n\n");
			costosDeVuelo(162965, 7090, &debito, &credito, &bitcoin, &precioKm);
			informarCostos(debito, credito, bitcoin, precioKm);
			printf("Latam:\n\n ");
			costosDeVuelo(159339, 7090, &debito, &credito, &bitcoin, &precioKm);
			informarCostos(debito, credito, bitcoin, precioKm);

			printf("La diferencia de precio es : %d\n", 162965 - 159339);
			break;

		case 6:

			printf("Confirma Salida: s ó n\n");
			fflush(stdin);
			scanf("%c", &salir);
			break;
		default:
			printf("Opcion Invalida\n");
		}
		system("pause");
	} while (salir != 's');
	return EXIT_SUCCESS;
}
