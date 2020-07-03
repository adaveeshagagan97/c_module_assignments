/* 
   Title       : A program to find factorial of a given number by calling main() recursively
   Author      : Gagan A
   Date        : 03/07/2020
   Description : Input : Read a number 'N' from the user
                 Output: Print the factorial of a given number
*/

#include <stdio.h>

int main()
{
    /* Declaring and initalizing storage class variables */
    static char option; 
    static long int temp, num, flag = 1, fact = 1;

    do
    {
	/* Read num, store it in a temp variable and make flag to 0 */ 
	if (flag)
	{
	    printf("Enter the value of N\t: ");
	    scanf("%ld", &num);
	    temp = num;
	    flag = 0;
	}

	/* Base Condition */
	if (num < 1)
	{
	    /* check if num < 0 and print the respective messages */
	    (num < 0) ? printf("Invalid Input\n") : printf("Factorial of '%ld' is\t: %ld\n", temp, fact);
	}
	/* recursive call of main() */
	else
	{
	    fact *= num--;
	    main();
	}

	/* Re-initialise */
	flag = 1;
	fact = 1;

	/* Check for continue */
	if (option != 'n')
	{
	    printf("Do you want to continue (y/n): ");
	    getchar();
	    scanf("%c", &option);
	}

    } while (option == 'y');
}
