#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int A; /* Primera variable */
    int B; /* Segunda variable */
    int ban1 = 0;  /* Primera bandera (Auxiliar) */
    int ban2 = 0; /* Segunda bandera (Auxiliar) */
    int banFun = 0; /* Bandera de las funciones (auxiliar) */
    int banMenu = 0; /* Bandera auxiliar para el menú */
    int rta;
    while (rta!=5)
    {
        rta=Menu(ban1, ban2, banMenu, A, B);
        switch(rta)
        {
            case 1:
                printf("Ingrese el primer número (A): ");
                A=Numero();
                ban1=1;
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo número (B): ");
                B=Numero();
                ban2=1;
                system("cls");
                break;
            case 3:
                if (ban1==0 || ban2==0)
                {
                    printf("No ha ingresado ningún valor.");
                    system("pause");
                }
                else
                {
                    printf("Operaciones realizadas.");
                    system("pause");
                    banFun=1;
                }
                system("cls");
                break;
            case 4:
                if (banFun==0)
                {
                    printf("No se ha realizado ninguna operación.");
                    system("pause");
                }
                else
                {
                    banMenu=1;
                }
                system("cls");
                break;
            case 5:
                system("cls");
                printf("\n---------------¡Hasta la proxima!-----------\n");
                break;
            default:
                system("cls");
                printf("\n----------ERROR: Ingrese una opcion valida--------");
                break;
        }
    }
    return 0;
}
