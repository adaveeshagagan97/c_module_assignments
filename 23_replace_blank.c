/*
   Title       : A program to replace each string of one or more blanks by a single blank
   Author      : Gagan A
   Date        : 05/07/2020
   Description : Input : Read a string of characters from the user
                 Output: Print the entered string with reduced space
*/

#include <stdio.h>

int main()
{
    /* Declare local variable */
    char option, c;

    do
    {
	/* Definining local variables */
	int flag = 0, count = 0;

	/* Read character until "\n" */
	printf("Enter the string with more spaces in between two words\n");
	while ((c = getchar()) != '\n')
	{
	    /* Print only once */
	    if (!count)
	    {
		printf("String with reduced space:\n");
		count = 1;
	    }

	    /* check whether 'c' is a not blank character */
	    if (c != ' ' && c != '\t')
	    {
		/* Print character */
		putchar(c);
		flag = 1;
	    }
	    /* check whether 'c' is a blank character */
	    else if ((c == ' ' && flag) || (c == '\t' && flag))
	    {
		/* Reduce multiple blanks into a single blank */
		putchar(' ');
		flag = 0;
	    }
	}

	/* Reinitialise */
	count = 0;

	/* check for continue */
	printf("\nDo you want to continue (y/n) : ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}
