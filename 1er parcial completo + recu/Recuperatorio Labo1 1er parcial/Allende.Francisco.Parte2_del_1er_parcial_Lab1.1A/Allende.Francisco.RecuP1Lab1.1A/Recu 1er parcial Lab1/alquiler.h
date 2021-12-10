#include "cliente.h"

#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
struct
{
    int id;
    char equipo[30];
    int idCliente;      //cliente FK
    char operador[30];
    int tiempoEstimado;
    int tiempoReal;
    int estado;
} typedef eAlquiler;


#endif // ALQUILER_H_INCLUDED

int initAlquiler(eAlquiler alquileres[], int tam);
int searchFreePositionAlq(eAlquiler alquileres[], int tam);
int findAlquilerById(eAlquiler alquileres[], int tam, int id);
int arrayHasAlquileres(eAlquiler alquileres[], int tam);
void printAlq(eAlquiler unAlq);
int addAlquiler(eAlquiler alquileres[], int tam, int indice, int* pidAlq, eCliente clientes[], int tamCli);
int finAlquiler(eAlquiler alquileres[], int tam, int idAlquilerFin);
int promedioTiempoReal(eAlquiler alquileres[], int tam);
int printClientAndAlq(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli);
void printAlqConNombre(eAlquiler unAlq, eCliente unCliente);
int clienteConMasAlquileres(eAlquiler alquileres[], int tamAlq, eCliente clientes[], int tamCli);













