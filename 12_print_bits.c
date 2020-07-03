/*
   Title       : A program to print bits of signed and unsigned types for given number and check for 2's complement
   Author      : Gagan A
   Date        : 11/06/2020
   Description : Input : Read a number from the user
                 Output: Print the number and its 2's complement in binary representation
*/

#include <stdio.h>

int main()
{
    /* Declaring local variables */
    int num, max, bit, mask, i;
    char option;

    do
    {
	/* Declaring and initialising max to 1 */
	int max = 1;

	/* To calculate max range (2^20) */
	for ( i = 1; i <= 20; i++ )
	{
	    max = max * 2;
	}
	
	/* Read number from the user */
	printf("Enter the number: ");
	scanf("%d", &num);
	
	/* Number greater than or equal to range is INVALID */
	if ( num >= max )
	{
	    printf("Number out of range\n");
	}
	else
	{
	    /* To print + for positive num */
	    (num > 0) ? printf("+%d -> ", num) : printf("%d -> ", num);

	    /* Print the 32 bit binary representation of num and -num */
	    for ( i = 31; i >= 0; i-- )
	    {
		/* masking */
		mask = 1 << i;
		/* To get MSB */
		bit = mask & num;
		/* Print bits */
		bit == 0 ? printf("0") : printf("1");
	    }
	    printf("\n");

	    /* To print + for positive num */
	    (num > 0) ? printf("%d -> ", (num * -1)) : printf("+%d -> ", (num * -1));

	    /* Print the 32 bit representation of num and -num */
	    for ( i = 31; i >= 0; i-- )
	    {
		/* Masking */
		mask = 1 << i;
		/* To get MSB */
		bit = mask & (num * -1);
		/* Print bits */
		bit == 0 ? printf("0") : printf("1");
	    }
	    printf("\n");
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);
    
    } while ( option == 'y');
    
    return 0;
}






