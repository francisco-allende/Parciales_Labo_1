#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

/* SOlo trabajo */

int idTrabajoBD[TAM] = {8000, 8001, 8002, 8003, 8004, 8005, 8006, 8007, 8008, 8009};

int idPatentesTrabajoBD[TAM] = {100, 100, 102, 104, 106, 100, 104, 108, 103, 109};

int idPServiciosTrabajoBD[TAM] = {20000, 20003, 20000, 20001, 20002, 20002, 20003, 20003, 20001, 20001};

/* Solo fecha */

int diasBD[TAM] = {1, 1, 1, 2, 2, 3, 3, 3 , 4, 5};
int mesesBD[TAM] = {1, 1, 1, 2, 2, 3, 3, 11 , 4, 5};
int aniosBD[TAM] = {2019, 2019, 2019, 2020, 2020, 2021, 2021, 2021 , 1999, 1988};

/** \brief Hardcodea un array de trabajos a modo de tener un BBDD para testear
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int                  Retorna -1 si no pudo hardcodear con exito
 *                              Retorna la cantidad de trabajos hardcodeados si todo salio bien
 */
int hardcodearTrabajosBD(eTrabajo trabajos[], int tam)
{
	int contador = -1;

	if(trabajos != NULL && tam > 0)
	{
		contador = 0;
		for(int i = 0 ; i < 10; i++)
		{
			trabajos[i].id = idTrabajoBD[i];
			trabajos[i].patente = idPatentesTrabajoBD[i];
			trabajos[i].idServicio = idPServiciosTrabajoBD[i];
			trabajos[i].fecha.dia = diasBD[i];
			trabajos[i].fecha.mes = mesesBD[i];
			trabajos[i].fecha.anio = aniosBD[i];
			trabajos[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
























