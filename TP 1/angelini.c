#include <stdio.h>
#include <stdlib.h>


    float pedirOperando(void)
    {
        float x;
        printf("Ingrese el numero: ");
        fflush(stdin);
        scanf("%f",&x);
        return x;
    }

    float funcionSuma(float x,float y)
    {
        return x + y;
    }

    float funcionResta(float x, float y)
    {
        return x - y;
    }


    float funcionDivision(float x, float y)
    {
        if(y==0)
        {
            printf("No se puede dividir por 0\n\n");
            system("pause");
        }else
        {
            return x / y;
        }
    }

    float funcionMultiplicacion(float x, float y)
    {
        return x * y;
    }

    float funcionFactorial(float x)
    {
        int i;
        float y=1;

        for(i=1 ; i<=x ; i++)
        {
            y = y * i;
        }
        return y;
    }


