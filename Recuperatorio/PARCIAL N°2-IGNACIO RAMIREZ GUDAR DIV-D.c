/*
 ============================================================================
 Name        : PARCIAL.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
	1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
	del mismo.
	2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
	3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una
	función que asignará a cada servicio el total calculado de la siguiente forma: cantidad x
	totalServicio.
	4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
	servicios del tipo seleccionado.
	5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por
	descripción de manera ascendente.
	6) Guardar servicios: Se deberá guardar el listado del punto anterior en un archivo de texto.
	7) Salir.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "input-UTN.h"
#include "Controller.h"
#include "eServicios.h"


int banderaIngreso = 0;

int getFile(LinkedList* ListServicios);
int listServices(LinkedList* ListServicios);
int filterServices(LinkedList* ListServicios);
int showlist(LinkedList* ListServicios);
int saveTextData(LinkedList* ListServicios);
int descuentoTOTALES(LinkedList* ListServicios);

int main(void) {

	setbuf(stdout, NULL);

	LinkedList* ListServicios = ll_newLinkedList();


	int ingresoDescuento;

	int opciones;

	do{
		UTN_getNumero(&opciones,"\n1) Cargar archivo"
								"\n2) Imprimir lista"
								"\n3) Asignar totales"
								"\n4) Filtrar por tipo"
								"\n5) Mostrar servicios"
								"\n6) Guardar servicios"
								"\n7) Realizar descuentos"
								"\n8) SALIR"
								"\nEliga una opcion: ", "\n ERROR...ELIGA OTRA OPCION: ", 1, 8, 10);

		switch(opciones){
			case 1:
				ingresoDescuento = getFile(ListServicios);
				banderaIngreso = 1;
				break;
			case 2:
				if(banderaIngreso == 1){
					listServices(ListServicios);
				} else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			case 3:
				if(banderaIngreso == 1){
					ll_map(ListServicios, calcularTotalPrecio);
				} else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			case 4:
				if(banderaIngreso == 1){
					filterServices(ListServicios);
				} else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			case 5:
				if(banderaIngreso == 1){
					showlist(ListServicios);
				} else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			case 6:
				if(banderaIngreso == 1){
					saveTextData(ListServicios);
				}else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			case 7:
				if(banderaIngreso == 1){
					if(ingresoDescuento == 1){
						descuentoTOTALES(ListServicios);
					} else {
						printf("\n-ERROR...PARA REALIZAR ESTA OPCION NECESITA HACER LOS CALCULOS TOTALES Y DESPUES FILTRARLOS POR PRECIOS MAYOR A 1000");
					}
				}else {
					printf("\n-ERROR...PRIMERO DEBE CARGAR UN ARCHIVO");
				}
				break;
			default:
				return 0;
				break;
		}

	}while(opciones != 8);

	return 0;
}


int getFile(LinkedList* ListServicios){

	char nombreArchivo[51];
	char archivo[51];
	int retorno;

	printf("\n\n========================================BUSCAR ARCHIVOS==========================================");
	printf("\n-Ingrese nombre del archivo: ");
	fflush(stdin);
	gets(nombreArchivo);
	strcat(nombreArchivo,".csv");
	strcpy(archivo, nombreArchivo);

	if(strcmp(archivo,"productosMayor.csv") == 0){
		retorno = 1;
	} else {
		retorno = 0;
	}

	controller_loadFromText(archivo , ListServicios);

	return retorno;
}


int listServices(LinkedList* ListServicios){

	printf("\n\n========================================LISTA SERVICIOS DEL TALLER==========================================");
	controller_ListSevices(ListServicios);
	printf("\n\n============================================================================================================");
	printf("\n");
	system("pause");
	return 0;
}


int filterServices(LinkedList* ListServicios){

	LinkedList* auxNewList;

	int opciones;
	char archivo[20];

	UTN_getNumero(&opciones,"\nINGRESE EL TIPO DE ARCHIVO A GENERAR"
							"\n1) MINORISTA"
							"\n2) MAYORISTA"
							"\n3) EXPORTAR"
							"\n4) Productos cuyo precio total sea mayor a 1000."
							"\n5) SALIR"
							"\nEliga una opcion: ", "\n ERROR...ELIGA OTRA OPCION: ", 1, 5, 10);

	switch(opciones){
		case 1:
			auxNewList = ll_filter(ListServicios, filter_Minorista);
			strcpy(archivo, "minorista.csv");
			if (controller_saveAsText(archivo, auxNewList) == 0){
				printf("\n|==================SE GENERO UN ARCHIVO CON ESTOS DATOS GUARDADOS========|");
				printf("\n");
				system("pause");
			}
			break;
		case 2:
			auxNewList = ll_filter(ListServicios, filter_Mayorista);
			strcpy(archivo, "mayorista.csv");
			if (controller_saveAsText(archivo, auxNewList) == 0){
				printf("\n|==================SE GENERO UN ARCHIVO CON ESTOS DATOS GUARDADOS========|");
				printf("\n");
				system("pause");
			}
			break;
		case 3:
			auxNewList = ll_filter(ListServicios, filter_Exportar);
			strcpy(archivo, "exportar.csv");
			if (controller_saveAsText(archivo, auxNewList) == 0){
				printf("\n|==================SE GENERO UN ARCHIVO CON ESTOS DATOS GUARDADOS========|");
				printf("\n");
				system("pause");
			}
			break;
		case 4:
			auxNewList = ll_filter(ListServicios, filter_PrecioProductos);
			strcpy(archivo, "productosMayor.csv");
			if (controller_saveAsText(archivo, auxNewList) == 0){
				printf("\n|==================SE GENERO UN ARCHIVO CON ESTOS DATOS GUARDADOS========|");
				printf("\n");
				system("pause");
			}
			break;
		default:
			return 0;
			break;
	}
	return 0;
}


int showlist(LinkedList* ListServicios){

	int opciones;

	UTN_getNumero(&opciones,"\n|=======================MOSTRAR LISTA=======================|"
							"\n1-Ordenar tipo de servicios de manera ascendente"
							"\n2-Ordenar tipo de servicios de manera descendente"
							"\n3-Salir"
							"\nIngrese un opcion: ","\ERROR AL INGRESAR UNA OPCION  \n INGRESE UNA OPCION VALIDA: ", 1,3,5);

	controller_sortSevices(ListServicios, opciones);
	return 0;
}


int saveTextData(LinkedList* ListServicios){

	int opciones;

	char archivo[20];

	UTN_getNumero(&opciones,"\n|=======================GUARDAR LISTA ACTUAL=======================|"
							"\n-DESEA GUARDAR LA LISTA ACTUAL?"
							"\n1-SI"
							"\n2-NO"
							"\nIngrese un opcion: ","\ERROR AL INGRESAR UNA OPCION  \n INGRESE UNA OPCION VALIDA: ", 1,2,5);

	switch(opciones){
		case 1:
			strcpy(archivo, "listaOrdenada.csv");
			controller_saveAsText(archivo, ListServicios);
			break;
		case 2:
			return 0;
			break;
	}
	return 0;
}


int descuentoTOTALES(LinkedList* ListServicios){

	int opciones;

	char archivo[20];

	UTN_getNumero(&opciones,"\n|=======================DESCUENTOS=======================|"
							"\n-DESEA REALIZAR LOS DESCUENTOS DEL 10%?"
							"\n1-SI"
							"\n2-NO"
							"\nIngrese un opcion: ","\ERROR AL INGRESAR UNA OPCION: ", 1,2,5);

	switch(opciones){
		case 1:
			ll_map(ListServicios, descuento);
			strcpy(archivo, "descuentos.csv");
			controller_saveAsText(archivo, ListServicios);
			break;
		case 2:
			return 0;
			break;
	}

	return 0;
}
