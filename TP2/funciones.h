#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int listarEdad(EPersona vec[], int cant);
int listarNombre(EPersona vec[], int cant);
void inicializarPersona(EPersona vec[], int tam);
int buscarLibre(EPersona vec[], int tam);
int agregarPersona(EPersona vec[], int cant);
int borrarPersona(EPersona vec[], int cant);


#endif // FUNCIONES_H_INCLUDED
