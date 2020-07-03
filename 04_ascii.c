/*
   Title       : A program to print all ascii characters
   Author      : Gagan A
   Date        : 31/05/2020
   Description : Input : None
                 Output: To print all ascii characters
*/

#include <stdio.h>

int main()
{
    //Declaring local variable
    int i;

    //Print all ASCII characters
    printf("Dec \t Oct \t Hex \t Ascii\n");
    printf("--- \t --- \t --- \t -----\n");

    //check the number is perfect number or not and print it
    for ( i = 0; i <= 127; i++)
    {
	if ( i <= 32 || i == 127 )
	{
	    printf("%d\t %.3o\t %.2x\t Non Printable\n", i, i, i);
	}
	else
	{
	    printf("%d\t %.3o\t %.2x\t %c\n", i, i, i, i);
	}
    }

    return 0;
}
	  
