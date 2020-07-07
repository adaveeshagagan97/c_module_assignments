/*
   Title       : A program to generate fibonacci numbers <= 'n' using recursions
   Author      : Gagan A
   Date        : 07/07/2020
   Description : Input : Read the value of N from the user
                 Output: Print fibonacci numbers <= 'n' 
*/

#include <stdio.h>

/* Defining global variables */
static int next, first, second = 1;

/* Function prototype */
void fib_pos(int num);
void fib_neg(int num);

int main()
{
    /* Declare local variables */
    char option;
    int num;

    do
    {
	/* Read number from the user */
	printf("Enter the value of N: ");
	scanf("%d", &num);

	/* check whether num is positive or negative and call function wrt it */
	printf("Fibonacci series using recursive functions is\n");
	(num < 0) ? fib_neg(num) : fib_pos(num);
	
	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

	/* check whether option = 'y' */
	if (option == 'y')
	{
	    /* Re-initialise */
	    next = first = 0;
	    second = 1;
	}

    } while (option == 'y');

    return 0;
}

/* Function body to print +ve fibonacci series using recursion */
void fib_pos(int num)
{
    /* Base condition */
    while (first <= num)
    {
	printf("%d ", first);
	next = first;
	first += second;
	second = next;

	/* Recursive function call */
	fib_pos(num);
    }
}

/* Function body to print -ve fibonacci series using recursion */ 
void fib_neg(int num)
{
    /* Base condition */
    printf("%d ", first);
    while (first > (num + 1) && first < (num * (-1)))  
    {
	next = first - second;
	first = second;
	second = next;

	/* Recursive function call */
	fib_neg(num);
    }
}

