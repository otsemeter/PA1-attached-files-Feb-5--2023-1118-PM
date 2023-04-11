#include "shell_array.h"
#include "sequence.h"
#include <stdlib.h>
#include<stdio.h>

long *Array_Load_From_File(char *filename, int *size)
{
    FILE * fptr = fopen(filename, "r");  
    if(fptr == NULL)
    {
        fprintf(stderr, "fopen fail inFile\n");
        return NULL;
    }

    fseek(fptr, 0, SEEK_END);
    size_t count = ftell(fptr) / (sizeof(long));
    *size = count;
    rewind(fptr);
   
    
    long * arr = malloc(sizeof(long) * (*size));
    if(arr == NULL)
    {
        fprintf(stderr, "malloc fail\n");
        return NULL;
    }
    if(fread(arr, sizeof(long), *size, fptr) != *size)
    {
        fprintf(stderr, "fread fail\n");
        return NULL;
    }

    fclose(fptr);

    return arr;
}

int Array_Save_To_File(char *filename, long *array, int size)
{
    FILE *fptr = fopen(filename, "w");
    if(fptr == NULL)
    {
        fprintf(stderr, "fopen fail\n");
        return 0;
    }

    fwrite(array, size, sizeof(long), fptr);

    fclose(fptr);
    return size;
}

void Array_Shellsort(long *array, int size, long *n_comp)
{
    int sequence_size = 0;
    int temp;
    int i;
    int j;
    long *seq = Generate_2p3q_Seq(size, &sequence_size);

    //shell sort using insertion sort
    for(i = 1; i < size; i++)
    {
        for(j = i; j > 0; j--)
        {
            if(array[i - 1] > array[i])
            {
                temp = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temp;
            }
        }
    }
    free(seq);
}
