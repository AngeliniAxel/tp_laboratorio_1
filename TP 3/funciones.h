#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TAM_MOVIES 500

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[256];
    int puntaje;
    char linkImagen[256];
    int id;
}eMovie;

int menu(void);

int validar_soloNumeros(char* aux,int limInferior, int limSuperior);

int validar_soloLetras(char* string);
void get_stringLetras(char* string,char* msj,char* msjError,int tamArray);
int get_numeros(char* msj,char* msjError, int limInferior, int limSuperior);

void movie_new(eMovie* pMovie);

void InicializarPeliculas(eMovie* x, int tamArray, int valor);

int BuscarEspacioLibre(eMovie* x, int tamArray);

int BuscarPorId(eMovie* x, int id, int tamArray);

int movie_baja(eMovie* pMovie, int tamArray);

void movie_modificar(eMovie* pMovie, int tamArray);

void GuardarArchivo(eMovie* pMovie, int cont);
void CargarPeliculas(eMovie* pMovie, int* cont);

void generarPagina(eMovie* pMovie, int cont);

void get_texto(char* string,char* msj,char* msjError,int tamArray);



/**
 *
 *  @param
 *  @return
 */
int agregarPelicula(eMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */


#endif // FUNCIONES_H_INCLUDED
