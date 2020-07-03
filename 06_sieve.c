/*
   Title       : A program to print all primes smaller than or equal to n using Sieve of Eratosthenes method
   Author      : Gagan A
   Date        : 12/06/2020
   Description : Input : Read the value of 'n' from the user
                 Output: To print the primes less than or equal to 'n'
*/

#include <stdio.h>

int main()
{
    /* Declare variable option */
    char option;

    do
    {
	/* Declare and intialise local variables */
	int num, i, j, max = 1;

	/* Read the value of 'n' from the user */
	printf("Enter the value of 'n': ");
	scanf("%d", &num);

	/* Declaring array of numbers */
	int array[num];

	/* To calculate the max range (2^20) */
	for ( i = 1; i <= 20; i++ )
	{
	    max = max * 2;
	}

	/* number >= max is out of range */
	if ( num >= max )
	{
	    printf("Number out of range\n");
	}
	else
	{
	    /* number <= 2 is an invalid entry */
	    if ( num <= 2 )
	    {
		printf("Invalid input\n");
	    }
	    else
	    {
		/* To populate array with natural numbers */
		for ( i = 2; i <= num; i++ )
		{
		    array[i] = i;
		}

		/* To replace multiples upto sqrt(num) with zeros */
		for ( i = 2; (i * i) <= num; i++ )
		{
		    if ( array[i] != 0 )
		    {
			for ( j = 2; j < num; j++ )
			{
			    if ( array[i]*j > num )
			    {
				break;
			    }
			    else
			    {
				/* Replacing with zeros */
				array[array[i]*j] = 0;
			    }
			}
		    }
		}

		/* To print the prime numbers <= num */
		printf("The prime numbers less than %d are: 2", num);
		for ( i = 3; i <= num; i++ )
		{
		    /* To print non zero elements */
		    if ( array[i] != 0 )
		    {
			printf(", %d", array[i]);
		    }
		}
		/* To print a new line */
		printf("\n");
	    }
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y' );

    return 0;
}
