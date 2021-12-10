#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "inputs.h"

/*----------------------------------------------------------*/
/* ------------      ALTA  TRABAJO        ------------------*/
/*----------------------------------------------------------*/

/** \brief Inicializa en isEmpty = 1 las posiciones vacias del array estatico de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param start int  Al usar dataWarehouse, necesito indicar desde donde arrancar y evitar isEmpty 1 en mi BBDD
 * \return int      Retorna 1 si pudo inicializar con exito
 *                  0 si algo fallo
 *
 */
int initTrabajo(eTrabajo trabajos[], int tam, int start)
{
    int todoOk = 0;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = start; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}



/** \brief Busca posicion libre en array de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int      Retorna -1 si no hay lugar libre
 *                  Retorna el indice libre si encunetra uno disponible
 */
int searchFreePositionTrabajo(eTrabajo trabajos[], int tam)
{
    int indiceLibre = -1;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                indiceLibre = i;
                break;
            }
        }
    }


    return indiceLibre;
}

/** \brief Valida que haya al menos un auto cargado al array de autos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int      Retorna 0 si no hay ningun auto cargado al array
 *                  Retorna 1 si hay al menos un auto cargado al array
 */
int arrayHasJobs(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;

    if(trabajos != NULL && tam  > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

/** \brief Añade un nuevo trabajo la array de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param indiceLibre int    Previamente se valido que haya espacio para un nuevo auto en search free position
 * \param patente int*              Id del auto
 * \param servicios[] eServicio     Array de la estructura marca
 * \param tamSer int
 * \param autos[] eAuto             Array de la estructura auto
 * \param tamAuto int
 * \param idTrabajo int*            Id autoincrremental
 * \return int                      Retorna 0 si no pudo cargar el nuevo trabajo al array de trabajos
 *                                  Retorna 1 si cargo con exito un nuevo trabajo al array de trabajos
 */
int addTrabajo(eTrabajo trabajos[], int tam, int indiceLibre, int* patente, eServicio servicios[], int tamSer, eAuto autos[], int tamAuto, int* idTrabajo)
{
    int todoOk = 0;
    eTrabajo auxTrabajo;

    if( tamAuto > 0 && trabajos != NULL)
    {
        printf("*** Carga de trabajo al Sistema ****\n\n");
        printf("\nTenemos lugar libre para un trabajo!\n\n");

        //trabajos[indiceLibre] = auxTrabajo;
        auxTrabajo = trabajos[indiceLibre];
        auxTrabajo.id = (*idTrabajo);

        printf("Ingrese la patente del auto (el id): ");
        fflush(stdin);
        scanf("%d", &auxTrabajo.patente);

        while((findAutoById(autos, tam, auxTrabajo.patente)) == -1)
        {
            printf("Ese id de auto no existe. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.patente);
        }

        printf("\n\nSiendo: \n");
        printf("Lavado ($450)\t\t 20000 \n");
        printf("Pulido ($500)\t\t 20001 \n");
        printf("Encerado ($600)\t\t 20002 \n");
        printf("Completo ($900)\t\t 20003 \n");
        printf("\nIngrese el Id del color: ");
        fflush(stdin);
        scanf("%d", &auxTrabajo.idServicio);
        while(auxTrabajo.idServicio < 20000 || auxTrabajo.idServicio > 20003)
        {
            printf("Ese id de marca no existe. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%d", &auxTrabajo.idServicio);
        }

        printf("ingrese la fecha: ");
        fflush(stdin);
        scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
        while(!validateDate(auxTrabajo.fecha.dia, auxTrabajo.fecha.mes, auxTrabajo.fecha.anio))
        {
            printf("Fecha invalida, vuelva a intentar: ");
            fflush(stdin);
            scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
        }

        auxTrabajo.isEmpty = 0;
        trabajos[indiceLibre] = auxTrabajo;

        (*idTrabajo)++;//incremento de id dinamico

        todoOk = 1;
    }

    return todoOk;
}




/** \brief Itera el array de trabajos y le envia a printTrabajo todos los autos a mostrar
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return                      Retorna 0 si no pudo realizar la iteracion
 *                              Retorna 1 si pudo realizar la iteracion con exito
 */
int printTrabajos(eTrabajo trabajos[], int tam, eServicio servicios[], int tamSer)
{
    int todoOk = 0;

    if(trabajos != NULL && tam > 0 && servicios != NULL && tamSer > 0)
    {
        tableTextTrabajo();

        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                printTrabajo(trabajos[i], servicios, tamSer);
            }
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}


/** \brief imprime individualmente cada trabajo recibido por printTrabajos
 *
 * \param unTrabajo eTrabajo        Trabajo individual recibido en cada iteracion de printTrabajos
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int                  Retorna 1 si pudo mostrar cada trabajo
 *                              Retorna 0 si fallo al mostrar al menos un trabajo
 */
int printTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamSer)
{
    int todoOk = 0;
    char descripcionServicios[25];
    int precioServicio;

    if(!cargarDescripcionServicio(servicios, tamSer, unTrabajo.idServicio, descripcionServicios, &precioServicio))
    {
        printf("Hubo un error al intentar mostrar la descripcion en texto del servicio. \n\n");
    }

    if(tamSer > 0)
    {
        printf("%3d\t\t\t   %3d\t\t  %15s\t   %3d\t   %d/%d/%d \n",
               unTrabajo.id,
               unTrabajo.patente,
               descripcionServicios,
               precioServicio,
               unTrabajo.fecha.dia,
               unTrabajo.fecha.mes,
               unTrabajo.fecha.anio
              );

        todoOk = 1;
    }

    return todoOk;
}

/** \brief Reacomoda el array de trabajos por prolijidad
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int                  Retorna 0 si no pudo reacomodarlo
 *                              Retorna 1 si pudo reacomodar el array con exito
 */
int sortReacomodarTrabajos(eTrabajo trabajos[], int tam)
{
    int todoOk = 0;

    eTrabajo auxTrabajo;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(
                    (trabajos[i].isEmpty > trabajos[j].isEmpty)
                   || (trabajos[i].isEmpty == trabajos[j].isEmpty)
                )
                {
                    auxTrabajo = trabajos[i];
                    trabajos[i] = trabajos[j];
                    trabajos[j] = auxTrabajo;
                }

            }
        }
    }

    todoOk = 1;

    return todoOk;
}


/** \brief Tabla con los datos de los trabajos
 *
 * \return void
 *
 */
void tableTextTrabajo()
{
    system("cls");
    printf("     LISTA DE TRABAJOS \n\n");
    printf("*******************************************************************************************\n");
    printf("ID DEL TRABAJO        PATENTE (id del auto)       SERVICIO         PRECIO          FECHA\n");
    printf("******************************************************************************************\n\n");
}






