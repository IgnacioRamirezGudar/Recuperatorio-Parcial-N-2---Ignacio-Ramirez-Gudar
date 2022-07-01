/*
 * eServicios.c
 *
 *  Created on: 29 jun. 2022
 *      Author: ignac
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "eServicios.h"

eServicios* Services_new(){

	eServicios* AuxPassenger;
	AuxPassenger = (eServicios*)malloc(sizeof(eServicios));
	return AuxPassenger;

}


eServicios* Services_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr){

	eServicios* auxServicies;

	auxServicies = Services_new();

	Services_setId(auxServicies,atoi(idStr));
	Services_setDescripcion(auxServicies,descripcionStr);
	Services_setTipo(auxServicies,atoi(tipoStr));
	Services_setPrecioUni(auxServicies,atoi(precioUnitarioStr));
	Services_setCantidad(auxServicies,atoi(cantidadStr));
	Services_setTotalServicio(auxServicies,atoi(totalServicioStr));

	if((idStr==NULL) && (descripcionStr==NULL) && (tipoStr==NULL) && (precioUnitarioStr==NULL) && (cantidadStr==NULL) && (totalServicioStr==NULL))
	{
		Services_delete(auxServicies);

		if(auxServicies == NULL)
		{
			Services_delete(auxServicies);
		}
	}

	return auxServicies;

}

void Services_delete(eServicios* this){

	free(this);

}


void Services_printOne(eServicios* this){

	char type[20];
	int id_servicio;
	char descripcion[150];
	int tipo;
	int precioUnitario;
	int cantidad;
	int totalServicio;

	Services_getId(this, &id_servicio);
	Services_getDescripcion(this, descripcion);
	Services_getTipo(this, &tipo);
	Services_getPrecioUni(this, &precioUnitario);
	Services_getCantidad(this, &cantidad);
	Services_getTotalServicio(this, &totalServicio);


	if(tipo == 1){
		strcpy(type, "MINORISTA");
	} else {
		if(tipo == 2){
			strcpy(type, "MAYORISTA,");
		} else {
			if(tipo == 3){
				strcpy(type, "EXPORTAR");
			}
		}
	}

	printf("|ID:%d||DESCRIPCION: %s||\tTIPO: %3s||PRECIO UNITARIO: %10d||CANITDAD: %10d||TOTAL SERVICIO: %10d|\n", id_servicio,descripcion,type,precioUnitario,cantidad,totalServicio);
}


/*
 *
 */
int Services_printOnFile(FILE* pFile,eServicios* this){

	int retorno;
	retorno = -1;

	int id_servicio;
	char descripcion[150];
	int tipo;
	int precioUnitario;
	int cantidad;
	int totalServicio;

	if(pFile!=NULL && this!=NULL){

		if(Services_getId(this, &id_servicio) == 1 && Services_getDescripcion(this, descripcion) == 1 && Services_getTipo(this, &tipo) == 1 && Services_getPrecioUni(this, &precioUnitario) == 1 &&
				Services_getCantidad(this,&cantidad) == 1 && Services_getTotalServicio(this,&totalServicio)){

				fprintf(pFile,"%d,%s,%d,%d,%d,%d\n",id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio);
		}


		retorno = 0;
	}


	return retorno;
}



/*-----------------------------------| ID |---------------------------------
 *
 *
 */

int Services_setId(eServicios* this,int id){

	int retorno;
	retorno=0;

	if(this!=NULL && id>0){
		this->id_servicio = id;
		retorno=1;
	}

	return retorno;
}


int Services_getId(eServicios* this,int* id){

	int retorno;
	retorno=0;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id_servicio;
		retorno=1;
	}

	return retorno;

}


/*-----------------------------------| DESCRIPCION |----------------------------------
 *
 *
 *
 */

int Services_setDescripcion(eServicios* this,char* descripcion){

	int retorno;
	retorno=0;

	if(this!=NULL && descripcion!=NULL){
		strcpy(this->descripcion,descripcion);
		retorno=1;
	}

	return retorno;

}


int Services_getDescripcion(eServicios* this,char* descripcion){

	int retorno;
	retorno=0;

	if(this!=NULL && descripcion!=NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno=1;
	}

	return retorno;

}


/*------------------------------------| TIPO |---------------------------
 *
 *
 *
 */

int Services_setTipo(eServicios* this,int tipo){

	int retorno;
	retorno=0;

	if(this!=NULL && tipo>0){
		this->tipo = tipo;
		retorno=1;
	}

	return retorno;

}


int Services_getTipo(eServicios* this,int* tipo){

	int retorno;

	retorno = 0;

	if (this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}

	return retorno;
}


/*-------------------------------| PRECIO UNITARIO |----------------------------------
 *
 *
 *
 */

int Services_setPrecioUni(eServicios* this,int precioUni){

	int retorno;
	retorno=0;

	if(this!=NULL && precioUni > -1){
		this->precioUnitario = precioUni;
		retorno=1;
	}

	return retorno;
}


int Services_getPrecioUni(eServicios* this,int* precioUni){

	int retorno;
	retorno=0;

	if(this!=NULL && precioUni!=NULL)
	{
		*precioUni = this->precioUnitario;
		retorno=1;
	}

	return retorno;

}


/*------------------------------| CANTIDAD |-----------------------------
 *
 *
 *
 */

int Services_setCantidad(eServicios* this,int cantidad){

	int retorno;
	retorno=0;

	if(this!=NULL && cantidad>0){
		this->cantidad = cantidad;
		retorno=1;
	}

	return retorno;

}


int Services_getCantidad(eServicios* this,int* cantidad){

	int retorno;
	retorno=0;

	if(this!=NULL && cantidad!=NULL)
	{
		*cantidad = this->cantidad;
		retorno=1;
	}

	return retorno;

}


/*-----------------------------| TOTAL SERVICIOS |------------------------------------
 *
 *
 *
 */

int Services_setTotalServicio(eServicios* this,int totalServicio){

	int retorno;
	retorno=0;

	if(this!=NULL && totalServicio > -1){
		this->totalServicio = totalServicio;
		retorno=1;
	}

	return retorno;

}


int Services_getTotalServicio(eServicios* this,int* totalServicio){

	int retorno;
	retorno=0;

	if(this!=NULL && totalServicio!=NULL)
	{
		*totalServicio = this->totalServicio;
		retorno=1;
	}

	return retorno;

}


/*-----------------------------| CALCULAR TOTALES Y DESCUENTOS|------------------------------------
 *
 *
 *
 */

void calcularTotalPrecio(void* pelement){

	eServicios* auxServicies = pelement;

	int tot;

    if(pelement != NULL)
    {
    	tot = (int)auxServicies->cantidad * auxServicies->precioUnitario;
    	Services_setTotalServicio(auxServicies, tot);
    }
}

void descuento(void* pelement){

	eServicios* auxServicies = pelement;

	int totdescuento;

	int descuento;

	descuento = 10;

    if(pelement != NULL)
    {
    	totdescuento = (int) auxServicies->totalServicio - (auxServicies->totalServicio*descuento/100);
    	Services_setTotalServicio(auxServicies, totdescuento);
    }

}

/*-----------------------------| FILTRO POR TIPO |------------------------------------
 * 	Realizo el filtro  de minorista, mayorista y exportar , para luego parasarlo a la funcion ll_filter.
 *
 */

int filter_Minorista(void* pelement){

	eServicios* auxServicesType = pelement;
    int retorno = 0;

    if(auxServicesType != NULL)
    {
		 if(auxServicesType->tipo == 1)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}


int filter_Mayorista(void* pelement){

	eServicios* auxServicesType = pelement;
    int retorno = 0;

    if(auxServicesType != NULL)
    {
		 if(auxServicesType->tipo == 2)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}


int filter_Exportar(void* pelement){

	eServicios* auxServicesType = pelement;
    int retorno = 0;

    if(auxServicesType != NULL)
    {
		 if(auxServicesType->tipo == 3)
		 {
			retorno = 1;
		 }
    }
    return retorno;
}


int filter_PrecioProductos(void* pelement){

	eServicios* auxServicesType = pelement;

    int retorno = 0;

    if(auxServicesType != NULL)
    {
		 if(auxServicesType->totalServicio > 1000)
		 {
			retorno = 1;
		 }
    }
    return retorno;

}

/*-----------------------------| COMPARACIONES |------------------------------------
 *
 *
 */
int Services_compareByDescripcion(void* s1, void* s2){

	char services_Uno[50];
	char servicies_Dos[50];

	int compare;

	eServicios* firstServicio = s1;
	eServicios* secondServicio = s2;

	Services_getDescripcion(firstServicio, services_Uno);
	Services_getDescripcion(secondServicio, servicies_Dos);

	compare = strcmp(services_Uno, servicies_Dos);

	return compare;
}
