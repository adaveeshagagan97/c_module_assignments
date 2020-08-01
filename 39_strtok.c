/*
   Title       : A program to impelement strtok function
   Author      : Gagan A
   Date        : 01/08/2020
   Description : Input : Read string1, string2 from the user  
                 Output: To print the tokens
*/

#include <stdio.h>
#include <stdlib.h>

/* Functions prototype */
char * my_strtok(char *str, char *delim);
int * create_delim(char *delim);
void my_strcpy(char * dest, char * src);
size_t my_strlen(char *str);

int main()
{
    /* Declare local variables */
    char str[100], del[100], option;

    do
    {
	/* Read string1, string2 from the user */
	printf("Enter string1: ");
	fgets(str, 100, stdin);
	printf("Enter string2: ");
	fgets(del, 100, stdin);

	/* Function call of my_strok */
	char *s = my_strtok(str, del);

	/* To print the tokens */
	printf("Tokens :\n");
	while(s) 
	{
	    printf("%s\n", s);
	    s = my_strtok(NULL, del);
	}

	/* Check for continue */
	printf("Do you want to continue (y/n): ");
	scanf("%c", &option);
	getchar();

    } while (option == 'y');

    return 0;
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
    {
	last++;
    }

    str = last;

    if(*last == '\0')
    {
	free(delimit);
	delimit = NULL;
	free(to_free);
	to_free = NULL;
	return NULL;
    }

    while ((*last != '\0') && (!delimit[*last])) 
    {
	last++;
    }

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
