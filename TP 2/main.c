#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 20

typedef struct
{
    char nombre[25];
    int edad;
    int dni;
    int estado;
}ePersonas;

void AltaPersona(ePersonas x[]);
void BajaUsuario(ePersonas x[]);
void OrdenarYMostrar(ePersonas x[]);
int BuscarLibre(ePersonas x[]);
int BuscarPorDni(ePersonas x[]);


int main()
{
    ePersonas lista[MAX];
    char seguir='s';
    int opcion=0;
    int i;

    for(i=0; i<MAX; i++)
    {
        lista[i].estado = 1;
    }

    while(seguir=='s')
    {
        system("cls");
        printf("***    MENU DE OPCIONES   ***\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                AltaPersona(lista);
                break;

            case 2:

                BajaUsuario(lista);
                break;

            case 3:

                OrdenarYMostrar(lista);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

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


void AltaPersona(ePersonas x[])
{
	int indice;

	indice = BuscarLibre(x);

	if(indice == -1)
    {
        printf("\n*** No hay espacio para usuario nuevo ***\n\n");
        system("pause");
    }
    else
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(x[indice].nombre);
        printf("\nIngrese edad: ");
        fflush(stdin);
        scanf("%d", &x[indice].edad);
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%d", &x[indice].dni);
        x[indice].estado = 0;
        printf("\n\n**  USUARIO CARGADO CON EXITO!!  **\n");

        system("pause");
    }
}

void BajaUsuario(ePersonas x[])
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
}


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


