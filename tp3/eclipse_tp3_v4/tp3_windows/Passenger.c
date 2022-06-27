#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"
#include "utn_validaciones.h"


int validacionId(int* id, char* path)
{
    int todoOk = 0;
    FILE* f;
    int auxId = 0;
    if(id != NULL && path != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            if(fscanf(f, "%d",  &auxId) == 1)
            {
                if(auxId > *id)
                {
                    *id = auxId;
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}

int Passenger_setId(Passenger* this,int id)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getId(Passenger* this,int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;

    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
    int todoOk = 0;

    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido, this->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
    int todoOk = 0;

    if(this != NULL && precio>0)
    {
        this->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
    int todoOk = 0;

    if(this != NULL && precio != NULL)
    {
        *precio = this->precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk = 0;

    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(this->codigoVuelo, codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk = 0;

    if(this != NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo, this->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk = 0;

    if(this != NULL && tipoPasajero!=NULL)
    {
        strcpy(this->tipoPasajero, tipoPasajero);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk = 0;

    if(this != NULL && tipoPasajero != NULL)
    {
        strcpy(tipoPasajero, this->tipoPasajero);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int todoOk = 0;

    if(this != NULL && estadoVuelo != NULL)
    {
        strcpy(this->estadoVuelo, estadoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int todoOk = 0;

    if(this != NULL && estadoVuelo != NULL)
    {
        strcpy(estadoVuelo, this->estadoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

void Passenger_delete(Passenger* this)
{
    free(this);
    this = NULL;
}

Passenger* Passenger_new()
{
    Passenger* newPassenger = (Passenger*) malloc(sizeof(Passenger));
    if(newPassenger!=NULL)
    {
        Passenger_setId(newPassenger, 0);
        Passenger_setNombre(newPassenger, " ");
        Passenger_setApellido(newPassenger, " ");
        Passenger_setPrecio(newPassenger, 0);
        Passenger_setCodigoVuelo(newPassenger, " ");
        Passenger_setTipoPasajero(newPassenger, " ");
        Passenger_setEstadoVuelo(newPassenger, " ");
    }
    return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoDeVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
    Passenger* newPassenger = NULL;
    if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && codigoDeVueloStr!=NULL && tipoPasajeroStr!=NULL && estadoVueloStr!=NULL)
    {
        newPassenger = Passenger_new();
        if(newPassenger!=NULL)
        {
            if(!(Passenger_setId(newPassenger, atoi(idStr)) &&
                    Passenger_setNombre(newPassenger, nombreStr) &&
                    Passenger_setApellido(newPassenger, apellidoStr) &&
                    Passenger_setPrecio(newPassenger, atof(precioStr)) &&
                    Passenger_setCodigoVuelo(newPassenger, codigoDeVueloStr)&&
                    Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr)&&
                    Passenger_setEstadoVuelo(newPassenger, estadoVueloStr)))
            {
                Passenger_delete(newPassenger);
            }
        }
    }
    return newPassenger;
}

int newPassenger(Passenger* this, int* id, char* path, LinkedList* pArrayListPassenger)
{
    int todoOk = 0;
    char nombre[128];
    char apellido[128];
    float precio = 0;
    char codigoVuelo[10];
    int tipoPasajero;
    int estadoVuelo;

    char auxPrecio[10];
    char auxTipoPasajero[20];
    char auxEstadoVuelo[20];
    char auxId[10];

    if(id != NULL && path != NULL)
    {

        validacionId(id, path);
        printf("Id: %d\n", *id);
        utn_getString("Ingrese el nombre: ","Error, reingrese: ", 128, 100, nombre);
        utn_getString("Ingrese el apellido: ","Error, reingrese: ", 128, 100, apellido);
        utn_getFloat("Ingrese el precio(1 millones Max.): ", "Error, reingrese: ", 1, 1000000, 100, &precio);

        printf("Ingrese codigo de vuelo (numeros y letras. 7 caracteres en total): ");
        fflush(stdin);
        gets(codigoVuelo);
        while(strlen(codigoVuelo)!=7)
        {
            printf("Error. Reingrese codigo de vuelo (numeros y letras pero menor a 7 caracteres): ");
            fflush(stdin);
            gets(codigoVuelo);
        }
    	printf("_______________________________________\n");
    	printf("|                                      |\n");
    	printf("|        TIPO DE PASAJEROS             |\n");
    	printf("|______________________________________|\n");
    	printf("|                                      |\n");
    	printf("| 1-FirstClass                         |\n");
    	printf("| 2-ExecutiveClass                     |\n");
    	printf("| 3-EconomyClass                       |\n");
    	printf("|______________________________________|\n");
        utn_getInt("Ingrese tipo de pasajero:  ", "Error, reingrese.",1,3,100,&tipoPasajero);
        switch(tipoPasajero)
        {
        case 1:
            strcpy(auxTipoPasajero, "FirstClass");
            break;
        case 2:
            strcpy(auxTipoPasajero, "ExecutiveClass");
            break;
        case 3:
            strcpy(auxTipoPasajero, "EconomyClass");
            break;
        }
        printf("_______________________________________\n");
        printf("|                                      |\n");
        printf("|       ESTADO DE VUELO                |\n");
       	printf("|______________________________________|\n");
       	printf("|                                      |\n");
      	printf("| 1-Aterrizado                         |\n");
      	printf("| 2-En Horario                         |\n");
        printf("| 3-En Horario                         |\n");
        printf("| 4-Demorado                           |\n");
        printf("|______________________________________|\n");
        utn_getInt("Ingrese estado de vuelo : ", "Error, reingrese.",1,4,100,&estadoVuelo);
        switch(estadoVuelo)
        {
        case 1:
            strcpy(auxEstadoVuelo, "Aterrizado");
            break;
        case 2:
            strcpy(auxEstadoVuelo, "En Horario");
            break;
        case 3:
            strcpy(auxEstadoVuelo, "En Vuelo");
            break;
        case 4:
            strcpy(auxEstadoVuelo, "Demorado");
            break;
        }

        itoa(precio,auxPrecio,10);
        itoa(*id,auxId,10);

        this = Passenger_newParametros(auxId,nombre,apellido,auxPrecio,codigoVuelo,auxTipoPasajero,auxEstadoVuelo);
        if(this != NULL)
        {
            todoOk = 1;
            ll_add(pArrayListPassenger, this);
        }
        else
        {
            Passenger_delete(this);
        }
    }
    return todoOk;
}

int mostrarPasajero(Passenger* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    char apellido[128];
    float precio;
    char codigoVuelo[10];
    char tipoPasajero[20];
    char estadoVuelo[20];

    if(this != NULL
       && Passenger_getId(this, &id)
       && Passenger_getNombre(this, nombre)
       && Passenger_getApellido(this, apellido)
       && Passenger_getPrecio(this, &precio)
       && Passenger_getCodigoVuelo(this,codigoVuelo)
       && Passenger_getTipoPasajero(this, tipoPasajero)
       && Passenger_getEstadoVuelo(this, estadoVuelo))
    {
        printf("%6d    %-10s    %-10s    %-10.2f    %-7s       %-14s      %-12s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int passenger_sortNombre(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		retorno = strcmp(passenger1->nombre, passenger2->nombre);
	}
	return retorno;
}

int passenger_sortApellido(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		retorno = strcmp(passenger1->apellido, passenger2->apellido);
	}
	return retorno;
}

int passenger_sortPrecio(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		if(passenger1->precio > passenger2->precio)
		{
			retorno = 1;
		}
		else
		{
			if(passenger1->precio < passenger2->precio)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int passenger_sortCodigoVuelo(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		retorno = strcmp(passenger1->codigoVuelo, passenger2->codigoVuelo);
	}
	return retorno;
}

int passenger_sortTipoPasajero(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		retorno = strcmp(passenger1->tipoPasajero, passenger2->tipoPasajero);
	}
	return retorno;
}

int passenger_sortEstadoVuelo(void* a, void* b)
{
	int retorno = 0;
	Passenger* passenger1;
	Passenger* passenger2;
	if(a != NULL && b != NULL)
	{
		passenger1 = (Passenger*) a;
		passenger2 = (Passenger*) b;

		retorno = strcmp(passenger1->estadoVuelo, passenger2->estadoVuelo);
	}
	return retorno;
}

int menu(){
	int opcion;

	printf("____________________________________________________________________________________\n");
	printf("|                                                                                   |\n");
	printf("|                                        MENU                                       |\n");
	printf("|___________________________________________________________________________________|\n");
	printf("|                                                                                   |\n");
	printf("| 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)       |\n");
	printf("| 2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario)     |\n");
	printf("| 3. Alta de pasajero                                                               |\n");
	printf("| 4. Modificar datos de pasajero                                                    |\n");
	printf("| 5. Baja de pasajero                                                               |\n");
	printf("| 6. Listar pasajeros                                                               |\n");
	printf("| 7. Ordenar pasajeros                                                              |\n");
	printf("| 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)         |\n");
	printf("| 9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)       |\n");
	printf("| 10. Salir                                                                         |\n");
	printf("|                                                                                   |\n");
	printf("|___________________________________________________________________________________|\n");
	utn_getInt("Ingrese una opcion: ", "Opcion no valida ", 1, 10, 5, &opcion);
	return opcion;
}

