/* 
   Title       : A program to count number of characters, words & lines entered through stdin buffer
   Author      : Gagan A
   Date        : 05/07/2020
   Description : Input : Read characters from user till EOF
                 Output: Print the character count, word count and line count respectively
*/

#include <stdio.h>

int main()
{
    /* Declare local variable */
    char option;

    do
    {
	/* Defining local variables */
	int c = 0, line_count = 0, word_count = 0, char_count = 0, flag = 0;

	/* Read character from user until EOF */
	while ((c = getchar()) != EOF)
	{
	    /* increment character count by 1 */
	    ++char_count;

	    /* when character is a new line */
	    if (c == '\n')
	    {
		/* increment line count by 1 */
		++line_count;
	    }

	    /* check whether character entered is blank/newline */
	    if (c == ' ' || c == '\n' || c == '\t')
	    {
		flag = 0;
	    }
	    /* increment word count by 1 when c = blank/newline only once until next blank/newline is read */
	    else if (flag == 0)
	    {
		++word_count;
		/* re-initialise */
		flag = 1;
	    }
	}

	printf("character count\t: %d\nLine count\t: %d\nWord count\t: %d\n", char_count, line_count, word_count);

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
}


