/*
   Title       : A program to find average of numbers by taking input in 3 different ways
   Author      : Gagan A
   Date        : 16/08/2020
   Description : Input : Read choice from the user
                 Output: Print average of entered numbers wrt choice made
*/

#include <stdio.h>
#include <stdlib.h>

/* Functions prototype */
int my_atoi(char *myInput);
int my_isdigit(int ch); 
char * my_strtok(char *str, char *delim);
int * create_delim(char *delim);
void my_strcpy(char * dest, char * src);
size_t my_strlen(char *str);

int main(int argc, char **argv, char **envp)
{
    /* Defining local variables */
    int a[25], num, choice, i, count = 0;
    char * token, *arr, option, str[2] = " ";
    float sum;

    do
    {
	/* Read choice from the user */
	printf("Select the method to calculate average:\n1. Scan from keyboard\n2. Proceed with provided command line arguments\n3. Proceed with environment variable arguments\nEnter your choice:  ");
	scanf("%d", &choice);

	/* Assign sum to zero */
	sum = 0;

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    /* I method */
	    case 1: 
		/* Read num from the user */
		printf("Enter the total number of integers: ");
		scanf("%d", &num);

		/* Loop to read elements and calculate sum of them */
		printf("Enter the elements: ");
		for (i = 0; i < num; i++)
		{
		    scanf("%d", &a[i]);
		    sum += a[i];
		}

		/* print the average */
		printf("The average of entered numbers: %g\n", (sum / num));
		break;

		/* II method */
	    case 2:
		/* check if argc <= 1 */
		if(argc <= 1)
		{
		    printf("Error: Enter appropriate number of arguments to calculate average through command line\n");
		}
		else
		{
		    /* Loop to calculate sum of command line arguments passed */
		    for(i = 1; i < argc; i++)
		    {
			sum += my_atoi(argv[i]);
		    }

		    /* Print the average */
		    printf("The average of entered numbers: %g\n", (sum / (argc - 1)));  
		}

		break;

		/* III method */
	    case 3:
		/* get the data from environment variable that is set */
		arr = getenv("arr");

		if (arr == NULL)
		{
		    printf("Error: From shell export a variable which contain numbers, export arr= 1 2 3 4 \n");
		}
		else
		{
		    /* get the first token */
		    token = my_strtok(arr, str);

		    /* walk through other tokens */
		    while( *token != '\0' )
		    {
			count++;
			/* convert the string to integer */
			a[count] = my_atoi(token);
			/* sum of the numbers */
			sum += a[count];
			/* Actual Numbers */
			token = my_strtok(NULL, str);
		    }

		    /* Print the average */
		    printf("The average of entered numbers : %g\n", sum/count);
		}

		break;

	    default:
		printf("Error: Invalid choice\n");
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to convert string to integer */
int my_atoi(char *myInput)
{
    int s = 1, intVal = 0, i = 0;

    /* check for boundary condition */
    if ( '\0' == *myInput )
    {
	return 0;
    }

    /* check for negative value */
    if ( myInput[0] == '-')
    {
	/* If first digit is -, let s = 1 and start i from next */
	s = -1;
	i++;
    }
    else if ( myInput[0] == '+')
    {
	/* If first digit is +, let s = 1 and start i from next */
	s = 1;
	i++;
    }
    /* check for each char */
    for (; myInput[i] != '\0' ; i++)
    {
	/* If it is not starting with a num */
	if (!my_isdigit(myInput[i]))
	{
	    break;
	}
	/* check if it is a number */
	if (my_isdigit(myInput[i]))
	{
	    /* update intVal by adding new value with 10* previous val - the ASCII value of 0 */
	    intVal = intVal*10 + myInput[i] - '0';
	}
	/* To check to break, as we only iterate till first word */
	if ((myInput[i] == ' ') || (myInput[i] == '\t') || (myInput[i] == '\n'))
	{
	    break;
	}
    }

    /* return the int value multiplied by the sign s */
    return (s * intVal);
}

/* Function body to check if character passed is digit or not */
int my_isdigit(int ch)
{
    return (ch >= 48 && ch <= 57) ? 1 : 0;
}


/* Function body of my_strok() */
char * my_strtok(char *str, char *delim)
{
    /* Declare static variable */    
    static char *last, *to_free;
    /* Define local variable */
    int *delimit = create_delim(delim);

    /* Logic to do strtok operation */
    if(!delimit)
    {
	if(to_free) 
	{
	    free(to_free);
	    to_free = NULL;
	}
	return NULL;
    }

    if(!delimit) 
    {
	return NULL;
    }

    if(str) 
    {
	last = (char*) malloc(my_strlen(str) + 1);
	if(!last)
	{
	    free(delimit);
	    delimit = NULL;
	    return NULL;
	}
	to_free = last;
	my_strcpy(last, str);
    }

    while((delimit[*last]) && (*last != '\0'))
	last++;

    str = last;

    if(*last == '\0')
    {
	free(delimit);
	delimit = NULL;
	free(to_free);
	to_free = NULL;
    }

    while ((*last != '\0') && (!delimit[*last])) 
	last++;

    *last = '\0';
    last++;

    if(delimit)
    {
	free(delimit);
	delimit = NULL;
    }

    return str;
}

/* Function body to allocate memory dynamically */
int * create_delim(char *delim)
{
    int *d = (int *)malloc(sizeof(int) * 256);

    for(int i = 0; i < my_strlen(delim); i++) 
	d[delim[i]] = 1;

    return d;
}

/* Function body to do string copy operation */
void my_strcpy(char * dest, char * src)
{
    while (*dest++ = *src++);
}

/* Function body to calculate string length */
size_t my_strlen(char *str)
{
    char *p = str;

    while (*str++);
    return str - p - 1;
}
