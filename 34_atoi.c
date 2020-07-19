/*
   Title       : A program to implement getword, atoi, itoa functions
   Author      : Gagan A
   Date        : 19/07/2020
   Description : Input : Read choice, string from the user
                 Output: Print respective output according to the choice made
*/

#include <stdio.h>

/* Functions prototype */
int getword(char *word);
int my_atoi(const char *s);
int my_itoa(int n, char *s);
int reverse_string(char * s, int str_len);

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Declare local variables */
	char str[40];
	int word_length, value, num, str_len, choice, i;

	/* Read choice from the user */
	printf("Select the option\n1. getword\n2. atoi\n3. itoa\nChoice : ");
	scanf("%d", &choice);

	/* Do respective operation wrt the choice made by the user */
	switch (choice)
	{
	    /* getword */
	    case 1:
		/* Read string from the user */
		printf("Enter a word: ");
		getchar();
		fgets(str, 40, stdin);

		/* Function call to calculate word_length*/
		word_length = getword(str);

		/* loop to print the word */
		printf("You entered ");
		for (i = 0; i < word_length; i++)
		{
		    printf("%c", str[i]);
		}
		printf("\n");
		break;
	    
            /* atoi */
	    case 2:
		/* Read a numeric string from the user */
		printf("Enter a numeric string: ");
		getchar();
		fgets(str, 40, stdin);

		/* Function call to calculate value */
		value = my_atoi(str);
		/* Printing the integer from a string */
		printf("String to integer is %d\n", value);
	
		break;

            /* itoa */		
	    case 3:
		/* Read num from the user */
		printf("Enter a numeric string: ");
		scanf("%d", &num);

		/* check if num is positive */
		if (num > 0)
		{
		    str_len = my_itoa(num, str);
		    reverse_string(str, str_len);	    
		    printf("Integer to string is %s\n", str);
		}
		/* Check if num is negative */
		else if (num < 0)
		{
		    str_len = my_itoa((num * -1), str);
		    reverse_string(str, str_len);
		    printf("Integer to string is -%s\n", str);
		}
		/* Check if num = 0 */
		else if (num == 0)
		{
		    printf("Integer to sring is %d\n", num);
		}
		else
		{
		    printf("Invalid numeric string\n");
		}

		break;
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}    

/* Function body to implement getword function */
int getword(char *word)
{
    int count = 0;

    while (*word != '\n')
    {
	if (*word == ' ')
	{
	    break;
	}
	else
	{
	    count++;
	    word++;
	}
    }

    return count;
}

/* Function body to implement atoi function */
int my_atoi(const char *s)
{
    int res = 0, flag = 0;

    while (*s != '\n')
    {
	if (*s == '-')
	{
	    flag = -1;
	    s++;

	    if(*s < '0' || *s > '9')
	    {
		flag = 0;
		break;
	    }
	}
	else if(*s >= '0' && *s <= '9')
	{
	    res = (res * 10) + *s - '0';
	    s++;
	}
	else
	{
	    flag = 1;
	    s++;

	    if (*s < '0' || *s > '9')
	    {
		flag = 0;
		break;
	    }
	}
    }

    return (flag == -1) ? (res * -1) : res;
}

/* Function body to implement itoa function */
int my_itoa(int n, char *s)
{
    int count = 0, digit = 0;

    while (n != 0)
    {
	digit = n % 10;
	*s = (((char)digit) + 48);
	n /= 10;
	count++;
	s++;
    }

    return count;
}

/* Function body to reverse a string */
int reverse_string(char * s, int str_len)
{
    int i = 0, j = str_len - 1, temp;

    while (j > i)
    {
	temp = s[j];
	s[j] = s[i];
	s[i] = temp;
	j--;
	i++;
    }
    s[str_len] = '\0';
}
