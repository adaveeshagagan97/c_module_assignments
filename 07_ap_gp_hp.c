/* 
   Title       : A program to read 3 numbers a, r, n and generate AP, GP, HP
   Author      : Gagan A
   Date        : 03/06/2020
   Description : Input : Read 3 numbers a, r, n from the user
                 Output: To generate AP, GP, HP series respectively 
*/

#include <stdio.h>

int main()
{
    //Declaring local variables
    int a, r, n, i;
    float AP, GP, HP;
    char ch;

    do
    {
	//Read input from the user (a, r, n)
       	printf("Enter the first number 'a': ");
	scanf("%d",&a);
	printf("Enter the common difference/ratio 'r': ");
	scanf("%d",&r);
	printf("Enter the number of terms 'n': ");
	scanf("%d",&n);
	
	//Check a, r, n for the limit ( < 2^10 )
	if ( a >= 1024 || r >= 1024 || n >= 1024 )
	{
	    printf("Input(s) out of range\n");
	}
	else
	{
	    //check a, r, n for negative values
	    if ( a < 0 || r < 0 || n < 0 )
	    {
		printf("Invalid input(s)\n");
	    }
	    else
	    {
		/* Arithematic Progression */

		//Print first term of AP series
		printf("AP = %d", a);
		//Initialise first term to AP
		AP = a;
		//Print remaining AP terms
		for ( i = 1; i < n; i++ )
		{
		    AP = AP + r;
		    printf(", %d", (int) AP);
		}
		printf("\n");

		/* Geometric Progression */

		//Print first term of GP series
		printf("GP = %d", a);
		//Initialise first term to GP
		GP = a;
		//Print remaining GP terms 
		for ( i = 1; i < n; i++ )
		{
		    GP = GP * r;
		    printf(", %d", (int) GP);
		}
		printf("\n");

		/* Harmonic Progression */
		
		//Print first term of HP series
		printf("HP = %g", (float) 1/a);
		//Initialise second term to HP
		HP = a + r;
		//Print remaining HP terms
		for ( i = 1; i < n; i++ )
		{
		    printf(", %g", 1/ HP);
		    HP = HP + r;
		}
		printf("\n");
	    }
	    
	    //check for continue
	    printf("Do you want to continue (y/n): ");
	    scanf(" %c",&ch);
       	}
    
    } while ( ch == 'y' );

    return 0;
}
