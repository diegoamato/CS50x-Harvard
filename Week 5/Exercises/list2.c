#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1; // *list = 1;
    list[1] = 2; // *(list+1) = 2;
    list[2] = 3; // *(list+2) = 3;
    
    //Size 3 list test
    //for (int i = 0; i < 3; i++)
    //{
    //    printf("%i\n", list[i]);
    //}
    //printf("FIM LISTA 3\n");
    //printf("===========\n");

    //Resize old array to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    //Add fourth number to new array
    tmp[3] = 4;
    
    //Remember new array
    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    //Size 4 list test
    //printf("FIM LISTA 4\n");
    //printf("===========\n");    
    
    free(tmp);
    return 0;
}