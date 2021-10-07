#include "cambioDeBase.h"
#include "leerInput.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *cantArg;
    int *esValido;
    int *origen;
    int *destino;
    int *v;
    int *inputParteEntera;
    int *inputParteFraccionaria;
    int *resultadoEntero;
    int *resultadoFraccionario;
    char *numEntero;
    char *numFraccionario;

    cantArg = (int*)malloc(sizeof(int));
    numEntero = (char*)malloc(sizeof(char)*10);
    numFraccionario = (char*)malloc(sizeof(char)*5);
    origen = (int*)malloc(sizeof(int));
    destino = (int*)malloc(sizeof(int));
    v = (int*)malloc(sizeof(int));

    *cantArg = argc;
    *origen = 0;
    *destino = 0;
    *v = 0;
    esValido = inputValido(argv,cantArg,numEntero,numFraccionario,origen,destino,v);
    if(*esValido==1)
    {
        inputParteEntera = (int*)malloc(sizeof(int)*10);
        inputParteFraccionaria = (int*)malloc(sizeof(int)*5);
        if(*destino==*origen)                 //Muestro los resultados de las conversiones.
        {
            printf("\nConversion de Base %i a Base %i\n\n",*origen,*destino);
            if(*v==1)
                printf("\nNo hace falta hacer ningun paso intermedio.\n\n");
            if(numFraccionario[0]=='\0')
                printf("\nEl resultado es: %s.0\n",numEntero);
            else
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
        }
        else
        {
            mapearLetras(numEntero,inputParteEntera);
            mapearLetras(numFraccionario,inputParteFraccionaria);
            free(numEntero);
            free(numFraccionario);
            numEntero = (char*)malloc(sizeof(char)*41);
            numFraccionario = (char*)malloc(sizeof(char)*6);
            if(*origen==10)
            {
                resultadoEntero = entero10aX(destino,inputParteEntera,v);
                resultadoFraccionario = fraccion10aX(destino,inputParteFraccionaria,v);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
            }
            else if(*destino==10)
            {
                resultadoEntero = enteroXa10(origen,inputParteEntera,v);
                resultadoFraccionario = fraccionXa10(origen,inputParteFraccionaria,v);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
            }
            else
            {
                printf("\nConversion de Base %i a Base %i con Base 10 como intermediario.\n\n",*origen,*destino);
                resultadoEntero = enteroXaY(origen,destino,inputParteEntera,v);
                resultadoFraccionario = fraccionXaY(origen,destino,inputParteFraccionaria,v);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
            }

            free(resultadoEntero);
            free(resultadoFraccionario);
        }

        free(inputParteEntera);
        free(inputParteFraccionaria);

    }
    else
    {
        printf("El formato ingresado no es valido.\n");
        exit(EXIT_FAILURE);
    }
    free(cantArg);
    free(numEntero);
    free(numFraccionario);
    free(origen);
    free(destino);
    free(v);
    free(esValido);
    exit(EXIT_SUCCESS);
    return 0;
}
