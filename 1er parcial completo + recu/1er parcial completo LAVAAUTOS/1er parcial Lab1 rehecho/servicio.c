#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM 4

/** \brief Carga la descripcion a texto del servicio y su correspondiente precio por trabajo
 *
 * \param servicios[] eServicio
 * \param tam int
 * \param idSer int                 Id del servicio a cargar descripcion y precio
 * \param descripcion char*         Descripcion a cargar
 * \param precioServicio int*       Precio a cargar
 * \return int                      Retorna 0 si no pudo cargar precio || descripcion
 *                                  Retorna 1 si pudo cargar precio && descripcion
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int idSer, char* descripcion, int* precioServicio)
{
    int todoOk = 0;

    if(servicios != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(servicios[i].id == idSer)
            {
                *precioServicio = servicios[i].precio;
                strcpy(descripcion, servicios[i].descripcion);
                break;
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


/** \brief Printea todos los servicios con sus ids, descripciones y precios
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int                  Retorna 0 si no pudo mostrar los servicios
 *                              Retorna 1 si muestra con exito los servicios
 */
int printServicios(eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer)
{
    int todoOk = 0;

    if(trabajos != NULL && tam > 0 && servicios != NULL && tamSer > 0)
    {
        tableTextServicio();

        for(int i = 0; i < tamSer; i++)
        {
            printf("%d %15s\t  %d\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}

/*
int printServicio(eTrabajo trabajos[], int indice, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    char descripcionServicios[25];
    int precioServicio;

    if(!cargarDescripcionServicio(servicios, tamSer, trabajos[indice].idServicio, descripcionServicios, &precioServicio))
    {
        printf("Hubo un error al intentar mostrar la descripcion en texto del servicio. \n\n");
    }
    if(trabajos != NULL && indice > -1)
    {
        printf("%3d\t   %15s\t     %3d\n",
               trabajos[indice].id,
               descripcionServicios,
               precioServicio
              );

        todoOk = 1;
    }

    return todoOk;
}
*/

/** \brief Tabla con los servicios por id, descripcion y precio
 *
 * \return void
 *
 */
void tableTextServicio()
{
    system("cls");
    printf("     LISTA DE SERVICIOS \n\n");
    printf("************************************\n");
    printf("ID\t      SERVICIO    PRECIO      \n");
    printf("************************************\n");
}


