#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int mostrarColorAElegir(eAuto autos[], eColor colores[], int tam, int colorAMostrar, int tamCol);
int elegirOpcionColor(int colorAElegir);
int mostrarMarcaAElegir(eAuto autos[], eMarca marcas[], int tam, int marcaAMostrar, int tamMar);
int elegirOpcionMarca(int marcaAElegir);
int mostrarMarcaYColor(eAuto autos[], eColor colores[],eMarca marcas[], int tamAuto, int tamMar, int tamCol, int colorAElegir, int marcaAElegir);
int mostrarMarcaMasElegida(eAuto autos[], int tam, eMarca marcas[], int tamMar);
int trabajosPorAuto(eAuto autos[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[],  int tamSer, int autoAMostrar, int* acumulador);
int promedioCajas(eAuto autos[], int tam);
int printCajas(eAuto autos[], int tam);
void printCaja(eAuto unAuto);
int sortAcomodarServicios(eServicio servicios[], int tam);
int servicioElegidoAMostrar(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer, int servicioAElegir);
int mostrarServiciosPorFecha(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer, int fechaMostrarAnio, int fechaMostrarMes, int fechaMostrarDia);







void tableTextCajas();

void  tableTextTrabajoPorAuto();

void tableTextInformeMarcaYColor();




