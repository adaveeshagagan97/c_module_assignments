/*
   Title       : A program to reverse a string using both recursive and iterative methods
   Author      : Gagan A
   Date        : 14/07/2020
   Description : Input : Read string and choice from the user
                 Output: To print the reversed string using the repective method according to the choice made
*/

#include <stdio.h>

/* Functions prototype */
void non_recur(char *str, size_t len);
void recur(char *first, char * last);
int my_strlen(char *str);

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Declaring local variables */
	char str[100];
	int choice, len;

	/* Read a string from the user */
	printf("Enter the string: ");
	fgets(str, 100, stdin);

	/* Calling function to calculate the length of the string and storing it */
	len = my_strlen(str);

	/* Read the choice from the user */
	printf("Select the choice\n1. Iterative_Method\n2. Recursive_Method\nChoice: ");
	scanf("%d", &choice);

	/* Do an operation wrt the choice */
	switch (choice)
	{
	    case 1 :
		/* Printing the reversed string using iterative technique */
		non_recur(str, len);
		printf("Reversed string is %s\n", str + 1);
		break;

	    case 2 :
		/* Printing the reversed string using recursion technique */
		recur(&str[0], &str[len - 2]);
		printf("Reversed string is %s", str);
		break;

	    default :
		printf("Error: Invalid option\n");
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}

/* Function body to reverse a string using iterative technique */
void non_recur(char *str, size_t len)
{
    int i = 0, j = len;
    char temp, *ptr = str + (len - 1);

    while (j-- > i++)
    {
	temp = *str;
	*str = *ptr;
	*ptr = temp;
	ptr--;
	str++;
    }
}

/* Function body to reverse a string using recursion technique */
void recur(char * first, char * last)
{
    /* Base condition */
    if (first > last)
    {
	return;
    }

    char tmp = *first;
    *first = *last;
    *last = tmp;

    /* Recursive function call */
    recur(++first, --last);
}

/* Function body to calculate the length of a string */
int my_strlen(char * str)
{
    char * p = str;
    while (*str++);
    return str - p - 1;
}
