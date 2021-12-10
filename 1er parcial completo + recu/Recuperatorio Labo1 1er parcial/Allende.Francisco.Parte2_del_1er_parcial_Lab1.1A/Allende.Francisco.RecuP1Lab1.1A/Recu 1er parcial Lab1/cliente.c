#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "inputs.h"
#include "alquiler.h"


int initCliente(eCliente clientes[], int tam)
{
    int todoOk = 0;

    if(clientes != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            clientes[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}


int searchFreePositionCli(eCliente clientes[], int tam)
{
    int indiceLibre = -1;

    if(clientes != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].isEmpty == 1)
            {
                indiceLibre = i;
                break;
            }
        }
    }

    return indiceLibre;
}

int findClienteById(eCliente clientes[], int tam, int id)
{
    int indice = -1;

    if(clientes != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].id == id && !clientes[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }


    return indice;
}


int arrayHasClientes(eCliente clientes[], int tam)
{
    int todoOk = 0;

    if(clientes != NULL && tam  > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!clientes[i].isEmpty)
            {
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}


int addCliente(eCliente clientes[], int tam, int indiceLibre, int* pId)
{
    int todoOk = 0;
    eCliente auxCli;

    if(clientes != NULL && tam > 0 && indiceLibre >= 0 && pId != NULL)
    {
        system("cls");
        printf("*** Carga de cliente al Sistema ****\n\n");
        printf("\nTenemos lugar libre para un cliente!\n\n");

        //Asigno auxiliar y el id
        clientes[indiceLibre] = auxCli;
        auxCli.id = (*pId);


        printf("\nIngrese DNI del cliente: ");
        scanf("%d", &auxCli.dni);
        while(auxCli.dni < 1000000 || auxCli.dni > 50000000)
        {
            printf("DNI fuera de rango (de un millon a 50 millones). Vuelva a intentar: ");
            scanf("%d", &auxCli.dni);
        }

        printf("\n\n");
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        scanf("%s", auxCli.nombre);
        while(!validarChar(auxCli.nombre, 2, 20))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxCli.nombre);
        }

        printf("\n\n");
        printf("Ingrese el apellido del cliente: ");
        fflush(stdin);
        scanf("%s", auxCli.apellido);
        while(!validarChar(auxCli.apellido, 2, 20))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxCli.apellido);
        }

        auxCli.isEmpty = 0;
        clientes[indiceLibre] = auxCli;

        //id Autoincremental
        (*pId)++;

        todoOk = 1;
    }

    return todoOk;
}

void printClientes(eCliente clientes[], int  tam)
{
    if(clientes != NULL && tam > 0)
    {
        tableTextCli();

        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                printCliente(clientes[i]);
            }
        }
        printf("\n\n");

    }
}

void printCliente(eCliente unCliente)
{
    printf("%3d   %d  %15s   %15s\n",
           unCliente.id,
           unCliente.dni,
           unCliente.nombre,
           unCliente.apellido
          );
}

int modifyClient(eCliente clientes[], int indice, int opcion)
{
    int todoOk = 0;

    eCliente auxCli = clientes[indice];

    system("cls");

    switch(opcion)
    {
    case 1:
        printf("\n\n");
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        scanf("%s", auxCli.nombre);
        while(!validarChar(auxCli.nombre, 2, 20))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxCli.nombre);
        }
        clientes[indice] = auxCli;
        todoOk = 1;
        break;

    case 2:
        printf("\n\n");
        printf("Ingrese el apellido del cliente: ");
        fflush(stdin);
        scanf("%s", auxCli.apellido);
        while(!validarChar(auxCli.apellido, 2, 20))
        {
            printf("\nIncorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%s", auxCli.apellido);
        }
        clientes[indice] = auxCli;
        todoOk = 1;
        break;


    case 3:
        printf("\nOpcion cancelada\n");
        break;

    default:
        printf("\nOpcion invalida, va del 1 al 3\n");
        break;
    }


    return todoOk;
}

int removeCliente(eCliente clientes[], int tam, int id)
{
    int todoOk = 0;

    if(clientes != NULL && tam > 0 && id > 99)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].id == id)
            {
                clientes[i].isEmpty = 1;
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}







































































































































































