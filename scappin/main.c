#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 80/100
// Falto usar punteros para extraer texto -20
void verificar_info(info[])
char * LeerDatos(char nombreArchivo[]);
int buscar(char info[], char tag[], int j);
int imprimir(char info[], int j);
int SubStr(char info[], char valor[], int j);

int main()
{
	int i = 0;
	    char * info = LeerDatos("info.txt");

	return 0;
}

void verificar_info(info[]){

  for (i = 0; info[i] != '\0'; i++) {
		i = buscar(info, instrumentos, i);
		if (i == 0)
			return 0;

		if (i > 0)
		{
				imprimir(info, i);
		}
	}



char * LeerDatos(char nombreArchivo[])
{
	int tamanoArchivo;
	FILE * archivo;
	char * info;

	archivo = fopen(nombreArchivo, "rt");

	if (archivo == NULL)
		return NULL;

	fseek(archivo, 0, SEEK_END);
	tamanoArchivo = ftell(archivo);
	fseek(archivo, 0, SEEK_SET);

	info = malloc((tamanoArchivo + 1) * sizeof(char));

	fread(info, sizeof(char), tamanoArchivo, archivo);
	fclose(archivo);
	info[tamanoArchivo] = '\0';

	return info;
}

int buscar(char info[], char tag[], int j)
{
	for (;info[j] != '\0';j++)
	{
		if (SubStr(info, tag, j))
		{
			j += strlen(tag);
			while (info[j++] != '>');
			return (j);
		}
	}
	return 0;
}

int imprimir(char info[], int j)
{
	for (;info[j] != '\0' && info[j] != '<';j++)
		printf("%c", info[j]);

	printf("\n");
	return j;
}

int SubStr(char info[], char valor[], int j)
{
	int i=0;

	while (valor[i] != '\0' && info[i + j] != '\0' )
	{
		if (valor[i] != info[i + j])
		{
			break;
		}
		i++;
	}

	if (i == strlen(valor))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
