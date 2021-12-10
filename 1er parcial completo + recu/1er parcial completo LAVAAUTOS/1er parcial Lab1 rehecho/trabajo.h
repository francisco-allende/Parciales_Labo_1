#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

struct
{
    int dia;
	int mes;
	int anio;

} typedef eFecha;

struct
{
    int id;
	int patente;
	int idServicio;
	int isEmpty;
    eFecha fecha;

} typedef eTrabajo;

#endif // TRABAJO_H_INCLUDED

int hardcodearTrabajosBD(eTrabajo trabajos[], int tam);
int arrayHasJobs(eTrabajo trabajos[], int tam);
int sortReacomodarTrabajos(eTrabajo trabajos[], int tam);
int initTrabajo(eTrabajo trabajos[], int tam, int start);
int searchFreePositionTrabajo(eTrabajo trabajos[], int tam);
void tableTextTrabajo();




