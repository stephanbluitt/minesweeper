#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculos();
    float a,b,c;
    float x1,x2;

int main()
{

    printf("resolver formula cuadratica\n\n");
    printf("digite el valor de 'a'=");
    scanf("%f",&a);
    printf("\ndigite el valor de 'b'=");
    scanf("%f",&b);
    printf("\ndigite el valor de 'c'=");
    scanf("%f",&c);
    printf("\n");
    calculos();


    return 0;
}


void calculos(){
        float discriminante;
    float raiz;

    discriminante= (b*b)-(4*a*c);
    printf("\ndiscriminante: %f\n",discriminante);
    if(discriminante<0){
        printf("respuesta, no rear Errol");
    }else{

    raiz= sqrt(discriminante);
    printf("Raiz cuadrada positiva: %f\n",raiz);
    system("pause");
    x1=(-b+raiz)/(2*a);
    x2=(-b-raiz)/(2*a);
    printf("posibles respuestas:%f y %f",x1,x2);
    system("pause");
    }
    }
