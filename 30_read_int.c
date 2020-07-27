/*
   Title       : A program to read an tnteger using read_int function
   Author      : Gagan A
   Date        : 16/07/2020 
   Description : Input : Read characters from the user
                 Output: To print the integer out of read characters
*/

#include <stdio.h>

/* Function prototype */
void read_int(int * num);

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Define local variable */
	int num = 0;
	printf("Enter a number: ");

	/* Function call to read an integer */
	read_int(&num);
	printf("The number is %d\n", num);

	/* Check for continue */
	printf("Do you want to continue (y/n) : ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}

void read_int(int * num)
{
    /* Defining local variables */
    char ch;
    int flag = 1, sign = 1;

    /* Read character until \n is entered */
    while ((ch = getchar()) != '\n')
    {
	if (ch == '-' && flag)
	{
	    sign = -1;
	}
	else if ((ch < 48 || ch > 57) && flag && ch != '+')
	{
	    sign = 0;
	}

	if (ch >= 48 && ch <= 57)
	{
	    *num = (*num * 10) + ch - 48;
	    flag = 0;
	}
    }

    *num *= sign;
}
