#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define TAM_MOVIES 500

int main()
{
    eMovie movies[TAM_MOVIES];
    eMovie* pMovies = movies;

    InicializarPeliculas(pMovies,TAM_MOVIES, 0);

    int contPeliculas = 0;
    CargarPeliculas(pMovies, &contPeliculas);


    int opcion;
    do{
        opcion = menu();

        switch(opcion)
        {
            case 1:
                movie_new(pMovies);
                contPeliculas++;
                GuardarArchivo(pMovies, contPeliculas);

                break;

            case 2:
                contPeliculas = contPeliculas - movie_baja(pMovies, TAM_MOVIES);
                GuardarArchivo(pMovies, contPeliculas);
                break;

            case 3:
                movie_modificar(pMovies, TAM_MOVIES);
                GuardarArchivo(pMovies, contPeliculas);
               break;

            case 4:

                generarPagina(pMovies, contPeliculas);
                printf("\n\n***\tPAGINA GENERADA!\t***\n");
                system("pause");
                break;
        }
    }while(opcion != 5);

    return 0;
}
