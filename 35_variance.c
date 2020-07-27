/*
   Title       : A program to calculate variance using static arrays & dynamic arrays
   Author      : Gagan A
   Date        : 19/07/2020
   Description : Input : Read size and choice from the user
                 Output: To print variance by using either static or dynamic arrays wrt the choice made
*/
#include <stdio.h>
#include <stdlib.h>

/* Functions prototype */
float static_array(int size);
float dynamic_array(int size);
int read_elements(int * x, int size);
float sum_of_square(int * x, float mean, float sum, int size);

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Declare local variables */
	int size, choice;
	float sigma;

	/* Read size and choice from the user */
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	printf("Select the option\n1. Static array\n2. Dynamic array\nChoice: ");
	scanf("%d", &choice);

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    /* Calculating variance and printing it using Static Memory allocation of array */
	    case 1:
		sigma = static_array(size);
		printf("The variance of entered numbers is %g\n", sigma);
		break;

            /* Calculating variance and printing it using Dynamic Memory allocation of array */	
	    case 2:
		sigma = dynamic_array(size);
		printf("The variance of entered numbers is %g\n", sigma);
		break;

	    default:
		printf("Error: Invalid choice\n");
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to return calculated sigma value using static memory allocation */
float static_array(int size)
{
    int x[size];
    float mean, sum = 0;

    sum = read_elements(x, size);
    mean = ((float) sum) / size;
    sum = sum_of_square(x, mean, 0, size);

    return ((float) sum) / size;
}

/* Function body to return calculated sigma value using dynamic memory allocation */
float dynamic_array(int size)
{
    int * x = (int *) malloc (size * sizeof(int));
    float mean, sum = 0;

    sum = read_elements(x, size);
    mean = ((float) sum) / size;
    sum = sum_of_square(x, mean, 0, size);
    free(x);

    return ((float) sum) / size;
}

/* Function body to read and calculate the sum of array elements */
int read_elements(int * x, int size)
{
    int sum = 0;

    printf("Enter the %d elements :\n", size);
    for (int i = 0; i < size; i++)
    {
	printf("[%d] -> ", i);
	scanf("%d", (x+i));
	sum += x[i];
    }

    return sum;
}

/* Function body to calculate the sum of square of array elements */
float sum_of_square(int * x, float mean, float sum, int size)
{
    for (int i = 0; i < size; i++)
    {
	sum += (x[i] - mean) * (x[i] - mean);
    }

    return sum;
}
