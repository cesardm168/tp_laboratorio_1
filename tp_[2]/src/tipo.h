/*
 * tipo.h
 *
 *  Created on: 14 may. 2022
 *      Author:  Cesar Davila
 */


#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_


typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif /* TYPEPASSENGER_H_ */
/// @fn Funcion que muestra en una lista los tipos de pasajeros
/// @param tipos Tipo de pasajeros (turista, primera clase,economica)
/// @param tam tamaño de la estructura
/// @return retorno de todo ok si es que las condiciones se cumplen
int listarTipo(eTipo tipos[], int tam);

/// @fn Funcion que ayuda a cargar la descripcion del tipo de pasajero ayudandose de otra funcion
/// @param tipos Tipo de pasajeros (turista, primera clase,economica)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del tipo de pasajero
/// @param descripcion descripcion del tipo de pasajero
/// @return retorno de todo ok si es que las condiciones se cumplen
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);


/// @fn Funcion que busca dentro de la estructura  Tipos, si es que hay datos cargados
/// @param tipos Tipo de pasajeros (turista, primera clase,economica)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del tipo de pasajero
/// @return retorno de esValido si es que hay datos en la estructura
int validarTipo(eTipo tipos[], int tam, int id);

/// @fn Funcion que busca dentro de la estructura los datos cargados y los almacena y modifica mediante un puntero
/// @param tipos Tipo de pasajeros (turista, primera clase,economica)
/// @param tam tamaño de la estructura
/// @param id Codigo identificador del tipo de pasajero
/// @param pIndice Puntero a indice que se modificara si es que hay datos dentro de la estructura
/// @return retorno de todo ok si es que las condiciones se cumplen
int buscarTipo (eTipo tipos[],int tam, int id, int* pIndice);
