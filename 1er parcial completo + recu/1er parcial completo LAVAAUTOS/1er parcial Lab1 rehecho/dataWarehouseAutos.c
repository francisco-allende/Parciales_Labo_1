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

#define TAM     10

/* Solo del auto */

int idAutosBD[TAM] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

int idMarcasBD[TAM] = {1000, 1001, 1002, 1003, 1004, 1000, 1000, 1001, 1002, 1003};

int idColoresBD[TAM] ={5000, 5000, 5001, 5003, 5004, 5000, 5001, 5002, 5002, 5000};

char cajaDescripcionesBD[TAM] ={'m', 'a', 'a', 'a', 'm', 'a', 'a', 'm', 'm', 'm'};

/** \brief Hardcodea un array de autos a modo de tener un BBDD para testear
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int          Retorna -1 si no pudo hardcodear el array
 *                      Retorna la cantidad de autos hardcodeados si todo salio con exito
 */
int hardcodearAutosBD(eAuto autos[], int tam)
{
    int contador = -1;
    if(autos != NULL && tam > 0)
    {
        contador = 0;
        for(int i = 0; i < 10; i++)
        {
            autos[i].id = idAutosBD[i];
            autos[i].idMarca = idMarcasBD[i];
            autos[i].idColor = idColoresBD[i];
            autos[i].caja = cajaDescripcionesBD[i];
            autos[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}
