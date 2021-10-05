#include "cambioDeBase.h"

int *enteroXa10 (int *origen, int *n, int *mostrar)
{
    int *ultDig;
    ultDig= (int *)malloc(sizeof(int));
    for(int i=0; n[i]!=-1; i++)
        *ultDig=i;
    long long unsigned int *suma;
    suma= (long long unsigned int *)malloc(sizeof(long long unsigned int));
    *suma= 0;
    for(int i=*ultDig,exp=0; i>=0; i--,exp++)
    {
        *suma= *suma+(n[i]*pow(*origen,exp));
        if(*mostrar==1)
        {
            printf("Operacion realizada: %.0lf + %d * %d ^ %d\n",*suma-(n[i]*pow(*origen,exp)),n[i],*origen,exp);
            printf("Se obtuvo parcialmente %I64u\n",*suma);
        }
    }
    int *toReturn;
    toReturn= (int *)malloc(sizeof(int)*14);
    toReturn[0]= -1;
    int * i;
    i= (int *)malloc(sizeof(int));
    *i= 0;
    int *f;
    f= (int *)malloc(sizeof(int));
    *f= 1;
    int *aux;
    aux= (int *)malloc(sizeof(int));
    while(*suma != 0)
    {
        toReturn[*f]= *suma%10;
        *f= *f+1;
        *suma= *suma/10;
    }
    *f= *f-1;
    while(*i<*f)
    {
        *aux= toReturn[*i];
        toReturn[*i]= toReturn[*f];
        toReturn[*f]= *aux;
        *i= *i+1;
        *f= *f-1;
    }
    free(ultDig);
    free(suma);
    free(i);
    free(f);
    free(aux);
    return toReturn;
}

int *fraccionXa10 (int * origen, int * n, int * mostrar)
{
    double *suma;
    suma= (double *)malloc(sizeof(double));
    *suma= 0;
    for(int i=0,exp=-1; n[i]!=-1; i++,exp--)
    {
        *suma=*suma+(n[i]*pow(*origen,exp));
        if(*mostrar==1)
        {
            printf("Operacion realizada: %lf + %d * %d ^ %d\n",*suma-(n[i]*pow(*origen,exp)),n[i],*origen,exp);
            printf("Se obtuvo parcialmente %lf\n",*suma);
        }
    }
    int *toReturn;
    toReturn= (int *)malloc(sizeof(int)*6);
    int *i;
    i= (int *)malloc(sizeof(int));
    *i=0;
    int *exp;
    exp= (int *)malloc(sizeof(int));
    *exp=1;
    int *termine;
    termine= (int *)malloc(sizeof(int));
    *termine=0;
    int *entero;
    entero= (int *)malloc(sizeof(int));
    int *digito;
    digito= (int *)malloc(sizeof(int));
    while(*exp<=5 && *termine==0)
    {
        *entero= *suma*(pow(10,*exp));
        if(*entero==*suma*(pow(10,*exp)))
            *termine=1;
        *digito= *entero%10;
        toReturn[*i]=*digito;
        *i= *i+1;
        *exp= *exp+1;
    }
    toReturn[*i]=-1;
    free(suma);
    free(i);
    free(exp);
    free(termine);
    free(entero);
    free(digito);
    return toReturn;
}

int *entero10aX(int *destino, int *n, int *cantDig, int *mostrar)
{
    int *resultadoTentativo = (int*)malloc(sizeof(int)*1000);
    int *resultadoFinal;
    int *numero = (int*)malloc(sizeof(int));
    int *dividendo = (int*)malloc(sizeof(int));
    int *resto = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    int *j = (int*)malloc(sizeof(int));
    numero[0] = 0;
    *i = 0;
    while(*i < *cantDig)
    {
        numero[0] *= 10;
        numero[0] += n[*i];
        *i = *i + 1;
    }
    *dividendo = *numero;
    *i = 0;
    while(*dividendo!=0)
    {
        *resto = *dividendo % *destino;
        resultadoTentativo[*i] = *resto;
        *dividendo = *dividendo / *destino;
        if(*mostrar==1)
        {
            printf("Se obtuvo: %i\n",*resto);
        }
        *i = *i + 1;
    }
    //Ver si el ultimo entero deberia ser -1. Usamos *cantDig?.
    resultadoFinal = (int*)malloc(sizeof(int)*((*i)));
    *j = 0;
    while(*i>0)
    {
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
}

