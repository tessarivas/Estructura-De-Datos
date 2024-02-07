/*
ALUMNA: Teresa Rivas Gómez
MATRICULA: 372565
MATERIA: Estrctura de datos
TEMA: Listas Enlazadas
FECHA: 06-02-2024
*/

/* Profe, me apoye mucho de IA para completar el código ya que viendo videos en YouTuube
me confundi un poco y aun no termino de entender muy bien el uso de punteros y las flechas,
espero pronto nos lo pueda explicar más a detalle en una clase. */

// LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ESTRCUTURA PARA LA LISTA
typedef struct libro {
    char *matricula;
    char *apellidoPaterno;
    char *apellidoMaterno;
    char *nombres;
    struct libro *siguiente;
} Libro;

// FUNCION QUE CREA UNA LISTA VACIA
Libro *crearLista() 
{
    return NULL;
}

// FUNCION PARA INSERTAR UN LIBRO AL INICIO DE LA LISTA
Libro *insertarAlInicio(Libro *lista, char *matricula, char *apellidoPaterno, char *apellidoMaterno, char *nombres) 
{
    Libro *nuevoLibro = (Libro*)malloc(sizeof(Libro));
    nuevoLibro->matricula = strdup(matricula);
    nuevoLibro->apellidoPaterno = strdup(apellidoPaterno);
    nuevoLibro->apellidoMaterno = strdup(apellidoMaterno);
    nuevoLibro->nombres = strdup(nombres);
    nuevoLibro->siguiente = lista;
    // RETORNO
    return nuevoLibro;
}

// FUNCION PARA INSERTAR UN LIBRO AL FINAL DE LA LISTA
Libro *insertarAlFinal(Libro *lista, char *matricula, char *apellidoPaterno, char *apellidoMaterno, char *nombres) 
{
    Libro *nuevoLibro = (Libro*)malloc(sizeof(Libro));
    nuevoLibro->matricula = strdup(matricula);
    nuevoLibro->apellidoPaterno = strdup(apellidoPaterno);
    nuevoLibro->apellidoMaterno = strdup(apellidoMaterno);
    nuevoLibro->nombres = strdup(nombres);
    nuevoLibro->siguiente = NULL;
    // CONDICION
    if (lista == NULL) 
    {
        return nuevoLibro;
    } 
    else 
    {
        Libro *temp = lista;
        while (temp->siguiente != NULL) 
        {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoLibro;
        // RETORNO
        return lista;
    }
}

// FUNCION PARA INSERTAR UN LIBRO EN UNA POSICION ESPECIFICA DE LA LISTA
Libro *insertarEnPosicion(Libro *lista, char *matricula, char *apellidoPaterno, char *apellidoMaterno, char *nombres, int posicion) 
{
    if (posicion < 0)
        return lista;
    
    Libro *nuevoLibro = (Libro*)malloc(sizeof(Libro));
    nuevoLibro->matricula = strdup(matricula);
    nuevoLibro->apellidoPaterno = strdup(apellidoPaterno);
    nuevoLibro->apellidoMaterno = strdup(apellidoMaterno);
    nuevoLibro->nombres = strdup(nombres);
    
    // CONDICION PARA LA POSICION
    if (posicion == 0) 
    {
        nuevoLibro->siguiente = lista;
        return nuevoLibro;
    }
    
    Libro *temp = lista;
    int i = 0;
    while (temp != NULL && i < posicion - 1) 
    {
        temp = temp->siguiente;
        i++;
    }
    
    if (temp == NULL)
        return lista;
    
    nuevoLibro->siguiente = temp->siguiente;
    temp->siguiente = nuevoLibro;

    //RETORNO
    return lista;
}

// FUNCION PARA BORRAR UN LIBRO DE LA LISTA
Libro *borrarElemento(Libro *lista, int posicion) 
{
    if (posicion < 0 || lista == NULL)
        return lista;
    
    if (posicion == 0) 
    {
        Libro *temp = lista;
        lista = lista->siguiente;
        free(temp->matricula);
        free(temp->apellidoPaterno);
        free(temp->apellidoMaterno);
        free(temp->nombres);
        free(temp);

        return lista;
    }
    
    Libro *temp = lista;
    int i = 0;
    while (temp != NULL && i < posicion - 1) 
    {
        temp = temp->siguiente;
        i++;
    }
    
    if (temp == NULL || temp->siguiente == NULL)
        return lista;
    
    Libro *temp2 = temp->siguiente;
    temp->siguiente = temp2->siguiente;
    free(temp2->matricula);
    free(temp2->apellidoPaterno);
    free(temp2->apellidoMaterno);
    free(temp2->nombres);
    free(temp2);

    return lista;
}

// FUNCION PARA IMPRIMIR LA LISTA DE LIBROS
void imprimirLista(Libro *lista) 
{
    printf("Lista de libros:\n");
    while (lista != NULL) 
    {
        printf("Matricula: %s, Apellido Paterno: %s, Apellido Materno: %s, Nombres: %s\n",
               lista->matricula, lista->apellidoPaterno, lista->apellidoMaterno, lista->nombres);
        lista = lista->siguiente;
    }
}

// FUNCION PARA LIBERAR LA MEMORIA OCUPADA POR LA LISTA DE LIBROS
void liberarLista(Libro *lista) 
{
    while (lista != NULL) {
        Libro *temp = lista;
        lista = lista->siguiente;
        free(temp->matricula);
        free(temp->apellidoPaterno);
        free(temp->apellidoMaterno);
        free(temp->nombres);
        free(temp);
    }
}

int main() 
{
    Libro *lista = crearLista();
    
    // INSERTAR LOS LIBROS EN LA LISTA
    lista = insertarAlInicio(lista, "372565", "Rivas", "Gomez", "Teresa");
    lista = insertarAlFinal(lista, "372566", "Rodriguez", "Lopez", "Juan");
    lista = insertarEnPosicion(lista, "372567", "Perez", "Martinez", "Ana", 1);
    
    // IMPRIMIR LA LISTA
    imprimirLista(lista);
    
    // BORRAR ELEMENTO DE LA LISTA
    lista = borrarElemento(lista, 1);
    
    // IMPRIMIR LA LISTA ACTUALIZADA
    imprimirLista(lista);
    
    // LIBERAR MEMORIA
    liberarLista(lista);
    
    return 0;
}