#include "cambioDeBase.h"

int * enteroXa10 (int * origen,int * n,int * cantDig,int * mostrar)
{
    int * ultDig= (int *)malloc(sizeof(int));
    int * suma= (int *)malloc(sizeof(int));
    *ultDig=*cantDig-1;
    *suma=0;
    for(int i=*ultDig,exp=0; i>=0; i--,exp++)
    {
        *suma=*suma+(n[i]*pow(*origen,exp));
        if(*suma>=10000000000)
            return NULL; // La suma excede los 10 dígitos(¿Cortar iteración o devolver nada?)
        if(*mostrar==1)
        {
            printf("Operacion realizada: %lf + %d * %d ^ %d\n",*suma-(n[i]*pow(*origen,exp)),n[i],*origen,exp);
            printf("Se obtuvo parcialmente %d\n",*suma);
        }
    }
    free(ultDig);
    return suma;
}

int * entero10aX(int *destino, int *n, int *cantDig, int *mostrar){
    int *resultadoTentativo = (int*)malloc(sizeof(int)*1000);
    int *resultadoFinal;
    int *numero = (int*)malloc(sizeof(int));
    int *dividendo = (int*)malloc(sizeof(int));
    int *resto = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    int *j = (int*)malloc(sizeof(int));
    numero[0] = 0;
    *i = 0;
    while(*i < *cantDig){
        numero[0] *= 10;
        numero[0] += n[*i];
        *i = *i + 1;
    }
    *dividendo = *numero;
    *i = 0;
    while(*dividendo!=0){
        *resto = *dividendo % *destino;
        resultadoTentativo[*i] = *resto;
        *dividendo = *dividendo / *destino;
        if(*mostrar==1){
            printf("Se obtuvo: %i\n",*resto);
        }
        *i = *i + 1;
    }
    //Ver si el ultimo entero deberia ser -1. Usamos *cantDig?.
    resultadoFinal = (int*)malloc(sizeof(int)*((*i)));
    *j = 0;
    while(*i>0){
        resultadoFinal[*j] = resultadoTentativo[(*i)-1];
        *j = *j + 1;
        *i = *i - 1;
    }
    resultadoFinal[*j] = (0-1);
    free(numero);
    free(dividendo);
    free(resto);
    free(i);
    free(j);
    free(resultadoTentativo);
    return resultadoFinal;

    int *fraccion10aX(int *destino, float *n, int *mostrar){
    }

    int *fraccionXa10(int *origen, int *n, int *cantDig, int *mostrar){
    }

    int *enteroXaY(int *origen, int *destino, int *n, int *cantDig, int *mostrar){
    }

    int *fraccionXaY(int *origen, int *destino, int *n, int *cantDig, int *mostrar){
    }

}
