#include <stdio.h>

/* Function definition */
int my_isalpha(int ch);
int my_isalnum(int ch);
int my_isascii(int ch);
int my_isblank(int ch);

int main()
{
    char option, ch;
    int choice;
    
    do
    {
	printf("Enter a ch: ");
	ch = getc(stdin);
	printf("Select any option:\n1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\nEnter your choice: ");
	scanf("%d", &choice);

	switch ( choice )
	{
	    case 1 : 
		my_isalpha(ch) ? printf("The ch '%c' is an alpha ch\n", ch) : printf("The ch '%c' is not an alpha ch\n", ch);
		break;

	    case 2 :
		my_isalnum(ch) ? printf("The ch '%c' is an alnum ch\n", ch) : printf("The ch '%c' is not an alnum ch\n", ch);
		break;

	    case 3 :
		my_isascii(ch) ? printf("The ch '%c' is an ascii ch\n", ch) : printf("The ch '%c' is not an ascii ch\n", ch);
		break;

	    case 4 :
		my_isblank(ch) ? printf("The ch is a blank ch\n") : printf("The ch is not a blank ch\n");
		break;

	    default :
		printf("Invalid option\n");
	}

	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y');

    return 0;
}

int my_isalpha(int ch)
{
    return (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) ? 1 : 0);
}

int my_isalnum(int ch)
{
    return (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)) ? 1 : 0);
}

int my_isascii(int ch)
{
    return ((ch > 32 && ch < 127) ? 1 : 0);
} 

int my_isblank(int ch)
{
    return ((ch == 9 || ch == 10 || ch == 32) ? 1 : 0);
}

