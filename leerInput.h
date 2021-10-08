#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* inputValido(char *argv[], int *cantArg, char *numEntero, char *numFraccionario, int *origen, int *destino, int *v);

void mapearDigitos(char *numero,int *numeroEntero);

void mapearLetras(char *numero,int *numeroEntero);

void mostrarAyuda();

int* esNumeroValido(char* numero, int* base);

