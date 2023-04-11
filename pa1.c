#include "sequence.h"
#include "shell_array.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
    int arr_size = 0;
    long n_comp = 0;
    if(argc != 3)
    {
        fprintf(stderr, "expected input and output file names");
        return EXIT_FAILURE;
    }

    long *arr = Array_Load_From_File(argv[1], &arr_size);
    printf("\narr_size: %d\n", arr_size);
    printf("arr: ");
    for(int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    
    }
    printf("\nsorted: ");
    
    Array_Shellsort(arr, arr_size, &n_comp);
    for (int j = 0; j < arr_size; j++)
    {
        printf("%d, ", arr[j]);
    }
    fprintf(stdout, "\n%ld\n", n_comp);
    Array_Save_To_File(argv[2], arr, arr_size);

    free(arr);
    return EXIT_SUCCESS;
}
