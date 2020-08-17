/*
   Title       : A program to implement student record using array of structures
   Author      : Gagan A
   Date        : 17/08/2020
   Description : Input : Read students' details from the user 
                 Output: print the database of respective student who has to be searched 
*/ 

#include<stdio.h>
#include<stdlib.h>

/* structure definition */
typedef struct
{
    char *name;
    char s[50];
    int roll_no;
    float *marks;
    float avg;
    char grade;
} student_t;

/* Functions prototype */
void populate(student_t *, size_t, size_t);
void avg_grade(student_t *, size_t, size_t);
void search_db(student_t *, char *, size_t, size_t, int);
void print_db(student_t *p, size_t m, size_t n);
int my_strlen(char * str);
void my_strcpy(char * dest, char * src);

int main()
{
    /* Declare local variables */
    size_t m, n;
    int select, method, num;
    char option, buffer[20] = {'\0'};
    int i;
    char s[50];
    student_t s1;

    do
    {
	/* Read no of students and subjects from the user */
	printf("Enter the number of students: ");
	scanf("%zu", &m);
	printf("Enter the number of subjects: ");
	scanf("%zu", &n);

	/* Dynamic memory allocation for structure */
	student_t *p = malloc(m *  sizeof(student_t));

	/* Do error handling */
	if (!p)
	{
	    perror("malloc");
	    return 0;
	}

	/* Function call to populate with inputs*/
	populate(p, m, n);

	/* Function call to calculate average and grade */
	avg_grade(p, m, n);

	/* Read choice from the user */
	printf("-----Display Menu-----\n1.Particular student details\n2.All students' details\nEnter your choice: ");
	scanf("%d", &select);

	/* Do operation wrt the choice made by the user */
	switch (select)
	{
	    case 1:	
		/* Read the method of search from the user */
		printf("-----Menu for particular student-----\n1. Name\n2. Roll No.\nEnter your choice: ");
		scanf("%d", &method);

		switch (method)
		{
		    /* Name search */
		    case 1:
			/* Read student's name to be searched from the user */
			printf("Enter the student's name: ");
			scanf("%s", buffer);

			/* Function call to search database of entered student's name */
			search_db(p, buffer, m, n, num);
			break;

		    /* Roll number search */
		    case 2:		
			/* Read student's roll number to be searched from the user */
			printf("Enter the roll no: ");
			scanf("%d", &num);

			/* Function call to search database of entered student's roll number */
			search_db(p, buffer, m, n, num);
			break;

		    default:	
			printf("Invalid entry.. Please select option 1 or option 2\n");
			return 0;
		}

		break;

	    case 2:
		/* Function call to print database */
		print_db(p, m, n);
		break;

	    default:
		printf("Invalid entry.. Please select option 1 or option 2\n");
	}

	/* check for continue */
	printf("Do you want to continue (y/n): ");
	getchar();
	scanf("%c", &option);

    } while (option == 'y');

    return 0;
}

/* Function body to populate with students' database */
void populate(student_t *p, size_t m, size_t n)
{
    size_t i, j, SIZE;
    char buffer[20] = {'\0'};
    char duffer[20]={'\0'};

    /* Loop to read students' database */
    for (i = 0; i < m; i++)
    {
	/* Read roll number */
	printf("-----Enter the student details-----\nEnter the roll number: ");
	scanf("%d", &p[i].roll_no);

	/* Read student's name */
	printf("Enter the student name: ");
	scanf("%s", buffer);

	/* Fetching string length */
	SIZE = my_strlen(buffer);

	/* Dynamic memory allocation for entered string name */
	p[i].name = malloc(SIZE + 1);

	/*Function call to  Copy the data from buffer to the allocated memory */
	my_strcpy(p[i].name, buffer);

	/* Dynamic memory allocation for storing marks */
	p[i].marks = malloc(n * sizeof(float));
	for (j = 0; j < n; j++)
	{
	    printf("enter the marks of subject[%ld]: ", j + 1 );
	    scanf("%g",p[i].marks +j);
	}	
    }
}

/* Function body to calculate average and grade of students */
void avg_grade(student_t *p, size_t m, size_t n)
{
    size_t i, j;
    float sum, avg;

    /* Loop to calculate sum of marks */
    for (i = 0; i < m; i++)
    {	
	sum = 0;
	for (j = 0; j < n; j++)
	{
	    sum += *(p[i].marks + j);
	}
	/* Calculating average */
	p[i].avg = sum / n;

	/* compare and assign the grade based on average */
	if(p[i].avg >= 90)
	{
	    p[i].grade = 'A';
	}
	else if(p[i].avg >= 80 && p[i].avg < 90)
	{
	    p[i].grade = 'B';
	}
	else if(p[i].avg >= 70 && p[i].avg < 80)
	{
	    p[i].grade = 'C';
	}
	else if(p[i].avg >= 60 && p[i].avg < 70)
	{
	    p[i].grade = 'D';
	}
	else if(p[i].avg >= 50 && p[i].avg < 60)
	{
	    p[i].grade = 'E';
	}
	else
	{
	    p[i].grade = 'F';
	}
    }
}

/* Function body to search student's database based on name or roll number */
void search_db(student_t *p, char *student_name, size_t m, size_t n, int roll_no)
{
    size_t i, j;

    /* Print the headings of the table */
    printf("Roll No   Name  \t\t");
    for (i = 1; i <= n; i++)
	printf("sub[%ld]  ", i);
    printf("Average\tGrade\n");

    /* Loop to print the database of the student */
    for (i = 0; i < m; i++)
    {
	if(*(p[i].name) == *student_name || p[i].roll_no == roll_no)
	{
	    printf("%-10d%s\t\t", p[i].roll_no, p[i].name);

	    for (j = 0; j < n; j++)
	    {
		if (j == 0)
		    printf(" %g\t", *(p[i].marks + j));
		else
		    printf(" %-3g\t", *(p[i].marks + j));
	    }

	    printf(" %.2g\t %c\n", p[i].avg, p[i].grade);
	    return ;
	}
    }
    printf("Student not found in database: \n");
}

/* Function body to print students' database */
void print_db(student_t *p, size_t m, size_t n)
{
    size_t i, j;

    /* Print the headings of the table */
    printf("Roll No   Name  \t\t");
    for (i = 1; i <= n; i++)
	printf("sub[%ld]  ", i);
    printf("Average\tGrade\n");

    /* Loop to print the database of the student */
    for (i = 0; i < m; i++)
    {
	if (my_strlen(p[i].name) > 6)
	    printf("%-10d%s\t\t", p[i].roll_no, p[i].name);
	else
	    printf("%-10d%s\t\t\t", p[i].roll_no, p[i].name);

	for (j = 0; j < n; j++)
	{
	    if (j == 0)
		printf(" %g\t", *(p[i].marks + j));
	    else
		printf(" %-3g\t", *(p[i].marks + j));
	}

	printf(" %.2g\t %c\n", p[i].avg, p[i].grade);
    }
}

/* Function body to calculate string length */
int my_strlen(char * str)
{
    char *p = str;
    while (*++str);
    return str - p;
}

/* Function body to copy two strings */
void my_strcpy(char * dest, char * src)
{
    while (*dest++ = *src++);
}
