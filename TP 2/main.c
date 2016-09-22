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


int main()
{
    ePersonas lista[MAX];
    char seguir='s';
    int opcion=0;
    int i;
    int j;
    char aux;
    int auxDni;
    char confirma;

    for(i=0; i<MAX; i++)
    {
        lista[i].estado = 0;
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

                for(i=0; i<MAX; i++)
                {
                	if(lista[i].estado == 0)
                	{
                		printf("\nIngrese apellido y nombre completo: ");
                		fflush(stdin);
                		gets(lista[i].nombre);
                		printf("\nIngrese edad: ");
                		fflush(stdin);
                		scanf("%d", &lista[i].edad);
                		printf("\nIngrese DNI: ");
                		fflush(stdin);
                		scanf("%d", &lista[i].dni);
                		lista[i].estado = 1;
                		printf("\n\n**  USUARIO CARGADO CON EXITO!!  **");
                		system("pause");
                		break;
                	}
                }
                break;

            case 2:

                printf("Ingrese el DNI de la persona a borrar: ");
                fflush(stdin);
                scanf("%d", &auxDni);

                for(i=0; i<MAX; i++)
                {
                	if(lista[i].dni == auxDni)
                	{
                		printf("***     USUARIO     ***\n");
                		printf("\nNombre: %s", lista[i].nombre);
                		printf("\nEdad: %d", lista[i].edad);
                		printf("\nDNI: %d", lista[i].dni);
                		printf("\n\nConfirma baja de usuario? S/N   ");
                		confirma=tolower(gets(confirma));

                		if(confirma == 's')
                		{
                			printf("***   USUARIO DADO DE BAJA   ***");
                			lista[i].estado = 0;
                			system("pause");
                		}
                		else
                		{
                			printf("***   BAJA CANCELADA   ***");
                			system("pause");
                		}

                	}
                	else
                	{
                		printf("Usuario no encontrado");
                		system("pause");
                	}
                }
                break;

            case 3:

                for(i=0; i<MAX-1; i++)
                {
                	for(j=i+1; j<MAX; j++)
                	{
                		if(strcmp(lista[i].nombre, lista[j].nombre) >0)
                		{
                			aux = lista[i].nombre;
                			lista[i].nombre = lista[j].nombre;
                			lista[j].nombre = aux;
                		}
                	}
                }
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
