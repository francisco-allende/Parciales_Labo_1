#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

struct
{
    int id;
    char titulo[150];
    char genero[80];
    int duracion;
}typedef eMovie;

#endif // MOVIES_H_INCLUDED

eMovie* eMovie_new();
eMovie* eMovie_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr);
int eMovie_setId(eMovie* this, int id);
int eMovie_setTitulo(eMovie* this, char* titulo);
int eMovie_setGenero(eMovie* this, char* genero);
int eMovie_setDurcion(eMovie* this, int duracion);
int eMovie_getId(eMovie* this, int* id);
int eMovie_getTitulo(eMovie* this, char* titulo);
int eMovie_getGenero(eMovie* this, char* genero);
int eMovie_getDuracion(eMovie* this, int* duracion);
void eMovie_delete(eMovie* eMovie);
int eMovie_print(eMovie* peli);
int eMovie_sortDuracion(void* peliOne, void* peliTwo);

int menu();
int menuFiltrado();
int eMovie_filerByAdventure(void* pElement);
int eMovie_filerByDrama(void* pElement);
int eMovie_filerByWestern(void* pElement);
int eMovie_filerByThriller(void* pElement);
int eMovie_filerByAction(void* pElement);
int eMovie_filerByAnimation(void* pElement);
int eMovie_filerByMusical(void* pElement);
int eMovie_filerByHorror(void* pElement);
int eMovie_filerByDocumentary(void* pElement);
int eMovie_filerByRomance(void* pElement);
int eMovie_filerByComedy(void* pElement);
int eMovie_sortGenero(void* peliOne, void* peliTwo);

