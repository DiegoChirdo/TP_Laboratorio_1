#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main()
{
    int A; /* Primera variable (n�mero) */
    int B; /* Segunda variable (n�mero) */
    int ban1 = 0;  /* Primera bandera (Auxiliar) Cuando el valor es 1, junto a la ban2, da paso a banFun, la cual realiza las operaciones */
    int ban2 = 0; /* Segunda bandera (Auxiliar) */
    int banFun = 0; /* Bandera de las funciones (auxiliar). Una vez �sta es activada, activa la variable banMenu la cual nos muestra el desarrollo de nuestras operaciones. */
    int banMenu = 0; /* Bandera auxiliar para el men�. Dependiendo su valor, mostrar� cierto men�, u otro */
    int rta; /* Es el entero a ingresar el cual nos permite movernos en el programa */
    while (rta!=5) /* Mientras la respuesta no sea 5, el programa no finalizar� */
    {
        rta=Menu(ban1, ban2, banMenu, A, B);
        switch(rta) /* Estos switch son los que nos permitir�n desplazarnos por el programa (con la variable rta) */
        {
            case 1:
                printf("Ingrese el primer n�mero (A): ");
                A=Numero();
                ban1=1; /* Cuando el n�mero es ingresado corr�ctamente, activa esta bandera auxiliar. */
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo n�mero (B): ");
                B=Numero();
                ban2=1; /* Una vez activados los dos, da paso a la bandera funci�n */
                system("cls");
                break;
            case 3:
                if (ban1==0 || ban2==0) /* Si el usuario ingresa 3 como opci�n, y no ingres� n�meros anteriormente, tira el siguiente mensaje */
                {
                    printf("No ha ingresado ning�n valor.");
                    system("pause");
                }
                else
                {
                    printf("Operaciones realizadas.");
                    system("pause");
                    banFun=1; /* Se informa que est� todo ok, y se da paso a las funciones */
                }
                system("cls");
                break;
            case 4:
                if (banFun==0)
                {
                    printf("No se ha realizado ninguna operaci�n.\n"); /* Si el usuario ingresa la opci�n 4, y no se ingres� ning�n n�mero tira �ste mensaje. Esto se verifica con banFun */
                    system("pause");
                }
                else
                {
                    banMenu=1; /* De lo contrario. Se activa el banMenu (que nos muestra todos los resultados) */
                }
                system("cls");
                break;
            case 5: /* Cierra el programa */
                system("cls");
                printf("\n---------------�Hasta la proxima!-----------\n");
                break;
            default: /* Si no es un n�mero del 1 al 5, tira error */
                system("cls");
                printf("\n----------ERROR: Ingrese una opcion valida--------");
                break;
        }
    }
    return 0;
}
