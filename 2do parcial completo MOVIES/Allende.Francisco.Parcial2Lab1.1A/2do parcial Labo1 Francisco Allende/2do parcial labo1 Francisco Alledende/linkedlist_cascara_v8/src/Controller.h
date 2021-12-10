#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pArrayListPelis);
int controller_ListMovies(LinkedList* pArrayListPelis);
int controller_sortMovies(LinkedList* pArrayListPelis);
int controller_saveAsText(char* path, LinkedList* pArrayListPelis);
void* controller_mapDuracion(void* pElement);

#endif // CONTROLLER_H_INCLUDED
