#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "input-UTN.h"
#include "eServicios.h"

/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicios){

	int retorno;

	retorno = 1;


	if(path!=NULL && pArrayListServicios!=NULL)
	{

		FILE* pFile = fopen(path,"r");

		if(parser_ServicesFromText(pFile, pArrayListServicios) == 0){

			retorno = -1;

		}

		fclose(pFile);
	}

    return retorno;
}


/** \brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int controller_ListSevices(LinkedList* pArrayListServicios){

	eServicios* auxServicies;

	int retorno;

	int sizeList;

	retorno = 0;

	if(pArrayListServicios!=NULL)
	{
		sizeList = ll_len(pArrayListServicios);

		for(int i=0; i < sizeList; i++)
		{
			auxServicies = (eServicios*) ll_get(pArrayListServicios, i);

			Services_printOne(auxServicies);
		}
		retorno = 1;
	}

    return retorno;
}


/* \brief Guarda los datos de los servicios en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicios){

	eServicios* auxServicies = NULL;

	int retorno;

	retorno = 1;

	int cantidadDatos;

	if(path!=NULL && pArrayListServicios!=NULL){

		FILE* pFile = fopen(path,"w");

		cantidadDatos = ll_len(pArrayListServicios);

		fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id_servicio","descripcion","tipo","precioUnitario","cantidad","totalServicio");

		for(int i = 0; i < cantidadDatos; i++){

			auxServicies = (eServicios*) ll_get(pArrayListServicios,i);
			Services_printOnFile(pFile,auxServicies);

		}
		if(!fclose(pFile)){

			retorno = 0;

		}

	}


    return retorno;
}


/** \brief Ordenar servicios
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */

int controller_sortSevices(LinkedList* pArrayListServicios,int opciones){

	   int retorno;

	   retorno=0;

	   switch(opciones){

	   	   case 1:
	   		   ll_sort(pArrayListServicios, Services_compareByDescripcion, 1);
	   		   break;
	   	   case 2:
	   		   ll_sort(pArrayListServicios, Services_compareByDescripcion, 0);
	   		   break;
	   	   default:
	   		   break;
	   }

	   return retorno;
}
