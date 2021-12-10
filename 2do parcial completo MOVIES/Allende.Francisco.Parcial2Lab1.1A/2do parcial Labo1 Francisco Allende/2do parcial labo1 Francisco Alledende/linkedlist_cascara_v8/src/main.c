#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "movies.h"


int main()
{
    srand(time(NULL));

    int option = 0;
    int opcionGenero;
    int flagTiemposAsignados = 0;
    char msjCarga[140] = "Asegurese antes de cargar los datos (1)  y asignar la duracion (3). Solo se puede cargar ambas opciones una vez\n\n";
    char nombreArchivo[100];


    LinkedList* listaPelis = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;

    do
    {
        switch(menu())
        {
        case 1:
            printf("\nIndique el nombre del archivo a cargar. \n");
            fflush(stdin);
            scanf("%s", nombreArchivo);
            strcat(nombreArchivo, ".csv");
            while(strlen(nombreArchivo) > 100)
            {
                printf("Ingrese un nombre mas corto: \n");
                gets(nombreArchivo);
            }

            if(ll_isEmpty(listaPelis) || strcmp(nombreArchivo, "movies.csv") != 0)
            {
                if(!controller_loadFromText(nombreArchivo, listaPelis))
                {
                    printf("No se pudieron cargar todos los datos en texto correctamente\n\n");
                }
                else
                {
                    system("cls");
                    printf("\n***\t Carga del archivo de texto exitosa! ***\n\n");
                }
            }
            else
            {
                printf("El archivo ya fue cargado. Solo se puede cargar una vez.\n\n");
            }
            break;

        case 2:
            if(flagTiemposAsignados || strcmp(nombreArchivo, "movies.csv") != 0)
            {
                if(!controller_ListMovies(listaPelis))
                {
                    printf("No se pudo mostrar el listado de peliculas\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 3:
            if(!ll_isEmpty(listaPelis))
            {
                listaPelis = ll_map(listaPelis, controller_mapDuracion);
                if(listaPelis != NULL)
                {
                    printf("\n*** Duracion de peliculas asignada con exito ***\n");
                }

                flagTiemposAsignados = 1;
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 4:
            if(!ll_isEmpty(listaPelis))
            {

                opcionGenero = menuFiltrado();

                switch(opcionGenero)
                {
                case 1:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByAdventure);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaAdventure.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 2:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByDrama);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaDrama.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 3:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByComedy);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaComedy.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 4:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByRomance);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaRomance.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 5:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByDocumentary);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaDocumentary.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 6:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByHorror);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaHorror.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 7:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByMusical);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaMusical.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 8:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByAnimation);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaAnimation.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 9:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByAction);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaAction.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 10:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByThriller);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaThriller.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;

                case 11:
                    listaFiltrada = ll_filter(listaPelis, eMovie_filerByWestern);
                    if(listaFiltrada != NULL)
                    {
                        controller_ListMovies(listaFiltrada);
                        controller_saveAsText("listaWestern.csv", listaFiltrada);
                        printf("\n*** lista filtrada con exito y guardada***\n");
                    }
                    break;
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 5:
            if(flagTiemposAsignados || strcmp(nombreArchivo, "movies.csv") != 0)
            {
                if(controller_sortMovies(listaPelis))
                {
                    controller_ListMovies(listaPelis);
                    printf("\n *** Listado exitoso! ***\n");
                }
                else
                {
                    printf("\nNo se pudo realizar el ordenamiento\n");
                }

            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 6:
            if(!ll_isEmpty(listaPelis))
            {
                if(controller_saveAsText(nombreArchivo, listaPelis))
                {
                    printf("\n***Archivo guardado con exito***\n");
                }
                else
                {
                    printf("\nNo s epudo guardar el archivo\n");
                }
            }
            else
            {
                printf("%s ", msjCarga);
            }
            break;

        case 7:
            printf("\nAdios!\n");
            option = -1;
            break;

        default:
            printf("Error, esa opcion es inexistente. Vuelvalo a intentar \n");
            break;
        }

        printf("\n\n");
        system("pause");
    }
    while(option != -1);







    ll_deleteLinkedList(listaPelis);

    return 0;
}
