#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Checkea que el input ingresado por consola sea valido de acuerdo al formato dictado por el enunciado que debe ser:
* convert -n <numero> [-s <base origen>] [-d <base destino>] [-v] [-h]
* Ademas, una serie de parametros seran modificados por referencia, es decir que ingresarian estando vacios.
* @param argv Es el input tal cual de la consola que se envia a un main().
* @param cantArg Cantidad de argumentos del input.
* @param numEntero Arreglo de caracteres en el cual se escribiran los digitos de la parte entera del numero.
* @param numFraccionario Arreglo de caracteress en el cual se escribiran los digitos de la parte fraccionaria del numero.
* @param origen Base origen del numero, en la cual esta expresado.
* @param destino Base destino del numero, a la cual se lo quiere convertir.
* @param v Denota si se quiere mostrar o no computos internos.
* @return Retorna un puntero el cual su valor indica si el input fue valido (1) o no (0), aunque si no es valido se llama a exit().
*/
int* inputValido(char *argv[], int *cantArg, char *numEntero, char *numFraccionario, int *origen, int *destino, int *v);

/**
* Mapea un numero expresado mediante un arreglo de enteros, ocupando cada digito una posicion y finalizado por un -1, a un arreglo de caracteres
* convirtiendo apropiadamente cada digito entero a un caracter segun la representacion de digitos de bases mayores a 10 (A=10, B=11, etc...).
* @param numero Arreglo de caracteres en el cual se mapearan los digitos del numero finalizado por un '\0'.
* @param numeroEntero Arreglo de enteros del cual se obtendra cada digito del numero para ser mapeado, finalizado por un -1.
*/
void mapearDigitos(char *numero,int *numeroEntero);

/**
* Mapea un numero expresado mediante un arreglo de caracteres en el cual cada uno de sus digitos ocupa una posicion y finaliza con '\0', a un arreglo
* de enteros donde cada caracter se lo convierte de forma que equivale a su representacion en bases mayores a 10.
* Es decir, es el metodo inverso de mapearDigitos.
* @param numero Arreglo de caracteres del cual se obtendran los digitos del numero para ser mapeados, finalizado por un '\0'
* @param numeroEntero Arreglo de enteros en el cual se mapearan los digitos del numero finalizado por un -1.
*/
void mapearLetras(char *numero,int *numeroEntero);

/**
* Muestra por consola un mensaje de ayuda sobre el formato de invocacion al programa, indicando cada argumento y una breve descripcion del mismo.
*/
void mostrarAyuda();

/** Se fija si un numero es valido en una cierta base.
* Checkea si un numero representado mediante un arreglo de caracteres en el cual cada posicion del arreglo contiene un digito del numero, es valido
* en la base ingresada, es decir si todos sus digitos pertenecen a una cierta base o se escapan de ella.
* @param numero Es el numero representado mediante un arreglo de caracteres a checkear si pertenece a una cierta base finalizado por un '\0'.
* @param base Base a checkear que el numero pertenezca.
*/
int* esNumeroValido(char* numero, int* base);

