/* 
   Title       : A program to read n person names of maxlen 32, sort and print the names
   Author      : Gagan A
   Date        : 27/07/2020
   Description : Input : Read count, names from the user
                 Output: To print the sorted names 
*/

#include <stdio.h>
#include <stdlib.h>

/* Functions prototype */
void sort(char ** name, int count);
int my_strcmp(char * s1, char * s2);
void my_strcpy(char * dest, char * src);

int main()
{
    /* Declare local variables */
    char ** name, option;
    int count, i;

    do
    {
	/* Read count from the user */
	printf("Enter the number of names you want to sort : ");
	scanf("%d", &count);

	/* allocating memory dynamically for rows */
	name = (char **) malloc(count * sizeof(char*));

	/* Check whether memory is allocated or not */
	if (name == NULL)
	{
	    printf("Error: Memory not allocated\n");
	    return -1;
	}

	/* loop to read names */
	printf("Enter the %d names of length max 32 characters in each\n", count);
	for (i = 0; i < count; i++)
	{
	    printf("[%d] -> ", i);

	    /*allocating memory dynamically for columns */
	    name[i] = (char *) malloc(32 * sizeof(char));

	    /* check whether memory is allocated or not */
	    if (name[i] == NULL)
	    {
		printf("Error: Memory not allocated\n");
		return -1;
	    }

	    scanf("%s", name[i]);
	}

	/* Function call to sort the names */
	sort(name, count);

	/* Loop to print the sorted names */
	printf("The sorted names are:\n");
	for (i = 0; i < count; i++)
	{
	    printf("%s\n", name[i]);
	}

	/* Free the allocated memory */
	free(name);

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to sort the names in an array */
void sort(char ** name, int count)
{
    int i, j;
    char * temp = (char *) malloc(32 * sizeof(char));

    /* Buuble sort technique to sort the names */
    for (i = 0; i < count - 1; i++)
    {
	for (j = 0; j < count - i - 1; j++)
	{
	    if (my_strcmp(name[j], name[j + 1]) > 0)
	    {
		my_strcpy(temp, name[j]);
		my_strcpy(name[j], name[j + 1]);
		my_strcpy(name[j + 1], temp);
	    }
	}
    }
}

/* Function body to compare two strings */
int my_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2)
    {
	if (*s1 == '\0' || *s2 == '\0')
	    break;
	s1++;
	s2++;
    }

    return (*s1 == '\0' && *s2 == '\0') ? 0 : (*s1 - *s2);
}

/* Function body to copy a string */
void my_strcpy(char * dest, char * src)
{
    while (*dest++ = *src++);
}
