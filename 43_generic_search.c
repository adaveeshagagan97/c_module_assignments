/*
   Title       : A program to implement binary search for all datatypes
   Author      : Gagan A
   Date        : 04/08/2020
   Description : Input : Read size, choice, array elements and key element of respective type from the user
                 Output: To print the position of key element in the array using binary search method
*/

#include <stdio.h>
#include <stdlib.h>

/* Function body to read array of int/float/double datatype */
void read_array(void * a, int size, int dt, char **fmt)
{
    char * temp = (char *)a;

    for (int i = 0; i < size; i++, temp += dt)
    {
	printf("%d. ", i + 1); 
	scanf(*fmt, temp);
    }
}

/* Function body to bubble sort array of any datatype */
void generic_sort(void* aptr, int no_of_elements, int (*compare_fp)(void *, void *), int size_len)
{
    int i, j;

    for (i = 0; i < no_of_elements; i++)
    {
	for (j = 0; j < no_of_elements - i - 1; j++)
	{
	    if ( compare_fp((aptr + j * size_len), (aptr + (j + 1) * (size_len))) > 0) {
		swap_generic((aptr + j * size_len), (aptr + (j + 1) * (size_len)), size_len );
	    }
	}
    }
}

/* Function body to compare int */
int compare_int(void *a, void *b)
{
    if (*(int *)b < *(int *)a) return 5;
    if (*(int *)b > *(int *)a) return -5;
    return 0;
}

/* Function body to compare string/char */
int compare_string(void *a, void *b)
{
    char  *c = (char *)a;
    char *d = (char *)b;
    return my_strcmp(c, d);
}

/* Function body to compare float */
int compare_float(void *a, void *b)
{
    if (*(float *)b < *(float *)a) return 5;
    if (*(float *)b > *(float *)a) return -5;
    return 0;
}

/* Function body to compare double */
int compare_double(void *a, void *b)
{
    if (*(double *)b < *(double *)a) return 5;
    if (*(double *)b > *(double *)a) return -5;
    return 0;
}

/* Function body to swap two elements of any datatype */
void swap_generic(void * aptr, void * bptr, int size)
{
    for (int i = 0; i < size; i++ )
    {
	char temp = * (char *) aptr;
	* (char *) aptr++ = * (char *) bptr;
	* (char *) bptr++ = temp;
    }
}

/* Function body to perform binary search of any datatype */
int generic_binarySearch(void *val, void *aptr, int no_of_element, int (*compare_fp)(void *, void *), int size_length)
{
    int mid, low = 0, high = no_of_element - 1;
    char temptest1 = 'a', temptest2 = 'a';

    while(low < high)
    {
	mid = (low + high) / 2;

	if (compare_fp(val, (aptr + (mid) * (size_length))) <= 0)
	    high = mid;
	else
	    low = mid+1;
    }

    return (compare_fp(val, (aptr + (low) * (size_length))) == 0)? low: -1;
}

/* Function body to sort strings */
void string_sort(char array[][32], int no_of_elements, int size_l)
{
    for (int i = 0; i < no_of_elements; i++)
    {
	for (int j = 0; j < no_of_elements - i - 1; j++)
	{
	    if ((my_strcmp(*(array+j), *(array+j+1)) > 0 ))
		swap_generic(*(array+j), *(array+j+1), size_l);
	}
    }
}

/* Function body to compare two strings */
int my_strcmp(char *s1, char *s2)
{
    while ((*s1 && *s2) && (*s1 == *s2))
    {
	s1++;
	s2++;
    }

    return (*s1 - *s2);
}

/* Function body to perform binary search of strings */
int string_binarySearch(char *val, char array[][32], int no_of_element, int size_length)
{
    int i, mid, low = 0, high = no_of_element - 1;

    while(low < high)
    {
	mid = (low + high) / 2;

	if (compare_string((val), *(array + (mid))) <= 0)
	    high = mid;
	else
	    low = mid+1;
    }

    return (compare_string((val), *(array + (low))) == 0)? low: -1;
}

int main()
{
    /* Declare local variables */
    char option;
    int choice, size, i, j, int_search_key;
    float float_search_key;
    double double_search_key;

    do
    {
	/* Define local variables */
	char type[3] = {sizeof(int), sizeof(float), sizeof(double)};
	char * dt = type;
	char *fmt[3] = {"%d", "%f", "%lf"};

	/* Read sizze, choice from the user */
	printf("Enter the size of an array: ");
	scanf("%d", &size);
	printf("Select the choice\n1. Int\n2. Char\n3. Float\n4. Double\n5. String\nChoice: ");
	scanf("%d", &choice);

	/* Define local variables */
	char str [size][32], key_str[32], * a = (char *)malloc(size * dt[choice - 1]);

	/* check whether memory is allocated or not */
	if (a == NULL)
	{
	    printf("Error: Memory is not allocated\n");
	}
	else
	{
	    switch (choice)
	    {
		case 1:
		    /* Read array elements of type int */
		    printf("Enter %d elements of type int:\n", size);
		    read_array(a, size, *dt, fmt);

		    /* Sort the array elements */
		    generic_sort(a, size, compare_int, sizeof(int));
		    
		    /* Print the sorted array elements */
		    printf("After sorting:\n");
		    for (i = 0; i < size; i++)
		    {
			printf("%d\n", *((int *)a + i));
		    }

		    /* Read key element to be searched from the user */
		    printf("Enter the key element to search: ");
		    scanf("%d", &int_search_key);

		    /* check whether key element is found or not by calling Function */
		    if ((generic_binarySearch(&int_search_key, a, size, compare_int, sizeof(int))) == -1)
		    {
			printf("Element not found\n");
		    }
		    else
		    {
			printf("Element %d is at position %d of array.\n", int_search_key, (generic_binarySearch(&int_search_key, a, size, compare_int, sizeof(int))));
		    }
		    break;

		case 2:

		    /* Read array elements of char type from the user */
		    printf("Enter %d elements of type char: \n", size);
		    for (i = 0; i < size; i++)
		    {
			scanf("%s", str[i]);
		    }

		    /* Function call to sort the characters */
		    string_sort(str, size, 32);

		    /* Print the sorted array elements */ 
		    printf("After sorting:\n");
		    for (i = 0; i < size; i++)
		    {
			printf("%s\n", str[i]);
		    }

		    /* Read key element to be searched from the user */
		    printf("Enter the key element to search: ");
		    scanf("%s", key_str);

		    /* Check whether key element is found or not by calling Function */
		    if ((string_binarySearch(key_str, str, size, 32)) == -1)
		    {
			printf("Element not found\n");
		    }
		    else
		    {
			printf("Element %s is at position %d of array.\n", key_str, (generic_binarySearch(key_str, str, size, compare_string, 32)));
		    }
		    break;

		case 3:
		    /* Read array elements of type float */
		    read_array(a, size, *(dt + 1), fmt + 1);

		    /* Function call to sort the array */
		    generic_sort(a, size, compare_float, sizeof(float));

		    /* Print the sorted array elements */
		    printf("After sorting:\n");
		    for (i = 0; i < size; i++)
		    {
			printf("%g\n", *((float *)a + i));
		    }

		    /* Read key element to be searched from the user */
		    printf("Enter the key element to search: ");
		    scanf("%f", &float_search_key);

		    /* check whether key element is found or not by calling function */
		    if ((generic_binarySearch(&float_search_key, a, size, compare_float, sizeof(float))) == -1)
		    {
			printf("Element not found\n");
		    }
		    else
		    {
			printf("Element %g is at position %d of array.\n", float_search_key, (generic_binarySearch(&float_search_key, a, size, compare_float, sizeof(float))));
		    }

		    break;

		case 4:
		    /* Read array elements of type double */
		    read_array(a, size, *(dt + 2), fmt + 2);

		    /* Function call to sort the array elements */
		    generic_sort(a, size, compare_double, sizeof(double));

		    /* Print the sorted array elements */
		    printf("After sorting:\n");
		    for (i = 0; i < size; i++)
		    {
			printf("%g\n", *((double *)a + i));
		    }

		    /* Read key element to be searched from the user */
		    printf("Enter the key element to search: ");
		    scanf("%lf", &double_search_key);

		    /* Check whether key element is found or not by calling function */
		    if ((generic_binarySearch(&double_search_key, a, size, compare_double, sizeof(double))) == -1)
		    {
			printf("Element not found\n");
		    }
		    else
		    {
			printf("Element %g is at position %d of array.\n", double_search_key, (generic_binarySearch(&float_search_key, a, size, compare_float, sizeof(float))));
		    }
		    break;

		case 5:
		    /* Read array of strings from the user */
		    printf("Enter 4 elements of type string\n");
		    for (i = 0; i < size; i++)
		    {
			scanf("%s", str[i]);
		    }

		    /* Function call to sort the array of strings */
		    string_sort(str, size, 32);

		    /* Print the sorted array of strings elements */
		    printf("After sorting:\n");
		    for (i = 0; i < size; i++)
		    {
			printf("%s\n", str[i]);
		    }

		    /* Read key element to be searched from the user */
		    printf("Enter the key element to search: ");
		    scanf("%s", key_str);

		    /* check whether key element is found or noy by calling function */
		    if ( (string_binarySearch(key_str, str, size, 32)) == -1)
		    {
			printf("Element not found\n");
		    }
		    else
		    {
			printf("Element %s is at position %d of array.\n", key_str, (string_binarySearch(key_str, str, size, 32)));
		    }
		    break;

		default:
		    printf("Error: Invalid option\n");

	    }

	    /* Free the allocated memory */
	    free(a);
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

