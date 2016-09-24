#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define MAX 20


/** \brief recibe una estructura y la recorre para encontrar un indice libre
 *
 * \param estructura
 * \return retorna el indice
 *
 */

int BuscarLibre(ePersonas x[])
{
    int indice = -1;
	int i;

	for(i=0; i<MAX; i++)
	{
		if(x[i].estado == 1)
        {
            indice = i;
        }

	}
	return indice;
}

/** \brief recorre una estructura comparando dni
 *
 * \param estructura
 * \return devuelve el indice correspondiente a la estruct del dni seleccionado
 *
 */

int BuscarPorDni(ePersonas x[])
{
    int auxDni;
	int i;
	int indice = -1;

	printf("\nIngrese el DNI de la persona a borrar: ");
    fflush(stdin);
    scanf("%d", &auxDni);

	for(i=0; i<MAX; i++)
	{
		if(x[i].dni == auxDni)
        {
            indice = i;
        }

	}
	return indice;
}

/** \brief  BAJA LOGICA
            recorre una estructura comparando por dni, cuando lo encuenra lo imprime por pantalla
            y si se confirma borrar le cambia el estado a 1
 *
 * \param estructura
 * \return retorna indice dado de baja
 *
 */

int BajaUsuario(ePersonas x[])
{
	int indice;
	char confirma;

	indice = BuscarPorDni(x);

    if(indice == -1)
    {
        printf("\n*** No se encontro usuario con ese Dni ***\n\n");
        system("pause");
    }
    else
    {
        printf("\n***     USUARIO     ***\n");
        printf("\nNombre: %s", x[indice].nombre);
        printf("\nEdad: %d", x[indice].edad);
        printf("\nDNI: %d", x[indice].dni);
        printf("\n\nConfirma baja de usuario? S/N   ");
        fflush(stdin);
        confirma=tolower(getchar());

        while(confirma != 's' && confirma != 'n')
        {
            printf("\nRespuesta invalida. Confirme S o N ");
            fflush(stdin);
            confirma=tolower(getchar());
        }

        if(confirma == 's')
        {
            printf("\n***   USUARIO DADO DE BAJA   ***\n\n");
            x[indice].estado = 1;
            system("pause");
        }
        else
        {
            printf("\n***   BAJA CANCELADA   ***\n\n");
            system("pause");
        }
    }
    return indice;
}

/** \brief ordena alfabeticamente por los .nombre de las esructuras y los muestra por pantalla
 *
 * \param void
 * \
 *
 */

void OrdenarYMostrar(ePersonas x[])
{

	ePersonas aux;
	int i;
	int j;

	for(i=0; i<MAX-1; i++)
	{
		for(j=i+1; j<MAX; j++)
	        {
	        	if(strcmp(x[i].nombre, x[j].nombre) >0)
	                {
	                	aux = x[i];
	                	x[i] = x[j];
	                	x[j] = aux;
	                }
		}
	}


	printf("***     LISTA DE USUARIOS     ***\n");

    for(i=0; i<MAX; i++)
    {
        if(x[i].estado == 0)
        {
            printf("\nNombre: %s", x[i].nombre);
            printf("\nEdad: %d", x[i].edad);
            printf("\nDNI: %d\n\n", x[i].dni);
        }
    }
    system("pause");
}

/** \brief recibe tres rangos, los compara y, en base al tamaño de cada uno
            imprime un asterisco o un campo vacio de forma ordenada
 *
 * \
 * \return void
 *
 */

void Graficar(int rango1, int rango2, int rango3)
{
    int mayor = calcularMayor(rango1, rango2, rango3);
    int i, j;

    char matriz[mayor][3];

    system("cls");
    printf("***   GRAFICO DE EDADES   ***\n\n");

    for(j=0; j<mayor; j++)
    {
        for(i=0; i<3; i++)
        {
            switch(i)
            {
                case 0:
                    if(rango1 > j)
                        matriz[j][i]='*';
                    else
                        matriz[j][i]=' ';
                        break;
                case 1:
                    if(rango2 > j)
                        matriz[j][i]='*';
                    else
                        matriz[j][i]=' ';
                        break;
                    case 2:
                    if(rango3 > j)
                        matriz[j][i]='*';
                    else
                        matriz[j][i]=' ';
                        break;
            }
        }
    }
    for(j=mayor-1; j>=0; j--)
    {
            printf("  %c      %c      %c \n", matriz[j][0], matriz[j][1], matriz[j][2]);
    }
    printf("\n <18   19-35   >35\n\n");
    system("pause");
}

/** \brief toma tres rangos y los compara
 *
 * \param se declara el in "mayor" y se le asigna el valor del rango mas alto
 * \return devuelve mayor
 *
 */

int calcularMayor(int x, int y, int z)
{
    int mayor;

    if(x > y && x > z)
    {
        mayor = x;
    }
        else
        {
            if( y > x && y >= z)
            {
            mayor = y;
            }
            else
            {
                mayor = z;
            }
        }
    return mayor;

}
