#include "cambioDeBase.h"
#include "leerInput.h"

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
    numEntero = (char*)malloc(sizeof(char)*11);
    numFraccionario = (char*)malloc(sizeof(char)*6);
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
        if(*destino==*origen)                 //Muestro los resultados de las conversiones.
        {
            printf("\nConversion de Base %i a Base %i\n\n",*origen,*destino);
            if(*v==1)
                printf("\nNo hace falta hacer ningun paso intermedio.\n\n");
            if(numFraccionario[0]=='\0' && numEntero[0]=='\0')
                printf("\nEl resultado es: 0.0\n");
            else if(numFraccionario[0]=='\0' && numEntero[0]!='\0')
                printf("\nEl resultado es: %s.0\n",numEntero);
            else if(numFraccionario[0]!='\0' && numEntero[0]=='\0')
                printf("\nEl resultado es: 0.%s\n",numFraccionario);
            else
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
        }
        else
        {
            inputParteEntera = (int*)malloc(sizeof(int)*11);
            inputParteFraccionaria = (int*)malloc(sizeof(int)*6);
            mapearLetras(numEntero,inputParteEntera);
            mapearLetras(numFraccionario,inputParteFraccionaria);
            free(numEntero);
            free(numFraccionario);
            numEntero = (char*)malloc(sizeof(char)*41);
            numFraccionario = (char*)malloc(sizeof(char)*6);
            if(*origen==10)
            {
                printf("\nConversion de Base 10 a Base %i\n\n",*destino);
                resultadoEntero = entero10aX(destino,inputParteEntera,v);
                resultadoFraccionario = fraccion10aX(destino,inputParteFraccionaria,v);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("\nEl resultado es: %s.%s\n",numEntero,numFraccionario);
            }
            else if(*destino==10)
            {
                printf("\nConversion de Base %i a Base 10\n",*origen);
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
            free(inputParteEntera);
            free(inputParteFraccionaria);
            free(resultadoEntero);
            free(resultadoFraccionario);
        }
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
