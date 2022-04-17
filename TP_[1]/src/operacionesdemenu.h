/*
 * operacionesdemenu.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Cesar Davila
 */

#ifndef OPERACIONESDEMENU_H_
#define OPERACIONESDEMENU_H_


/// @fn int menu(despliega el menu de la aplicacion)
/// @brief se declara opcion variable a retorna
/// @pre se utilizan varios print para mostrar el menu al usuario
/// @return opcion la cual se va a utilizar para seleccionar las opciones del  menu
int menu();

/// @fn int ingresoDeDatos(int)
/// @brief se solicita el ingreso de un numero
///
/// @pre se valida que sea positivo
/// @param se verifica que no sea negativo ni cero
/// @return retorna un numero positivo para hacer los calculos
int ingresoDeDatos(int);

/// @fn void costosDeVuelo(int, int, float*, float*, float*, float*)
/// @brief  funcion en la cual se calculan los costos de los vuelos con los datos ingresados y validados
/// @param precio Precio que puede ser de latam o aerolineas
/// @param Km  Cantidad de kilometros cuyos datos ya fueron validados
/// @param debito Puntero que luego modificara la variable debito en el main
/// @param credito Puntero que luego modificara la variable credito en el main
/// @param bitcoin  Puntero que luego modificara la variable bitcoin en el main
/// @param precioKm Puntero que luego modificara la variable precioKm en el main
void costosDeVuelo(int precio, int Km, float *debito, float *credito,
		float *bitcoin, float *precioKm);

/// @fn int informarCostos(int, int, float, float)
/// @brief Funcion que imprime los resultados obtenidos a traves de otra funcion
/// @param debito Costo del vuelo con el 10% de descuento
/// @param credito  Costo del vuelo con el 15% de aumento
/// @param bitcoin  Costo del vuelo expresado en bitcoin
/// @param precioKm Costo del km del vuelo
/// @return
int informarCostos(int debito, int credito, float bitcoin, float precioKm);


#endif /* OPERACIONESDEMENU_H_ */
