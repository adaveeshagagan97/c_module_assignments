/*
   Title       : A program to check your processor endianess
   Author      : Gagan A 
   Date        : 31/07/2020
   Description : Input : Read a number from the user
                 Output: Print respective processor endianess
*/

#include <stdio.h>

int main()
{
    /* Declare local variables */
    char option;
    int num;

    do
    {
	/* Defining local variable */
	char * cptr = (char *)&num;

	/* Read a number from the user */
	printf("Enter a number: ");
	scanf("%x", &num);

	/* check for liitle or big endian system */
	((num % 100) == *cptr) ? printf("Little Endian System\n") : printf("Big Endian System\n");

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

