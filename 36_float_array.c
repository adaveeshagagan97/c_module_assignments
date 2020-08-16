/*
   Title       : A program to sort float array 'store' without modifying or copying 'store'
   Author      : Gagan A
   Date        : 16/08/2020
   Description : Input : Read size and array elements from the user
                 Output: To print the sorted float array elements
*/

#include <stdio.h>
#include <stdlib.h>

/* Function prototype */
void sort(float * ptr, int num);

int main()
{
    /* Declare local variables */
    char option;
    int i, num;

    do
    {
	/* Read the size of the array from the user */
	printf("Enter the count of float elements need to store: ");
	scanf("%d", &num);

	/* Declare local float array */
	float store[num];

	/* Read array elements from the user */
	printf("Enter the elements:\n");
	for (i = 0; i < num; i++)
	{
	    printf("[%d] = ", i);
	    scanf("%f", &store[i]);
	}

	/* Function call to sort the array elements */
	sort(store, num);

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to sort the array elements */
void sort(float * ptr, int num)
{
    /* Define local variables */
    float min = *ptr, max = *ptr, temp = 0;
    int i = 0, flag = 0;

    /* Loop to find min and max elements in the array */
    for (; i < num; i++)
    {
	if (ptr[i] < min)
	    min = ptr[i];

	if (ptr[i] > max)
	    max = ptr[i];
    }

    printf("After sorting: ");

    /* Loop to print sorted array elements */
    do
    {
	/* check if temp = max, if so then assign flag to 1 */
	if (temp == max)
	    flag = 1;

	/* Loop to print array elements */
	for (i = 0; i < num; i++)
	{
	    if (ptr[i] == min)
		printf("%g ", min);
	}
	temp = max;

	/* Loop to find the next min element */
	for (i = 0; i < num; i++)
	{
	    if (ptr[i] > min && ptr[i] < temp)
		temp = ptr[i];
	}
	min = temp;

    } while (flag == 0);
}


