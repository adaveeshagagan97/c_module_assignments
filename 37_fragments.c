/*
   Title       : A program to implement fragments using array of pointer (First Static Second Dynamic)
   Author      : Gagan A
   Date        : 16/08/2020
   Description : Input : Read row, no of cols, elements of each row from the user 
                 Output: To print the sorted array elements with its average at its end 
*/

#include<stdio.h>
#include<stdlib.h>

/* Functions prototype */
void fragments(int row, float **arr, int *tmp, float *savg);
void display(int row, float **arr, int *tmp);

int main()
{
    /* Declare local variables */
    char option;
    int row, col, i, j, tmp[20];
    float sum, avg;

    do
    {
	/* defining local variables */
	sum = avg = 0;

	/* Read row value from the user */
	printf("Enter no of row : ");
	scanf("%d",&row);

	/* Declare a 2D-array where its row is static and column is dynamic */
	float *arr[row];

	/* Loop tp read no of columns for each row */
	for (i = 0; i < row; i++)
	{
	    printf("Enter no of coloum in row[%d] : ", i);
	    scanf("%d", &col);

	    tmp[i] = col + 1;

	    /* Dynamic memory allocation for columns */
	    arr[i] = calloc (col + 1, sizeof(float));
	}

	/* Declare a local array of size row */
	float savg[row];

	/* Loop to read elements for each row and calculate average of each row */
	for (i = 0; i < row; i++)
	{
	    printf("Enter the elements for row[%d] : ", i);

	    for (sum = avg = 0, j = 0; j < tmp[i] - 1; j++)
	    {
		scanf(" %f", &arr[i][j]);
		sum = sum + arr[i][j];
	    }
	    avg = sum/(tmp[i] - 1);

	    /* Store the average calculated of each row at its end */
	    arr[i][j] = avg;
	    savg[i] = avg;
	}

	/* Print array elements before sorting by calling function */
	printf("\nBefore Sorting output : \n");
	display(row, arr, tmp);

	/* Function call */
	fragments(row, arr, tmp, savg);

	/* print the array elements after sorting and calculating average */
	printf("\nAfter Sorting output : \n");
	display(row, arr, tmp);
	
	/* Loop to free allocated memory */
	for (int i = 0; i < row; i++)
	    free(arr[i]);

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to implement fragments using array of pointers */
void fragments(int row, float **arr, int *tmp, float *savg) 
{
    /* Declare local variables */
    float *ptr, swp;
    int i, j, p;

    /* Loop  to compare average and sort the row based on its average */
    for (i = 0; i < row - 1; i++)
    {
	for (j = (i + 1); j < row; j++)
	{
	    /* compare average of each row */
	    if (savg[i] > savg[j])
	    {
		/* Swap an address of the respective row */
		ptr = arr[i];
		arr[i] = arr[j];
		arr[j] = ptr;

		/* Swap the average */
		swp = savg[i];
		savg[i] = savg[j];
		savg[j] = swp;

		/* Swap respective columns */
		p = tmp[i];
		tmp[i] = tmp[j];
		tmp[j] = p;
	    }
	}
    }
}

/* Function body to display array elements */
void display(int row, float **arr, int *tmp)
{
    /* Declare local variables */
    int i, j;

    /* Loop to print array elements */
    printf("\n");
    for (i = 0; i < row; i++)
    {
	for (j = 0; j < tmp[i]; j++)
	{
	    printf("%.3g ",arr[i][j]);
	}
	printf("\n");
    }
}
