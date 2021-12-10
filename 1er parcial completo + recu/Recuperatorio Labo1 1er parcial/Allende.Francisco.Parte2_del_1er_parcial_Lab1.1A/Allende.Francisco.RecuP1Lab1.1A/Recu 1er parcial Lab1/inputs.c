#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

int menu()
{
    int opcion;

    system("cls");
    printf("*********************************\n");
    printf("*\tABM   Construcciones y alquileres \t\t*\n");
    printf("*********************************\n");
    printf("\t\t\t\t*\n");
    printf("1 - Alta Cliente\t\t\t\n");
    printf("2 - Modificar datos del cliente\t\n");
    printf("3 - Baja cliente\t\t\t\n");
    printf("4 - Alta alquiler\t\n");
    printf("5 - Baja alquiler\t\t\n");
    printf("6 - Listar el nombre y apellido del asociado con más alquileres\t\t\n");
    printf("7 - El o los equipo/s más alquilado/s y su cantidad\t\t\n");
    printf("8 - El tiempo promedio real de alquiler de los equipos\t\t\n");
    printf("9 - Todos los clientes con sus alquileres.\t\t\n");
    printf("10 - Salir\t\t\t*\n");
    printf("\t\t\t\t*\n");
    printf("*********************************\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void tableTextCli()
{
    system("cls");
    printf("     Lista DE CLIENTES \n\n");
    printf("*********************************************************************\n");
    printf("ID          DNI             NOMBRE              APELLIDO        \n");
    printf("*********************************************************************\n\n");
}

void tableTextAlq()
{
    system("cls");
    printf("     Lista DE CLIENTES \n\n");
    printf("*********************************************************************\n");
    printf("ID     EQUIPO      ID CLIENTE       OPERADOR     TIEMPO ESTIMADO      \n");
    printf("*********************************************************************\n\n");
}

int subMenuModificar()
{
    int opcion;

    system("cls");
    printf("*********************************\n");
    printf("*\t Modificar \t\t*\n");
    printf("*********************************\n");
    printf("\t\t\t\t*\n");
    printf("1 - Modificar Nombre\t\t\t\n");
    printf("2 - Modificar Apellido\t\n");
    printf("3 - Cancelar\t\t\t*\n");
    printf("\t\t\t\t*\n");
    printf("*********************************\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}























int validarChar(char* cadena, int minimo, int maximo)
{

    //Validar si un string tiene letras o numeros y su length
    int todoOk = 0;
    int esNum;
    int esChar = 0;
    int length = strlen(cadena);

    if(length >= minimo && length < maximo)
    {
        esChar = esSoloLetras(cadena);
        esNum = esNumerico(cadena);


        if(!esNum && esChar)
        {
            todoOk = 1;
        }
        else
        {
            printf("No se pueden ingresar numeros\n\n");
        }
    }
    else
    {
        printf("\n");
        printf("No puede superar los %d caracteres ni ser igual o menor a %d \n", maximo, minimo);
        printf("\n\n");
        esChar = 0;
    }


    return todoOk;
}

int esSoloLetras(char str[])
{
    int i = 0;


    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) //que no sea un espacio y que no este entre a y z y que no este entre A y Z
        {
            return 0; //NO es una letra
        }

        i++;
    }

    return 1; //SI es una letra

}

int esNumerico(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0; //no es numerico, no se hayaron numeros
        }
        i++;
    }

    return 1; //hace referencia a que si es numerico
}













































