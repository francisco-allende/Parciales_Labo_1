#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

/** \brief Menu principal con opciones. Posee un submenu de informes en el punto 10
 *
 * \return int      Retorna la opcion elegida al main para hacer el case segun lo elegido
 *
 */
int menu()
{
    int opcion;

    system("cls");
    printf("*********************************\n");
    printf("*\tABM   Lavadero \t\t*\n");
    printf("*********************************\n");
    printf("\t\t\t\t*\n");
    printf("1 - Alta auto\t\t\t\n");
    printf("2 - Modificar datos del auto\t\n");
    printf("3 - Baja auto\t\t\t\n");
    printf("4 - Listar autos ordenado\t\n");
    printf("5 - Listar marcas\t\t\n");
    printf("6 - Listar colores\t\t\n");
    printf("7 - Listar servicios\t\t\n");
    printf("8 - Alta trabajo\t\t\n");
    printf("9 - Listar trabajos\t\t\n");
    printf("10 - Submenu de informes\n");
    printf("11 - Salir\t\t\t*\n");
    printf("\t\t\t\t*\n");
    printf("*********************************\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/** \brief menu puramente de informes que se despliega cuando en el menu principal se presiona el 10
 *
 * \return int      Retorna la opcion elegida al main para hacer el case segun lo elegido
 *
 */
int menuInformes()
{
    int opcion;

    system("cls");
    printf("*********************************\n");
    printf("*\tMenu  Listados e Informes\t\t*\n");
    printf("*********************************\n");
    printf("1 - Listar autos del mismo color.\t\t\t\n");
    printf("2 - Listar autos de la misma marca.\t\n");
    printf("3 - Listar promedio de autos con caja manual y automatica\t\t\t\n");
    printf("4 - Listar los autos por caja.\t\n");
    printf("5 - Listar por marca y color a eleccion.\t\t\n");
    printf("6 - Listar la marca mas elegida por los clientes.\t\t\n");
    printf("7 - Listar todos los trabajos hechos a un auto.\t\t\n");
    printf("8 - Listar la suma de los importes a pagar segun auto.\t\t\n");
    printf("9 - Listar autos por servicio y fecha.\t\t\n");
    printf("10 - Listar todos los servicios hechos en una misma fecha.\t\t\n");
    printf("11 - Volver al menu principal\t\t\n\n");

    printf("Marque su opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


/** \brief subMenu con criterio de ordenamiento a eleccion
 *
 * \param opcion int*
 * \return int          Retorna la opcion elegida como el criterio elegido
 *
 */
int subMenu(int* opcion)
{
    int subOpcion;
    int todoOk = 0;

    if(opcion != NULL)
    {
        system("cls");
        printf("*** Ordenar listado de autos ***\n\n");
        printf("Siendo:\n");
        printf("Orden ascendente (De la A a la Z)\t 1\n");
        printf("Orden descendente (De la Z a la A)\t 2\n");
        printf("Ingrese su opcion: ");
        fflush(stdin);
        scanf("%d", &subOpcion);
        while(subOpcion != 1 && subOpcion != 2)
        {
            printf("Numero incorrecto. \n");
            fflush(stdin);
            scanf("%d", &subOpcion);
        }

        *opcion = subOpcion;

        todoOk = 1;
    }

    return todoOk;
}

/** \brief SubMenu con las opciones a modificar (Color || Modelo)
 *
 * \param opcion int*
 * \return int          Retorna la opcion a modificar
 *
 */
int subMenuModificar(int* opcion)
{
    int subOpcion;
    int todoOk = 0;

    if(opcion != NULL)
    {
        system("cls");
        printf("*** Modificar datos del auto ***\n\n");
        printf("Siendo:\n");
        printf("Color\t 1\n");
        printf("Modelo\t 2\n");
        printf("Ingrese su opcion: ");
        fflush(stdin);
        scanf("%d", &subOpcion);
        while(subOpcion != 1 && subOpcion != 2)
        {
            printf("Numero incorrecto. \n");
            fflush(stdin);
            scanf("%d", &subOpcion);
        }

        *opcion = subOpcion;

        todoOk = 1;
    }

    return todoOk;
}

/** \brief Valida que el usuario quiera seguir o no realizando una accion
 *
 * \param seguir char
 * \return int          Retorna 0 si no existe la opcion de seguir presionada
 *                      Retorna 1 si se presiona una opcion valida, s || n
 */
int validateSeguir(char seguir)
{
    int todoOk = 0;

    if(seguir == 's' || seguir == 'n')
    {
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Valida el rango de la fecha
 *
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int          Retorna 0 si la fecha es inexistente
 *                      Retorna 1 si la fecha es realista
 */
int validateDate(int dia, int mes, int anio)
{
    int todoOk = 0;

    if(
        (dia > 0 && dia < 32) &&
        (mes > 0 && mes < 13) &&
        (anio > 1979 && anio < 2022)
    )
    {
        todoOk = 1;
    }

    return todoOk;
}

/** \brief subMenu con la opcion del color a mostrar
 *
 * \param colorAElegir int  variable a cargar con el color a elegir
 * \return int              Retorna el color a elegir
 *
 */
int elegirOpcionColor(int colorAElegir)
{

    printf("\nIngrese el Id del color a mostrar: ");
    fflush(stdin);
    scanf("%d", &colorAElegir);
    while(colorAElegir < 5000 || colorAElegir > 5004)
    {
        printf("Ese id de color no existe. Vuelva a intentar: ");
        fflush(stdin);
        scanf("%d", &colorAElegir);
    }

    return colorAElegir;
}

/** \brief subMneu con la opcion de la marca a mostrar
 *
 * \param marcaAElegir int  Variable a cargar con la marca a mostrar
 * \return int              Retorna la marca a mostrar
 *
 */
int elegirOpcionMarca(int marcaAElegir)
{

    printf("\nIngrese el Id de la marca: ");
    fflush(stdin);
    scanf("%d", &marcaAElegir);
    while(marcaAElegir < 1000 || marcaAElegir > 1004)
    {
        printf("Ese id de marca no existe. Vuelva a intentar: ");
        fflush(stdin);
        scanf("%d", &marcaAElegir);
    }

    return marcaAElegir;
}
