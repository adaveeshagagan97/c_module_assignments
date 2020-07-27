/*
   Title       : A program to implement solution for tower of hanoi
   Author      : Gagan A
   Date        : 27/07/2020
   Description : Input : Read num of disks from the user
                 Output: To print the solution for tower of hanoi respectively
*/

#include <stdio.h>

/* Function prototype */
void toh(int num, char from, char aux, char to);

int main()
{
    /* Declare local variables */
    char option;
    int num;

    do
    {
	/* Read num of disks from the user */
	printf("Enter the number of disks: ");
	scanf("%d", &num);

	/* Check whether num < 1 if not => print error msg, else => Function call */
	(num < 1) ? printf("Error: Enter positive numbers only") : toh(num, 'A', 'C', 'B');

	/* Check for continue */
	printf("\n\nDo you want to continue (y/n) : ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to implement solution for tower of hanoi */
void toh(int num, char from, char aux, char to)
{
    /* Base condition */
    if (num <= 1)
    {
	printf("\nMake the legal move from %c to %c ", from, aux);
	return;
    }

    /* Recursive function call */
    toh(num - 1, from, to, aux);
    printf("\nMake the legal move from %c to %c ", from, aux);
    toh(num - 1, to, aux, from);
}
