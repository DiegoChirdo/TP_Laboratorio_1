#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int Menu (int ban1, int ban2, int banMenu, int primerNumero, int segundoNumero)
{
    int opcion;
    int A;
    int B;

    printf("\n\n-------Calculadora de Diego Chirdo-------\n");
    if(ban1==0)
    {
        printf("\n\n1) Ingrese el primer numero. - (A)");
    }
    else
    {
        A=primerNumero;
        printf("\n2) Primer numero es: %d", A);
    }
    if (ban2==0)
    {
        printf("\n2) Ingrese el segundo numero. - (B)");
    }
    else
    {
        B=segundoNumero;
        printf("\n2) Segundo numero es: %d", B);
    }
    if (ban1 == 1 && ban2  == 1)
    {
        printf("\n3) Se haran las siguientes operaciones: \n");
        printf("\na) Suma (%d + %d)", A, B);
        printf("\nb) Resta (%d - %d)", A, B);
        printf("\nc) Division (%d / %d)", A, B);
        printf("\nd) Multiplicacion (%d * %d)", A, B);
        printf("\ne) Factoriales (%d! & %d!)", A, B);
    }
    else
    {
        printf("\n3) Se haran las siguientes operaciones: \n");
        printf("\na) Suma (A+B)");
        printf("\nb) Resta (A-B)");
        printf("\nc) División (A/B)");
        printf("\nd) Multiplicación (A*B)");
        printf("\ne) Factoriales (A! & B!)");
    }
    if (banMenu==0)
    {
        printf("\n\n4) Informe de resultados: ");
        printf("\na) El resultado de A+B es: RESPUESTA");
        printf("\nb) El resultado de A-B es: RESPUESTA");
        printf("\nc) El resultado de A/B es: RESPUESTA");
        printf("\nd) El resultado de A*B es: RESPUESTA");
        printf("\ne) El resultado de A! y B! es: RESPUESTA y RESPUESTA (respectivamente)");
    }
    if (banMenu==1)
    {
        printf("\n\n4) Informe de resultados: ");
        printf("\na) El resultado de %d+%d es: %d", A, B, suma(A, B));
        printf("\nb) El resultado de %d-%d es: %d", A, B, res(A, B));
        if (B==0)
        {
            printf("\nc) Es imposible dividir por 0");
        }

        else
        {
            printf("\nc) El resultado de %d/%d es: %d", A, B, division(A, B));
        }

        printf("\nd) El resultado de %d*%d es: %d", A, B, mul(A, B));

        if(A<0)
        {
            printf("\ne) No es posible calcular factorial de %d (numero negativo)", A);
        }
        else
        {
            printf("\ne) El factorial de %d es: %f ", A, factorial(A));
        }

        if(B<0)
        {
            printf("\ne)  No es posible calcular factorial de %d (numero negativo)", B);
        }
        else
        {
            printf("\ne)   El factorial de %d es: %f ", B, factorial(B));
        }
    }

    printf("\n\n5) Salir");
     printf("\n\nIngresa tu opcion: ");
     scanf("%d", &opcion);

        return opcion;


}

    int Numero()
    {
        int num;
        scanf("%d",&num);
        return num;
    }

    int suma (int primerNumero, int segundoNumero)
    {
        return primerNumero+segundoNumero;
    }

    int res (int primerNumero, int segundoNumero)
    {
        return primerNumero-segundoNumero;
    }

    int mul (int primerNumero, int segundoNumero)
    {
        return primerNumero*segundoNumero;
    }

    int division (int primerNumero, int segundoNumero)
    {
        return primerNumero/segundoNumero;
    }

    double factorial (double numerito)
    {
    double fac;

    fac=numerito;

    if(numerito==0 || numerito==1)
    {
        fac=1;
    }
    else
    {
        for(numerito-=1;numerito>0;numerito--)
        {
            fac*=numerito;
        }
    }

    return fac;
    }
