/*
   Title       : A program to check whether a given number is odd or even and its signedness
   Author      : Gagan A
   Date        : 31/05/2020
   Description : Input : It is entered by the user
                 Output: To print whether a given number is odd or even with its sign	    
 */

#include <stdio.h>

int main()
{
    //declaring a character
    char ch;
    
    //user prompt
    do
    {
	//declaring and initializing local variables
	int i, num, limit = 1;

	//Read input from the user
	printf("Enter the value of 'n': ");
	scanf("%d",&num);

	//To calculate max range of input ( 2^20 )
	for ( i = 1; i<= 20; i++ )
	{
	    limit = limit * 2;
	}
       	
	//when number is in the range
	if ( num < limit  )
	{
	    //when number is -ve
	    if ( num < 0 )
	    {
		if ( ( num % 2 ) == 0 )
		{
		    printf("%d is -ve even number\n",num);
		}
		else
		{
		    printf("%d is -ve odd number\n",num);
		}
	    }
	    //when number is +ve
	    else if ( num > 0)
	    {
		if ( (num % 2 ) == 0 )
		{
		    printf("%d is +ve even number\n",num);
		}
		else
		{
		    printf("%d is +ve odd number\n",num);
		}
	    }
	    //when number is zero
	    else
	    {
		printf("%d is a neutral number\n",num);
	    }
	}
	else
	{
	    printf("Number out of range\n");
	}
	
	//Read input from the user to continue or not
	printf("Do you want to continue(y/n): ");
	scanf(" %c",&ch);
    
    } while ( ch == 'y' );
    
    return 0;
}

