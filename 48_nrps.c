/* 
   Title       : A program to generate consecutive NRPS of length n using k distinct characters 
   Author      : Gagan A
   Date        : 02/08/2020
   Description : Input : Read k, n and k distinct characters from the user
                 Output: To print the consecutive NRPS of length n using k distinct characters
*/

#include <stdio.h>

/* Function prototype */
void nrps(char * ptr, int len, int k);

int main()
{
    /* Declare local variables */
    char option;

    do
    {
	/* Declare local variables */
	char ptr[100];
	int n, k, i, j, flag = 0;

	/* Read k[characters] from the user */
	printf("Enter the number characters C: ");
	scanf("%d", &k);

	/* check if k is out of range or not */
	if (k < 1 || k > 10)
	{
	    printf("Error: Number out of range, please enter k such that [1 <= k <= 10]");
	}
	else
	{
	    /* Read n[length] from the user */
	    printf("Enter the length of the string N: ");
	    scanf("%d", &n);

	    /* check if n < k or not */
	    if (n < k)
	    {
		printf("Error: Number out of range, please enter n such that [n >= k]");
	    }
	    else
	    {
		/* Read k distinct characters from the user */
		getchar();
		printf("Enter %d distinct characters: ", k);
		scanf("%[^\n]", ptr);

		/* Loop to check whether characters are identical */
		for (i = 0; i < k; i++)
		{
		    for (j = i + 1; j < k; j++)
		    {
			if (ptr[i] == ptr[j])
			{
			    flag = 1;
			}
		    }
		}

		/* check whether characters are distinct or not */
		if (flag)
		{
		    printf("Error: Please enter distinct characters");
		}
		else
		{
		    printf("Possible NRPS is: ");
		    /* Function call */
		    nrps(ptr, n, k);
		}
	    }
	}

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to generarte consecutive nrps */
void nrps(char * ptr, int len, int k)
{
    int i, val = 0, count = 0;

    for (i = 0; i < len; i++)
    {
	if (((i % k) == 0) && (i != 0))
	{
	    val++;
	}
	printf("%c", *(ptr + ((i + val) % k)));
    }
}    
