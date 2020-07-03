/*
   Title       : A program to find the median of two unsorted arrays
   Author      : Gagan A
   Date        : 12/06/2020
   Description : Input : Read sizes and elements of two arrays from the user
                 Output: To print the median of two unsorted arrays
*/

#include <stdio.h>

int main()
{
    /* Declare local varibales */
    int  i, j, temp, num_a, num_b;
    float  median_a, median_b, avg;
    char option;

    do
    { 
	/* Read the size of array_a from the user */
	printf("Enter the 'n' value for Array A: ");
	scanf("%d", &num_a);

	/* size of array_a out of range is invalid */
	if ( (num_a >= 10) || (num_a <= 0) )
	{
	    printf("Number out of range, 0 < N < 10\n");
	}
	else
	{
	    /* Declare array_a */
	    int array_a[num_a];

	    /* Read the elements of array_a from the user */
	    printf("Enter the elements one by one for Array A: ");
	    for ( i = 0; i < num_a; i++ )
	    {
		scanf("%d", &array_a[i]);
	    }

	    /* Read the size of array_b from the user */
	    printf("Enter the 'n' value for Array B: ");
	    scanf("%d", &num_b);

	    /* size of array_b out of range is invalid */
	    if ( (num_b >= 10) || (num_b <= 0) )
	    {
		printf("Number out of range, 0 < N < 10\n");
	    }
	    else
	    {
		/* Declare array_b */
		int array_b[num_b];

		/* Read the elements of array_b from the user */
		printf("Enter the elements one by one for Array B: ");
		for ( i = 0; i < num_b; i++ )
		{
		    scanf("%d", &array_b[i]);
		}

		/* To sort array_a in ascending order */
		for ( i = 0; i < num_a - 1; i++ )
		{
		    for ( j = 0; j < (num_a - 1 - i); j++ )
		    {
			if ( array_a[j] > array_a[j+1] )
			{
			    /* Swap */
			    temp = array_a[j];
			    array_a[j] = array_a[j+1];
			    array_a[j+1] = temp;
			}
		    }
		}

		/* To sort array_b in ascending order */
		for ( i = 0; i < num_b - 1; i++ )
		{
		    for ( j = 0; j < (num_b - 1 - i); j++ )
		    {
			if ( array_b[j] > array_b[j+1] )
			{
			    /* Swap */
			    temp = array_b[j];
			    array_b[j] = array_b[j+1];
			    array_b[j+1] = temp;
			}
		    }
		}

		/* To find median of array_a */
		(num_a % 2) == 0 ? (median_a =((float) (array_a[num_a/2] + array_a[(num_a-1)/2]))/2) : (median_a = array_a[num_a/2]) ;

		/* To find median of array_b */
		(num_b % 2) == 0 ? (median_b = (((float) array_b[num_b/2] + array_b[(num_b-1)/2]))/2) : (median_b = array_b[num_b/2]) ;

		/* To find the median of both the arrays */
		avg =  ( median_a + median_b ) / 2;
		printf("The median of two unsorted arrays = %g\n", avg);
	    }
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y' );
    
    return 0;
}
