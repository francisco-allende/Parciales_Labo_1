#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

struct
{
    int id;
	int idMarca;
    int idColor;
    char caja;
    int isEmpty;

} typedef eAuto;


#endif // AUTO_H_INCLUDED

int initAuto(eAuto autos[], int tam, int start);
int searchFreePosition(eAuto autos[], int tam);
int arrayHasCars(eAuto autos[], int tam);
int addAuto(eAuto autos[], int tam, int indiceLibre, int* pId, eMarca marcas[], int tamMar, eColor colores[], int tamCol);
int printAuto(eAuto unAuto, eMarca marcas[], int tamMar, eColor colores[], int tamCol);
//int printAuto(eAuto autos[i], int indice, eMarca marcas[], int tamMar, eColor colores[], int tamCol);
void tableText();
int subMenuInformes(int* opcion);
int askForId(eAuto autos[], int tam, int id);
int removeAuto(eAuto autos[], int tam, int indice);
int findAutoById(eAuto autos[], int tam, int id);
int printAutos(eAuto autos[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCol);
int sortAutos(eAuto autos[], int tam, int* opcion);
int modifyAuto(eAuto autos[], int indice, int* opcion, eMarca marcas[], int tamMar, eColor colores[], int tamCol);
int printMarcas(eAuto autos[], int tam, eMarca marcas[], int tamMar);
int printMarca(eAuto autos[], int indice, eMarca marcas[], int tamMar);
int printColor(eAuto autos[], int indice, eColor colores[], int tamCol);
//int printColor(eAuto unAuto, eColor unColor, int tamCol);
int printColores(eAuto autos[], int tam, eColor colores[], int tamCol);
int sortReacomodar(eAuto autos[], int tam);
int hardcodearAutosBD(eAuto autos[], int tam);
//int hardcodearAutosBD(eAuto autos[], int tam, eColor colores[], int tamCol, eMarca marcas[], int tamMar);
int addTrabajo(eTrabajo trabajos[], int tam, int indiceLibre, int* pId, eServicio servicios[], int tamSer, eAuto autos[], int tamAuto, int* idTrabajo);
int printTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamSer);
int printTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer);
int printServicio(eTrabajo trabajos[], int indice, eServicio servicios[], int tamSer);
int printServicios(eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer);



