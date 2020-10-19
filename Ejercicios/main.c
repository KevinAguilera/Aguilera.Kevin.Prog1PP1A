#include <stdio.h>
#include <stdlib.h>

float aplicarDescuento(float precioProducto);
int contarCaracteres(char string[],char caracter);


int main()
{
    float precio=100;

    precio=aplicarDescuento(precio);

    printf("El precio con descuento es: $%.2f\n\n",precio);

    char palabra[50]="calavera",caracter='a';
    int cant;

    cant=contarCaracteres(palabra,caracter);
    printf("El caracter %c aparece %d veces en la palabra %s.\n",caracter,cant,palabra);
    return 0;


    return 0;
}

float aplicarDescuento(float precioProducto)
{
    float retorno;
    retorno =precioProducto-(precioProducto*0.05);
    return retorno;
}

int contarCaracteres(char string[],char caracter)
{
    int contador=0;

    for(int i = 0; string[i]!= '\0' ;i++)
   {
       if(string[i]==caracter)
        {
            contador++;
        }
   }
   return contador;
}
