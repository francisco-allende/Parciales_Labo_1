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

/** \brief Informe 1. Muestra el color elegido por el usuario
 *
 * \param autos[] eAuto
 * \param colores[] eColor
 * \param tam int
 * \param colorAMostrar int     Id color a mostrar elegido previamente en un menu
 * \param tamCol int
 * \return int                  Retorna 0 si no pudo mostrar el color elegido
 *                              Retorna 1 si muestra el color ocn exito
 */
int mostrarColorAElegir(eAuto autos[], eColor colores[], int tam, int colorAMostrar, int tamCol)
{
    int todoOk = 0;
    char descripcion[20];

    tableTextColores();

    for(int i = 0; i < tam; i++)
    {
        if(autos[i].idColor == colorAMostrar)
        {
            cargarDescripcionColor(colores, tamCol, colorAMostrar, descripcion);
            printf("%d\t\t %s\n", autos[i].id, descripcion);
            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief Informe 2. Muestra la marca elegida por el usuario
 *
 * \param autos[] eAuto
 * \param marcas[] eMarca
 * \param tam int
 * \param marcaAMostrar int     Id de la marca a mostrar previamente elegido en un menu
 * \param tamMar int
 * \return int                  Retorna 0 si no pudo mostrar la marca
 *                              Retorna 1 si muestra la marca con exito
 */
int mostrarMarcaAElegir(eAuto autos[], eMarca marcas[], int tam, int marcaAMostrar, int tamMar)
{
    int todoOk = 0;
    char descripcion[20];

    tableTextMarcas();

    for(int i = 0; i < tam; i++)
    {
        if(autos[i].idMarca == marcaAMostrar)
        {
            cargarDescripcionMarca(marcas, tamMar, marcaAMostrar, descripcion);
            printf("%d\t\t %s\n", autos[i].id, descripcion);
            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief Informe 3. Calcula el promedio de los autos con caja automatica por un lado y manual por el otro
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int              Retorna 0 si no pudo calcular el promedio
 *                          Retorna 1 si pudo calcular con exito el promedio
 */
int promedioCajas(eAuto autos[], int tam)
{
    int todoOk = 0;

    int promedioManual = 0;
    int contadorManual = 0;
    int promedioAutomatica = 0;
    int contadorAutomatica = 0;
    int contadorTotal = 0;

    if(autos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(autos[i].caja == 'a')
            {
                contadorAutomatica++;
            }
            if(autos[i].caja == 'm')
            {
                contadorManual++;
            }
            contadorTotal++;
        }

        promedioAutomatica = (contadorTotal * contadorAutomatica) / contadorTotal;
        promedioManual = (contadorTotal * contadorManual) /  contadorTotal;

        printf("El promedio de autos con caja automatica es de: %d \n",promedioAutomatica);
        printf("El promedio de autos con caja manual es de: %d \n",promedioManual);

        todoOk = 1;
    }


    return todoOk;
}

/** \brief Informe 4. Printea el tipo de caja por auto
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int              Retorna 0 si no pudo mostrarlas las cajas
 *                          Retorna 1 si pudo mostrar las cajas
 */
int printCajas(eAuto autos[], int tam)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0)
    {
        tableTextCajas();

        for(int i = 0; i < tam; i++)
        {
            if(autos[i].isEmpty == 0)
            {
                printCaja(autos[i]);
            }
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Informe 4 complementacion. Carga la descripcion completa de la caja manual y automatica
 *
 * \param unAuto eAuto
 * \return void
 *
 */
void printCaja(eAuto unAuto)
{
    char descripcionCaja[20];
    char manual[20] = "Manual";
    char automatica[20] = "Automatica";

    if(unAuto.caja == 'm')
    {
        strcpy(descripcionCaja, manual);
    }
    if(unAuto.caja == 'a')
    {
        strcpy(descripcionCaja, automatica);
    }

    printf("%3d   %15s \n",
           unAuto.id,
           descripcionCaja
          );
}


/** \brief Informe 5. Muestra la marca && el color elegido por el usuario. Doble criterio de matcheo.
 *
 * \param autos[] eAuto
 * \param colores[] eColor
 * \param marcas[] eMarca
 * \param tamAuto int
 * \param tamMar int
 * \param tamCol int
 * \param colorAMostrar int     Id del color a mostrar
 * \param marcaAMostrar int     Id de la marca a mostrar
 * \return int                  Retorna 0 si no pudo mathcear ambas
 *                              Retorna 1 si matchea ambas con exito
 */
int mostrarMarcaYColor(eAuto autos[], eColor colores[],eMarca marcas[], int tamAuto, int tamMar, int tamCol, int colorAMostrar, int marcaAMostrar)
{
    int todoOk = 0;
    int hayMarca = 0;
    int hayColor = 0;
    char descripcionColores[20];
    char descripcionMarcas[20];

    //eAuto auxArray[tamAuto];

    tableTextInformeMarcaYColor();

    if(autos != NULL && colores != NULL && marcas != NULL && tamAuto > 0 && tamCol > 0 && tamMar >0 )
    {

        for(int i = 0; i < tamAuto; i++)
        {
            if(autos[i].idColor == colorAMostrar && autos[i].idMarca == marcaAMostrar)
            {
                for(int j = 0; j < tamCol; j++)
                {
                    if(colores[j].id == colorAMostrar)
                    {
                        strcpy(descripcionColores, colores[j].nombreColor);
                        printf("%d\t %s\t", autos[i].id, descripcionColores);
                        hayColor = 1;
                    }
                    if(marcas[j].id == marcaAMostrar)
                    {
                        strcpy(descripcionMarcas, marcas[j].descripcion);
                        printf("%s \n", descripcionMarcas);
                        hayMarca = 1;
                    }
                }
            }
        }

        if(hayMarca == 1 && hayColor == 1)
        {
            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief Informe 6. Muestra la marca mas comun dentro del array de autos. Funciona como un maximo con iteracion.
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamMar int
 * \return int              Retorna 0 si no pudo mostrar la marca mas comun del array de autos
 *                          Retorna 1 si pudo mostrar la marca mas comun del array de autos
 */
int mostrarMarcaMasElegida(eAuto autos[], int tam, eMarca marcas[], int tamMar)
{
    int todoOk = 0;
    int contadores[5] = {0};
    int contadorMayor;
    int flagMayor = 1;

    if(autos != NULL && marcas != NULL && tam > 0 && tamMar > 0)
    {
        system("cls");
        printf("Informe de los autos con la marca mas elegido\n");
        printf("*********************************************\n");

        //Cargo los valores del contador. Cada valor por posicion es la cantidad de marcas encontradas en autos
        //ejemplo 3 ford, 2 fiat, 5 renauult, etc.

        for(int i = 0; i < tamMar; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(autos[j].isEmpty == 0 && autos[j].idMarca  == marcas[i].id)
                {
                    contadores[i]++;
                }
            }
        }

        //Ya cargado el array contador, saco el maximo tambien con iteracion
        for(int i = 0; i < tamMar; i++)
        {
            if(flagMayor || contadores[i] > contadorMayor)
            {
                contadorMayor = contadores[i];
                flagMayor = 0;
            }
        }

        //Cargo la descripcion de la marca mas comun del array
        for(int i = 0; i < tamMar; i++)
        {
            if(contadores[i] == contadorMayor)
            {
                printf("%s\n", marcas[i].descripcion);
            }
        }

        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Informes 7 && 8. Muestra todos los trabajos hechos a un mismo auto y calcula el total a pagar por esos servicios
 *
 * \param autos[] eAuto
 * \param tam int
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamSer int
 * \param autoAMostrar int          Auto con los trabajos realizados
 * \param acumulador int*           Acumulador que es cargado pero solo printeado en el informe 8
 * \return int                      Retorna 0 si no pudo mostrar los trabajos hechos por auto
 *                                  Reotrna 1 si pudo mostrar con exito los trabajos hechos por auto
 */
int trabajosPorAuto(eAuto autos[], int tam, eTrabajo trabajos[], int tamTra, eServicio servicios[],  int tamSer, int autoAMostrar, int* acumulador)
{
    int todoOk = 0;
    *acumulador = 0;
    //eTrabajo auxTrabajo[10] = {};
    //eServicio auxServicio[10] = {};


    tableTextTrabajoPorAuto();

    if(autos != NULL && tam > 0 && tamTra > 0 && tamSer > 0)
    {
        for(int i = 0; i < tamTra; i++)
        {
            if(trabajos[i].patente == autoAMostrar && trabajos[i].isEmpty == 0)
            {
                for(int j = 0; j < tamSer; j++)
                {
                    if(trabajos[i].idServicio == servicios[j].id)
                    {
                        *acumulador = *acumulador + servicios[j].precio;  //CALCULO EL TOTAL A PAGAR

                        printf("%d\t   %d\t   %15s     %d\n",
                               trabajos[i].patente, trabajos[i].id,
                               servicios[j].descripcion,
                               servicios[j].precio);

                        todoOk = 1;
                    }
                }
            }
        }
    }

    return todoOk;
}


/** \brief Informe 9. Muestra el servicio elegido por auto y la fecha en que se realizaron dichso servicios
 *
 * \param autos[] eAuto
 * \param tamAuto int
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamSer int
 * \param servicioAElegir int       Servicio elegido
 * \return int                      Retorna 0 si no pudo mostrar los servicios por auto y fecha
 *                                  Retorna 1 si pudo mostrar los servicios por auto y fecha con exito
 */
int servicioElegidoAMostrar(eAuto autos[], int tamAuto, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer, int servicioAElegir)
{
    int todoOk = 0;

    eAuto auxAuto[10] = {};
    eTrabajo auxTrabajo[10] = {};

    if(autos != NULL && trabajos != NULL && servicios != NULL && tamAuto > 0)
    {
        for(int i = 0; i < tamAuto; i++)
        {
            if(trabajos[i].idServicio == servicioAElegir)
            {

                auxAuto[i].id = autos[i].id;
                auxAuto[i].isEmpty = 0;
                auxTrabajo[i].fecha.anio = trabajos[i].fecha.anio;
                auxTrabajo[i].fecha.mes = trabajos[i].fecha.mes;
                auxTrabajo[i].fecha.dia = trabajos[i].fecha.dia;
                auxTrabajo[i].isEmpty = 0;
            }
        }

        system("cls");
        printf("******************************\n");
        printf("***   Id auto      Fecha  ****\n");
        printf("******************************\n");

        for(int i = 0; i < tamAuto; i++)
        {
            if(auxAuto[i].isEmpty == 0 && auxAuto[i].id != 0)
            {
                printf(" %d ", auxAuto[i].id);

            }
            if(auxTrabajo[i].isEmpty == 0 && auxTrabajo[i].fecha.anio != 0)
            {
                printf("\t\t %d/%d/%d \n", auxTrabajo[i].fecha.anio, auxTrabajo[i].fecha.mes, auxTrabajo[i].fecha.dia);
            }

        }
    }

    todoOk = 1;

    return todoOk;
}

/** \brief Informe 10. Muestra el o los servicios realizados segun la fecha indicada
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamSer int
 * \param fechaMostrarDia int       Dia elegido
 * \param fechaMostrarMes int       Mes elegido
 * \param fechaMostrarAnio int      Año elegido
 * \return int                      Retorna 0 si no pudo mostrar los servicios por fecha
 *                                  Retorna 1 si con exito muestra los servicios por fecha
 */
int mostrarServiciosPorFecha(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer, int fechaMostrarDia, int fechaMostrarMes, int fechaMostrarAnio)
{
    int todoOk = 0;
    int precioServicio;
    char descripcion[20];

    printf("*********************************************\n");
    printf("Servicios en la fecha %d/%d/%d \n", fechaMostrarDia, fechaMostrarMes, fechaMostrarAnio);
    printf("\n");
    printf("ID Servicio  Servicio        Precio\n");
    printf("*************************************************\n");

    if(trabajos !=  NULL && servicios != NULL && tamTra > 0 && tamSer > 0)
    {
        for(int i = 0; i < tamTra; i ++)
        {
            if(trabajos[i].fecha.anio ==  fechaMostrarAnio && trabajos[i].fecha.mes ==  fechaMostrarMes && trabajos[i].fecha.dia ==  fechaMostrarDia)
            {
                cargarDescripcionServicio(servicios, tamSer, trabajos[i].idServicio, descripcion, &precioServicio);
                printf("%d %15s\t %d\n", trabajos[i].idServicio, descripcion, precioServicio);
            }

            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief Reacomodo el array de servicios por prolijidad
 *
 * \param servicios[] eServicio
 * \param tam int
 * \return int                      Retorna 0 si no pudo acomodarlo
 *                                  Retorna 1 si lo acomoda con exito
 */
int sortAcomodarServicios(eServicio servicios[], int tam)
{
    int todoOk = 0;

    eServicio auxServicio;

    if(servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(
                    (servicios[i].precio < servicios[j].precio||
                     servicios[i].precio == servicios[j].precio)
                )
                {
                    auxServicio = servicios[i];
                    servicios[i] = servicios[j];
                    servicios[j] = auxServicio;
                }
            }
        }
    }

    todoOk = 1;

    return todoOk;
}


/** \brief Muestra el trabajo realizado mas reciente
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int                  Retorna 0 si lo muestra con exito
 *                              Retorna 1 si no pudo mostrarlo
 */
int trabajoMasNuevo(eTrabajo trabajos[], int tam)
{
    int anioTrabajoMasNuevo = 0;
    int mesTrabajoMasNuevo = 0;
    int diaTrabajoMasNuevo = 0;
    int bandera = 1;

    int todoOk = 0;

    if(trabajos != NULL && tam > 0)
    {
        todoOk = 1;

        for(int i = 0; i < tam; i++)
        {
            if(bandera || (trabajos[i].fecha.anio >= anioTrabajoMasNuevo && trabajos[i].isEmpty == 0))
            {
                anioTrabajoMasNuevo = trabajos[i].fecha.anio;

                if(bandera || (trabajos[i].fecha.mes >= mesTrabajoMasNuevo))
                {
                    mesTrabajoMasNuevo = trabajos[i].fecha.mes ;

                    if(bandera || (trabajos[i].fecha.dia >= diaTrabajoMasNuevo))
                    {
                        diaTrabajoMasNuevo = trabajos[i].fecha.dia;
                        bandera = 0;
                    }
                }

            }
        }
    }

    printf("Fecha del trabajo mas nuevo: %d/%d/%d \n\n", anioTrabajoMasNuevo, mesTrabajoMasNuevo, diaTrabajoMasNuevo);

    return todoOk = 1;
}


/** \brief Tabla con id del auto y el tipo de caja
 *
 * \return void
 *
 */
void tableTextCajas()
{
    system("cls");
    printf("     LISTA  CAJAS \n\n");
    printf("*******************\n");
    printf("  PATENTE     CAJA\n");
    printf("*******************\n\n");
}

/** \brief Muestra los autos por marca y color elegido con sus ids
 *
 * \return void
 *
 */
void tableTextInformeMarcaYColor()
{
    system("cls");
    printf("     LISTA DE AUTOS POR MARCA Y COLOR ELEGIDO \n\n");
    printf("************************************************\n");
    printf("ID      COLOR       MARCA           \n");
    printf("**********************************************\n\n");
}

/** \brief Tabal para los trabajos realizados por cada auto
 *
 * \return void
 *
 */
void  tableTextTrabajoPorAuto()
{
    system("cls");
    printf("     LISTA DE TRABAJOS POR AUTO \n\n");
    printf("***************************************************\n");
    printf("  PATENTE     ID TRABAJO     SERVICIO    PRECIO    \n");
    printf("**************************************************\n\n");
}





