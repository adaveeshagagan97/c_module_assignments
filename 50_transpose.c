/*
   Title       : A program to find the product of given matrix 
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read row, col and elements of a given matrix 
                 Output: To print the transpose and product of the given matrix
*/

#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
void print_matrix(int ** matrix, int row);

int main()
{
    /* Declare local variables */
    int  row, col, sum = 0, i, j, k;
    int * matrix_A, * transpose_A, * res_matrix;
    char option;

    do
    {
	/* Read rows and cols from the user */
	printf("Enter the number of rows: ");
	scanf("%d", &row);
	printf("Enter the number of columns: ");
	scanf("%d", &col);

	/* Check if (row != cols or size < 1) */
	if (row != col || (row < 1 || col < 1))
	{
	    (row < 1 && col < 1) ? printf("Error: size must be a positive digit\n") : printf("Error: row and column sizes must be identical\n");
	}
	else
	{
	    /* Dynamic memory allocation for row dimension of matrices */
	    int ** matrix_A = (int **) malloc(row * sizeof(int *));
	    int ** transpose_A = (int **) malloc(row * sizeof(int *));
	    int ** res_A = (int **) malloc(row * sizeof(int *));

	    /* Dynamic memory allocation for column dimension of matrices*/
	    for (i = 0; i < col; i++)
	    {
		matrix_A[i] = (int *) malloc(col * sizeof(int));
		transpose_A[i] = (int *) malloc(col * sizeof(int));
		res_A[i] = (int *) malloc(col * sizeof(int));
	    }

	    /* check whether memory is allocated or not */
	    if (matrix_A == NULL || transpose_A == NULL || res_matrix == NULL)
	    {
		printf("Error: Memory not allocated\n");
	    }
	    else
	    {
		/* To read the elements of matrix_A */
		printf("Enter values for %d x %d matrix:\n", row, col);
		for (i = 0; i < row; i++)
		{
		    for (j = 0; j < col; j++)
		    {
			scanf("%d", &matrix_A[i][j]);
		    }
		}

		/* To calculate the transpose of matrix_A */
		for (i = 0; i < row; i++)
		{
		    for (j = 0; j < col; j++)
		    {
			transpose_A[i][j] = matrix_A[j][i];
		    }
		}

		/* To print the transpose of matrix_A */
		printf("Transpose of given Matrix:\n");
		print_matrix(transpose_A, row);

		/* To calculate the product of two matrices */
		for (i = 0; i < row; i++)
		{
		    for (j = 0; j < col; j++)
		    {
			for (k = 0; k < col; k++)
			{
			    sum += matrix_A[i][k] * transpose_A[k][j];
			}
			res_A[i][j] = sum;
			sum = 0;
		    }
		}

		/* To print the resultant matrix */
		printf("Product of two matrices:\n"); 
		print_matrix(res_A, row);

		/* Free the allocated memory */
		free(res_A);
		free(transpose_A);
		free(matrix_A);
	    }
	}

	/* check for continue */
	printf("Do you want ro continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to print the elements of matrix */
void print_matrix(int ** matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
	for (int j = 0; j < row; j++)
	{
	    printf("%d\t", matrix[i][j]);
	}
	putchar('\n');
    }
}
