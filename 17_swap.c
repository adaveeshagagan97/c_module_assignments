/*
   Title       : A program to swap two variables by using pass by reference method
   Author      : Gagan A
   Date        : 02/07/2020
   Description : Input : Read N1, N2 from the user
              	 Output: Print N1, N2 after swapping is performed
*/

#include <stdio.h>

/* Swap function prototype */
void swap(int * num1, int * num2);

int main()
{
    /* Declaring local variables */
    int num1, num2;
    char option;

    do
    {
	/* Read N1 and N2 from the user */
	printf("Enter N1: ");
	scanf("%d", &num1);
	printf("Enter N2: ");
	scanf("%d", &num2);

	/* Call swap function to perform swapping */
	swap(&num1, &num2);

	/* Print the values of N1 and N2 after swapping is performed */
	printf("After swapping,\nN1 = %d\nN2 = %d\n", num1, num2);
        
	/* Check for continue */
	printf("Do you want to continue (y/n): ");
        getchar();
	scanf("%c", &option);

    } while (option == 'y'); 

    return 0;
}

/* Swap function body */
void swap(int * num1, int * num2)
{
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}
