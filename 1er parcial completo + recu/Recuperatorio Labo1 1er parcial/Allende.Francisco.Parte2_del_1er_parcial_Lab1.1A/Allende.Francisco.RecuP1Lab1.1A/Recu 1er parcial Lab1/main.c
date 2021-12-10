#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "alquiler.h"
#include "inputs.h"

#define TAMALQ 20
#define TAM 10

int main()
{
    //DECLARO VARIABLES
    char msjCarga[100] = "Antes de de alta al menos un cliente\n";
    char seguir = 's';
    int freePosition;
    int opcion;
    int idModify;
    int indiceModificar;
    int idBaja;
    int indiceBaja;
    int idAlquilerFin;
    int indiceFinAlq;

    //VARIABLES PUNTERO
    int nextIdCli = 100;
    int nextIdAlquiler = 800;

    //Array estructuras
    eCliente clientes[TAM];
    eAlquiler alquileres[TAMALQ];

    //Inicicializo
    if(!initCliente(clientes, TAM))
    {
        printf("No se pudo inicialziar el array de clientes\n");
    }
    if(!initAlquiler(alquileres, TAM))
    {
        printf("No se pudo inicialziar el array de alquileres\n");
    }


    do
    {
        switch(menu())
        {
        case 1:
            if((freePosition = searchFreePositionCli(clientes, TAM)) != -1)
            {
                if(!addCliente(clientes, TAM, freePosition, &nextIdCli))
                {
                    printf("Algo fallo al cargar el cliente. Intente de nuevo.");
                }
                else
                {
                    system("cls");
                    tableTextCli();
                    printCliente(clientes[freePosition]);
                    printf("\n\n\t*** Alta de cliente exitosa! ***\n\n");
                }
            }
            else
            {
                printf("Lo sentimos, no hay lugar libre para cargar un cliente\n");
            }
            break;

        case 2:
            if(arrayHasClientes(clientes, TAM))
            {
                opcion = subMenuModificar();
                printClientes(clientes, TAM);

                printf("Ingrese el id del cliente a modificar: ");
                scanf("%d", &idModify);

                indiceModificar = findClienteById(clientes, TAM, idModify);

                if(indiceModificar != -1)
                {
                    if(modifyClient(clientes, indiceModificar, opcion))
                    {
                        tableTextCli();
                        printCliente(clientes[indiceModificar]);
                        printf("\n***Modificacion exitosa**\n");
                    }
                    else
                    {
                        printf("No se pudo realizar la modificacion\n");
                    }
                }
                else
                {
                    printf("Clinte no encontrado\n\n");
                }
            }
            else
            {
                printf("%s \n", msjCarga);
            }
            break;

        case 3:
            if(arrayHasClientes(clientes, TAM))
            {
                printClientes(clientes, TAM);
                printf("Ingrese el id del a dar de baja: ");
                scanf("%d", &idBaja);

                indiceBaja = findClienteById(clientes, TAM, idBaja);
                if(removeCliente(clientes, TAM, idBaja))
                {
                    printCliente(clientes[indiceBaja]);
                    printf("\n*** Baja exitosa ***\n");
                }
            }
            else
            {
                printf("%s \n", msjCarga);
            }

            break;

        case 4:
            if(arrayHasClientes(clientes, TAM))
            {
                if((freePosition = searchFreePositionAlq(alquileres, TAM)) != -1)
                {
                    if(!addAlquiler(alquileres, TAMALQ, freePosition, &nextIdAlquiler, clientes, TAM))
                    {
                        printf("Algo fallo al cargar el nuevo alquiler. Intente de nuevo.");
                    }
                    else
                    {
                        system("cls");
                        tableTextAlq();
                        printAlq(alquileres[freePosition]);
                        printf("\n\n\t*** Nuevo alquiler exitoso! ***\n\n");
                    }
                }
                else
                {
                    printf("Lo sentimos, no hay lugar libre para cargar un cliente\n");
                }
            }
            else
            {
                printf("%s\n", msjCarga);
            }

            break;

        case 5:
            if(arrayHasClientes(clientes, TAM) && arrayHasAlquileres(alquileres, TAMALQ))
            {

                printf("Ingrese el id del alquiler a finalizar: ");
                scanf("%d", &idAlquilerFin);

                indiceFinAlq = findAlquilerById(alquileres, TAMALQ, idAlquilerFin);

                if(indiceFinAlq != -1)
                {
                    if(finAlquiler(alquileres, TAMALQ, idAlquilerFin))
                    {

                        printf("Fin del alquiler con exito\n");
                    }
                    else
                    {
                        printf("No se pudo dar la baja del alquiler\n");
                    }
                }
                else
                {
                    printf("id del alquiler no encontrado\n");
                }
            }
            else
            {
                printf("%s y un alquiler\n", msjCarga);
            }
            break;

        case 6:
            clienteConMasAlquileres(alquileres, TAMALQ, clientes, TAM);

            break;

        case 7:

            break;

        case 8:
            if(!promedioTiempoReal(alquileres, TAMALQ))
            {
                printf("No se pudieron encontrar alquileres con tiempo real\n\n");
            }
            break;

        case 9:
            printClientAndAlq(alquileres, TAM, clientes, TAMALQ);

            break;

        case 10:
            seguir = 'n';
            printf("\n\nAdios! \n\n");
            break;

        default:
            printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
            break;
        }
        printf("\n\n");
        system("pause");

        //reacomodo para que no se descalabren las posiciones

    }
    while(seguir == 's');

    return 0;
}




