#include <stdio.h>
#include <stdlib.h>

    //brief recibe un float y lo retorna
    float pedirOperando(void)
    {
        float x;
        printf("\nIngrese el numero: ");
        fflush(stdin);
        scanf("%f",&x);
        return x;
    }

    //brief realiza la suma de dos numeros
    //variable x toma el primer numero
    //variable y toma el segundo numero
    //return devuelve el resultado de la suma
    float funcionSuma(float x,float y)
    {
        return x + y;
    }

    //brief realiza la resta de dos numeros
    //variable x toma el primer numero
    //variable y toma el numero a restar
    //return devuelve el resultado de la resta
    float funcionResta(float x, float y)
    {
        return x - y;
    }

    //brief realiza la division entre dos numeros
    //variable x toma el dividendo
    //variable y toma el divisor
    //return devuelve el resultado de la division
    float funcionDivision(float x, float y)
    {
            return x / y;
    }

    //brief realiza la multiplicacion entre dos numeros
    //variable x toma el primer numero
    //variable y toma el segundo numero
    //return devuelve el resultado de la multiplicacion
    float funcionMultiplicacion(float x, float y)
    {
        return x * y;
    }

    //brief realiza el factorial de un numero
    //variable x toma el numero a factorear
    //return devuelve el resultado
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


