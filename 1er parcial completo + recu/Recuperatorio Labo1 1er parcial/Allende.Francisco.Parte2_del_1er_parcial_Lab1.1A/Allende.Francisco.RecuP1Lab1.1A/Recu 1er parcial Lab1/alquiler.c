#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "cliente.h"
#include "inputs.h"

#define FINALIZADO 1
#define ALQUILADO 0


/** \brief incializa el estado de los alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int initAlquiler(eAlquiler alquileres[], int tam)
{
    int todoOk = 0;

    if(alquileres != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            alquileres[i].estado = FINALIZADO;
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief busca una posicion libre para los alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int searchFreePositionAlq(eAlquiler alquileres[], int tam)
{
    int indiceLibre = -1;

    if(alquileres != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(alquileres[i].estado == FINALIZADO)
            {
                indiceLibre = i;
                break;
            }
        }
    }

    return indiceLibre;
}

/** \brief busca un alquiler por id
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \param id int
 * \return int
 *
 */
int findAlquilerById(eAlquiler alquileres[], int tam, int id)
{
    int indice = -1;

    if(alquileres != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(alquileres[i].id == id && alquileres[i].estado == ALQUILADO)
            {
                indice = i;
                break;
            }
        }
    }


    return indice;
}


/** \brief valida que haya al menos un alquiler cargado
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int arrayHasAlquileres(eAlquiler alquileres[], int tam)
{
    int todoOk = 0;

    if(alquileres != NULL && tam  > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(alquileres[i].estado == ALQUILADO)
            {
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}

/** \brief añade un nuevo alquiler al array de alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \param indice int
 * \param pidAlq int*
 * \param clientes[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int addAlquiler(eAlquiler alquileres[], int tam, int indice, int* pidAlq, eCliente clientes[], int tamCli)
{
    int todoOk = 0;
    eAlquiler auxAlq;

    if(alquileres != NULL && tam > 0 && indice >= 0 && pidAlq != NULL)
    {
        system("cls");
        printf("*** Carga de alquiler al Sistema ****\n\n");
        printf("\nTenemos lugar libre para un alquiler!\n\n");

        //Asigno auxiliar y el id
        alquileres[indice] = auxAlq;
        auxAlq.id = (*pidAlq);


        printf("\n\n");
        printf("Ingrese el equipo: ");
        fflush(stdin);
        scanf("%s", auxAlq.equipo);
        while(!validarChar(auxAlq.equipo, 2, 30))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxAlq.equipo);
        }

        printClientes(clientes, tamCli);
        printf("\nIngrese id del cliente: ");
        scanf("%d", &auxAlq.idCliente);
        findClienteById(clientes, tamCli, auxAlq.idCliente);



        printf("\n\n");
        printf("Ingrese el nombre del operador: ");
        fflush(stdin);
        scanf("%s", auxAlq.operador);
        while(!validarChar(auxAlq.operador, 2, 30))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxAlq.operador);
        }


        printClientes(clientes, tamCli);
        printf("\nIngrese el tiempo estimado de alquiler (esta en dias): ");
        scanf("%d", &auxAlq.tiempoEstimado);
        while(auxAlq.tiempoEstimado < 0 || auxAlq.tiempoEstimado > 99999999)
        {
            printf("Error. Vuelva a intentar: ");
            scanf("%d", &auxAlq.tiempoEstimado);
        }

        auxAlq.estado = ALQUILADO;
        alquileres[indice] = auxAlq;

        //id Autoincremental
        (*pidAlq)++;

        todoOk = 1;
    }

    return todoOk;
}

/** \brief muestra un alquiler
 *
 * \param unAlq eAlquiler
 * \return void
 *
 */
void printAlq(eAlquiler unAlq)
{
    printf("%3d   %15s  %d   %15s %d dias\n",
           unAlq.id,
           unAlq.equipo,
           unAlq.idCliente,
           unAlq.operador,
           unAlq.tiempoEstimado
          );
}

/** \brief cambia el estado de alquiler por FINALIZADO
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \param idAlquilerFin int
 * \return int
 *
 */
int finAlquiler(eAlquiler alquileres[], int tam, int idAlquilerFin)
{
    int todoOk = 0;
    int tiempoReal;

    if(alquileres != NULL && idAlquilerFin != -1)
    {

        printf("Cual fue el tiempo real de alquiler? (en dias)\n");
        scanf("%d", &tiempoReal);
        while(tiempoReal < 0)
        {
            printf("Error, intente otra vez.\n");
            scanf("%d", &tiempoReal);
        }

        for(int i = 0; i < tam; i++)
        {
            if(alquileres[i].estado == ALQUILADO && alquileres[i].id == idAlquilerFin)
            {
                alquileres[i].estado = FINALIZADO;
                alquileres[i].tiempoReal = tiempoReal;
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief promedio de tiempo real
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \return int
 *
 */
int promedioTiempoReal(eAlquiler alquileres[], int tam)
{
    int todoOk = 0;

    int acumuladorReal = 0;
    int contadorReal = 0;
    int contadorTotal = 0;
    float promedioReal = 0;

    for(int i = 0; i< tam; i++)
    {
        if(alquileres[i].tiempoReal > 0)
        {
            acumuladorReal = acumuladorReal + alquileres[i].tiempoReal;
            contadorReal++;
            todoOk = 1;

        }
        contadorTotal++;
    }

    promedioReal = (float) (contadorTotal * acumuladorReal) / contadorReal;


    printf("El tiempo promedio real por uso de los euqipos es de: %.2f dias\n\n", promedioReal);


    return todoOk;
}

/** \brief cleinte con mas alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tamAlq int
 * \param clientes[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int clienteConMasAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli)
{
    int todoOk = 0;
    int contadores[10] = {0};
    int contadorMayor;
    int flagMayor = 1;
    int indice;

    if(alquileres != NULL && tamAlq >0 && clientes != NULL && tamCli > 0)
    {
        system("cls");
        printf("Informe del cliente con mas alquileres\n");
        printf("*********************************************\n");

        //Cargo los valores del contador.
        for(int i = 0; i < tamCli; i++)
        {
            for(int j = 0; j < tamAlq; j++)
            {
                if(alquileres[j].estado == ALQUILADO && alquileres[j].idCliente  == clientes[i].id)
                {
                    contadores[i]++;
                }
            }
        }

        //Ya cargado el array contador, saco el maximo tambien con iteracion
        for(int i = 0; i < tamCli; i++)
        {
            if(flagMayor || contadores[i] > contadorMayor)
            {
                contadorMayor = contadores[i];
                indice = i;
                flagMayor = 0;
            }
        }

        for(int i = 0; i < tamCli; i++)
        {
            if(indice == i)
            {
                printf("El cliente con mayor cantidad de alquileres es %s %s y posee %d\n",
                       clientes[i].nombre,
                       clientes[i].apellido,
                       contadorMayor);
                break;
            }
        }


        todoOk = 1;
    }


    return todoOk;
}


/** \brief muestra cleinte y alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tamAlq int
 * \param clientes[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int printClientAndAlq(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli)
{
    int todoOk = 0;

    if(alquileres != NULL && clientes != NULL && tamAlq > 0 && tamCli >0)
    {
        for(int i = 0; i < tamAlq; i++)
        {
            if(clientes[i].isEmpty == 0 && alquileres[i].estado == ALQUILADO)
            {
                printAlqConNombre(alquileres[i], clientes[i]);
            }
        }
    }


    return todoOk;
}


/** \brief printea un alquiler y un cliente
 *
 * \param unAlq eAlquiler
 * \param unCliente eCliente
 * \return void
 *
 */
void printAlqConNombre(eAlquiler unAlq, eCliente unCliente)
{

    printf("%3d   %15s  %15s   %15s %d  %d   %d dias\n",
           unAlq.id,
           unAlq.equipo,
           unCliente.nombre,
           unCliente.apellido,
           unCliente.dni,
           unCliente.id,
           unAlq.tiempoEstimado
          );
}































































