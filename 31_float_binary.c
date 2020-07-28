/* 
   Title       : A program to print bits of float and double in IEEE format
   Author      : Gagan A
   Date        : 28/07/2020
   Description : Input : Read choice, float/double value from the user
                 Output: To prints bits in IEEE format of float/double wrt the choice made by the user
*/

#include <stdio.h>

/* Function body to return double in bits */
int float_bit_return(int num, int loc)
{
    return (num & 1 << loc) ? 1 : 0;
}

/* Function body to return float in bits */
int double_bit_return(long int num, int loc)
{
    return (num & 1L << loc) ? 1 : 0;
}

int main()
{
    /* Declare local variables */
    int i, choice, *num_f;
    float f_num;
    double d_num;
    long int * num_d;
    char option;

    do
    {
	/* Read choice from the user */
	printf("Enter the choice:\n1. float\n2. double\nChoice: ");
	scanf("%d", &choice);

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    case 1:
		/* Read float value from the user */
		printf("Enter the float value: ");
		scanf("%f", &f_num);

		/* Type casting */
		num_f = (int *)&f_num;

		/* Loop to print the bits of float in IEEE standard by calling function */
		printf("Sign\tMantissa\tExponent\n------------------------------------------------\n");
		for (i = (8 * sizeof(int)) - 1; i >= 0; i--)
		{
		    if (i == 30 || i == 22)
			printf("\t");
		    printf("%d", float_bit_return(*num_f, i));
		}
		break;

	    case 2:
		/* Read double value from the user */
		printf("Enter the double value: ");
		scanf("%lf", &d_num);

		/* Type casting */
		num_d = (long int *)&d_num;

		/* Loop to print the bits of double in IEEE standard by calling function */
		printf("Sign\tMantissa   \tExponent\n----------------------------------------------------------------------------\n");
		for (i = (8 * sizeof(long int)) - 1; i >= 0; i--)
		{
		    if (i == 62 || i == 51)
			printf("\t");

		    printf("%d", double_bit_return(*num_d, i));
		}
		break;

	    default:
		printf("Error: Invalid choice");
	}

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}
