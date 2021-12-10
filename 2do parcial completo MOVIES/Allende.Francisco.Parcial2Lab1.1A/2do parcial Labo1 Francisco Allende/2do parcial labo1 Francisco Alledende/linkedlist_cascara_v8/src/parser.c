#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "movies.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeMovie LinkedList*
 * \return int
 *
 */
int parser_PelisFromText(FILE* pFile , LinkedList* pArrayListeMovie)
{
	int todoOk = 0;

	eMovie* auxeMovie = NULL;
	char buffer[4][80];
	int cant;

	if(pFile!= NULL && pArrayListeMovie != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //lectura fantasma

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); //lectura real

			if(cant == 4)
			{
				auxeMovie = eMovie_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(auxeMovie!=NULL)
				{
					if(!ll_add(pArrayListeMovie, auxeMovie))
					{
						todoOk = 1;
					}
					else
					{
						eMovie_delete(auxeMovie);
						todoOk = 0;
						break;
					}
				}
			}
		}
	}

	return todoOk;
}
