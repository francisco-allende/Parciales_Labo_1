#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movies.h"

/** \brief menu general de opciones
 *
 * \return int
 *
 */
int menu()
{
    int opcion = 0;

    system("cls");
    printf("*****************************************\n");
    printf("*\t 		Menu Peliculas \t*\n");
    printf("*****************************************\n\n");
    printf("1 - Cargar datos de las peliculas desde un CSV\n");
    printf("2 - Imprimir lista de peliculas\n");
    printf("3 - Asignar tiempo de duracion\n");
    printf("4 - Filtrar por genero\n");
    printf("5 - Ordenar por genero y duraciones\n");
    printf("6 - Guardar archivo\n");
    printf("7   Salir\n");
    printf("\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


//**************    Constructores   ********************

/** \brief constructor que instancia los campos de la estructura
 *
 * \return eMovie*
 *
 */
eMovie* eMovie_new()
{
    eMovie* newPeli = NULL;

    newPeli = (eMovie*) malloc(sizeof(eMovie));

    if(newPeli != NULL)
    {
        newPeli->id = 0;
        strcpy(newPeli->titulo, "nn");
        strcpy(newPeli->genero, "nn");
        newPeli->duracion = 0;
    }

    return newPeli;
}


/** \brief contruye con los parametros recibidos y los carga
 *
 * \param idStr char*
 * \param tituloStr char*
 * \param generoStr char*
 * \param duracionStr char*
 * \return eMovie*
 *
 */
eMovie* eMovie_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
    eMovie* newPeli = eMovie_new();

    if(idStr != NULL && tituloStr != NULL && generoStr != NULL && duracionStr != NULL)
    {
        if(!(eMovie_setId(newPeli, atoi(idStr))
                && eMovie_setTitulo(newPeli, tituloStr)
                && eMovie_setGenero(newPeli, generoStr)
                && eMovie_setDurcion(newPeli, atoi(duracionStr))
            ))
        {
            free(newPeli);
            newPeli = NULL;
        }
    }

    return newPeli;
}

//**************    Setters     ********************

/** \brief setter del id
 *
 * \param this eMovie*
 * \param id int
 * \return int
 *
 */
int eMovie_setId(eMovie* this, int id)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this->id = id;

        todoOk = 1;
    }

    return todoOk;
}


/** \brief setter del titulo
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int
 *
 */
int eMovie_setTitulo(eMovie* this, char* titulo)
{
    int todoOk = 0;

    if(this != NULL && titulo != NULL)
    {
        if(strlen(titulo) >= 2 && strlen(titulo) < 150)
        {
            strcpy(this->titulo, titulo);

            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief setter del genero
 *
 * \param this eMovie*
 * \param genero char*
 * \return int
 *
 */
int eMovie_setGenero(eMovie* this, char* genero)
{
    int todoOk = 0;

    if(this != NULL && genero != NULL)
    {
        if(strlen(genero) >= 2 && strlen(genero) < 80)
        {
            strcpy(this->genero, genero);

            todoOk = 1;
        }
    }

    return todoOk;
}


/** \brief  setter de la duracion
 *
 * \param this eMovie*
 * \param duracion int
 * \return int
 *
 */
int eMovie_setDurcion(eMovie* this, int duracion)
{
    int todoOk = 0;

    if(this != NULL)
    {
        this->duracion = duracion;

        todoOk = 1;
    }

    return todoOk;
}

//**************    Getters     ********************

/** \brief  getter del id
 *
 * \param this eMovie*
 * \param id int*
 * \return int
 *
 */
int eMovie_getId(eMovie* this, int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;

        todoOk = 1;
    }

    return todoOk;
}

/** \brief  getter del titulo
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int
 *
 */
int eMovie_getTitulo(eMovie* this, char* titulo)
{
    int todoOk = 0;

    if(this != NULL && titulo!= NULL)
    {
        strcpy(titulo, this->titulo);

        todoOk = 1;
    }

    return todoOk;
}

/** \brief  getter del genero
 *
 * \param this eMovie*
 * \param genero char*
 * \return int
 *
 */
int eMovie_getGenero(eMovie* this, char* genero)
{
    int todoOk = 0;

    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);

        todoOk = 1;
    }

    return todoOk;
}


/** \brief getter de la duracion
 *
 * \param this eMovie*
 * \param duracion int*
 * \return int
 *
 */
int eMovie_getDuracion(eMovie* this, int* duracion)
{
    int todoOk = 0;

    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;

        todoOk = 1;
    }

    return todoOk;
}


/** \brief destructor
 *
 * \param eMovie eMovie*
 * \return void
 *
 */
void eMovie_delete(eMovie* eMovie)
{
    free(eMovie);
}


/** \brief printea cada una de las peliculas
 *
 * \param peli eMovie*
 * \return int
 *
 */
int eMovie_print(eMovie* peli)
{
    int todoOk = 0;

    if(peli != NULL)
    {
        printf("%d %40s     %20s\t\t     %d\n",
               peli->id,
               peli->titulo,
               peli->genero,
               peli->duracion);

        todoOk = 1;
    }

    return todoOk;
}

/** \brief da la opcion de filtrado a elegir
 *
 * \return int
 *
 */
int menuFiltrado()
{
    int opcion;
    system("cls");
    printf("\n\nElija el genero por el cual desea filtrar: ");
    printf("\n1) Adventure \n");
    printf("2) Drama\n");
    printf("3) Comedy\n");
    printf("4) Romance\n");
    printf("5) Documentary\n");
    printf("6) Horror\n");
    printf("7) Musical\n");
    printf("8) Animation\n");
    printf("9) Action\n");
    printf("10) Thriller\n");
    printf("11) Western\n");
    printf("\n\nMarque su opcion: ");
    scanf("%d", &opcion);
    while(opcion > 11 || opcion < 1)
    {
        printf("Error, seleccione una opcion posibke: ");
        scanf("%d", &opcion);
    }



    return opcion;
}


/*************** Filter pFunc ***********************/


/** \brief filtra por genero aventura
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByAdventure(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Adventure") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero drama
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByDrama(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Drama") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero comedia
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByComedy(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Comedy") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero romance
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByRomance(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Romance") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero documental
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByDocumentary(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Documentary") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero horror
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByHorror(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Horror") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero musical
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByMusical(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Musical") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero animacion
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByAnimation(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Animation") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero animacion
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByAction(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Action") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por genero thriller
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByThriller(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Thriller") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

/** \brief filtra por western
 *
 * \param pElement void*
 * \return int
 *
 */
int eMovie_filerByWestern(void* pElement)
{
    int retorno = 0;
    eMovie* aux = NULL;

    if(pElement != NULL)
    {
        aux = (eMovie*) pElement;

        if(aux != NULL)
        {
            if(strcmp(aux->genero, "Western") == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


/** \brief hace el ordenamiento segun genero
 *
 * \param peliOne void*
 * \param peliTwo void*
 * \return int
 *
 */
int eMovie_sortGenero(void* peliOne, void* peliTwo)
{
    int criterio = 0;
    char generoUno[20];
    char generoDos[20];

    eMovie* auxPeliUno = (eMovie*) peliOne;
    eMovie* auxPeliTwo = (eMovie*) peliTwo;

    if(peliOne != NULL && peliTwo != NULL)
    {
        eMovie_getGenero(auxPeliUno, generoUno);
        eMovie_getGenero(auxPeliTwo, generoDos);

        if(strcmp(generoUno, generoDos) > 0)
        {
            criterio = 1;
        }
        else if(strcmp(generoUno, generoDos) < 0)
        {
            criterio = -1;
        }
    }
    return criterio;
}

//es bastante facil ordenar por dos criterios.
//La funcion es casi igual solo que contempla el eje ordenador, por lo cual debo getter genero y duracion
//y antes del hacer el if retornando el criterio, validar con strcmp que el genero sea el mismo (osea, == 0)
int eMovie_sortDuracion(void* peliOne, void* peliTwo)
{
    int criterio = 0;

    char generoUno[20];
    char generoDos[20];
    int duracionUno;
    int duracionDos;

    eMovie* auxPeliUno = (eMovie*) peliOne;
    eMovie* auxPeliTwo = (eMovie*) peliTwo;

    if(peliOne != NULL && peliTwo != NULL)
    {
        eMovie_getGenero(auxPeliUno, generoUno);
        eMovie_getGenero(auxPeliTwo, generoDos);
        eMovie_getDuracion(auxPeliUno, &duracionUno);
        eMovie_getDuracion(auxPeliTwo, &duracionDos);

        if(strcmp(generoUno, generoDos) == 0)
        {

            if(duracionUno > duracionDos)
            {
                criterio = 1;
            }
            else if(duracionUno < duracionDos)
            {
                criterio = -1;
            }
        }
    }

    return criterio;
}



