/*
   Title       : A program to print "Hello" in X format
   Author      : Gagan A
   Date        : 03/06/2020
   Description : Input : Read number of lines from the user
                 Output: To Print hello in X format
*/

#include <stdio.h>

int main()
{
    //Declaring local variables
    int row, column, lineCount, lines;
    char option;

    do
    {
	//Read number of lines from the user
	printf("Enter the number of lines: ");
	scanf("%d", &lineCount);
        
	//check the limit of no of lines
	if ( lineCount >= 32 || lineCount <= 0 )
	{
	    printf("Number out of range\n");
	}
	else
	{
	    //Take a copy of no of lines
	    lines = lineCount;
	    
	    //If lineCount is odd then make it even by adding one
	    if ( lineCount%2 != 0 )
	    {
		lineCount += 1;
	    }
	    
	    //for each row and column, print space and hello world respectively
	    for ( row = 0; row < lineCount; row++ )
	    {
		for ( column = 0; column < lineCount; column++ )
		{
		    //if actual lines was odd, then when row is half of lineCount, skip one line print and continue 
		    if ( row == lineCount/2 && lines%2 != 0 )
		    {
			continue;
		    }
		    
		    //To print hello when row and column are same and also when column = (lineCount - 1) - row
		    if ( row == column || column == (lineCount - 1) - row )
		    {
			printf("Hello");
		    }
		    else
		    {
			//else print the spaces
			printf(" "); 
		    }
	       	}
		
		//if actual lines was odd, then when row = lines / 2, skip printing newline
		if ( row == lines/2 && lines%2 != 0 )
		{
		    continue;
		}
		else
	       	{
		    //else after each row print a new linw
		    printf("\n");
		}
	    }
	    
	    //check for continue
	    printf("Do you want to continue (y/n): ");
	    scanf(" %c", &option);
	}
    
    } while ( option == 'y' );
    
    return 0;
}
	    


