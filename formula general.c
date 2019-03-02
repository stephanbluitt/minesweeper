#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a=2;
    int b=14;
    int c=1;
    printf("digite los valores de A,B y C");
    int discriminante=0;
    float raiz;
    float x;
    float y;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    discriminante = (b*b)-(4*a*c);
    printf("discriminante es %d\n",discriminante);

    if(discriminante<0){
    printf("no hay respuesta real");}else{

    raiz = sqrt(discriminante);
    printf("la raiz es: %f\n",raiz);
    x=(-b-raiz)/2*a;
    y=(-b+raiz)/2*a;

    if(x==y){
    printf("%f",x);
    }else{
    printf("%d y %d",x,y);
    }
    return 0;
}

}
