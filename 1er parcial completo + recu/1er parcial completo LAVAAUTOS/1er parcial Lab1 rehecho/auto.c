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
/* -----------------        ALTA           -----------------*/
/*----------------------------------------------------------*/

/** \brief Inicializa en isEmpty = 1 las posiciones vacias del array estatico de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param start int     Al usar dataWarehouse, necesito indicar desde donde arrancar y evitar isEmpty 1 en mi BBDD
 * \return int todoOk   Retorna 1 si pudo inicializar con exito
 *                      0 si algo fallo
 */
int initAuto(eAuto autos[], int tam, int start)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0)
    {
        for(int i = start; i < tam; i++)
        {
            autos[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}

/** \brief Busca posicion libre en array de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int  Retorna -1 si no hay lugar libre
 *              Retorna el indice libre si encunetra uno disponible
 */
int searchFreePosition(eAuto autos[], int tam)
{
    int indiceLibre = -1;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                indiceLibre = i;
                break;
            }
        }
    }

    return indiceLibre;
}

/** \brief Busca un auto segun el id que recibe en su 3er parametro
 *
 * \param autos[] eAuto
 * \param tam int
 * \param id int
 * \return int  Retorna -1 si no encontró el auto
 *              Retorna el indice del auto indicado si lo encuentra
 */
int findAutoById(eAuto autos[], int tam, int id)
{
    int indice = -1;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(autos[i].id == id && !autos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }


    return indice;
}

/** \brief Valida que haya al menos un auto cargado al array de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int  Retorna 0 si no hay ningun auto cargado al array
 *              Retorna 1 si hay al menos un auto cargado al array
 */
int arrayHasCars(eAuto autos[], int tam)
{
    int todoOk = 0;

    if(autos != NULL && tam  > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!autos[i].isEmpty)
            {
                todoOk = 1;
                break;
            }
        }
    }

    return todoOk;
}


/** \brief Añade un nuevo auto al array de autos
 *
 * \param autos[] eAuto
 * \param tam int
 * \param indiceLibre int   Previamente se valido que haya espacio para un nuevo auto en search free position
 * \param pId int*          Id autoincremental
 * \param marcas[] eMarca   Array de la estructura marca
 * \param tamMar int
 * \param colores[] eColor  Array de la estructura color
 * \param tamCol int
 * \return int              Retorna 0 si no pudo añadir el auto al array
 *                          Retorna 1 si pudo aladir el nuevo auto con exito
 */
int addAuto(eAuto autos[], int tam, int indiceLibre, int* pId, eMarca marcas[], int tamMar, eColor colores[], int tamCol)
{
    int todoOk = 0;
    eAuto auxAuto;

    if(autos != NULL && marcas != NULL && tam > 0 && indiceLibre >= 0 && pId != NULL && colores != NULL && tamCol >0 && tamMar > 0)
    {
        system("cls");
        printf("*** Carga de auto al Sistema ****\n\n");

        printf("\nTenemos lugar libre para un auto!\n\n");

        autos[indiceLibre] = auxAuto;

        auxAuto.id = (*pId);

        printf("\n\nSiendo: \n");
        printf("Renault\t\t 1000 \n");
        printf("Ford\t\t 1001 \n");
        printf("Fiat\t\t 1002 \n");
        printf("Chevrolet\t 1003 \n");
        printf("Peugeot\t\t 1004 \n");
        printf("\nIngrese el Id de la marca: ");
        fflush(stdin);
        scanf("%d", &auxAuto.idMarca);
        while(auxAuto.idMarca < 1000 || auxAuto.idMarca > 1004)
        {
            printf("\nEse id de marca no existe. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%d", &auxAuto.idMarca);
        }

        printf("\n\n");
        printf("\n\nSiendo: \n");
        printf("Negro\t\t 5000 \n");
        printf("Blanco\t\t 5001 \n");
        printf("Rojo\t\t 5002 \n");
        printf("Gris\t\t 5003 \n");
        printf("Azul\t\t 5004 \n");
        printf("\nIngrese el Id del color: ");
        fflush(stdin);
        scanf("%d", &auxAuto.idColor);
        while(auxAuto.idColor < 5000 || auxAuto.idColor > 5004)
        {
            printf("\nEse id de marca no existe. Vuelva a intentar: ");
            fflush(stdin);
            scanf("%d", &auxAuto.idColor);
        }

        printf("\n\n");
        printf("Ingrese el tipo de caja, siendo m la manual y a la automatica: ");
        fflush(stdin);
        scanf("%c", &auxAuto.caja);
        while(auxAuto.caja != 'm' && auxAuto.caja != 'a' && auxAuto.caja != 'M' && auxAuto.caja != 'A')
        {
            printf("\nCaracter incorrecto. Vuelva a intenar: ");
            fflush(stdin);
            scanf("%c", &auxAuto.caja);
        }

        auxAuto.isEmpty = 0;
        autos[indiceLibre] = auxAuto;

        (*pId)++; //incremento en 1 el id para la siguiente ronda

        todoOk = 1;
    }

    return todoOk;
}


/*----------------------------------------------------------*/
/* -----------------      MODIFICAR        -----------------*/
/*----------------------------------------------------------*/

/** \brief Modifica color y/o modelo del auto indicado
 *
 * \param autos[] eAuto
 * \param indice int    Previamente se utiliza find auto by id para indicar que auto modificar
 * \param opcion int*   Previamente se desplego un menu que retorna la opcion a modificar
 * \param marcas[] eMarca
 * \param tamMar int
 * \param colores[] eColor
 * \param tamCol int
 * \return int          Retorna 0 si no pudo modificar el dato
 *                      Retorna 1 si pudo modifcar el dato con exito
 */
int modifyAuto(eAuto autos[], int indice, int* opcion, eMarca marcas[], int tamMar, eColor colores[], int tamCol)
{
    int todoOk = 0;
    eAuto auxAuto;
    char seguir;

    if(autos != NULL && indice > -1 && *opcion > 0 && *opcion < 5)
    {
        do
        {
            auxAuto = autos[indice];

            system("cls");

            switch(*opcion)
            {
            case 1:
                printf("\n\nSiendo: \n");
                printf("Negro\t\t 5000 \n");
                printf("Blanco\t\t 5001 \n");
                printf("Rojo\t\t 5002 \n");
                printf("Gris\t\t 5003 \n");
                printf("Azul\t\t 5004 \n");
                printf("\nIngrese el Id del color: ");
                fflush(stdin);
                scanf("%d", &auxAuto.idColor);
                while(auxAuto.idColor < 5000 || auxAuto.idColor > 5004)
                {
                    printf("Ese id de color no existe. Vuelva a intentar: ");
                    fflush(stdin);
                    scanf("%d", &auxAuto.idColor);
                }
                break;

            case 2:
                printf("\n\nSiendo: \n");
                printf("Renault\t\t 1000 \n");
                printf("Ford\t\t 1001 \n");
                printf("Fiat\t\t 1002 \n");
                printf("Chevrolet\t 1003 \n");
                printf("Peugeot\t\t 1004 \n");
                printf("\nIngrese el Id de la marca: ");
                fflush(stdin);
                scanf("%d", &auxAuto.idMarca);
                while(auxAuto.idMarca < 1000 || auxAuto.idMarca > 1004)
                {
                    printf("Ese id de marca no existe. Vuelva a intentar: ");
                    fflush(stdin);
                    scanf("%d", &auxAuto.idMarca);
                }

                break;
            }

            autos[indice] = auxAuto;

            todoOk = 1;

            printf("Desea seguir? s/n: ");
            fflush(stdin);
            scanf("%c", &seguir);
            while(!validateSeguir(seguir))
            {
                printf("Caracter invalido. Intente de nuevo con s/n: ");
                fflush(stdin);
                scanf("%c", &seguir);
            }

            if(seguir == 's')
            {
                subMenuModificar(opcion);
            }
            if(seguir == 'n')
            {
                tableText();
                printAuto(autos[indice], marcas, tamMar, colores, tamCol);
                printf("\n\n  *** Modificacion de datos del auto exitosa! ***\n\n");
            }
        }
        while(seguir == 's');
    }

    return todoOk;
}


/*----------------------------------------------------------*/
/* -----------------        BAJA           -----------------*/
/*----------------------------------------------------------*/

/** \brief Da de baja un auto segun el 3er parametro recibido
 *
 * \param autos[] eAuto
 * \param tam int
 * \param indice int    Indice del auto a dar de baja
 * \return int          Retorna 0 si no pudo dar de baja el auto
 *                      Reotrna 1 si pudo dar de baja el auto con exito
 */
int removeAuto(eAuto autos[], int tam, int indice)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0 && indice > -1)
    {
        autos[indice].isEmpty = 1;

        todoOk = 1;
    }

    return todoOk;
}

/*----------------------------------------------------------*/
/* -----------------        LISTAR         -----------------*/
/*----------------------------------------------------------*/


/** \brief Ordena los autos en modo ascednete o descendente segun el critero, el 3er parametro
 *
 * \param autos[] eAuto
 * \param tam int
 * \param opcion int*   criterio elegido en un submenu previo
 * \return int          Retorna 0 si fallo al ordenar
 *                      Retorna 1 si ordeno el array con exito
 */
int sortAutos(eAuto autos[], int tam, int* opcion)
{
    int todoOk = 0;
    int criterio = *opcion;

    eAuto auxAuto;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(criterio == 1)
                {
                    if(
                        (autos[i].idMarca > autos[j].idMarca ||
                         autos[i].idMarca == autos[j].idMarca) //&&
                        //(autos[i].id > autos[j].id)
                    )
                    {
                        auxAuto = autos[i];
                        autos[i] = autos[j];
                        autos[j] = auxAuto;
                    }
                }
                if(criterio == 2)
                {
                    if(
                        (autos[i].idMarca < autos[j].idMarca ||
                         autos[i].idMarca == autos[j].idMarca) //&&
                        //(autos[i].id < autos[j].id)
                    )
                    {
                        auxAuto = autos[i];
                        autos[i] = autos[j];
                        autos[j] = auxAuto;
                    }
                }
            }
        }
    }

    todoOk = 1;

    return todoOk;
}


/** \brief Itera el array de autos y le envia a printAuto todos los autos a mostrar
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \param colores[] eColor
 * \param tamCol int
 * \return int  Retorna 0 si no pudo realizar la iteracion
 *              Retorna 1 si todo salio con exito
 */
int printAutos(eAuto autos[], int tam, eMarca marcas[], int tamMar, eColor colores[], int tamCol)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0 && marcas != NULL && colores != NULL && tamCol > 0 && tamMar > 0)
    {
        tableText();

        for(int i = 0; i < tam; i++)
        {
            if(autos[i].isEmpty == 0)
            {
                printAuto(autos[i], marcas, tamMar, colores, tamCol);
            }
        }
        printf("\n\n");

        todoOk = 1;
    }

    return todoOk;
}


/** \brief imprime individualmente cada auto recibido por printAutos
 *
 * \param unAuto eAuto  Auto individual recibido en cada iteracion de printAutos
 * \param marcas[] eMarca
 * \param tamMar int
 * \param colores[] eColor
 * \param tamCol int
 * \return int      Retorna 1 si pudo mostrar cada auto
 *                  Retorna 0 si fallo al mostrar al menos un auto
 */
int printAuto(eAuto unAuto, eMarca marcas[], int tamMar, eColor colores[], int tamCol)
{
    int todoOk = 0;
    char descripcionMarca[20];
    char descripcionColor[20];
    char descripcionCaja[20];
    char manual[20] = "Manual";
    char automatica[20] = "Automatica";

    cargarDescripcionMarca(marcas, tamMar, unAuto.idMarca, descripcionMarca);
    cargarDescripcionColor(colores, tamCol, unAuto.idColor, descripcionColor);


    if(unAuto.caja == 'm')
    {
        strcpy(descripcionCaja, manual);
    }
    if(unAuto.caja == 'a')
    {
        strcpy(descripcionCaja, automatica);
    }

    printf("%3d   %15s  %15s   %15s\n",
           unAuto.id,
           descripcionMarca,
           descripcionColor,
           descripcionCaja
          );


    todoOk = 1;


    return todoOk;
}


/** \brief Tabla generica para listar autos
 *
 * \return void
 *
 */
void tableText()
{
    system("cls");
    printf("     Lista DE AUTOS \n\n");
    printf("*********************************************************************\n");
    printf("ID               MARCA             Color              Caja                          \n");
    printf("*********************************************************************\n\n");
}


/** \brief Reacomoda el array de autos a fin de ser mas prolijo de manipular
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int sortReacomodar(eAuto autos[], int tam)
{
    int todoOk = 0;

    eAuto auxAuto;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(
                    (autos[i].isEmpty > autos[j].isEmpty)
                   || (autos[i].isEmpty == autos[j].isEmpty)
                )
                {
                    auxAuto = autos[i];
                    autos[i] = autos[j];
                    autos[j] = auxAuto;
                }

            }
        }
    }

    todoOk = 1;

    return todoOk;
}










