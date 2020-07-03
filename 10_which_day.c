/*
   Title       : A program to find which day of the year
   Author      : Gagan A
   Date        : 03/06/2020
   Description : Input : Read the value of n and first day from the user
                 Output: To print the day of the year
*/

#include <stdio.h>

int main()
{
    //Declaring local variables
    int days_num, first_day, temp;
    char option;

    do
    {
	//Read the number from the user
	printf("enter the value of 'n': ");
	scanf("%d", &days_num);

	//Check the limit for the number
	if ( days_num <= 0 || days_num > 365 )
       	{
	    printf("Invalid Input\n");
	}       
	else
	{
	    //Read the starting day from the user
	    printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");
	    printf("Enter the option to set the first day: ");
	    scanf("%d", &first_day);
	    
	    //check the limit for the starting day
	    if ( first_day <= 0 || first_day > 7 )
	    {
		printf("Invalid Input\n");
	    }
	    else
	    {
		//calculations to fetch a new first_day value
	        temp = (first_day + days_num) - 1;
		first_day = temp % 7;

		//Print the day accordingly
		switch (first_day)
		{
		    case 0 :
			printf("The %dth day is Saturday\n", days_num);
			break;
		    
		    case 1 :
			printf("The %dth day is Sunday\n", days_num);
		       	break;
		   
		    case 2 :
		      	printf("The %dth day is Monday\n", days_num);
			break;
		    
		    case 3 :
		       	printf("The %dth day is Tuesday\n", days_num);
			break;
		    
		    case 4 :
			printf("The %dth day is Wednesday\n", days_num);
		       	break;
		    
		    case 5 :
		       	printf("The %dth day is Thursday\n", days_num);
			break;
		    
		    case 6 :
		       	printf("The %dth day is Friday\n", days_num);
		       	break;
		}
	    }
	}

	//check for continue
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);
    
    } while ( option == 'y' );
    
    return 0;
}



	    


