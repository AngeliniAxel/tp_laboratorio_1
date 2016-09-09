#include <stdio.h>
#include <stdlib.h>
#include "angelini.h"

int main()
{
    int opcion;
    float a=0;
    float b=0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorial;

    do{
        system("cls");
        printf("\nMENU DE OPCIONES:\n\n");
        printf("1- Ingresar primer operando (A=%.2f)\n",a);
        printf("2- Ingresar segundo operando (B=%.2f)\n",b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\nIngrese opcion: ");

        scanf("%d",&opcion);

        // Toma el dato y valida que este dentro del rango de opciones disponibles
        while(opcion < 1 || opcion > 9)
        {
            printf("\nError. Ingrese una opcion valida: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
            case 1:

                a = pedirOperando();
                break;

            case 2:

                b = pedirOperando();
                break;

            case 3:

                suma = funcionSuma(a,b);
                printf("\nEl resultado de la suma es: %.2f\n\n",suma);
                system("pause");
                break;

            case 4:

                resta = funcionResta(a,b);
                printf("\nEl resultado de la resta es: %2.f\n\n",resta);
                system("pause");
                break;

            case 5:

                //Valida que el divisor sea mayor a 0
                if(b==0)
                {
                    printf("\nNo se puede dividir por 0\n\n");
                    system("pause");
                }else
                {
                    division = funcionDivision(a,b);
                    printf("\nEl resultado de la division es: %.2f\n\n",division);
                    system("pause");
                }
                break;

            case 6:

                multiplicacion = funcionMultiplicacion(a,b);
                printf("\nEl resultado de la multiplicacion es: %.2f\n\n",multiplicacion);
                system("pause");
                break;

            case 7:

                factorial = funcionFactorial(a);
                printf("\nEl resultado del factorial es: %.2f\n\n",factorial);
                system("pause");
                break;

            case 8:

                suma = funcionSuma(a,b);
                printf("\nEl resultado de la suma es: %.2f\n\n",suma);

                resta = funcionResta(a,b);
                printf("El resultado de la resta es: %2.f\n\n",resta);

                if(b==0)
                {
                    printf("No se puede dividir por 0\n\n");
                }else
                {
                    division = funcionDivision(a,b);
                    printf("El resultado de la division es: %.2f\n\n",division);
                }

                multiplicacion = funcionMultiplicacion(a,b);
                printf("El resultado de la multiplicacion es: %.2f\n\n",multiplicacion);

                factorial = funcionFactorial(a);
                printf("El resultado del factorial es: %.2f\n\n\n\n",factorial);

                system("pause");

                break;


        }

    }while(opcion != 9);

    system("cls");
    printf("\nHASTA LUEGO!!!\n\n");





    return 0;
}



