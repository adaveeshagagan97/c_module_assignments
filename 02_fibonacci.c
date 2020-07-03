/*
   Title       : A program to generate fibonacci numbers <= 'n'
   Author      : Gagan A
   Date        : 31/05/2020
   Description : Input : Read a number from the user
                 Output: To generate the fibonacci series <= 'n'
 */

#include <stdio.h>

int main()
{
    //Declare a character 
    char ch;

    //user prompt
    do
    {
       	//Declaring and initialising local variables
	int first = 0, second = 1, next = 0, num;
	
	//Read input from the user
        printf("enter a number: ");
        scanf("%d",&num);
	
	//when number is positive
	if ( num > 0 )
	{
	    //print first term of the series
	    printf("%d", first);
	    
	    //To print the positive fibonacci series upto <= num
	    while ( second <= num )
	    {
		printf(", %d", second );
	        next = first + second;
	        first = second;
	    	second = next;
	    }
	}
	//when number is negative
       	else
	{
	    //print first term of the series
	    printf("%d", first);
	    
	    //To print the negative fibonacci series upto <= num
	    while ( first >= (num + 1) && first < (num * (-1)) )  
	    {
		next = first - second;
	  	first = second;
	        second = next;
	        printf(", %d",first);
	    }
	}
	
	//print new line
	printf("\n");
       
	//Read input from the user
       	printf("Do you want to continue (y/n) : ");
	scanf(" %c", &ch);
   
    } while ( ch == 'y' );
   
    return 0;
}

