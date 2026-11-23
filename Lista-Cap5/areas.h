#ifndef AREAS_H
#define AREAS_H

/*
 * Biblioteca de Calculo de Areas Geometricas
 * Definicao de constantes e macros com parenteses de protecao.
 */

#define PI 3.14159265358979323846

// Area do Circulo: pi * r^2
#define A_CIRC(raio) (PI * ((double)(raio)) * ((double)(raio)))

// Area do Retangulo: base * altura
#define A_RET(base, alt) (((double)(base)) * ((double)(alt)))

// Area do Triangulo: (base * altura) / 2
#define A_TRI(base, alt) ((((double)(base)) * ((double)(alt))) / 2.0)

#endif // AREAS_H
