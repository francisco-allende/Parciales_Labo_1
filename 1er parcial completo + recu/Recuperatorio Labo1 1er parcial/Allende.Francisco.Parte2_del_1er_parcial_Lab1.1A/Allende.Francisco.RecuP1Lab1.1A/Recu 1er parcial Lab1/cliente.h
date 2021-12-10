#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int isEmpty;
} typedef eCliente;



#endif // CLIENTE_H_INCLUDED

int initCliente(eCliente clientes[], int tam);
int searchFreePositionCli(eCliente clientes[], int tam);
int findClienteById(eCliente clientes[], int tam, int id);
int arrayHasClientes(eCliente clientes[], int tam);
void printCliente(eCliente unCliente);
int addCliente(eCliente clientes[], int tam, int indiceLibre, int* pId);
void printClientes(eCliente clientes[], int  tam);
int modifyClient(eCliente clientes[], int indice, int opcion);
int removeCliente(eCliente clientes[], int tam, int id);
















