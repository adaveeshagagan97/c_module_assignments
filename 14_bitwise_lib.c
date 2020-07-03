/*
   Title       : A program to implement bitwise operations
   Author      : Gagan A
   Date        : 16/06/2020
   Description : Input : Read choice from the user
                 Output: To display the result of respective operations wrt choice
*/

#include <stdio.h>

int main()
{
    /* Declaring local variables */
    char option;
    int choice, num, n, pos, val, result, count = 0;
    int mask, mask2, i;
    int replaceValue, shiftNum, shiftReplace;
    
    do 
    {
	/* Read choice from the user */
	printf("Select bit operation from the below list\n1. get_nbits\n2. replace_nbits\n3. get_nbits_from_pos\n4. replace_nbits_from_pos\n5. toogle_bits_from_pos\n6. print_bits\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	/* To perform the operations according to the choice made respectively */
	switch ( choice )
	{	
	    case 1 : 
		/* Read num, pos from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter pos: ");
		scanf("%d", &pos);

		/* To get_nbits */
		result = num & ((1 << pos) - 1);
		printf("Value at %d[%d] -> %d\n", num, pos, result);
		break;

	    case 2 :
		/* Read num, n, val from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter val: ");
		scanf("%d", &val);

		/* mask */
		mask = 1;
		
		/* mask */
		for ( i = 1; i < n; i++ )
		{
		    mask |= (1 << i);
		}
		
		/* complement mask to get mask2 */
		mask2 = ~mask;
		
		/* To replace_nbits */
		result = (num & mask2) | (val & mask);
		printf("Value at %d[%d] -> %d\n", num, n, result);
		break;

	    case 3 :
		/* Read num, n, pos from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter pos: ");
		scanf("%d", &pos);

		/* mask */
		mask = 1;

		/* mask */
		for ( i = 1; i < n; i++ )
		{
		    mask |= (1 << i);
		}
		
		/* shift mask to position (pos-n+1) */
		mask2 = (mask << (pos - n + 1));

		/* To get_nbits from pos */
		result = ((num & mask2) >> (pos - n + 1));
		printf("Value at %d[%d:%d] -> %d\n", num, pos, n, result);
		break;

	    case 4 :
		/* Read num, n, pos, val from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter pos: ");
		scanf("%d", &pos);
		printf("Enter val: ");
		scanf("%d", &val);

		/* Fetch n number of bits from LSB of val */
		replaceValue = val & ((1 << n) - 1);

		/* Right shift pos position bit of num */
		shiftNum = num >> (pos - n + 1);
		
		/* mask */
		mask = 1;

		/* mask */
		for ( i = 1; i < n; i++ )
		{
		    mask |= (1 << i);
		}

		/* complement mask to get mask2 */
		mask2 = ~mask;

		/* Do replacement */
		shiftReplace = (shiftNum & mask2) | (replaceValue & mask);
		
		/* Left shift the replaced value back to position pos */
		shiftNum = shiftReplace << (pos - n + 1);
		
		/* mask */
		mask = 1;

		/* mask */
		for ( i = 1; i < (pos - n + 1); i++ )
		{
		    mask |= (1 << i);
		}

		/* fetch the lost bits from num when right shifted */
		replaceValue = num & mask;

		/* To replace_nbits from pos */
		result = replaceValue | shiftNum;
		printf("Value at %d[%d:%d] -> %d\n", num, pos, n, result);   
		break;

	    case 5 :
		/* Read num, n, pos from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter pos: ");
		scanf("%d", &pos);

		/* mask */
		mask = 1;

		/* mask */
		for ( i = 1; i < n; i++ )
		{
		    mask |= 1 << i;
		}

		/* To toggle bits from pos */
		result = (num ^ (mask << (pos - n + 1 )));
		printf("Value at %d[%d:%d] -> %d\n", num, pos, n, result);
		break;

	    case 6 :
		/* Read num, n from the user */
		printf("Enter num: ");
		scanf("%d", &num);
		printf("Enter n: ");
		scanf("%d", &n);

		/* when n > 32, then initialise it back to 32 bits */
		if ( n > 32 )
		{
		    n = 32;
		}

		/* To print n bits of binary representation of num */
		printf("The last %d bits of %d -> ", n, num);
		for ( i = n - 1; i >= 0; i-- )
		{
		    if ( (count % 8) == 0 )
		    {
			printf(" ");
		    }
		    ((1 << i) & num) ? printf("1") : printf("0");
		    count++;
		}
		printf("\n");
		break;

	    default :
		printf("Error: Invalid choice. Please select from 1 to 6 only\n");
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	scanf(" %c", &option);

    } while ( option == 'y');
    
    return 0;
}
