/*
   Title       : A program to perform post and pre increment using functions by passing int pointer as their parameter
   Author      : Gagan A
   Date        : 02/07/2020
   Description : Input : Read a number 'N' and choice from the user
                 Output: Print post/pre incremented values of 'N' wrt the choice made by the user
*/

#include <stdio.h>

/* Function prototype */
int pre_increment(int * num);
int post_increment(int * num);

int main()
{
    /* Declaring local variables */
    int i, num, choice;
    char option;

    do
    {
	/* Read N and choice from the user */
	printf("Enter the value of N: ");
	scanf("%d", &num);
	printf("Enter the operation: \n1. Pre-Increment\n2. Post-Increment\nChoice: ");
	scanf("%d", &choice);

	/* Do respective operation wrt the choice made by the user */
	switch(choice)
	{
	    case 1:
		/* Function call to perform pre-increment operation */
		i = pre_increment(&num);
		printf("After pre increment i = %d, num = %d\n", i, num);
		break;

	    case 2:
		/* Function call to perform post-increment operation */
		i = post_increment(&num);
		printf("After post increment i = %d, num = %d\n", i, num);
		break;

	    default:
		printf("Error: Invalid choice\n");
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while(option == 'y');

    return 0;
}

/* Pre_increment function body */
int pre_increment(int * num)
{
    int pre;
    pre = *num;
    *num = pre + 1;
    return *num;
}

/* Post_increment function body */
int post_increment(int * num)
{
    int post;
    post = *num;
    *num = post + 1;
    return post;
}
