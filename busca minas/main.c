#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
// 90/100
// El buscaminas tenía que soportar tamaño variable -10
L=8;
main()
{

    int A;
    char vectormina[L][L],nivel, vectormuerte[L][L], fin, condicion;
    int  minas=0, clicki=0, clickj=0, posicion=0, acum = 0;
    int i=0,j=0;
    int s=0, m=0, h=0;

    system("color f");

    Bienvenida();
    printf("digite el tamano de 'fila columna' de la matris ");
    scanf("%d",&A);
    L=A;
    Eleccion(&nivel);
    Inicializar(vectormina, vectormuerte);
    Random(vectormuerte, &nivel, i, j);
    Mostrar(vectormina);

    do
    {
        Pregunta(&condicion);
        if (condicion=='b'|| condicion=='B')
        {
            Bandera( vectormuerte, vectormina, &clicki, &clickj, &acum);
        }
        else if( condicion=='c' || condicion== 'C')
        {
            Coordenada(vectormina, vectormuerte, &clicki, &clickj, posicion, &acum);
        }
        Mostrar(vectormina);

        if (vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='c' || vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='C')
        {
            fin = 'X';

            for (int i=0; i<L; i++)
            {

                for(int j=L; j<L; j++)
                {

                    if (vectormuerte[i][j]=='X')
                    {
                        vectormina[i][j]=0;
                        vectormina[i][j]= vectormuerte[i][j];
                    }
                }
            }
            system("cls");

            Mostrar(vectormina);
            printf("\n\n     :::::::::Usted ha perdido !x_x!   LA PARTIDA HA FINALIZADO:::::::::\n");
            system("pause");
            system("cls");
            printf("\n El puntaje obtenido en la partida es %i\n", acum);
            printf("\n El tiempo jugado fue:\n");
            printf("%i %i %i",h,m,s);
            printf("\n\n       ");
            system("pause");
        }

    }
    while (fin != 'X');



}


void Bienvenida()
{
    char rsp;
    printf("buscaMinas\n");
    system("pause");

}

void Eleccion(char *nivel)
{


    system("cls");
    printf("\n Ingrese el nivel de dificultad en el cual desea jugar:\n");
    printf("\n 1, 2, 3\n");
    printf("\n Facil: 3 minas\n");
    printf("\n Intermedio:6 minas \n");
    printf("\n Dificil10 minas\n");

    do
    {
        scanf(" %c", &*nivel);
        system("cls");
        if(*nivel!='1' && *nivel!='2' && *nivel!='3')
        {

            printf("\n El nivel ingresado es incorrecto por favor ingrese un dato valido\n\n");
        }
    }
    while( *nivel!='1' && *nivel!='2' && *nivel!='3' );
}

void Inicializar(char vectormina[][L], char vectormuerte[][L])
{
    for(int i=0; i<L; i++)// For para la matriz base
    {
        for(int j=0; j<L; j++)
        {
            vectormina[i][j]='$';
            vectormuerte[i][j]=0;
        }
    }
}

void Random(char vectormuerte[][L], char *nivel, int i, int j)
{
    if (*nivel == '1')
    {
        printf("\n Ha seleccionado el Nivel Facil\n");
        system("pause");
        srand(time(NULL)); //SEMILLA DEL RANDOM 1
        for(int k =1; k <=3; k++)
        {
            if(vectormuerte[i][j] != 'X')
            {
                i = (rand() % L);
                j = (rand() % L);
            }
            else if(vectormuerte[i][j] == 'X')
            {
                i = (rand() % 7)+1;
                j = (rand() % 7)+1;
            }
            vectormuerte[i][j] = 'X';
        }
    }
    else if (*nivel == '2')
    {
        printf("\n Ha seleccionado el nivel Intermedio\n");
        system("pause");
        srand(time(NULL));
        for(int k =1; k <=6; k++)
        {
            if(vectormuerte[i][j] != 'X')
            {
                i = (rand() % L);
                j = (rand() % L);
            }
            else if(vectormuerte[i][j] == 'X')
            {
                i = (rand() % 7)+1;
                j = (rand() % 7)+1;
            }
            vectormuerte[i][j] = 'X';
        }
    }
    else if (*nivel == '3')
    {
        printf("\n Ha seleccionado el nivel Dificil\n");
        system("pause");
        srand(time(NULL)); //SEMILLA DEL RANDOM 3
        for(int k =1; k <=10; k++)
        {
            if(vectormuerte[i][j] != 'X')
            {
                i = (rand() % L);
                j = (rand() % L);
            }
            else if(vectormuerte[i][j] == 'X')
            {
                i = (rand() % 7)+1;
                j = (rand() % 7)+1;
            }
            vectormuerte[i][j] = 'X';
        }

    }
}

void Mostrar(char vectormina[][L])
{

    printf("\n\n");
    printf("                   ");
    for(int i = 1; i <= L; i++)
    {
        printf("( %i )", i);
    }
    printf("\n");

    for(int i = 1; i <= L; i++)
    {
        printf("\n              ( %i )", i);
        for(int j = 1; j <= L; j++)
        {
            printf("[ %c ]", vectormina[i-1][j-1]);
        }
        printf("\n");
    }
}

void Pregunta(char *condicion)
{
    printf("\n Si desea desbloquear una casilla marque la letra 'c'\n");
    printf("\n Si desea marcar una casilla marque la letra 'b'\n");
    do
    {
        scanf(" %c", &*condicion);
        if( *condicion!='c' && *condicion!='C' && *condicion!='b' && *condicion!='B')
        {
            printf("\n    Opcion equivocada, seleccione una opcion valida ('c') o ('b')\n ");
        }
    }
    while( *condicion!='c' && *condicion!='C' && *condicion!='b' && *condicion!='B');

}

void Bandera(char vectormuerte[][L], char vectormina[][L], int *clicki, int *clickj,  int *acum)
{
    do
    {
        printf("\n Ingrese la coordenana que desea marcar (en forma de fila y columna)\n");
        scanf("%i", &*clicki);
        scanf("%i", &*clickj);
        if(vectormina[*clicki-1][*clickj-1]!='$')
        {
            system("cls");
            printf("\n                La coordenada seleccionada ya fue utilizada\n");
            Mostrar(vectormina);
        }
    }
    while (vectormina[*clicki-1][*clickj-1]!='$');
    vectormina[*clicki-1][*clickj-1] = 0;
    vectormina[*clicki-1][*clickj-1] = 'B';
    if (vectormuerte[*clicki-1][*clickj-1] == 'X')
    {
        *acum = *acum + 5;
    }
    else if (vectormuerte[*clicki-1][*clickj-1] != 'X')
    {
        *acum = *acum -2;
    }
}

void Coordenada(char vectormina[][L], char vectormuerte[][L], int *clicki, int *clickj, int posicion, int *acum)
{
    do
    {
        printf("\n Ingrese la coordenada que desea desbloquear (en forma de fila y columna)\n");

        scanf("%i", &*clicki);
        scanf("%i", &*clickj);
        if(vectormina[*clicki-1][*clickj-1]!='$' && vectormina[*clicki-1][*clickj-1]!='B')
        {
            system("cls");
            printf("\n                La coordenada seleccionada ya fue utilizada\n\n");
            Mostrar(vectormina);
        }
    }
    while (vectormina[*clicki-1][*clickj-1]!='$' && vectormina[*clicki-1][*clickj-1]!='B');
    if (vectormina[*clicki-1][*clickj-1]!='$')
    {
        *acum++;
    }
    if (vectormuerte[*clicki-1][*clickj-1] != 'X')
    {
        *acum++;
        if ((*clicki-1)!=0 && (*clicki-1)!=7 && (*clickj-1)!=0 && (*clickj-1)!=7) //Calculo Matriz central
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                    {
                        posicion++;
                    }
                }
            }
        }
        else if( (*clicki-1)==0 && (*clickj-1)!=0 && (*clickj-1)!=7)  //Validacion Fila 0
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {
                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;
                        }
                    }
                    while( (*clicki-1>0) );
                }
            }
        }
        else if( (*clicki-1)==7 && (*clickj-1)!=0 && (*clickj-1)!=7)  //Validacion Fila 7
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<L) );
                }
            }
        }

        else if( (*clickj-1)==0 && (*clicki-1)!=0 && (*clicki-1)!=7) //Validacion columna 0
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)!=0 && (*clicki-1)!=7)) //Validacion columna 7
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<L) );
                }
            }
        }

        else if( ( (*clickj-1)==0 && (*clicki-1)==0) ) //Validacion Esquina 1
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<0) && (*clicki-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==0 && (*clicki-1)==7) ) //Validacion Esquina 2
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<0) && (*clickj-1<L) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)==0) ) //Validacion Esquina 3
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<L) && (*clickj-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)==7) ) //Validacion Esquina 4
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<7) && (*clickj-1<7) );
                }
            }
        }



        switch(posicion)
        {
        case 1:
            vectormuerte[*clicki-1][*clickj-1] = '1';
            break;

        case 2:
            vectormuerte[*clicki-1][*clickj-1] = '2';
            break;

        case 3:
            vectormuerte[*clicki-1][*clickj-1] = '3';
            break;

        case 4:
            vectormuerte[*clicki-1][*clickj-1] = '4';
            break;

        case 5:
            vectormuerte[*clicki-1][*clickj-1] = '5';
            break;

        case 6:
            vectormuerte[*clicki-1][*clickj-1] = '6';
            break;

        case 7:
            vectormuerte[*clicki-1][*clickj-1] = '7';
            break;

        case 8:
            vectormuerte[*clicki-1][*clickj-1] = '8';
            break;
        }
    }
    vectormina[*clicki-1][*clickj-1] = 0;
    vectormina[*clicki-1][*clickj-1] = vectormuerte[*clicki-1][*clickj-1];
}

void cronometro(int s, int m, int h)
{
    while(1)
    {
        if (s >=60)
        {
            s = 0;
            m++;
            if (m >= 60)
            {
                m = 0;
                h++;
            }
        }
        Sleep(1000); // funcion para que corra el ciclo en milisegundos
        s++;
    }
    getch();
}

