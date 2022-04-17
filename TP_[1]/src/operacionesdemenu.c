#include <stdio.h>
#include <stdlib.h>

/*
 * operacionesdemenu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Cesar Davila
 */


int menu() {
	int opcion;
	printf("\n\n\n***  Menu de Opciones  ***\n\n");
	printf("1- Ingresar Kilometros\n");
	printf("2- Ingresar Precios de Vuelos \n");
	printf("3- Calcular todos los costos \n");
	printf("4- Informar Resultados\n");
	printf("5- Carga Forzada de Datos\n");
	printf("6- Salir \n\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	//system(cls);
	return opcion;
}

int ingresoDeDatos(int a) {

	scanf("%d", &a);
	while (a <= 0) {
		printf("ERROR, Ingrese un valor adecuados: positivo y mayor a 0: ");
		fflush(stdin);
		scanf("%d", &a);
	}

	return a;
}

void costosDeVuelo(int precio, int km, float *debito, float *credito,
		float *bitcoin, float *precioKm) {

	*debito = precio * 0.90; //descuento debito
	*credito = precio * 1.25; //interes credito
	*bitcoin = (float) precio / 4517428.09; //bitcoin a precio de hoy 12/04 4,517,428.09
	*precioKm = (float) precio / km;

}

int informarCostos(int debito, int credito, float bitcoin, float precioKm) {

	printf("a) Precio con tarjeta de débito: %d\n", debito);
	printf("b) Precio con tarjeta de crédito: %d\n", credito);
	printf("c) Precio pagando con bitcoin : %.7f\n", bitcoin);
	printf("d) Precio unitario: %.2f\n", precioKm);

	return 0;
}

