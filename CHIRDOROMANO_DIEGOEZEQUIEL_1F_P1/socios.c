#include <stdio.h>
#include <stdlib.h>
#include "socios.h"
#include "input.h"
#include <string.h>

int menuOpcion()
{
    int rta;

    printf("\tMENU DE OPCIONES\n");
    printf("1) ALTA\n");
    printf("2) MODIFICAR\n");
    printf("3) BAJA\n");
    printf("4) LISTAR\n");
    printf("5) LISTAR LIBROS\n");
    printf("6) LISTAR AUTORES\n");
    printf("7) PRESTAMOS\n");
    printf("8) LISTADOS ESPECIALES\n");
    printf("9) SALIR\n");
    fflush(stdin);
    scanf("%d", &rta);

    return rta;
}

int menuAutores()
{
    int rta;
    printf("1) ALTA DE AUTOR\n2) BAJA\n 3)MODIFICAR AUTOR\n4) SALIR\n;");
    fflush(stdin);
    scanf("%d",&rta);
    return rta;
}

int inicializarSocios(Socio vec[], int tam)
{
    int result=-1;
    int i;
    for(i=0; i<tam ; i++)
    {
        vec[i].isEmpty=0;
        result=0;
    }

    return result;
}

int altaSocio(Socio vec[],int cant)
{
    int codigo;
    int libre;
    char sexo;
    if(buscarLibre(vec, cant)==-1)
    {
        printf("\nNo hay lugares libres\n");
        system("pause");
        return 0;
    }
    libre=buscarLibre(vec, cant);
    codigo=generarCodigo(vec, cant);
    vec[libre].codigo=codigo;
    if(!getStringLetras("Ingrese un nombre: \n",vec[libre].nombre))
    {
        printf("Solo letras.\n");
        system("pause");
        return 0;
    }
    if(!getStringLetras("Ingrese un apellido: \n",vec[libre].apellido))
    {
        printf("Solo letras.\n");
        system("pause");
        return 0;
    }
    printf("Ingrese un sexo (m/f):\n");
    fflush(stdin);
    scanf("%c",&sexo);
    while(sexo!='f' && sexo!='m')
    {
        printf("Reingrese el sexo: \n");
        scanf("%c",&sexo);
    }
    vec[libre].sexo=sexo;
    if(!getStringTelefono("Ingrese un telefono: \n",vec[libre].telefono))
    {
        printf("Ingrese correctamente.\n");
        system("pause");
        return 0;
    }
    getString("Ingrese un email: \n", vec[libre].email);
    printf("Fecha de ingreso: \n");
    printf("Ingrese un dia: \n");
    scanf("%d",&vec[libre].fechaSocio.dia);
    while(vec[libre].fechaSocio.dia < 1 || vec[libre].fechaSocio.dia > 31)
    {
        printf("Ingrese un dia correctamente: \n");
        scanf("%d",&vec[libre].fechaSocio.dia);
    }
    fflush(stdin);
    printf("Ingrese un mes: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.mes);
    while(vec[libre].fechaSocio.mes < 1 || vec[libre].fechaSocio.mes > 12)
    {
        printf("Ingrese un mes correctamente: \n");
        scanf("%d",&vec[libre].fechaSocio.mes);
    }
    printf("Ingrese un anio: \n");
    fflush(stdin);
    scanf("%d",&vec[libre].fechaSocio.anio);
    vec[libre].isEmpty=1;
    printf("HECHO!!!\n");
    return 0;
}

int modificarSocio(Socio vec[],int cant)
{
    int codigoModificar;
    int indexBuscar;
    int campoModificar;

    printf("Ingrese el codigo de socio: \n");
    scanf("%d", &codigoModificar);
    indexBuscar=buscarSocio(vec, cant, codigoModificar);

    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
        return 0;
    }

    while(campoModificar!=6)
    {

        printf("Ingrese el campo a modificar: \n");
        printf("1) Apellido\n2) Nombre\n3) Sexo\n4) Telefono\n5) eMail\n6) Salir\n");
        scanf("%d", &campoModificar);
        switch(campoModificar)
        {
        case 1:
            if(!getStringLetras("Ingrese nuevo apellido: \n",vec[indexBuscar].apellido))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
                break;
            }
            break;
        case 2:
            if(!getStringLetras("Ingrese nuevo nombre: \n",vec[indexBuscar].nombre))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
                break;
            }
            break;
        case 3:
            vec[indexBuscar].sexo=pedirSexo();
            break;
        case 4:
            if(!getStringTelefono("Ingrese nuevo telefono: \n",vec[indexBuscar].telefono))
            {
                printf("Ingrese correctamente.\n");
                system("pause");
                return 0;
                break;
            }
            break;
        case 5:
            getString("Ingrese nuevo correo: \n",vec[indexBuscar].email);
            break;
        }

    }
    return 0;
}

int bajaSocio(Socio vec[],int cant)
{
    int codigoBaja;
    int indexBuscar;
    if(vec[0].isEmpty==0)
    {
        printf("TODAVIA NO SE HAN INGRESADO DATOS.\n");
        system("pause");
        return 0;
    }
    printf("Ingrese codigo de socio para la baja: \n");
    scanf("%d", &codigoBaja);
    indexBuscar=buscarSocio(vec, cant, codigoBaja);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
        return 0;
    }
    vec[indexBuscar].isEmpty=0;
    printf("Hecho!!!\n");
    return 0;
}

int buscarLibre(Socio vec[], int tam)
{
    int indexLibre=-1;
    int i;
    for(i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

int generarCodigo(Socio vec[], int cant)
{
    int indexLibre=buscarLibre(vec, cant);
    int codigoAnterior;
    int codigo;

    if(indexLibre==0)
    {
        codigo=1000;
    }else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }

    return codigo;

}


int buscarSocio(Socio vec[], int cant, int codigoBuscar){

    int indexSocio=-1;
    int i;
    for(i=0; i<cant ; i++)
    {
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexSocio=i;
            break;
        }
    }

    return indexSocio;
}

void listarSocios(Socio vec[], int cant)
{
    int i;

    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  APELLIDO  -  NOMBRE  -  SEXO  -  TELEFONO  -  EMAIL\n");
            printf("%d  -  %s   -  %s   -  %c  -  %s  -  %s\n\n",vec[i].codigo,vec[i].apellido,vec[i].nombre,vec[i].sexo,vec[i].telefono,vec[i].email);
        }
    }
}

void listarLibros(Libro vec[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1 && vec[i].codigo!=0)
        {
            printf("CODIGO  -  LIBRO  -  COD. AUTOR\n");
            printf("%d  -  %s   -  %d\n",vec[i].codigo,vec[i].titulo,vec[i].codigoAutor.codigo);
        }
    }
}

void listarAutores(Autor vec[],int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  APELLIDO  -  NOMBRE\n");
            printf("%d  -  %s   -  %s\n",vec[i].codigo,vec[i].apellido,vec[i].nombre);
        }
    }
}

int altaPrestamos(Prestamos vec[],Libro array[], Socio arr[], int cant)
{
    int indexLibre;
    int busquedaLibro;
    int busquedaSocio;
    int codigo;
    int codigoLibro;
    int codigoSocio;

    indexLibre=buscarLibrePrestamo(vec,cant);
    codigo=generarCodigoPrestamo(vec,cant);
    printf("INGRESE UN CODIGO DE LIBRO: \n");
    scanf("%d",&codigoLibro);
    busquedaLibro=codigoLibro;
    if(buscarCodigoLibro(array,cant,busquedaLibro)==-1)
    {
        printf("NO SE ENCONTRO.\n");
        system("pause");
        return 0;
    }
    printf("INGRESE UN CODIGO DE SOCIO: \n");
    scanf("%d",&codigoSocio);
    busquedaSocio=codigoSocio;
    if(buscarCodigoSocio(arr,cant,busquedaSocio)==-1)
    {
        printf("NO SE ENCONTRO. \n");
        system("pause");
        return 0;
    }
    printf("Fecha de prestamo: \n");
    printf("Ingrese un dia: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.dia);
    while(vec[indexLibre].fechaPrestamo.dia < 1 || vec[indexLibre].fechaPrestamo.dia > 31)
    {
        printf("Ingrese dia correctamente: \n");
        scanf("%d",&vec[indexLibre].fechaPrestamo.dia);
    }
    printf("Ingrese un mes: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.mes);
    while(vec[indexLibre].fechaPrestamo.mes < 1 || vec[indexLibre].fechaPrestamo.mes > 12)
    {
        printf("Ingrese mes correctamente: \n");
        scanf("%d", &vec[indexLibre].fechaPrestamo.mes);
    }
    printf("Ingrese un anio: \n");
    fflush(stdin);
    scanf("%d",&vec[indexLibre].fechaPrestamo.anio);
    vec[indexLibre].codigo=codigo;
    strcpy(vec[indexLibre].codigoSocio.nombre,arr[buscarCodigoSocio(arr,cant,busquedaSocio)].nombre);
    strcpy(vec[indexLibre].codigoSocio.apellido,arr[buscarCodigoSocio(arr,cant,busquedaSocio)].apellido);
    vec[indexLibre].codigoLibro.codigo=busquedaLibro;
    strcpy(vec[indexLibre].codigoLibro.titulo,array[buscarCodigoSocio(arr,cant,busquedaSocio)].titulo);
    vec[indexLibre].codigoSocio.codigo=busquedaSocio;
    vec[indexLibre].isEmpty=1;
    arr[buscarCodigoSocio(arr,cant,busquedaSocio)].contador++;
    printf("HECHO!!!\n");
    return 0;
}

void mostrarPrestamos(Prestamos vec[], int cant)
{

int i;

    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            printf("CODIGO  -  COD. LIBRO  -  COD. SOCIO  -  Fecha de prestamo\n");
            printf("%d   -  %d   -  %d  -  %d/%d/%d\n",vec[i].codigo,vec[i].codigoLibro.codigo,vec[i].codigoSocio.codigo,vec[i].fechaPrestamo.dia,vec[i].fechaPrestamo.mes,vec[i].fechaPrestamo.anio);
        }
    }

}


int generarCodigoPrestamo(Prestamos vec[],int cant)
{
    int indexLibre;
    int codigoAnterior;
    int codigo;

    indexLibre=buscarLibrePrestamo(vec,cant);
    if(indexLibre==0)
    {
        codigo=1000;
    }
    else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }
    return codigo;
}

int buscarLibrePrestamo(Prestamos vec[], int tam)
{
    int indexLibre=-1;
    int i;
    for(i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

 void inicializarPrestamo (Prestamos vec[], int cant)
{
    int i;
    for(i=0; i<cant ; i++)
    {
        vec[i].isEmpty=0;
    }
}

int buscarCodigoLibro(Libro vec[], int cant, int codigoBuscar)
{
    int indexLibro=-1;
    int i;
    for(i=0; i<cant ; i++){
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexLibro=i;
            break;
        }
    }

    return indexLibro;
}

int buscarCodigoSocio(Socio vec[], int cant, int codigoBuscar)
{
    int indexSocio=-1;
    int i;
    for(i=0; i<cant ; i++){
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexSocio=i;
            break;
        }
    }

    return indexSocio;
}

int altaAutor(Autor vec[],int cant)
{
    int codigo;
    int libre;
    libre=buscarLibreAutor(vec, cant);
    if(libre==-1)
    {
        printf("NO HAY MAS LUGAR.\n");
        system("pause");
        return 0;
    }
    codigo=generarCodigoAutor(vec,cant);
    vec[libre].codigo=codigo;
    if(!getStringLetras("Ingrese nombre: \n",vec[libre].nombre))
    {
        printf("Solo letras.\n");
        system("pause");
        return 0;
    }
    if(!getStringLetras("Ingrese apellido: \n",vec[libre].apellido))
    {
        printf("Solo letras.\n");
        system("pause");
        return 0;
    }
    vec[libre].isEmpty=1;
    printf("HECHO!!!\n");
    return 0;
}

int generarCodigoAutor(Autor vec[], int cant)
{
    int indexLibre=buscarLibreAutor(vec, cant);
    int codigoAnterior;
    int codigo;

    if(indexLibre==0)
    {
        codigo=1000;
    }else
    {
        codigoAnterior=vec[indexLibre-1].codigo;
        codigo=codigoAnterior+1;
    }

    return codigo;

}

int buscarLibreAutor(Autor vec[], int tam)
{
    int indexLibre=-1;
    int i;
    for(i=0 ; i<tam ; i++){
        if(vec[i].isEmpty==0)
        {
            indexLibre=i;
            break;
        }
    }
    return indexLibre;
}

int bajaAutor(Autor vec[],int cant)
{
    int codigoBaja;
    int indexBuscar;

    printf("Ingrese codigo de autor para la baja: \n");
    scanf("%d", &codigoBaja);
    indexBuscar=buscarAutor(vec, cant, codigoBaja);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
        return 0;
    }
    vec[indexBuscar].isEmpty=0;
    printf("Hecho!!!\n");
    return 0;
}

int buscarAutor(Autor vec[], int cant, int codigoBuscar){

    int indexAutor=-1;
    int i;
    for(i=0; i<cant ; i++)
    {
        if(vec[i].codigo==codigoBuscar && vec[i].isEmpty==1)
        {
            indexAutor=i;
            break;
        }
    }

    return indexAutor;
}

int modificarAutor(Autor vec[],int cant)
{
    int codigoModificar;
    int indexBuscar;
    int campoModificar;

    printf("Ingrese el codigo de autor: \n");
    scanf("%d", &codigoModificar);
    indexBuscar=buscarAutor(vec, cant, codigoModificar);

    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
        return 0;
    }

    while(campoModificar!=3)
    {

        printf("Ingrese el campo a modificar: \n");
        printf("1) Apellido\n2) Nombre\n3) Salir\n");
        scanf("%d", &campoModificar);
        switch(campoModificar)
        {
        case 1:
            if(!getStringLetras("Ingrese nuevo apellido: \n",vec[indexBuscar].apellido))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
            }
            break;
        case 2:
            if(!getStringLetras("Ingrese nuevo nombre: \n",vec[indexBuscar].nombre))
            {
                printf("Solo letras.\n");
                system("pause");
                return 0;
            }
            break;
        }

    }
    return 0;
}

int menuListado()
{
    int rta;
    printf("\n\n1) TOTAL GENERAL Y PROMEDIO DIARIO DE PRESTAMOS\n2) CANTIDAD DE DIAS QUE NO SUPERAN EL PROMEDIO DE PRESTAMOS DIARIOS\n3) SOCIOS DE UN LIBRO DETERMINADO\n4) LIBROS DE X SOCIO\n5) LIBRO MENOS SOLICITADO\n6) SOCIO QUE REALIZO MAS PRESTAMOS\n7) LIBROS SOLICITADOS EN UNA FECHA DETERMINADA\n8) SOCIOS QUE REALIZARON PRESTAMO EN DETERMINADA FECHA\n9) LISTADO LIBROS ORDENADOS POR TITULO\n10) SOCIOS ORDENADOS POR APELLIDO\n11) SALIR\n\n");
    fflush(stdin);
    scanf("%d",&rta);
    return rta;
}

void mostrarLibrosPrestados(Libro array[],Prestamos vec[], int cant)
{
    int codigo;
    int i;
    int resultadoBusqueda;
    printf("INGRESE CODIGO DE LIBRO: \n");
    scanf("%d",&codigo);
    resultadoBusqueda=buscarCodigoLibro(array,cant,codigo);
    if(resultadoBusqueda==-1)
    {
        printf("NO SE ENCONTRO.\n");
    }
    for(i=0;i<cant;i++)
    {
        if(vec[i].codigoLibro.codigo == resultadoBusqueda)
        {
            printf("CODIGO PRESTAMO - CODIGO SOCIO\n");
            printf("%d  -  %d",vec[i].codigo,vec[i].codigoSocio.codigo);
        }
    }
}

int totalGeneral(Prestamos vec[], int cant)
{
    int i;
    int acumulador = 0;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            acumulador=acumulador+1;
        }
    }
    return acumulador;
}

int promedioDiario(Prestamos vec[], int cant)
{
    int i;
    int acumulador = 0;
    int promedio;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            acumulador=acumulador+1;
        }
    }
    promedio=acumulador/7;
    return promedio;
}

int noSuperaPromedioDiario(Prestamos vec[], int cant)
{
    int i;
    int j;
    int acumulador = 0;
    int contador = 0;
    int auxiliar = 0;
    int promedio;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty==1)
        {
            acumulador=acumulador+1;
        }
    }
    promedio=acumulador/7;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(vec[i].isEmpty == 1 && vec[j].isEmpty == 1)
            {
                    if(vec[i].fechaPrestamo.dia && vec[i].fechaPrestamo.mes && vec[i].fechaPrestamo.anio == vec[j].fechaPrestamo.dia && vec[j].fechaPrestamo.mes && vec[j].fechaPrestamo.anio)
                {
                    contador++;
                }
            }
        }
    }
    if(contador<promedio)
    {
        auxiliar++;
    }
    return auxiliar;
}

int sociosPrestamoDeterminado(Libro array[], Prestamos vec[], int cant)
{
    int codigo;
    int i;
    int resultadoBusqueda;
    printf("INGRESE CODIGO DE LIBRO: \n");
    scanf("%d",&codigo);
    resultadoBusqueda=buscarCodigoLibro(array,cant,codigo);
    if(resultadoBusqueda==-1)
    {
        printf("NO SE ENCONTRO.\n");
        system("pause");
        return 0;
    }
    system("cls");
    printf("SOCIOS DEL LIBRO INGRESADO: \n");
    printf("CODIGO  -  NOMBRE  - APELLIDO\n");
    for(i=0;i<cant;i++)
    {
        if(vec[i].codigoLibro.codigo == codigo && vec[i].isEmpty == 1)
        {
            printf("%d  -  %s  -  %s\n",vec[i].codigoSocio.codigo, vec[i].codigoSocio.nombre, vec[i].codigoSocio.apellido);
        }
    }
    return 0;
}

int libroPrestamoDeterminado(Socio arr[], Prestamos vec[], int cant)
{
    int codigo;
    int indexBuscar;
    int i;
    printf("INGRESE UN CODIGO DE SOCIO: \n");
    scanf("%d",&codigo);
    indexBuscar=buscarSocio(arr, cant, codigo);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo.\n");
        system("pause");
        return 0;
    }
    printf("LIBROS SOLICITADOS POR EL SOCIO: \n");
    for(i=0;i<cant;i++)
    {
        if(vec[i].codigoSocio.codigo == codigo && vec[i].isEmpty == 1)
        {
            printf("%d  -  %s\n", vec[i].codigoLibro.codigo, vec[i].codigoLibro.titulo);
        }
    }
    return 0;
}

/*int libroMenosSolicitado(Prestamos vec[], int cant)
{
    int i, j;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(vec[i].codigoLibro.codigo == vec[j].codigoLibro.codigo && vec[j].isEmpty == 1);
        }
    }

    return 0;
}*/

int socioMasPrestamos(Socio vec[], int cant)
{
    int i,j,aux;
    char auxStringApellido[51];
    char auxStringNombre[51];
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(vec[i].contador>vec[j].contador && vec[i].isEmpty == 1 && vec[j].isEmpty == 1)
            {
                aux=vec[i].codigo;
                strcpy(auxStringApellido,vec[i].apellido);
                strcpy(auxStringNombre,vec[i].nombre);
                strcpy(vec[i].apellido,vec[j].apellido);
                strcpy(vec[i].nombre,vec[j].nombre);
                strcpy(vec[j].apellido,auxStringApellido);
                strcpy(vec[j].nombre,auxStringNombre);
                vec[j].codigo=aux;
            }
        }
    }
    printf("SOCIO CODIGO: %d  -  DE NOMBRE Y APELLIDO %s %s\n", vec[0].codigo, vec[0].nombre, vec[0].apellido);
    return 0;
}

int prestamoMenor(Prestamos vec[],vecesPrestado index[],int cant)
{
    int i,j, aux;
    char auxString[51];
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(index[i].contador<index[j].contador)
            {
                aux=index[i].index;
                strcpy(auxString, index[i].titulo);
                index[i].index=index[j].index;
                strcpy(index[i].titulo,index[j].titulo);
                index[j].index=aux;
                strcpy(index[j].titulo,auxString);
            }
        }
    }
    printf("LIBRO MENOR PRESTADO CON %d veces: \n",index[0].contador);
    printf("%d  -  %s\n\n", index[0].index, index[0].titulo);
    for(i=0;i<cant;i++)
    {
        index[i].contador=0;
    }
    return 0;
}

int recorrerPrestamos (Prestamos vec[], vecesPrestado index[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(vec[i].isEmpty == 1)
        {
            index[i].index=vec[i].codigoLibro.codigo;
            strcpy(index[i].titulo,vec[i].codigoLibro.titulo);
            index[i].isEmpty = 1;
            index[i].contador++;
        }
    }
    return 0;
}

int sociosFechaDeterminada(Prestamos vec[], Socio arr[], int cant)
{
    int codigo;
    int i;
    int indexBuscar;
    printf("INGRESE CODIGO DE SOCIO: \n");
    scanf("%d",&codigo);
    indexBuscar=buscarSocio(arr, cant, codigo);
    if(indexBuscar==-1)
    {
        printf("No existe ese codigo de socio.\n");
        system("pause");
        return 0;
    }
    printf("PRESTAMOS SOLICITADOS POR EL SOCIO NUMERO %d\n", codigo);
    printf("CODIGO LIBRO  -  TITULO\n");
    for(i=0;i<cant;i++)
    {
        if(vec[i].codigoSocio.codigo == codigo && vec[i].isEmpty == 1)
        {
            printf("%d  -  %s\n",vec[i].codigoLibro.codigo, vec[i].codigoLibro.titulo);
        }
    }
    return 0;
}

void librosPorTitulo(Libro array[], int cant)
{
    int i, j;
    char auxiliar[50];
    int auxiliarLibro;
    int auxiliarCodigo;
    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(array[i].titulo,array[j].titulo)==1)
            {
                strcpy(auxiliar,array[i].titulo);
                auxiliarLibro=array[i].codigo;
                auxiliarCodigo=array[i].codigoAutor.codigo;
                array[i].isEmpty=1;
                strcpy(array[i].titulo,array[j].titulo);
                array[i].codigo=array[j].codigo;
                array[i].codigoAutor.codigo=array[j].codigoAutor.codigo;
                strcpy(array[j].titulo,auxiliar);
                array[j].codigo=auxiliarLibro;
                array[j].codigoAutor.codigo=auxiliarCodigo;
                array[j].isEmpty=1;

            }
        }
    }
    printf("CODIGO  -  TITULO\n");
    for(i=0;i<cant;i++)
    {
        if(array[i].codigo != 0)
        {
            printf("%d  -  %s\n",array[i].codigo,array[i].titulo);
        }
    }
}

void sociosPorApellido(Socio arr[], int cant)
{
    int i, j;
    int libre;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if(strcmp(arr[i].apellido,arr[j].apellido)==1)
            {
                libre = buscarLibre(arr, cant);
                arr[libre] = arr[i];
                arr[i] = arr[j];
                arr[j] = arr[libre];
                arr[libre].isEmpty = -1;
            }
        }
    }
    printf("CODIGO  -  APELLIDO\n");
    for(i=0;i<cant;i++)
    {
        if(arr[i].codigo!=0)
        {
            printf("%d  -  %s\n", arr[i].codigo, arr[i].apellido);
        }
    }
}

int prestamoFechaDeterminada(Prestamos vec[], int cant)
{
    int dia;
    int mes;
    int anio;
    int i;

    printf("INGRESE UN DIA: \n");
    scanf("%d", &dia);
    while(dia<1 || dia>31)
    {
        printf("INGRESE CORRECTAMENTE: \n");
        scanf("%d",&dia);
    }
    printf("INGRESE UN MES: \n");
    scanf("%d", &mes);
    while(mes<1 || mes>12)
    {
        printf("INGRESE MES CORRECTAMENTE: \n");
        scanf("%d",&mes);
    }
    printf("INGRESE UN ANIO: \n");
    scanf("%d",&anio);
    while(anio<1900 || anio > 2020)
    {
        printf("INGRESE ANIO CORRECTAMENTE: \n");
        scanf("%d",&anio);
    }
    printf("PRESTAMOS DE FECHA SOLICITADA: \n");
    printf("CODIGO SOCIO  -  CODIGO LIBRO  -  TITULO\n\n");
    for(i=0;i<cant;i++)
    {
        if(vec[i].fechaPrestamo.dia == dia && vec[i].fechaPrestamo.mes == mes && vec[i].fechaPrestamo.anio == anio && vec[i].isEmpty == 1)
        {
            printf("%d  -  %d  -  %s\n",vec[i].codigoSocio.codigo, vec[i].codigoLibro.codigo, vec[i].codigoLibro.titulo);
        }
    }
    return 0;
}
