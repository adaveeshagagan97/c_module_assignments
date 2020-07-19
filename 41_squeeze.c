/*
   Title       : A program to implement squeeze(s1, s2)
   Author      : Gagan A
   Date        : 15/07/2020
   Description : Input : Read s1, s2 from the user
                 Output: To print s1 after performing squeeze operation
*/

#include <stdio.h>

/* Function prototype */
void squeeze(char * str1, char * str2);

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Declare str1, str2 */
	char str1[100], str2[100];

	/* Read s1 and s2 from the user */
	printf("Enter s1: ");
	fgets(str1, 100, stdin);
	printf("Enter s2: ");
	fgets(str2, 100, stdin);

	/* Function call to perform squeeze operation */
	squeeze(str1, str2);

	/* Printing s1 after performing squeeze operation */
	printf("After squeeze s1: %s\n", str1);

	/* Check for continue */
	printf("Do you want to continue (y/n) : ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}

/* Function body to perform squeeze operation */
void squeeze(char * str1, char * str2)
{
    int i, j, k;

    for (i = 0; str1[i]; i++)
    {
	for (j = 0; str2[j]; j++)
	{
	    /* if equal, initialise that element to 0 */
	    if (str1[i] == str2[j])
	    {
		str1[i] = '0';
	    }
	}
    }

    /* Loop to delete zeros in str1 */
    for (i = j = 0; str1[i]; i++)
    {
	if (str1[i] != '0')
	{
	    str1[j++] = str1[i];
	}
    }
    str1[j] = '\0';
}

