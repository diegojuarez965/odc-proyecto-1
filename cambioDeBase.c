#include "cambioDeBase.h"

int *enteroXa10 (int *origen, int *n, int *mostrar)
{
    int *ultDig;
    int *toReturn;
    int *expo;
    int *i;
    int *f;
    int *aux;
    long long unsigned int *suma;
    ultDig = (int *)malloc(sizeof(int));
    expo = (int *)malloc(sizeof(int));
    suma = (long long unsigned int *)malloc(sizeof(long long unsigned int));
    *ultDig = 0;
    *expo = 0;
    *suma = 0;

    if(*mostrar==1)
        printf("\nConversion de la parte entera desde Base %i a Base 10:\n\n",*origen);
    while(n[*ultDig]!=-1)
        *ultDig = *ultDig + 1;
    *ultDig = *ultDig - 1;
    while(*ultDig>=0)
    {
        *suma = *suma+(n[*ultDig]*pow(*origen,*expo));
        if(*mostrar==1)
        {
            printf("Operacion realizada: %.0lf + %d*%d^%d\n",*suma-(n[*ultDig]*pow(*origen,*expo)),n[*ultDig],*origen,*expo);
            printf("Se obtuvo parcialmente %I64u en la base 10\n",*suma);
        }
        *ultDig = *ultDig - 1;
        *expo = *expo + 1;
    }
    free(ultDig);
    free(expo);
    toReturn = (int *)malloc(sizeof(int)*14);
    if(*suma==0)
    {
        toReturn[0] = 0;
        toReturn[1] = -1;
    }
    else
    {
        toReturn[0] = -1;

        i = (int *)malloc(sizeof(int));
        f = (int *)malloc(sizeof(int));
        *i = 0;
        *f = 1;
        while(*suma != 0)
        {
            toReturn[*f] = *suma%10;
            *f = *f + 1;
            *suma = *suma/10;
        }
        free(suma);
        *f = *f - 1;
        aux = (int *)malloc(sizeof(int));
        while(*i<*f)
        {
            *aux= toReturn[*i];
            toReturn[*i]= toReturn[*f];
            toReturn[*f]= *aux;
            *i = *i + 1;
            *f = *f - 1;
        }
        free(i);
        free(f);
        free(aux);
    }
    if(*mostrar==1)
            printf("\n");
    return toReturn;
}

int *fraccionXa10 (int * origen, int * n, int * mostrar)
{
    double *suma;
    int *it;
    int *expo;
    int *toReturn;
    int *i;
    int *exp;
    int *termine;
    int *entero;
    int *digito;
    suma = (double *)malloc(sizeof(double));
    it = (int *)malloc(sizeof(int));
    expo = (int *)malloc(sizeof(int));
    *it = 0;
    *suma = 0;
    *expo= -1;

    if(*mostrar==1)
            printf("\nConversion de la parte fraccionaria desde Base %i a Base 10:\n\n",*origen);
    while(n[*it]!=-1)
    {
        *suma= *suma+(n[*it]*pow(*origen,*expo));
        if(*mostrar==1)
        {
            printf("Operacion realizada: %lf + %d*%d^%d\n",*suma-(n[*it]*pow(*origen,*expo)),n[*it],*origen,*expo);
            printf("Se obtuvo parcialmente %lf en la base 10\n",*suma);
        }
        *it=*it+1;
        *expo=*expo-1;
    }
    free(it);
    free(expo);

    toReturn = (int *)malloc(sizeof(int)*6);
    i = (int *)malloc(sizeof(int));
    exp = (int *)malloc(sizeof(int));
    termine = (int *)malloc(sizeof(int));
    entero = (int *)malloc(sizeof(int));
    digito = (int *)malloc(sizeof(int));
    *i = 0;
    *exp = 1;
    *termine = 0;

    while(*exp<=5 && *termine==0)
    {
        *entero = *suma*(pow(10,*exp));
        if(*entero==*suma*(pow(10,*exp)))
            *termine = 1;
        *digito = *entero%10;
        toReturn[*i] = *digito;
        *i = *i + 1;
        *exp = *exp + 1;
    }
    toReturn[*i] = -1;
    if(*mostrar==1)
            printf("\n");
    free(suma);
    free(i);
    free(exp);
    free(termine);
    free(entero);
    free(digito);
    return toReturn;
}

int * entero10aX(int *destino, int *n, int *mostrar)
{
    int *resultadoTentativo;
    int *resultadoFinal;
    long long unsigned int *numero;
    long long unsigned int *dividendo;
    long long unsigned int *resto;
    int *i;
    int *j;
    numero = (long long unsigned int*)malloc(sizeof(long long unsigned int));
    i = (int*)malloc(sizeof(int));
    *numero = 0;
    *i = 0;

    if(*mostrar==1)
        printf("\nConversion de la parte entera desde Base 10 a Base %i:\n\n",*destino);
    while(n[*i] >= 0)  //Paso el numero decimal el cual cada digito ocupa 1 espacio en un arreglo de enteros, a un entero que ocupe una unica celda, es decir su representacion real.
    {
        *numero *= 10;
        *numero += n[*i];
        *i = *i + 1;
    }
    if(*numero==0)
    {
        resultadoFinal= (int *)malloc(sizeof(int)*2);
        resultadoFinal[0]=0;
        resultadoFinal[1]=-1;
        if(*mostrar==1)
            printf("Se obtuvo el digito: 0 en la base %i\n",*destino);
        free(numero);
        free(i);
    }
    else
    {
        resultadoTentativo = (int*)malloc(sizeof(int)*40);                        //Le asigno este tamaño ya que no le pusimos limite a la parte entera.
        dividendo = (long long unsigned int*)malloc(sizeof(long long unsigned int));
        resto = (long long unsigned int*)malloc(sizeof(long long unsigned int));
        *dividendo = *numero;
        free(numero);
        *i = 0;
        while(*dividendo!=0)    //Realizo el algoritmo de la division para la parte entera almacenando cada digito en cada celda de resultadoTentativo
        {
            *resto = *dividendo % *destino;
            resultadoTentativo[*i] = *resto;
            *dividendo = *dividendo / *destino;
            if(*mostrar==1)
                printf("Se obtuvo el digito: %i en la base %i\n",resultadoTentativo[*i],*destino);
            *i = *i + 1;
        }
        free(dividendo);
        free(resto);
        resultadoFinal = (int*)malloc(sizeof(int)*((*i)+1)); //Le sumo uno, ya que necesito agregar el digito finalizador '-1'.
        j = (int*)malloc(sizeof(int));
        *j = 0;
        while(*i>0)  //Finalmente ordeno los digitos que obtuve guardandolos en resultadoFinal
        {
            resultadoFinal[*j] = resultadoTentativo[(*i)-1];
            *j = *j + 1;
            *i = *i - 1;
        }
        resultadoFinal[*j] = -1;
        free(resultadoTentativo);
        free(i);
        free(j);
    }
    if(*mostrar==1)
            printf("\n");
    return resultadoFinal;
}

int *fraccion10aX(int *destino, int *n, int *mostrar)
{
    int *resultado;
    double *numero;
    double *aux;
    int *i;
    resultado = (int*)malloc(sizeof(int)*6);
    numero = (double*)malloc(sizeof(double));
    aux = (double*)malloc(sizeof(double));
    i = (int*)malloc(sizeof(int));
    *i = 0;
    *numero = 0;

    if(*mostrar==1)
            printf("\nConversion de la parte fraccionaria desde Base 10 a Base %i:\n\n",*destino);
    while(n[*i]>=0)  //Paso el numero decimal el cual cada digito ocupa 1 espacio en un arreglo de enteros, a un real que ocupe una unica celda, o sea a su representacion real.
    {
        *numero = *numero * 10;
        *numero = *numero + n[*i];
        *i = *i + 1;
    }
    if(*numero==0)
    {
        resultado[0]=0;
        resultado[1]=-1;
        if(*mostrar==1)
            printf("Se obtuvo el digito: 0 en la base %i\n",*destino);
    }
    else
    {
        *numero = *numero / pow(10,*i);
        *i = 0;
        while(*i<5 && *numero>0)     //Realizo el algoritmo de la multiplicacion y almaceno la parte entera en cada celda de resultado.
        {
            *numero = *numero * (*destino);
            *numero = modf(*numero, &(*aux));
            resultado[*i] = (int)*aux;
            if(*mostrar==1)
                printf("Se obtuvo el digito: %i en la base %i\n",resultado[*i],*destino);
            *i = *i +1;
        }
        resultado[*i] = -1;
    }
    if(*mostrar==1)
            printf("\n");
    free(numero);
    free(aux);
    free(i);
    return resultado;
}

int *enteroXaY(int *origen, int *destino, int *n, int *mostrar)
{
    return entero10aX(destino,enteroXa10(origen,n,mostrar),mostrar);
}

int *fraccionXaY(int *origen, int *destino, int *n, int *mostrar)
{
    return fraccion10aX(destino,fraccionXa10(origen,n,mostrar),mostrar);
}
