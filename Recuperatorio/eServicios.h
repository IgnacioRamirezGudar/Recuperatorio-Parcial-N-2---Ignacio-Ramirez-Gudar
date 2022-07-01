/*
 * eServicios.h
 *
 *  Created on: 29 jun. 2022
 *      Author: ignac
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

struct{

	int id_servicio;
	char descripcion[150];
	int tipo;
	int precioUnitario;
	int cantidad;
	int totalServicio;

}typedef eServicios;

eServicios* Services_new();
eServicios* Services_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioUnitarioStr,char* cantidadStr,char* totalServicioStr);
void Services_delete(eServicios* this);
void Services_printOne(eServicios* this);
int Services_printOnFile(FILE* pFile,eServicios* this);

int Services_setId(eServicios* this,int id);
int Services_getId(eServicios* this,int* id);

int Services_setDescripcion(eServicios* this,char* descripcion);
int Services_getDescripcion(eServicios* this,char* descripcion);

int Services_setTipo(eServicios* this,int tipo);
int Services_getTipo(eServicios* this,int* tipo);

int Services_setPrecioUni(eServicios* this,int precioUni);
int Services_getPrecioUni(eServicios* this,int* precioUni);

int Services_setCantidad(eServicios* this,int cantidad);
int Services_getCantidad(eServicios* this,int* cantidad);

int Services_setTotalServicio(eServicios* this,int totalServicio);
int Services_getTotalServicio(eServicios* this,int* totalServicio);


void descuento(void* pelement);

void calcularTotalPrecio(void* pelement);

int filter_Minorista(void* pelement);

int filter_Mayorista(void* pelement);

int filter_Exportar(void* pelement);

int filter_PrecioProductos(void* pelement);

int Services_compareByDescripcion(void* s1, void* s2);

#endif /* ESERVICIOS_H_ */
