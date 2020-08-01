/*
   Title       : A program to define a macro swap(t, x, y) that interchanges two arguments of type t
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read choice and two repsective type elements from the user
                 Output: To print the output of swapped numbers of datatype wrt the choice made by the user
*/

#include <stdio.h>

/* MACRO definition to swap two elements of any datatype */
#define SWAP(t, x, y)   \
{                       \
    t temp = x;         \
    x = y;              \
    y = temp;           \
}

int main()
{
    /* Declare local variables */
    char option, char1, char2;
    int num1, num2, choice;
    float numf_1, numf_2;
    double numd_1, numd_2;

    do
    {
	/* Read choice from the user */
	printf("Select the choice\n1. int\n2. char\n3. float\n4. double\nChoice : ");
	scanf("%d", &choice);

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    /* swap two INT values */
	    case 1:
		/* Read num1, num2 from the user */
		printf("Enter num1: ");
		scanf("%d", &num1);
		printf("Enter num2: ");
		scanf("%d", &num2);

		/* MACRO function call to swap */
		SWAP(int, num1, num2);
		printf("\nAfter swapping:\n\nnum1: %d\nnum2: %d\n", num1, num2);		
		break;

	    /* swap two Characters */
	    case 2:
		/* Read char1, char2 from the user */
		printf("Enter char1: ");
		getchar();
		scanf("%c", &char1);
		printf("Enter char2: ");
		getchar();
		scanf("%c", &char2);

		/* MACRO function call to swap */
		SWAP(char, char1, char2);
		printf("\nAfter swapping:\n\nchar1: %c\nchar2: %c\n", char1, char2);
		break;

            /* swap two FLOAT values */		
	    case 3:
		/* Read numf_1, numf_2 from the user */
		printf("Enter numf_1: ");
		scanf("%f", &numf_1);
		printf("Enter numf_2: ");
		scanf("%f", &numf_2);

		/* MACRO function call to swap */
		SWAP(float, numf_1, numf_2);
		printf("\nAfter swapping:\n\nnumf_1: %g\nnumf_2: %g\n", numf_1, numf_2);
		break;
            
	    /* swap two DOUBLE values*/
	    case 4:
		/* Read numd_1, numd_2 from the user */
		printf("Enter numd_1: ");
		scanf("%lf", &numd_1);
		printf("Enter numd_2: ");
		scanf("%lf", &numd_2);

		/* MACRO function call to swap */
		SWAP(double, numd_1, numd_2);
		printf("\nAfter swapping:\n\nnumd_1: %g\nnumd_2: %g\n", numd_1, numd_2);
		break;

	    default:
		printf("Error: Invalid choice\n");
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}
