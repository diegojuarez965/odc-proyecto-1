#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Transforma la parte entera de un numero en cierta base a base 10, mostrando o no los computos intermedios.
 * @param origen Base origen.
 * @param n  Parte entera de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte entera de un numero en base 10.
*/
int *enteroXa10(int *origen, int *n, int *mostrar);

/**
 * Transforma la parte entera de un numero en base 10 a cierta base, mostrando o no los computos intermedios.
 * @param destino Base destino.
 * @param n  Parte entera de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte entera de un numero en base destino.
*/
int *entero10aX(int *destino, int *n, int *mostrar);

/**
 * Transforma la parte fraccionaria de un numero en base 10 a cierta base, mostrando o no los computos intermedios.
 * @param destino Base destino.
 * @param n  Parte fraccionaria de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte fraccionaria de un numero en base destino.
*/
int *fraccion10aX(int *destino, int *n, int *mostrar);

/**
 * Transforma la parte fraccionaria de un numero en cierta base a base 10, mostrando o no los computos intermedios.
 * @param origen Base origen.
 * @param n  Parte fraccionaria de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte fraccionaria de un numero en base 10.
*/
int *fraccionXa10(int *origen, int *n, int *mostrar);

/**
 * Transforma la parte entera de un numero en cierta a base a cierta base, mostrando o no los computos intermedios.
 * @param origen Base origen.
 * @param destino Base destino.
 * @param n  Parte entera de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte entera de un numero en base destino.
*/
int *enteroXaY(int *origen, int *destino, int *n, int *mostrar);

/**
 * Transforma la parte fraccionaria de un numero en cierta a base a cierta base, mostrando o no los computos intermedios.
 * @param origen Base origen.
 * @param destino Base destino.
 * @param n  Parte fraccionaria de un numero a cambiar de base.
 * @param mostrar Si es 0 no muestra los computos intermedios, si es 1 muestra los computos intermedios.
 * @return Parte fraccionaria de un numero en base destino.
*/
int *fraccionXaY(int *origen, int *destino, int *n, int *mostrar);

