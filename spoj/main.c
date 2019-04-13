#include <stdio.h>
#include <stdlib.h>
// es tomar dos numeros, invertirlos los dos, sumarlos y volverlos a inverti
// 100/100
int InvertirNum(int N)
{
  int Invertido=0, Resto;
      while(N!=0)
      {
          Resto=N%10;
          N=N/10;
          Invertido=Invertido*10+Resto;
       }
     return Invertido;
 }
int main()
{
   int N1, Respuesta1;
   int N2, Respuesta2;
   int N3, Respuesta3;


   printf("Ingrese el numero que desea invertir \n");
   scanf("%d", &N1);
   Respuesta1=InvertirNum(N1);
   printf("El numero invertido es %d \n", Respuesta1);

   printf("Ingrese el numero que desea invertir \n");
   scanf("%d", &N2);
   Respuesta2=InvertirNum(N2);
   printf("El numero invertido es %d \n", Respuesta2);
   system("pause");

   N3 = Respuesta1 + Respuesta2;

   Respuesta3=InvertirNum(N3);
   printf("El numero invertido es %d \n", Respuesta3);


}
