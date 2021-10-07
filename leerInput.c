#include "leerInput.h"
#include "leerInput.h"
#include <stdio.h>
#include <stdlib.h>

void mapearLetras(char *numero,int *numeroEntero);

void mostrarAyuda();

int* caracterValido(char* palabra, int* indice);

int* esNumeroValido(char* numero, int* base);

int* esArgumento(char* palabra, char* argumento);

int* inputValido(char *argv[], int argc)
{
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
    if(*cantArg==3 || *cantArg==4 || *cantArg==5 || *cantArg==7 || *cantArg==9)  //Como minimo, debe ser: convert -n <num>, como maximo tendra los 9 parametros y despues si o si tendra 4, 5 o 7 parametros.
    {
        *i = 1;
        *j = 0;
        while(*i<*cantArg)              //Primero me fijo si todos los caracteres ingresados son validos.
        {
            while(argv[*i][*j]!='\0')
            {
                if(*caracterValido(argv[*i],j)==0)
                {
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
        while(*i<*cantArg)     //En cada argumento, me fijo si es de algun tipo del formato del enunciado, a lo que pregunto si se repitio.
        {
            if(esArgumento(argv[*i],"-s"))
            {
                if(*origen==0)
                {
                    *aux = 10;
                    if((*i+1)<*cantArg && *esNumeroValido(argv[*i+1],aux))
                    {
                        *origen = atoi(argv[*i+1]);
                        *i = *i + 1;
                    }
                    else
                    {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-d"))
            {
                if(*destino==0)
                {
                    *aux = 10;
                    if((*i+1)<*cantArg && *esNumeroValido(argv[*i+1],aux))
                    {
                        *origen = atoi(argv[*i+1]);
                        *i = *i + 1;
                    }
                    else
                    {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-v"))
            {
                if(*v==0)
                    *v = 1;
                else
                {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-h"))
            {
                if(*h==0)
                    *h = 1;
                else
                {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else if(esArgumento(argv[*i],"-n"))
            {
                if(*numero==0)
                {
                    if((*i+1)<*cantArg)
                    {
                        *numero = *i;
                        *i = *i + 1;
                    }
                    else
                    {
                        printf("El formato ingresado no es valido.");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    printf("El formato ingresado no es valido.");
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
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
    else
    {
        printf("La cantidad de parametros ingresada no es correcta.");
        exit(EXIT_FAILURE);
    }
}

//Mapea un entero expresado con digitos a un entero expresado con caracteres.
void mapearDigitos(char *numero,int *numeroEntero)
{
    int *i;
    i= malloc(sizeof(int));
    *i=0;
    while(numeroEntero[*i]!=-1)
    {
        switch(numeroEntero[*i])
        {
        case 0:
        {
            numero[*i]='0';
            break;
        }
        case 1:
        {
            numero[*i]='1';
            break;
        }
        case 2:
        {
            numero[*i]='2';
            break;
        }
        case 3:
        {
            numero[*i]='3';
            break;
        }
        case 4:
        {
            numero[*i]='4';
            break;
        }
        case 5:
        {
            numero[*i]='5';
            break;
        }
        case 6:
        {
            numero[*i]='6';
            break;
        }
        case 7:
        {
            numero[*i]='7';
            break;
        }
        case 8:
        {
            numero[*i]='8';
            break;
        }
        case 9:
        {
            numero[*i]='9';
            break;
        }
        case 10:
        {
            numero[*i]='A';
            break;
        }
        case 11:
        {
            numero[*i]='B';
            break;
        }
        case 12:
        {
            numero[*i]='C';
            break;
        }
        case 13:
        {
            numero[*i]='D';
            break;
        }
        case 14:
        {
            numero[*i]='E';
            break;
        }
        case 15:
        {
            numero[*i]='F';
            break;
        }
        }
        *i=*i+1;
    }
    numero[*i]='\0';
    free(i);
}

//Mapea un entero expresado con caracteres a un entero expresado con dígitos finalizado en -1.
void mapearLetras(char *numero,int *numeroEntero)
{
    int *i;
    i= malloc(sizeof(int));
    *i=0;
    while(numero[*i]!='\0')
    {
        switch(numero[*i])
        {
        case '0':
        {
            numeroEntero[*i]=0;
            break;
        }
        case '1':
        {
            numeroEntero[*i]=1;
            break;
        }
        case '2':
        {
            numeroEntero[*i]=2;
            break;
        }
        case '3':
        {
            numeroEntero[*i]=3;
            break;
        }
        case '4':
        {
            numeroEntero[*i]=4;
            break;
        }
        case '5':
        {
            numeroEntero[*i]=5;
            break;
        }
        case '6':
        {
            numeroEntero[*i]=6;
            break;
        }
        case '7':
        {
            numeroEntero[*i]=7;
            break;
        }
        case '8':
        {
            numeroEntero[*i]=8;
            break;
        }
        case '9':
        {
            numeroEntero[*i]=9;
            break;
        }
        case 'A':
        case 'a':
        {
            numeroEntero[*i]=10;
            break;
        }
        case 'B':
        case 'b':
        {
            numeroEntero[*i]=11;
            break;
        }
        case 'C':
        case 'c':
        {
            numeroEntero[*i]=12;
            break;
        }
        case 'D':
        case 'd':
        {
            numeroEntero[*i]=13;
            break;
        }
        case 'E':
        case 'e':
        {
            numeroEntero[*i]=14;
            break;
        }
        case 'F':
        case 'f':
        {
            numeroEntero[*i]=15;
            break;
        }
        }
        *i=*i+1;
    }
    numeroEntero[*i]=-1;
    free(i);
}

void mostrarAyuda()
{
    printf("Parámetros de invocación:\n");
    printf("-n <numero>: admite solo positivos, con la parte entera hasta 10 digitos y la fraccionaria hasta 5 digitos\n");
    printf("-s <base origen> : admite 2 a 16\n");
    printf("-d <base destino> : admite 2 a 16\n");
    printf("-v : muestra computos intermedios\n");
    printf("-h : muestra este mensaje\n");
}

//Se fija si el caracter indicado por un entero en un arreglo de caracteres es valido segun los posibles caracteres que se puedan recibir segun el formato del enunciado.
int* caracterValido(char* palabra, int* indice)
{
    int *toReturn;
    toReturn= malloc(sizeof(int));
    *toReturn=0;
    switch(palabra[*indice])
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'a':
    case 'B':
    case 'b':
    case 'C':
    case 'c':
    case 'D':
    case 'd':
    case 'E':
    case 'e':
    case 'F':
    case 'f':
    case 'n':
    case 's':
    case 'v':
    case 'h':
    case '-':
    case '.':
    case '\0':
    {
        *toReturn=1;
        break;
    }
    }
    return toReturn;
}

//Se fija si el numero en un arreglo de caracteres es valido en la base ingresada.
int* esNumeroValido(char* numero, int* base)
{
    int *toReturn;
    toReturn= malloc(sizeof(int));
    *toReturn=0;
    int *i;
    i= malloc(sizeof(int));
    *i=0;
    int *fin;
    fin= malloc(sizeof(int));
    *fin=0;
    switch(*base)
    {
    case 2:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 3:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 4:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 5:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 6:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 7:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 8:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 9:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 10:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 11:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 12:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 13:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 14:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'D':
            case 'd':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 15:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'D':
            case 'd':
            case 'E':
            case 'e':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    case 16:
    {
        while(numero[*i]!='\0' && *fin==0)
        {
            switch(numero[*i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'A':
            case 'a':
            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'D':
            case 'd':
            case 'E':
            case 'e':
            case 'F':
            case 'f':
            {
                *toReturn=1;
                break;
            }
            default:
            {
                *toReturn=0;
                *fin=1;
                break;
            }
            }
            *i=*i+1;
        }
        break;
    }
    }
    free(i);
    free(fin);
    return toReturn;
}

//Se fija si la palabra ingresada es un argumento del tipo: -n, -s, -d, -v, -h.
int* esArgumento(char* palabra, char* argumento)
{
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

