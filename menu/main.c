#include <stdio.h>
#include <stdlib.h>
//calcular indice, entrar, quitar materia, 1 solo estudiante

void agregar_materias();
//int quitar_materia();
void calcularindice();
int numerooo;
struct numero_materia_credito{int letra; char materias[10]; int cantidad_de_materias; int credito;}ciclo[21];

int main()
{
int opcion=5;
 //el limite xe creditos son 21

while(opcion!=0){
printf("bienvenido al menu de opciones academincas\n\n");
printf("1. colocar materias\n");
printf("2. quitar materias\n");
printf("3. calcular indice\n");
printf("0. para salir\n\n");
        scanf("%d",&opcion);

        switch(opcion){

            case 1 : agregar_materias();
  break;

            case 2 :

  break;

            case 3 : calcularindice();

  break;

    }

}

printf("muchas gracias por entrar");

return 0;}



void agregar_materias(){

    int i;
    int cantidad;

    printf("digite el numero de materias a tomar\n");
    scanf("%d",&cantidad);

            for(i=0;i<cantidad;i++){
            printf("materia\n");
            scanf("%s",&ciclo[i].materias);
            fflush(stdin);
            printf("creditos\n");
            scanf("%d",&ciclo[i].credito);
            fflush(stdin);}
printf("\n");

printf("%d materias\n\n",cantidad);

        for(i=0;i<cantidad;i++){
        printf("%d.%s de %d creditos\n",i+1,ciclo[i].materias,ciclo[i].credito);}


cantidad=ciclo[0].cantidad_de_materias;
numerooo=cantidad;
printf("\n\n");
return ;}

void calcularindice(){
int i;
float valor=0;
float indice;
float credito;
char letra;

for(i=0;i<numerooo;i++){

        printf("en %s de \n",ciclo[i].materias);
        fflush(stdin);
        scanf("%s",&letra);

        for(i=0;i<numerooo;i++){
            credito+=ciclo[i].credito;
        }
        printf("creditos del ciclo,%d",credito);
        for(i=0;i<=numerooo;i++){
            if(letra=='a'){valor+=4;};
            if(letra=='b'){valor+=3;};
            if(letra=='c'){valor+=2;};
            if(letra=='d'){valor+=1;};
            if(letra=='f'){valor+=0;};
        }
        printf("valor acumulado %d\n",valor);
        indice=valor/credito;
        printf("indice final%f\n",indice);
}




return ;
}



