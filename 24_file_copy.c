/* 
   Title       : A program to implement my_cp() function
   Author      : Gagan A
   Date        : 04/08/2020
   Description : Input : Read two file names from the user
                 Output: copy first file contents into second file using my_cp()
*/

#include <stdio.h>

/* Function prototype */
void my_cp(FILE *dest, FILE *src);

int main(int argc, char **argv)
{
    /* File descriptors */
    FILE *fp1, *fp2;

    /* Do respective operation wrt argc [argument count] */
    switch (argc)
    {
	/* when both dest and src files are not passed */
	case 1:
	    printf("Error: Destination and source files missing\n");
	    break;

	/* When only src file is passed */
	case 2:
	    printf("Error: Destination file missing\n");
	    break;

	case 3:
	    /* Open first file in read only mode */
	    fp1 = fopen(argv[1], "r");

	    /* check fopen success or not */
	    if (NULL == fp1)
	    {
		perror("fopen");
		return -1;
	    }

	    /* Open second file in write only mode */
	    fp2 = fopen(argv[2], "w");
	    
	    /* check fopen success or not */
	    if (NULL == fp2)
	    {
		perror("fopen");
		/* clean exit */
		fclose(fp1); 
		return -1;
	    }

	    /* Function call to copy two files */
	    my_cp(fp2, fp1);

	    /* close the files */
	    fclose(fp1);
	    fclose(fp2);

	    break;

	default:
	    printf("Error: Too many arguments\n");
    }
    return 0;
}

/* Function body to copy contents of one file into another */
void my_cp(FILE * dest, FILE * src)
{
    int c;
    while ((c = fgetc(src)) != EOF)
	fputc(c, dest);
}

