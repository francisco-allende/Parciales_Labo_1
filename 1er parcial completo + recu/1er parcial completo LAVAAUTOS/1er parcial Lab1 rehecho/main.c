#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"
#include "inputs.h"

#define TAMSER 4
#define TAMMAR 5
#define TAMCOL 5
#define TAMTRA 15
#define TAM 15

int main()
{
    //DECLARO VARIABLES
    int freePosition, contAutos, contWork;
    int indiceBaja = 0;
    char seguir = 's';
    int idBaja = 0;
    int idModificar = 0;
    int indiceModificar = 0;
    char seguirInformes = 'n';
    char msjCarga[150] = "Antes de de alta al menos una auto\n";

    //VARIABLES PUNTERO
    int opcion, subOpcion;
    int idAuto = 110; //arranco en 110 por el datawarehpuse (hasta 109). Lo mismo en trabajo
    int idTrabajo = 8010;
    int patente; //es lo mismo que el id del auto
    int acumuladorServiciosPorAuto = 0;

    //Variables informe
    int colorAElegir, marcaAElegir, autoAElegir, servicioAElegir, indiceAutoElegir;
    int fechaAElegirAnio, fechaAElegirMes, fechaAElegirDia;

    //ARRAYS DE ESTRUCTURAS
    eAuto autos[TAM];
    eTrabajo trabajos[TAMTRA];
    eMarca marcas[TAMMAR] =
    {
        {1000, "Renault"},
        {1001, "Ford"},
        {1002, "Fiat"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"},
    };

    eColor colores[TAMCOL] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"},
    };

    eServicio servicios[TAMSER] =
    {
        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900},
    };

    //HARDCODEO E INICIALIZACION.
    //Incializao como libres segun lo que retorne el contador del datawarehouse

    contAutos = hardcodearAutosBD(autos, TAM);
    if(!initAuto(autos, TAM, contAutos))
    {
        printf("No se pudieron inicializar los autos\n");
    }

    contWork = hardcodearTrabajosBD(trabajos, TAMTRA);
    if(!initTrabajo(trabajos, TAMTRA, contWork))
    {
        printf("No se pudieron inicialziar los trabajos\n");
    }

    //ordeno arrays de entrada por prolijidad
    sortReacomodar(autos, TAM);
    sortReacomodarTrabajos(trabajos, TAMMAR);


    do
    {
        switch(menu())
        {
        case 1:
            if((freePosition = searchFreePosition(autos, TAM)) != -1)
            {
                if(!addAuto(autos, TAM, freePosition, &idAuto, marcas, TAMMAR, colores, TAMCOL))
                {
                    printf("Algo fallo al cargar el auto. Intente de nuevo.");
                }
                else
                {
                    system("cls");
                    tableText();
                    printAuto(autos[freePosition], marcas, TAMMAR, colores, TAMCOL);
                    printf("\n\n\t*** Alta de auto exitosa! ***\n\n");
                }
            }
            else
            {
                printf("Lo sentimos, no hay lugar libre para cargar un auto\n");
            }
            break;

        case 2:
            if(arrayHasCars(autos, TAM))
            {
                subMenuModificar(&opcion);
                printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL);

                idModificar = 0;
                indiceModificar = 0;

                printf("Ingrese el id del auto para continuar con la operacion: ");
                fflush(stdin);
                scanf("%d", &idModificar);
                indiceModificar = findAutoById(autos, TAM, idModificar);

                if(indiceModificar != -1)
                {
                    if(!modifyAuto(autos, indiceModificar, &opcion, marcas, TAMMAR, colores, TAMCOL))
                    {
                        printf("No se pudo modificar lso datos del auto \n");
                    }
                }
                else
                {
                    printf("Auto no encontrado\n\n");
                }

            }
            else
            {
                printf("%s", msjCarga);
            }

            break;
        case 3:
            if(arrayHasCars(autos, TAM))
            {
                if(!printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL))
                {
                    printf("No se pudo listar a los autos para dar de baja correctamente\n\n");
                }
                else
                {
                    idBaja = 0;
                    indiceBaja = 0;

                    printf("Ingrese el id del auto para continuar con la operacion: ");
                    fflush(stdin);
                    scanf("%d", &idBaja);
                    indiceBaja = findAutoById(autos, TAM, idBaja);

                    if(indiceBaja != -1)
                    {
                        if(!removeAuto(autos, TAM, indiceBaja))
                        {
                            printf("No se pudo dar de baja el auto. Vuelva a intentar \n\n");
                        }
                        else
                        {
                            tableText();
                            printAuto(autos[indiceBaja], marcas, TAMMAR, colores, TAMCOL);
                            printf("\n\n\t*** Baja de auto exitosa! ***\n\n");
                        }
                    }
                    else
                    {
                        printf("No se pudo encontrar ningun auto con ese id\n\n");
                    }
                }
            }
            else
            {
                printf("%s", msjCarga);
            }
            break;

        case 4:
            if(arrayHasCars(autos, TAM))
            {
                subMenu(&subOpcion);

                if(!sortAutos(autos, TAM, &subOpcion))
                {
                    printf("No se pudo ordenar correctamente el listado de autos\n\n");
                }
                else
                {
                    printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL);
                }
            }
            else
            {
                printf("%s", msjCarga);
            }
            break;

        case 5:
            if(!printMarcas(autos, TAM, marcas, TAMMAR))
            {
                printf("No se pudieron listar las marcas\n\n");
            }
            break;

        case 6:
            if(!printColores(autos, TAM, colores, TAMCOL))
            {
                printf("No se pudieorn listar los colores\n\n");
            }
            break;

        case 7:
            if(!printServicios(trabajos, TAM, servicios, TAMSER))
            {
                printf("No se pudieron listar los servicios\n\n");
            }
            break;

        case 8:
            if(arrayHasCars(autos, TAM))
            {
                if((freePosition = searchFreePositionTrabajo(trabajos, TAMTRA)) != -1)
                {
                    system("cls");
                    printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL);

                    if(!addTrabajo(trabajos, TAMTRA, freePosition, &patente, servicios, TAMSER, autos, TAM, &idTrabajo))
                    {
                        printf("Algo fallo al cargar el auto. Intente de nuevo.");
                    }
                    else
                    {
                        system("cls");
                        printTrabajos(trabajos, TAM, servicios, TAMSER);
                        printf("\n\n\t*** Alta de trabajo exitosa! ***\n\n");
                    }
                }
                else
                {
                    printf("Lo sentimos, no hay lugar libre para cargar un trabajo \n");
                }
            }
            else
            {
                printf("%s", msjCarga);
            }
            break;

        case 9:
            if(arrayHasJobs(trabajos, TAMTRA))
            {
                if(!printTrabajos(trabajos, TAM, servicios, TAMSER))
                {
                    printf("No se pudo mostrar el listado de trabajos\n\n");
                }
            }
            else
            {
                printf("Antes de de alta una trabajo\n");
            }
            break;

        case 10:
            do
            {
                switch(menuInformes())
                {

                case 1:
                    if(arrayHasCars(autos, TAM))
                    {
                        system("cls");
                        printColores(autos, TAM, colores, TAMCOL);

                        colorAElegir = elegirOpcionColor(colorAElegir);

                        if(!mostrarColorAElegir(autos, colores, TAM, colorAElegir, TAMCOL))
                        {
                            printf("No se pudo mostrar el color a elegir\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 2:
                    if(arrayHasCars(autos, TAM))
                    {
                        system("cls");
                        printMarcas(autos, TAM, marcas, TAMMAR);

                        marcaAElegir = elegirOpcionMarca(marcaAElegir);

                        if(!mostrarMarcaAElegir(autos, marcas, TAM, marcaAElegir, TAMMAR))
                        {
                            printf("No se pudo mostrar la marca a elegir\n\n");
                        }
                        else
                        {
                            printf("\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 3:
                    if(arrayHasCars(autos, TAM))
                    {
                        if(!promedioCajas(autos, TAM))
                        {
                            printf("No se pudieron listar los promedios de cajas\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 4:
                    if(arrayHasCars(autos, TAM))
                    {
                        if(!printCajas(autos, TAM))
                        {
                            printf("No se pudieron listar las cajas\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }

                    break;
                case 5:
                    if(arrayHasCars(autos, TAM))
                    {
                        system("cls");
                        printColores(autos, TAM, colores, TAMCOL);
                        colorAElegir = elegirOpcionColor(colorAElegir);

                        system("cls");
                        printMarcas(autos, TAM, marcas, TAMMAR);
                        marcaAElegir = elegirOpcionMarca(marcaAElegir);

                        if(!mostrarMarcaYColor(autos, colores, marcas, TAM, TAMMAR, TAMCOL, colorAElegir, marcaAElegir))
                        {
                            printf("No se encontraron autos con esa marca y color\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 6:
                    if(arrayHasCars(autos, TAM))
                    {
                        if(!mostrarMarcaMasElegida(autos, TAM, marcas, TAMMAR))
                        {
                            printf("No se pudo mostrar la marca mas elegida\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 7:
                    if(arrayHasCars(autos, TAM) && arrayHasJobs(trabajos, TAMTRA))
                    {
                        autoAElegir = 0;
                        indiceAutoElegir = 0;

                        printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL);
                        printf("\n\n");
                        printf("Seleccione el id del auto para mostrar sus trabajos: ");
                        fflush(stdin);
                        scanf("%d", &autoAElegir);
                        indiceAutoElegir = findAutoById(autos, TAM, autoAElegir);

                        if(indiceAutoElegir != -1)
                        {
                            if(!trabajosPorAuto(autos, TAM, trabajos, TAMTRA, servicios, TAMSER, autoAElegir, &acumuladorServiciosPorAuto))
                            {
                                printf("No se encontraron trabajos para el auto\n");
                            }
                        }
                        else
                        {
                            printf("No se encontro ningun auto con ese id\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 8:
                    if(arrayHasCars(autos, TAM) && arrayHasJobs(trabajos, TAMTRA))
                    {
                        autoAElegir = 0;
                        indiceAutoElegir = 0;

                        printAutos(autos, TAM, marcas, TAMMAR, colores, TAMCOL);
                        printf("\n\n");
                        printf("Seleccione el id del auto para mostrar sus trabajos y servicios: ");
                        fflush(stdin);
                        scanf("%d", &autoAElegir);
                        indiceAutoElegir = findAutoById(autos, TAM, autoAElegir);

                        if(indiceAutoElegir != -1)
                        {
                            if(!trabajosPorAuto(autos, TAM, trabajos, TAMTRA, servicios, TAMSER, autoAElegir, &acumuladorServiciosPorAuto))
                            {
                                printf("No se encontraron trabajos para el auto\n");
                            }
                            else
                            {
                                printf("\n\n\t\tTotal a pagar: %d \n\n", acumuladorServiciosPorAuto);
                            }

                        }
                        else
                        {
                            printf("No se encontro ningun auto con ese id\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 9:
                    if(arrayHasCars(autos, TAM) && arrayHasJobs(trabajos, TAMTRA))
                    {
                        system("cls");
                        printf("******************\n");
                        printf("Mostrar por servicio \n");
                        printf("******************\n\n");

                        printServicios(trabajos, TAM, servicios, TAMSER);

                        printf("\nIngrese el Id del servicio: ");
                        fflush(stdin);
                        scanf("%d", &servicioAElegir);
                        while(servicioAElegir < 20000 || servicioAElegir > 20003)
                        {
                            printf("\nEse id de servicio no existe. Vuelva a intentar: ");
                            fflush(stdin);
                            scanf("%d", &servicioAElegir);
                        }

                        if(!servicioElegidoAMostrar(autos, TAM, trabajos, TAMTRA, servicios, TAMSER, servicioAElegir))
                        {
                            printf("No se pudo mostrar el servicio elegido y otros datos\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }
                    break;

                case 10:
                    if(arrayHasCars(autos, TAM) && arrayHasJobs(trabajos, TAMTRA))
                    {
                        printf("Seleccione una fecha por dia: ");
                        fflush(stdin);
                        scanf("%d", &fechaAElegirDia);
                        printf("Seleccione una fecha por mes: ");
                        fflush(stdin);
                        scanf("%d", &fechaAElegirMes);
                        printf("Seleccione una fecha por anio: ");
                        fflush(stdin);
                        scanf("%d", &fechaAElegirAnio);

                        if(validateDate(fechaAElegirDia, fechaAElegirMes, fechaAElegirAnio))
                        {
                            mostrarServiciosPorFecha(trabajos, TAMTRA, servicios, TAMSER, fechaAElegirDia, fechaAElegirMes, fechaAElegirAnio);
                        }
                        else
                        {
                            printf("No se encontro ningun servicio en esa fecha\n\n");
                        }
                    }
                    else
                    {
                        printf("%s", msjCarga);
                    }

                    break;

                case 11:
                    printf("Volvemos al menu principal \n");
                    seguirInformes = 'n';
                    break;

                default:
                    printf("Esa opcion es inexistente \n");
                    break;
                }
            }
            while(seguirInformes == 's');

            break;

        case 11:
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
        sortReacomodar(autos, TAM);
        sortReacomodarTrabajos(trabajos, TAMMAR);
    }
    while(seguir == 's');

    return 0;
}




