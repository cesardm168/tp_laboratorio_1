/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author:  Cesar Davila
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}ePassenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief recorre el array de pasajeros y pone en 1 el campo isEmpty de cada posicion
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo Ok y 0 si hubo algun error
 *
 */
int initPassenger(ePassenger* pasajeros, int tam);

/** \brief recorre el array de pasajeros y busca la primer posicion libre, es decir, con el campo esEmpty en 1
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param pIndex int* direccion de memoria de la variable donde se guardara la posicion libre encontrada
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int searchFree(ePassenger* pasajeros, int tam, int* pIndex);

/** \brief permite dar de alta un pasajero ubicandolo en la primer posicion libre del array
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int variable auxiliar para guardar el id
 * \param name[] char variable auxiliar para guardar el name
 * \param lastName[] char variable auxiliar para guardar el lastName
 * \param price float variable auxiliar para guardar el price
 * \param typePassenger int variable auxiliar para guardar el tipo de pasajero
 * \param flycode[] char variable auxiliar para guardar el codigo de vuelo
 * \param pNextId int* puntero a la direccion de memoria de la variable donde se encuentra el id asignado al pasajero
 * \param statusFlight int variable auxiliar para guardar el estado de vuelo
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int addPassenger(ePassenger* pasajeros, int tam, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int* pNextId, int statusFlight);

/** \brief muestra un pasajero
 *
 * \param unPasajero ePassenger  pasajero del array que se desea mostrar
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int showPassenger(ePassenger unPasajero);
/** \brief muestra en pantalla un listado con todos los pasajeros cuyo campo isEmpty este en 0
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listPassenger(ePassenger* pasajeros, int tam);
/** \brief muestra un menu de opciones de modificacion de pasajero y pide seleccionar una
 *
 * \return int retorna la opcion seleccionada
 *
 */

int modifyPassengerMenu();
/** \brief recorre el array de pasajeros y busca al pasajero que tenga el mismo id que le pasamos a la funcion por parametro
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int id del pasajero que deseamos buscar
 * \param pIndex int* puntero a variable donde se guarda el indice del pasajero encontrado. En caso de no encontrarlo pIndex se carga con -1
 * \return int retorna 1 si todo OK y 0 si hubo algun error
 *
 */

int searchPassenger(ePassenger* pasajeros, int tam, int id, int* pIndex);
/** \brief permite realizar la modificacion de alguno de los datos de un pasajero
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */

int modifyPassenger(ePassenger* pasajeros, int tam);

/** \brief realiza la baja logica de un pasajero, es decir, pone su campo isEmpty en 1
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param id int id del pasajero que deseamos dar de baja
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */

int removePassenger(ePassenger* pasajeros, int tam, int id);
/** \brief recorre el array de pasajeros y los ordena por tipo de pasajero y lastName
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param orden int orden en el que queremos que se ordenen los pasajeros 1 para Ascendente 0 para Descendente
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */

int sortPassenger(ePassenger* pasajeros, int tam, int orden);
/** \brief calcula el total de los prices de los vuelos, el promedio de price y cuantos pasajeros superan el promedio
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */

int calcularPromedios(ePassenger* pasajeros, int tam);
/** \brief ordena los pasajeros por estado de vuelo y por codigo de vuelo
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \param orden int orden en el que queremos que se ordenen los pasajeros 1 para Ascendente 0 para Descendente
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */

int sortPassengersByCode(ePassenger* pasajeros, int tam, int orden);

/** \brief muestra en pantalla a todos los pasajeros con vuelos activos
 *
 * \param pasajeros ePassenger* lista de pasajeros
 * \param tam int tamaño de la lista de pasajeros
 * \return int retorna 1 si todo OK o 0 si hubo algun error
 *
 */
int listActivePassenger(ePassenger* pasajeros, int tam);


/// @brief Muestra en la pantalla el menu principal  menu
/// @return Reto
int menu();

/// @fn int hardcodearPassenger(ePassenger[], int, int, int*)
/// @brief Funcion que se utiliza para agregar 10 pasajeros a la fuerza en el abm
///
/// @param vec nombre de la variable de la estructura ePassenger
/// @param tam Tamaño del array Passenger
/// @param cant cantidad de pasajeros agregados a la fuerza
/// @param pId Puntero al id de los pasajeros
/// @return retorna 1 si todo esta ok o 0  si hubo algun error
int hardcodearPassenger(ePassenger vec[], int tam, int cant, int* pId);
