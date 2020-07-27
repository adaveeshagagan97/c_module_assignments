/*
   Title       : A program to print all possible combinations of a string
   Author      : Gagan A
   Date        : 23/07/2020
   Description : Input : Read a string from the user
                 Output: To print all the possible combinations of a string
*/

#include <stdio.h>

/* Functions prototype */
int my_strlen(char * str);
void string_combinations(char * str, int first, int last);
void swap(char * x, char * y);

int main()
{
    /* Declare local variables */
    char str[20], option;
    int str_len;

    do
    {
	/* Read a string from the user */
	printf("Enter a string: ");
	scanf("%s", str);

	/* Calling my_strlen function to calculate and store length of the string */
	str_len = my_strlen(str);

	/* Function call to print all possible combinations in a string */
	string_combinations(str, 0, str_len - 1);

	/* Check for continue */
	printf("Do you want to continue (y/n) : ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to calculate length of the string */
int my_strlen(char * str)
{
    char *p = str;
    while (*++str);
    return str - p;
}

/* Function body to print all combinations of a string */
void string_combinations(char * str, int first, int last)
{
    /* Loop to check for repetitive characters */
    for (int i = 0; str[i]; i++)
    {
	for (int j = i; str[j]; j++)
	{
	    if (str[i] == str[j+1])
	    {
		printf("Error: please enter distinct characters\n");
		return;
	    }
	}
    }

    /* Base condition */
    if (first == last)
    {
	printf("%s\n", str);
    }
    else
    {
	/* Loop to check for all possible combinations of a string */
	for (int j = first; j <= last; j++)
	{
	    swap((str + first), (str + j));
	    string_combinations(str, first + 1, last);
	    swap((str + first), (str + j));
	}
    }
}

/* Function body to swap characters of a string */
void swap(char * x, char * y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
