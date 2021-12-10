#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

struct
{
    int id; //comienza en 1000
	char descripcion[20];

} typedef eMarca;


#endif // MARCA_H_INCLUDED

void hardcodearMarcas(eMarca marcas[], int tam);
int cargarDescripcionMarca(eMarca marcas[], int tam, int idMar, char* descripcion);
void tableTextMarcas();


