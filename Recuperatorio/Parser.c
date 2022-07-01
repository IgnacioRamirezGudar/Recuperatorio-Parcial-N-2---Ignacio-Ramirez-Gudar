#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "eServicios.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServicesFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int ok;
	int escaneo;
	ok=1;

	eServicios* services;


	char id_servicio[50];
	char descripcion[150];
	char tipo[50];
	char precioUnitario[50];
	char cantidad[50];
	char totalServicio[50];

	if(pFile!=NULL && pArrayListServicios!=NULL)
	{

		while(!feof(pFile))
		{

			escaneo = fscanf(pFile,"\n%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]",id_servicio,
																						descripcion,
																						tipo,
																						precioUnitario,
																						cantidad,
																						totalServicio);

			if(escaneo==6)
			{

				services = Services_newParametros(id_servicio, descripcion, tipo, precioUnitario, cantidad, totalServicio);
				ll_add(pArrayListServicios, services);
			}


		}

		ok=0;
	}

    return ok;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
/*int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListServicios)
{
	int resultado;
	resultado=1;
	Passenger* unPasajero;

	int cant;


	if(pFile!=NULL && pArrayListPassenger!=NULL){
		while(!feof(pFile)){
			cant = fread(&unPasajero, sizeof(unPasajero), 1, pFile);
			if(cant != 1){
				if(feof(pFile)){
					break;
				}else {
					printf("\nError en la lectura");
				}
			} else {
				printf("\nID: %d - NOMBRE: %s\n", unPasajero->id, unPasajero->nombre);
				ll_add(pArrayListPassenger, unPasajero);
			}
		}
		resultado = 0;
	}


    return resultado;
}*/
