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

int sortNotebooks(eNotebook* list, int len);
void showNotebook(eNotebook compu);
int printNotebooks(eNotebook* list, int len);

int main()
{
    eNotebook notebooks[NOTEBOOK] =
    {
        {1000, "I5", "NVIDIA", 12345.75},
        {1000, "I9", "INTEL", 23456.75},
        {1001, "I9", "ASUS", 43450.89},
    };

    printNotebooks(notebooks, NOTEBOOK);
    sortNotebooks(notebooks, NOTEBOOK);
    printNotebooks(notebooks, NOTEBOOK);

    return 0;
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
        
        for(int i = 0; i < len; i++)
        {
                showNotebook(list[i]);
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showNotebook(eNotebook compu)
{
    printf("%6d %15s            %8s              $%4.2f\n",
           compu.id,
           compu.procesador,
           compu.marca,
           compu.precio
          );
}
