/*
   Title       : A program to sort float array 'store' without modifying or copying 'store'
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read size and array elements from the user
                 Output: To print the sorted float array elements
*/

#include <stdio.h>
#include <stdlib.h>

/* Functions prototype */
void sort_float_numbers(float * store, int size);
void swap_generic(void * aptr, void * bptr, int size);

int main()
{
    /* Declare local variables */
    char option;
    int size, i, j;

    do
    {
	/* Read the size of an array from the user */
	printf("Enter the count of float elements need to store: ");
	scanf("%d", &size);

	/* Declaring pointer and allocating memory using Dynamic method */
	float * store = (float *) malloc(size * sizeof(float));

	/* Check whether memory is alloacted or not */
	if (store == NULL)
	{
	    printf("Error: Memory not allocated\n");
	}
	else
	{
	    /* Read elements of the array from the user */ 
	    for (i = 0; i < size; i++)
	    {
		printf("[%d] = ", i);
		scanf("%f", &store[i]);
	    }

	    /* Function call to sort float array */
	    sort_float_numbers(store, size);

	    /* Loop to print the elements of sorted array */
	    printf("After sorting: ");
	    for (i = 0; i < size; i++)
	    {
		printf("%g ", store[i]);
	    }
	}

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to sort float array */
void sort_float_numbers(float * store, int size)
{   
    for (int i = 0; i < size; i++)
    {
	for (int j = 0; j < size - i - 1; j++)
	{
	    if (store[j] > store[j + 1])
	    {
		swap_generic((store + j), (store + j + 1), sizeof(float));
	    }
	}
    }
}

/* Function body to swap two elements of any datatype */
void swap_generic(void * aptr, void * bptr, int size)
{    
    for (int i = 0; i < size; i++ )
    {
	char temp = * (char *) aptr;
	* (char *) aptr++ = * (char *) bptr;
	* (char *) bptr++ = temp;
    }
}
