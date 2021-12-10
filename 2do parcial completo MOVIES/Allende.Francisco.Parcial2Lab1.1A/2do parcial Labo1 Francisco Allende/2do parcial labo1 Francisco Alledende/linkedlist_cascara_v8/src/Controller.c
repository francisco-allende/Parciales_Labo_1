#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "movies.h"
#include "parser.h"


/** \brief Carga los datos de los pelileados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPelis LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPelis)
{
    int todoOk = 0;

    if(path != NULL && pArrayListPelis != NULL)
    {
        FILE* fTxt = fopen(path, "r"); //abro en modo lectura

        if(fTxt != NULL)
        {
            todoOk = parser_PelisFromText(fTxt, pArrayListPelis);
            fclose(fTxt);
        }
    }

    return todoOk;
}



/** \brief Listar pelileados
 *
 * \param path char*
 * \param pArrayListPelis LinkedList*
 * \return int
 *
 */
int controller_ListMovies(LinkedList* pArrayListPelis)
{
    int todoOk = 0;
    eMovie* aux = NULL;
    int tam = ll_len(pArrayListPelis);


    if(pArrayListPelis != NULL && tam > 0)
    {
        system("cls");
        printf("****************************************************************************************************\n");
        printf("ID\t\t\t	Titulo\t\t	     Genero\t\t        Duracion\n");
        printf("****************************************************************************************************\n\n");

        for(int i = 0; i < tam; i++)
        {
            aux = ll_get(pArrayListPelis, i);
            eMovie_print(aux);
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief mapea la duracion de las peliculas en un rango dado
 *
 * \param pElement void*
 * \return void*
 *
 */
void* controller_mapDuracion(void* pElement)
{
    int max = 240;
    int min = 100;
    int duracion;
    eMovie* auxMovie = NULL;

    if(pElement != NULL)
    {
        //asigno valores randoms
        duracion = rand() % (max - min + 1) + min;

        //casteo
        auxMovie = (eMovie*) pElement;

        //setteo
        eMovie_setDurcion(auxMovie, duracion);
    }

    return auxMovie;
}



/** \brief Ordenar pelileados
 *
 * \param path char*
 * \param pArrayListPelis LinkedList*
 * \return int
 *
 */
int controller_sortMovies(LinkedList* pArrayListPelis)
{
    int todoOk = 0;
    system("cls");
    printf("\nAguarde! Estamos ordenando la lista. Esto podria demorar unos segundos...\n\n");

    if(pArrayListPelis != NULL)
    {
        if(!ll_sort(pArrayListPelis, eMovie_sortGenero, 1))
        {
            if(!ll_sort(pArrayListPelis, eMovie_sortDuracion, 0))
            {
                controller_ListMovies(pArrayListPelis);
                todoOk = 1;
            }
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los pelileados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPelis LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPelis)
{

    int todoOk = 0;
    eMovie* peli = NULL;

    int id;
    char titulo[150];
    char genero[80];
    int duracion;
    int tam = ll_len(pArrayListPelis);

    if(path != NULL && pArrayListPelis != NULL)
    {
        FILE* f = fopen(path, "w"); //lo abro en modo escritura txt
        peli = eMovie_new(); //instancio al pelileado para cargar bien los getters

        if(f != NULL && peli != NULL)
        {
            fprintf(f, "id,titulo,genero,duracion\n"); //cargo la data de las columnas

            for(int i = 0; i < tam; i++)
            {
                peli = ll_get(pArrayListPelis, i); //me traigo un pelileado por iteracion

                if(peli != NULL)
                {
                    eMovie_getId(peli, &id);
                    eMovie_getTitulo(peli, titulo);
                    eMovie_getGenero(peli, genero);
                    eMovie_getDuracion(peli, &duracion);

                    fprintf(f, "%d,%s,%s,%d\n", id, titulo, genero, duracion);
                    todoOk = 1;
                }
            }
        }

        fclose(f);
    }

    return todoOk;
}

