#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 5

/** \brief Carga la descripcion a texto de la marca segun el id numerico recibido en el 3er parametro
 *
 * \param marcas[] eMarca
 * \param tam int
 * \param idMar int             Id a matchear con la descripcion texto
 * \param descripcion char*     Descripcion en texto de la marca a cargar segun id matcheado
 * \return int                  Retorna 0 si no pudo cargar la descripcion
 *                              Retorna 1 si carga la descripcion con exito
 */
int cargarDescripcionMarca(eMarca marcas[], int tam, int idMar, char* descripcion)
{
    int todoOk = 0;

    if(marcas != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(marcas[i].id == idMar)
            {
                strcpy(descripcion, marcas[i].descripcion);
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Printea todas las marcas disponibles para los autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \return int              Retorna 0 si no pudo mostrar todas las marcas
 *                          Retorna 1 si muestra todas las marcas con exito
 */
int printMarcas(eAuto autos[], int tam, eMarca marcas[], int tamMar)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0 && marcas != NULL && tamMar > 0)
    {
        tableTextMarcas();

        for(int i = 0; i < tamMar; i++)
        {
            printf("%d    %15s  \n", marcas[i].id, marcas[i].descripcion);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

/** \brief Tabla que muestra el id de cada marca disponible
 *
 * \return void
 *
 */
void tableTextMarcas()
{
    system("cls");
    printf("     Lista DE AUTOS POR MARCA \n\n");
    printf("*****************\n");
    printf("   ID      MARCA             \n");
    printf("******************\n\n");
}
