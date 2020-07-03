/*
   Title       : A program to check whether a given number is perfect or not
   Author      : Gagan A
   Date        : 31/05/2020
   Description : Input : Read a number from the user
                 Output: To print whether it is a perfect number or not
*/

#include <stdio.h>

int main()
{
    //Declare a character
    char ch;

    //user prompt
    do
    {
	//Declaring and initialising local variabales
	int num, i, sum = 0, limit = 1;
	
	//To calculate the value of max range ( 2^20)
	for ( i = 1; i <= 20; i++ )
	{
	    limit = limit * 2;
	}
	
	//Read input from the user
	printf("Enter a number: ");
	scanf("%d",&num);
	
        //when number is greater than or equal to zero
	if ( num >= 0 )
	{
	    //when number < (2^20)
	    if ( num < limit )
	    {
		//To find divisors and sum of those divisors
		for ( i = 1; i < num - 1; i++)
		{
		    if ( (num % i) == 0 )
		    {
			sum = sum + i;
		    }
		}
		
		//when sum of divisors equal to number
		if ( sum == num )
		{
		    printf("Yes, entered number is a perfect number\n");
		}
		else
		{
		    printf("No, entered number is not a perfect number\n");
		}

	    }
	    else
	    {
		printf("Number is out of range\n");
	    }

       	}
	//when number is a negative digit
	else
	{
	    printf("Invalid input\n");
	}
       
	//Read input from the user to continue or not
	printf("Do you want to continue (y/n): ");
        scanf(" %c",&ch);
   
    } while ( ch == 'y' );
    
    return 0;
}

