#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct
{
    int id;
	char nombreColor[20];

} typedef eColor;

#endif // COLOR_H_INCLUDED

void hardcodearColores(eColor colores[], int tam);
int cargarDescripcionColor(eColor colores[], int tam, int idCol, char* descripcion);
void tableTextColores();

