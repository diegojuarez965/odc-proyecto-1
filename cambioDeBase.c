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
    toReturn= (int *)malloc(sizeof(int)*13);
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


int * entero10aX(int *destino, int *n, int *mostrar){
    int *resultadoTentativo;
    int *resultadoFinal;
    long long unsigned int *numero;
    long long unsigned int *dividendo;
    long long unsigned int *resto;
    int *i;
    int *j;
    resultadoTentativo = (int*)malloc(sizeof(int)*1000);                        //Le asigno este tama�o ya que no le pusimos limite a la parte entera.
    numero = (long long unsigned int*)malloc(sizeof(long long unsigned int));
    dividendo = (long long unsigned int*)malloc(sizeof(long long unsigned int));
    resto = (long long unsigned int*)malloc(sizeof(long long unsigned int));
    i = (int*)malloc(sizeof(int));
    j = (int*)malloc(sizeof(int));
    *numero = 0;
    *i = 0;
    while(n[*i] >= 0){ //Paso el numero decimal el cual cada digito ocupa 1 espacio en un arreglo de enteros, a un entero que ocupe una unica celda, es decir su representacion real.
        *numero *= 10;
        *numero += n[*i];
        *i = *i + 1;
    }
    *dividendo = *numero;
    free(numero);
    *i = 0;
    while(*dividendo!=0){   //Realizo el algoritmo de la division para la parte entera almacenando cada digito en cada celda de resultadoTentativo
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
    *j = 0;
    while(*i>0){ //Finalmente ordeno los digitos que obtuve guardandolos en resultadoFinal
        resultadoFinal[*j] = resultadoTentativo[(*i)-1];
        *j = *j + 1;
        *i = *i - 1;
    }
    resultadoFinal[*j] = -1;
    free(resultadoTentativo);
    free(i);
    free(j);
    return resultadoFinal;
}

int *fraccion10aX(int *destino, int *n, int *mostrar){
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
    while(n[*i]>=0){ //Paso el numero decimal el cual cada digito ocupa 1 espacio en un arreglo de enteros, a un real que ocupe una unica celda, o sea a su representacion real.
        *numero = *numero * 10;
        *numero = *numero + n[*i];
        *i = *i + 1;
    }
    *numero = *numero / pow(10,*i);
    *i = 0;
    while(*i<5 && *numero>0){    //Realizo el algoritmo de la multiplicacion y almaceno la parte entera en cada celda de resultado.
        *numero = *numero * (*destino);
        *numero = modf(*numero, &(*aux));
        resultado[*i] = (int)*aux;
        if(*mostrar==1)
            printf("Se obtuvo el digito: %i en la base %i\n",resultado[*i],*destino);
        *i = *i +1;
    }
    resultado[*i] = -1;
    free(numero);
    free(aux);
    free(i);
    return resultado;
}

int *enteroXaY(int *origen, int *destino, int *n, int *mostrar){

}

int *fraccionXaY(int *origen, int *destino, int *n, int *mostrar){

}
