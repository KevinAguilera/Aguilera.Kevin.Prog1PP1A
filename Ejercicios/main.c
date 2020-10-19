#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NOTEBOOK 3

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

void aplicarDescuento(float precio, float* resultado);
int contarCaracteres(char* cadena, char caracter);
int sortNotebooks(eNotebook* list, int len);
void showNotebook(eNotebook computadora);
int printNotebooks(eNotebook* list, int len);


int main()
{
    float precio = 100;
    float resultadoConDescuento;
    aplicarDescuento(precio, &resultadoConDescuento);
    printf("El precio es: %.2f\n", precio);
    printf("El precio con descuento es: %.2f\n", resultadoConDescuento);
    printf("\n\n");

    char frase[]="Hola como esta usted hoy";
    printf("%s\n", frase);
    printf("La frase tiene %d cantidad de a\n", contarCaracteres(frase, 'a'));
    printf("\n\n");

    eNotebook notebooks[NOTEBOOK] =
    {
        {1000, "I5", "INTEL", 25000.75},
        {1000, "I9", "INTEL", 40000.75},
        {1001, "I9", "IBM", 80000.89},
    };

    printNotebooks(notebooks, NOTEBOOK);
    sortNotebooks(notebooks, NOTEBOOK);
    printNotebooks(notebooks, NOTEBOOK);

    return 0;
}

void aplicarDescuento(float precio, float* resultado)
{
    float porcentaje;
    porcentaje = (precio * 5) / 100;
    *resultado = precio - porcentaje;
}

int contarCaracteres(char* cadena, char caracter)
{
    int lenCadena = strlen(cadena);
    int contarCaracter = 0;
    for(int i = 0; i < lenCadena; i++)
    {
        if(cadena[i] == caracter)
        {
            contarCaracter++;
        }
    }
    return contarCaracter;
}

int sortNotebooks(eNotebook* list, int len)
{
    int error = -1;
    eNotebook auxNotebook;

    if(list!= NULL && len > 0)
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(strcmp(list[i].marca, list[j].marca) > 0)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                }
                else if(strcmp(list[i].marca, list[j].marca) == 0 && list[i].precio < list[j].precio)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                }
            }
        }
        error = 0;

    }

    return error;
}


int printNotebooks(eNotebook* list, int len)
{
    if(list != NULL && len > 0 && len <= 10)
    {
        printf("******************************************************************\n");
        printf("  ID            PROCESADOR           MARCA              PRECIO\n");
        printf("******************************************************************\n");
        for(int i = 0; i < len; i++)
        {
                showNotebook(list[i]);
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showNotebook(eNotebook computadora)
{
    printf("%6d %15s            %8s              $%4.2f\n",
           computadora.id,
           computadora.procesador,
           computadora.marca,
           computadora.precio
          );
}
