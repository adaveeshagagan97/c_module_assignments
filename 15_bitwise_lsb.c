/*
   Title       : A program to put (b-a+1) lsb's of n into i[b:a]
   Author      : Gagan A
   Date        : 16/06/2020
   Description : Input : Read n, i, a, b from the user
                 Output: To print the new value of i in binary form
 */

#include <stdio.h>

/* Function declaration */
int max_range(void);
int set_nbits_from_pos(int num, int n, int pos, int val);
int print_bits(int num);

int main()
{
    /* Declaring local variables */
    int n, a, b, i, result;
    char option;

    do
    {
	/* Read number n from user */
	printf("Enter number n: ");
	scanf("%d", &n);

	/* Error Check for limit */
	if (n >= max_range())
	{
	    printf("Error: n is Invalid Number. Retry\n");
	}
	else
	{	    
	    /* Read number i from user */
	    printf("Enter number i: ");
	    scanf("%d", &i);

	    /* Error check for limit */
	    if (i >= max_range())
	    {
		printf("Error: i is Invalid Number. Retry\n");
	    }
	    else
	    {	    
		/* Read number a from user(0 < a < 31) */
		printf("Enter number a: ");
		scanf("%d", &a);

		/* Do error checking */
		if ((a < 0) || (a > 31))
		{
		    printf("Error: a is out of range\n");
		}
		else
		{
		    /* Read number b from user(a < b < 31) */
		    printf("Enter number b: ");
		    scanf("%d", &b);

		    /* Do error checking */
		    if ((b <= a) || (b >= 31))
		    {
			printf("Error: b is out of range\n");
		    }
		    else
		    {
			/* To print binary representation of n by function call */
			printf("The binary form of 'n' : ");
			print_bits(n);
			printf("\n");

			/* To print binary representation of i by function call*/
			printf("The binary form of 'i' : ");
			print_bits(i);
			printf("\n");

			/* To put (b-a+1) lsbs pf n into i[b:a] */
			result = set_nbits_from_pos(i, (b - a + 1), b, n);

			/* To print binary representation of new 'i' by function call */
			printf("The new binary value of 'i' : ");
			print_bits(result);
			printf("\n");

			/* Print the new value of i in decimal system */
			printf("The decimal value of new 'i' = %d\n", result);
		    }
		}
	    }
	}

	/* Prompt for continue option */
	printf("Do you want to continue (y/n): ");
	scanf("\n%c", &option);

    } while ( option == 'y');

    return 0;
}

/* function definition for max_range */
int max_range(void)
{
    int i, pro = 1;

    for ( i = 1; i <= 20; i++)
    {
	pro *= 2;
    }
    
    return pro;
}

/* function definition to replace (b-a+1) lsbs of n into i */
int set_nbits_from_pos(int num, int n, int pos, int val)
{
    return ((val & ((1 << n) - 1)) << pos - n + 1) | (num & ~((~(~0 << n)) << pos - n + 1));
}

/* function definition to print values in binary format */
int print_bits(int num)
{
    for (int j = 31; j >= 0; j-- )
    {
       	((1 << j) & num) ? printf("1") : printf("0");
    }
}

