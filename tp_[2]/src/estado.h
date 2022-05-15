/*
 * estado.h
 *
 *  Created on: 14 may. 2022
 *      Author: Maria Luyo
 */

#ifndef ESTADO_H_
#define ESTADO_H_

typedef struct{

int id;
char descripcion[20];

}eEstado;

#endif /* ESTADO_H_ */
/// @fn Funcion que muestra en una lista los tipos vuelos de los pasajeros
/// @param tipos Tipo de estados de vuelo (activo, demorado, cancelado, reprogramado)
/// @param tam tamaño de la estructura
/// @return retorno de todo ok si es que las condiciones se cumplen
int listarEstado(eEstado estados[], int tam);

/// @fn Funcion que ayuda a cargar la descripcion del estado de vuelo ayudandose de otra funcion
/// @param tipos Tipo de estados de vuelo (activo, demorado, cancelado, reprogramado)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del estado del vuelo
/// @param descripcion descripcion del estado del vuelo
/// @return retorno de todo ok si es que las condiciones se cumplen
int cargarDescripcionEstado(eEstado estados[], int tam, int id, char descripcion[]);


/// @fn Funcion que busca dentro de la estructura  Estados, si es que hay datos cargados
/// @param tipos Tipo de estados de vuelo (activo, demorado, cancelado, reprogramado)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del estado de vuelo
/// @return retorno de esValido si es que hay datos en la estructura
int validarEstado(eEstado estados[], int tam, int id);

/// @fn Funcion que busca dentro de la estructura los datos cargados y los almacena y modifica mediante un puntero
/// @param tipos Tipo de estados de vuelo (activo, demorado, cancelado, reprog*ramado)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del estado de vuelo
/// @param pIndice Puntero a indice que se modificara si es que hay datos dentro de la estructura
/// @return retorno de todo ok si es que las condiciones se cumplen
int buscarEstado (eEstado estados[],int tam, int id, int* pIndice);
