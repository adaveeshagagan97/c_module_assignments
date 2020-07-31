/*
   Title       : A program to implement my_printf() function
   Author      : Gagan A
   Date        : 31/07/2020
   Description : Input : Read number, char, string from the user
                 Output: Print the output using my_printf() function
*/

#include <stdio.h>
#include <stdarg.h>

/* Function prototype */
void my_printf(const char *format, ...);

int main()
{
    /* Declare local variables */
    char ch, str[100], option;
    int num;

    do
    {
	/* Read input from the user */
	my_printf("Enter a number, char, string: ");
	scanf("%d %c %s", &num, &ch, str);

	/* Function call */
	my_printf("Output: %d %c %s", num, ch, str);

	/* Check for continue */
	my_printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to implement my_printf() function */
void my_printf(const char *format, ...)
{
    int i = 0;
    char ch, * str, buffer[30] = {'\0'};
    const char *p = format;

    /* Declare a pointer */
    va_list ap;

    /* Initialize the pointer */
    va_start(ap, format);

    /* Loop to print the characters */
    while (*p)
    {
	/* check for '%' character */
	if (*p == '%')
	{
	    /* check for a character after '%' and do respective operations */
	    switch (*++p)
	    {
		/* char */
		case 'c':
		    ch = (char)va_arg(ap, int);
		    putchar(ch);
		    break;

		/* int */		    
		case 'd':
		    i = va_arg(ap, int);
		    sprintf(buffer, "%d", i);
		    fputs(buffer, stdout);
		    break;

		/* string */    
		case 's':
		    str = va_arg(ap, char *);
		    puts(str);
		    break;
	    }

	}
	else
	    putchar(*p);
	
	p++;
    }

    va_end(ap);
}
