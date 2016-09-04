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
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

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
                printf("El resultado de la suma es: %.2f\n\n",suma);
                system("pause");
                break;

            case 4:

                resta = funcionResta(a,b);
                printf("El resultado de la resta es: %2.f\n\n",resta);
                system("pause");
                break;

            case 5:

                division = funcionDivision(a,b);
                printf("El resultado de la division es: %.2f\n\n",division);
                system("pause");
                break;

            case 6:

                multiplicacion = funcionMultiplicacion(a,b);
                printf("El resultado de la multiplicacion es: %.2f\n\n",multiplicacion);
                system("pause");
                break;

            case 7:

                factorial = funcionFactorial(a);
                printf("El resultado del factorial es: %.2f\n\n",factorial);
                system("pause");
                break;

            case 8:

                suma = funcionSuma(a,b);
                printf("El resultado de la suma es: %.2f\n\n",suma);

                resta = funcionResta(a,b);
                printf("El resultado de la resta es: %2.f\n\n",resta);

                division = funcionDivision(a,b);
                printf("El resultado de la division es: %.2f\n\n",division);

                multiplicacion = funcionMultiplicacion(a,b);
                printf("El resultado de la multiplicacion es: %.2f\n\n",multiplicacion);

                factorial = funcionFactorial(a);
                printf("El resultado del factorial es: %.2f\n\n",factorial);

                system("pause");

                break;


        }

    }while(opcion != 9);





    return 0;
}



