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
    esValido = (int*)malloc(sizeof(int));

    *cantArg = argc;
    esValido = inputValido(argv,cantArg,numEntero,numFraccionario,origen,destino,v);
    if(*esValido==1){
        inputParteEntera = (int*)malloc(sizeof(int)*10);
        inputParteFraccionaria = (int*)malloc(sizeof(int)*5);
        if(*destino==10 && *origen==10){                //Muestro los resultados de las conversiones.
            printf("Conversion de Base 10 a Base 10\n");
            printf("El resultado es: %s,%s\n",numEntero,numFraccionario);
        }
        else {
            mapearLetras(numEntero,inputParteEntera);
            mapearLetras(numFraccionario,inputParteFraccionaria);
            free(numEntero);
            free(numFraccionario);
            resultadoEntero = (int*)malloc(sizeof(int)*41);
            resultadoFraccionario = (int*)malloc(sizeof(int)*6);
            if(*origen==10){
                printf("Conversion de Base 10 a Base %i\n",*destino);
                resultadoEntero = entero10aX(destino,inputParteEntera,v);
                resultadoFraccionario = fraccion10aX(destino,inputParteFraccionaria,v);
                numEntero = (char*)malloc(sizeof(char)*41);
                numFraccionario = (char*)malloc(sizeof(char)*6);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("El resultado es: %s,%s\n",numEntero,numFraccionario);
            }
            else if(*destino==10){
                printf("Conversion de Base %i a Base 10\n",*origen);
                resultadoEntero = enteroXa10(origen,inputParteEntera,v);
                resultadoFraccionario = fraccionXa10(origen,inputParteFraccionaria,v);
                numEntero = (char*)malloc(sizeof(char)*41);
                numFraccionario = (char*)malloc(sizeof(char)*6);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("El resultado es: %s,%s\n",numEntero,numFraccionario);
            }
            else {
                printf("Conversion de Base %i a Base %i con Base 10 como intermediario.\n",*origen,*destino);
                resultadoEntero = enteroXaY(origen,destino,inputParteEntera,v);
                resultadoFraccionario = fraccionXaY(origen,destino,inputParteFraccionaria,v);
                numEntero = (char*)malloc(sizeof(char)*41);
                numFraccionario = (char*)malloc(sizeof(char)*6);
                mapearDigitos(numEntero,resultadoEntero);
                mapearDigitos(numFraccionario,resultadoFraccionario);
                printf("El resultado es: %s,%s\n",numEntero,numFraccionario);
            }

            free(resultadoEntero);
            free(resultadoFraccionario);
        }

        free(inputParteEntera);
        free(inputParteFraccionaria);

    }
    else {
        printf("El formato ingresado no es valido.");
        exit(EXIT_FAILURE);
    }
    free(cantArg);
    free(numEntero);
    free(numFraccionario);
    free(origen);
    free(destino);
    free(v);
    exit(EXIT_SUCCESS);
    return 0;
}
/*printf("Test 1:\n");
    int *origen;
    origen= (int*)malloc(sizeof(int));
    *origen=2;
    int *n;
    n= (int*)malloc(sizeof(int)*11);
    n[0]= 1;
    n[1]= 1;
    n[2]= -1;
    int *mostrar;
    mostrar= (int*)malloc(sizeof(int));
    *mostrar=1;
    int* entero10= enteroXa10(origen,n,mostrar);
    int i0 =0;
    while(entero10[i0]!=(-1))
    {
        printf("%i",entero10[i0]);
        i0++;
    }
    printf("\n");
    int* fraccion10= fraccionXa10(origen,n,mostrar);
    i0 =0;
    while(fraccion10[i0]!=(-1))
    {
        printf("%i",fraccion10[i0]);
        i0++;
    }
    printf("\n");
    printf("Test 2:\n");
    int *destino = (int*)malloc(sizeof(int));
    *destino = 2;
    int *numero = (int*)malloc(sizeof(int)*5);
    int *mostro = (int*)malloc(sizeof(int));
    *mostro = 1;
    numero[0] = 2;
    numero[1] = 0;
    numero[2] = 0;
    numero[3] = 9;
    numero[4] = 9;
    int* base8 = entero10aX(destino,numero,mostro);
    int i =0;
    while(base8[i]!=(-1))
    {
        printf("%i",base8[i]);
        i++;
    }
    free(destino);
    free(base8);
    free(numero);
    free(mostro);
    printf("\n");
    printf("Test 3:\n");
    int * origen3= (int*)malloc(sizeof(int));
    *origen3= 16;
    int * destino3= (int*)malloc(sizeof(int));
    *destino3= 2;
    int * mostrar3= (int*)malloc(sizeof(int));
    *mostrar3= 1;
    int * n3= (int*)malloc(sizeof(int)*11);
    n3[0]=1;
    n3[1]=1;
    n3[2]=-1;
    int *entero= enteroXaY(origen3,destino3,n3,mostrar3);
    int i3 =0;
    while(entero[i3]!=(-1))
    {
        printf("%i",entero[i3]);
        i3++;
    }
    printf("\n");
    int* fraccion= fraccionXaY(origen3,destino3,n3,mostrar);
    i3 =0;
    while(fraccion[i3]!=(-1))
    {
        printf("%i",fraccion[i3]);
        i3++;
    }
    printf("\n");*/
