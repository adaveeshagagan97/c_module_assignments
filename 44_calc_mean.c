/*
   Title       : A program to implement calc_mean for all data types
   Author      : Gagan A
   Date        : 27/07/2020
   Description : Input : Read size and choice from the user
                 Output: To print the mean of array elements of respective data type
*/

#include <stdio.h>
#include <stdlib.h>

/* Functions Prototype */
void read_array(void * a, int size, int dt, char ** fmt);
double calc_mean(void * a, int size, int choice);

int main()
{
    /* Declare local variables */
    char option;
    int choice, size, i;

    do 
    {
	/* Define local variables */
	char type[4] = {sizeof(int), sizeof(short int), sizeof(float), sizeof(double)};
	char * dt = type;
	char *fmt[4] = {"%d", "%hd", "%f", "%lf"};

	/* Read size and choice from the user */
	printf("Enter the size of an array: ");
	scanf("%d", &size);
	printf("1. Int\n2. Short\n3. Float\n4. Double\nEnter the choice: ");
	scanf("%d", &choice);

	/* Dynamic memory allocation */
	char * a = malloc(size * dt[choice - 1]);

	/* check whether memory is allocated or not */
	if (a == NULL)
	{
	    printf("Error: Memory is not allocated\n");
	    return -1;
	}

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    /* read array elements of int type and print the mean of them */
	    case 1:
		read_array(a, size, *dt, fmt);
		printf("The mean value: %g\n", calc_mean(a, size, choice));	
		break;

            /* read array elements of short int type and print the mean of them */
	    case 2:
		read_array(a, size, *(dt + 1), fmt + 1);
		printf("The mean value: %g\n", calc_mean(a, size, choice));
		break;

	    /* read array elements of float type and print the mean of them */
	    case 3:
		read_array(a, size, *(dt + 2), fmt + 2);
		printf("The mean value: %g\n", calc_mean(a, size, choice));
		break;

	    /* read array elements of double type and print the mean of them */
	    case 4: 
		read_array(a, size, *(dt + 3), fmt + 3);
		printf("The mean value: %g\n", calc_mean(a, size, choice));
		break;

	    default:
		printf("Error: Invalid choice\n");
	}

	/* Free the allocated memory */
	free(a);

	/* Check for continue */ 
	printf("Do you want to continue (y/n) : ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to read array elements */
void read_array(void * a, int size, int dt, char **fmt)
{
    char * temp = (char *) a;

    for (int i = 0; i < size; i++, temp += dt)
    {
	printf("a[%d] -> ", i); 
	scanf(*fmt, temp);
    }
}

/* Function body to calculate mean */
double calc_mean(void * a, int size, int choice)
{
    double sum = 0;
    int i;

    for (i = 0; i < size; i++)
    {
	if (choice == 1)
	    sum += *((int *)a + i);
	else if (choice == 2)
	    sum += *((short int *)a + i);
	else if (choice == 3)
	    sum += *((float *)a + i);
	else 
	    sum += *((double *)a + i);
    }

    return (sum / size);
}
