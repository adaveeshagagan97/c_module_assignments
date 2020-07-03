/* 
   Title       : A program to check whether a given number is even or odd using bitwise operators along with its sign
   Author      : Gagan A
   Date        : 04/06/2020
   Description : Input : Read the value of 'N' from the user
                 Output: TO print whether a given number is even or odd along with its sign
*/

#include <stdio.h>

int main()
{
    /* Declaring local variables */
    int num, shift, i;
    char option;

    /* Calculate number of bits to shift */
    shift = (sizeof(int) * 8) - 1;

    do
    {
	/*Declare and initialise temp to 1 */
	int temp = 1;

	/* Read the value of 'N' from the user */
	printf("Enter the value of 'N': ");
	scanf("%d", &num);
	
	/* Calculate the MAX limit (2^20) */
	for ( i = 1; i <= 20; i++ )
	{
	    temp = temp * 2;
       	}
	
	/* Number out of limit is INVALID */
	if ( num >= temp )
	{
	    printf("Number out of range\n");
	}
	/* when num = 0 */
	else if ( num == 0 )
	{
	    printf("%d is a neutral number. It is neither positive nor negative\n", num);
	}
	else
	{
	    /* RIGHT SHIFT num and if num = 0, then it is a positive number */
	    if ( (num >> shift) == 0 )
	    {
		/* when bitwise AND conditon between num and 1 is true, then it is odd */
		if ( num & 1 )
		{
		    printf("%d is a +ve odd number\n", num);
		}
		else
		{
		    printf("%d is a +ve even number\n", num);
		}
	    }
	    else
	    {
		/* when bitwise AND condition between num and 1 is true, then it is odd */
		if ( num & 1 )
		{
		    printf("%d is a -ve odd number\n", num);
		}
		else
		{
		    printf("%d is a -ve even number\n", num);
		}
	    }
	}
	
	/* check for cntinue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y');
    
    return 0;
}
