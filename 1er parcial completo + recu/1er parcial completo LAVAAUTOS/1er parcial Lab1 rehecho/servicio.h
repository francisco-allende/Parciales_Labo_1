#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

struct
{
    int id;
	char descripcion[25];
    int precio;

} typedef eServicio;

#endif // SERVICIO_H_INCLUDED

void hardcodearServicios(eServicio servicios[], int tam);
int cargarDescripcionServicio(eServicio servicios[], int tam, int idSer, char* descripcion, int* precio);
void tableTextServicio();
