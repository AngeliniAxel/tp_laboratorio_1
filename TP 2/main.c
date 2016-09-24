// goto.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define MAX 20

int main()
{
    ePersonas lista[MAX];
    char seguir='s';
    int opcion=0;
    int i;
    int edad18 = 0;
    int edad19a35 = 0;
    int edadMayor35 = 0;
    int indice;
    int flag = 0;


    for(i=0; i<MAX; i++) /* Inicializa los estados para que esten vacios */
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

                system("cls");
                indice = BuscarLibre(lista); /* Busca un indice con estado libre */

                if(indice == -1)
                {
                    printf("\n*** No hay espacio para usuario nuevo ***\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nIngrese nombre: ");
                    fflush(stdin);
                    gets(lista[indice].nombre);
                    printf("\nIngrese edad: ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].edad);

                    while(lista[indice].edad <= 0 || lista[indice].edad > 100) /* Verifica que se ingrese una edad valida */
                    {
                        printf("Error. Ingrese edad valida: ");
                        fflush(stdin);
                        scanf("%d", &lista[indice].edad);
                    }
                    printf("\nIngrese DNI: ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].dni);

                    while(lista[indice].dni <= 1000000 || lista[indice].dni > 99999999) /* Verifica que se ingrese un dni valido */
                    {
                        printf("Error. Ingrese dni valida: ");
                        fflush(stdin);
                        scanf("%d", &lista[indice].dni);

                    }

                    lista[indice].estado = 0;
                    printf("\n\n**  USUARIO CARGADO CON EXITO!!  **\n\n");

                    strcpy(lista[indice].nombre,strlwr(lista[indice].nombre)); /*Pasa toda la cadena de texto a minusculas */
                    lista[indice].nombre[0] = toupper(lista[indice].nombre[0]); /* Pasa la primer letra de la cadena a mayuscula */
                    flag = 1;

                }
                if(lista[indice].edad<18)  /* El if toma como param la edad y la utiliza para sumar los contadores */
                {
                    edad18++;
                }else if(lista[indice].edad >= 19 && lista[indice].edad <= 35){
                    edad19a35++;
                }else if(lista[indice].edad > 35){
                    edadMayor35++;
                }
                system("pause");
                break;

            case 2:

                if(flag != 1)
                {
                    printf("\nDebe agregar un usuario antes de acceder a esta funcion!!\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    indice = BajaUsuario(lista);
                    if(lista[indice].edad<18) /*El if toma como param la edad del usuario dado de baja y la resta al contador correspondiente */
                    {
                        edad18--;
                    }else if(lista[indice].edad >= 19 && lista[indice].edad <= 35){
                        edad19a35--;
                    }else if(lista[indice].edad > 35){
                        edadMayor35--;
                    }
                }
                break;

            case 3:

                if(flag != 1)
                {
                    printf("\nDebe agregar un usuario antes de acceder a esta funcion!!\n\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    OrdenarYMostrar(lista);
                }
                break;
            case 4:

                if(flag != 1)
                {
                    printf("\nDebe agregar un usuario antes de acceder a esta funcion!!\n\n");
                    system("pause");
                }
                else
                {
                    Graficar(edad18, edad19a35, edadMayor35);
                }
                break;
            case 5:
                seguir = 'n';
                printf("\n\n*** HASTA LUEGO!!!   ***\n\n");
                break;
        }
    }

    return 0;
}




