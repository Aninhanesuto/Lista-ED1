#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "complexo.h"

complexo complexo_novo(double real, double imag){
    complexo c;
    c.real = real;
    c.img = imag;
    return c;
}

complexo complexo_soma(complexo a, complexo b){
    return complexo_novo(a.real + b.real, a.img + b.img);
}

complexo complexo_le(){
    complexo a;
    scanf("%lf %lf",&a.real, a.img);
    return a;
}

double complexo_absoluto(complexo a){
    return sqrt(a.real*a.real + a.img*a.img);
}

void complexo_imprime(complexo a){
    printf("%lf + %lf\n",a.real,a.img);
}

int complexo_iguais(complexo a, complexo b){
    return (a.real == b.real) && (a.img == b.img);
}

complexo complexo_multiplicador(complexo a, complexo b){
    return complexo_novo(a.real*b.real - a.img*b.img, a.real*b.img + b.real*a.img);
};

complexo complexo_conjugado(complexo a){
    return complexo_novo(a.real, - a.img);
}

