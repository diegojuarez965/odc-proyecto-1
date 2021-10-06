#include "leerInput.h"

#include "leerInput.h"
#include <stdio.h>
#include <stdlib.h>


int* caracterValido(char* palabra, int* indice);

int* esArgumento(char* palabra, char* argumento);

int* esNumeroValido(char* numero, int* base);

int* inputValido(char *argv[], int argc){
    int *numero;
    int *origen;
    int *destino;
    int *v;
    int *h;
    int *cantArg;
    int *i;
    int *j;
    int *aux;
    cantArg = (int*)malloc(sizeof(int));
    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));
    *cantArg = argc;
    if(*cantArg==3 || *cantArg==4 || *cantArg==5 || *cantArg==7 || *cantArg==9){ //Como minimo, debe ser: convert -n <num>, como maximo tendra los 9 parametros y despues si o si tendra 4, 5 o 7 parametros.
        *i = 1;
        *j = 0;
        while(*i<*cantArg){             //Primero me fijo si todos los caracteres ingresados son validos.
            while(argv[*i][*j]!='\0'){
                if(*caracterValido(argv[*i],j)==0){
                    printf("Algun caracter ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
                *j  = *j + 1;
            }
            *i = *i + 1;
        }
        *i = 1;
        *j = 0;
        origen = (int*)malloc(sizeof(int));    //A partir de aca me fijo si se respeta el formato del enunciado.
        destino = (int*)malloc(sizeof(int));
        v = (int*)malloc(sizeof(int));
        h = (int*)malloc(sizeof(int));
        aux = (int*)malloc(sizeof(int));
        numero = (int*)malloc(sizeof(int));     //N guardo su numero sino la posicion en el arreglo de argumentos.
        *origen = 0;
        *destino = 0;
        *v = 0;
        *h = 0;
        *numero = 0;
        while(*i<*cantArg){    //En cada argumento, me fijo si es de algun tipo del formato del enunciado, a lo que pregunto si se repitio.
            if(esArgumento(argv[*i],"-s")){
                if(*origen==0){
                    *aux = 10;
                    if((*i+1)<*cantArg && *esNumeroValido(argv[*i+1],aux)){
                        *origen = atoi(argv[*i+1]);
                        *i = *i + 1;
                    }
                    else {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-d")){
                if(*destino==0){
                    *aux = 10;
                    if((*i+1)<*cantArg && *esNumeroValido(argv[*i+1],aux)){
                        *origen = atoi(argv[*i+1]);
                        *i = *i + 1;
                    }
                    else {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-v")){
                if(*v==0)
                    *v = 1;
                else {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-h")){
                if(*h==0)
                    *h = 1;
                else {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-n")){
                if(*numero==0){
                    if((*i+1)<*cantArg){
                        *numero = *i;
                        *i = *i + 1;
                    }
                    else {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else {
                printf("El formato ingresado no es valido.");
                exit(EXIT_FAILURE);
            }
            *i = *i + 1;
        }
        *i = 0;
        if(*origen==0)
            *origen = 10;
        if(*destino==0)
            *destino = 10;
        //Falta pasar el numero su parte entera a un arreglo de enteros y su parte fraccionaria a un arreglo de enteros.
    }
    else{
        printf("La cantidad de parametros ingresada no es correcta.");
        exit(EXIT_FAILURE);
    }
}

int* mapearLetras(char *letra);

void mostrarAyuda();

int* caracterValido(char* palabra, int* indice){ //Se fija si el caracter indicado por un entero en un arreglo de caracteres es valido segun los posibles caracteres que se puedan recibir segun el formato del enunciado.
    return 1;
}
int* esArgumento(char* palabra, char* argumento){ //Se fija si la palabra ingresada es un argumento del tipo: -n, -s, -d, -v, -h.
    /*if(argv[*i][0]=='-' && argv[*i][1]!='\0'){
        if(argv[*i][1]=='n' || argv[*i][1]=='s' || argv[*i][1]=='d'){

        }
        else if(argv[*i][1]=='v' || argv[*i][1]=='h'){

        }
        if(argv[*i][2]=='\0'){

        }
    }*/
    return 1;
}

int* esNumeroValido(char* numero, int* base){ //Se fija si el numero en un arreglo de caracteres es valido en la base ingresada.
    return 1;
}
