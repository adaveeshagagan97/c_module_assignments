/*
   Title       : A program to generate n * n magic square (n is odd _ve no.)
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read a number from the user
                 Output: To print n * n magic square matrix
*/

#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
void magic_square(int size, int **ptr);

int main( )
{
    /* Declare local variables */
    char option;
    int size;

    do
    {
	/* Read a number from the user */
	printf("Enter a number: ");
	scanf("%d", &size);

	/* Dynamic memory allocation for magic square matrix */
	int **ptr = (int **) malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++)
	    ptr[i] = (int *) malloc(size * sizeof(int));

	/* Check whether size is a +ve odd number or not, if not +ve odd => print error, else =>  Function call */
	(size < 1) ? printf("Enter posiive odd numbers only\n") : ((!(size % 2)) ? printf("Enter odd numbers only\n") : magic_square(size, ptr)); 

	/* Free the allocated memory */
	free(ptr);

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to generate size * size magic square matrix*/
void magic_square(int size, int **ptr)
{
    /* Define local variables */
    int sqr = size * size;
    int i = 0, j = size / 2, k;

    for (k = 1; k <= sqr; ++k) 
    {
	ptr[i][j] = k;
	i--;
	j++;

	if (!(k % size)) 
	{ 
	    i += 2; 
	    --j; 
	}
	else 
	{
	    if (j == size) 
	    {
		j -= size;
	    }
	    else if (i < 0)
	    {
		i += size;
	    }
	}
    }

    /* Loop to print the elements of magic square matrix */
    for (i = 0; i < size; i++)
    {
	for (j = 0; j < size; j++)
	{
	    printf("%3d\t", ptr[i][j]);
	}
	printf("\n");
    }
}
