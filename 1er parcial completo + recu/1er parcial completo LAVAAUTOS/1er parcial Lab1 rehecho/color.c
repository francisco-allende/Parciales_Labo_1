#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#define TAM 5


/** \brief color es una FK en la estructura auto. Para no printear un numero, cargo la descripcion del color matcheando ids
 *
 * \param colores[] eColor
 * \param tam int
 * \param idCol int             Id del color del auto a matchear
 * \param descripcion char*     Descripcion en texto del color a cargar segun id matcheado
 * \return int                  Retorna 0 si no pudo cargar la descripcion
 *                              Retorna 1 si pudo cargar la descripcion con exito
 */
int cargarDescripcionColor(eColor colores[], int tam, int idCol, char* descripcion)
{
    int todoOk = 0;

    if(colores != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(colores[i].id == idCol)
            {
                strcpy(descripcion, colores[i].nombreColor);
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Printea todos los colores disponibles para los autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamCol int
 * \return int              Retorna 0 si no pudo printear con exito
 *                          Reoorna 1 si pudo printear con exito
 */
int printColores(eAuto autos[], int tam, eColor colores[], int tamCol)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0 && colores != NULL && tamCol > 0)
    {
        tableTextColores();

        for(int i = 0; i < tamCol; i++)
        {
            printf("%d    %15s  \n", colores[i].id,colores[i].nombreColor);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

/** \brief Tabla para listar colores segun id y descripcion
 *
 * \return void
 *
 */
void tableTextColores()
{
    system("cls");
    printf("     Lista de colores \n\n");
    printf("***********************\n");
    printf("    ID       COLOR            \n");
    printf("************************\n\n");
}

