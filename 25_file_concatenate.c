/* 
   Title       : A program to concatenate two files
   Author      : Gagan A
   Date        : 04/08/2020
   Description : Input : Read file names from the user through command line
                 Output: Do respective operation like concatenate files or copy contents of two files into one file wrt argument count
*/

#include <stdio.h>

/* Function prototype */
void filecopy(FILE *fp1, FILE *fp2);

int main(int argc, char **argv)
{
    /* File descriptors */
    FILE *fp1, *fp2, *fp3;

    /* Do respective operation wrt argc [argument count] */
    switch (argc)
    {
	/* When only 1 argument is passed */
	case 1:
	    filecopy(stdin, stdout);
	    break;

	case 3:
	    /* open both files in read mode only */
	    fp1 = fopen(argv[1], "r");
	    fp2 = fopen(argv[2], "r");

	    /* check whether files exist or fopen is successful or not */
	    if (fp1 == NULL || fp2 == NULL)
	    {
		printf("Error: Could not open files or files don't exist\n");
		return -1;
	    }

	    /* Function call to concatenate two files */
	    filecopy(fp1, stdout);
	    filecopy(fp2, stdout);

	    /* Close the files */
	    fclose(fp1);
	    fclose(fp2);
	    break;

	case 4:

	    /* Open file1, file2 in read mode only */
	    fp1 = fopen(argv[1], "r");
	    fp2 = fopen(argv[2], "r");
	    /* open file3 in write mode only */
	    fp3 = fopen(argv[3], "w");

	    /* check whether files exist or fopen is successful or not */
	    if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
	    {
		puts("Error: Could not open files or files don't exist");
		return -1;
	    }

	    /* copy contents of fp1 into fp3 */ 
	    filecopy(fp1, fp3);
	    /* copy contents of fp2 into fp3 */
	    filecopy(fp2, fp3);

	    /* close the files */
	    fclose(fp1);
	    fclose(fp2);
	    fclose(fp3);
	    break;

	default: 
        printf("ERROR\nUsage: ./25_my_cat file1.txt file2.txt\n Or\nUsage: ./25_my_cat file1.txt file2.txt file3.txt\n Or\nUsage: 25_my_cat \n");
    }

    return 0;
}

/* function body to copy contents from one file into another */
void filecopy(FILE *fp1, FILE *fp2)
{
    int c;
    while ((c = fgetc(fp1)) != EOF)
	fputc(c, fp2);
}
