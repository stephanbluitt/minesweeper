#include <stdio.h>
#include <stdlib.h>
//calcular indice, entrar, quitar materia, 1 solo estudiante
// 100/100
void agregar_materias();
void indice();
void quitarmateria();
int lim;
int eliminar;
int i;
int cantidad;
float indiceacumulado;
float cantidaddematerias;
float creditos[20];
float Tcredito=0;
char calificacion[20];
float Tputntos;

struct numero_materia_credito
{
    int letra[10];
    char materias[10];
    int cantidad_de_materias;
    int credito;
} ciclo[21];

int main()
{
    int opcion=5;

    while(opcion!=0)
    {
        printf("bienvenido al menu de opciones academincas\n\n");
        printf("1. colocar materias\n");
        printf("2. quitar materias\n");
        printf("3. calcular indice\n");
        printf("0. para salir\n\n");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1 :
        {


            printf("digite el numero de materias a tomar\n");
            scanf("%d",&cantidad);

            for(i=0; i<cantidad; i++)
            {
                printf("materia\n");
                scanf("%s",&ciclo[i].materias);
                fflush(stdin);
                printf("creditos\n");
                scanf("%d",&ciclo[i].credito);
                fflush(stdin);
            }
            printf("\n");

            printf("%d materias\n\n",cantidad);

            for(i=0; i<cantidad; i++)
            {
                printf("%d.%s de %d creditos\n",i+1,ciclo[i].materias,ciclo[i].credito);
            }

            cantidad=ciclo[0].cantidad_de_materias;
            lim=cantidad;
            printf("\n\n");
        }

        break;

        case 2 :


            printf("selecione el numero de la materia que decea eliminar");
            scanf("%d",&eliminar);
            eliminar++;

            for(i=0; i<10; i++)
            {

                ciclo[eliminar].materias[i]='\0';
            }
            ciclo[eliminar].credito=NULL;



            break;

        case 3 :



            printf("digite el numero de materias a consursar\n");
            scanf("%f",&cantidaddematerias);



            for(i=0; i<cantidaddematerias; i++)
            {
                printf("digite los creditos de la materia %d\n",i+1);
                scanf("%f",&creditos[i]);
                fflush(stdin);
                printf("digite la calificacion, en letra\n");
                \
                scanf("%c",&calificacion[i]);
                fflush(stdin);

            }


            for(i=0; i<cantidaddematerias; i++)
            {
                Tcredito+=creditos[i];
            }

            Tputntos=0;

            for(i=0; i<cantidaddematerias; i++)
            {

                if(calificacion[i]=='a'||'A')
                {
                    Tputntos+=4;
                }

                if(calificacion[i]=='b'||'B')
                {
                    Tputntos+=3;
                }

                if(calificacion[i]=='c'||'C')
                {
                    Tputntos+=2;
                }

                if(calificacion[i]=='d'||'D')
                {
                    Tputntos+=1;
                }

                if(calificacion[i]=='f'||'F')
                {
                    Tputntos+=0;
                }
            }


            indiceacumulado =(Tputntos/Tcredito);

            printf("indice de: %f",indiceacumulado);
            break;



        }
    }
    printf("muchas gracias por entrar");
    return 0;


}
