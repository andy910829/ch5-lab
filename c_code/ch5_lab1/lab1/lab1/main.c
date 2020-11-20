#include <stdio.h>
#include <stdlib.h>

#define STUDENTS 3
#define EXAMS 4

void minimum(int grade[][EXAMS], int pupils, int tests);
void maximum(int grade[][EXAMS], int pupils, int tests);
void average(int grade[][EXAMS], int pupils, int tests);
void printarray(int grade[][EXAMS], int pupils, int tests);
void printmenu();

int main()
{
	int studentgrades[STUDENTS][EXAMS] = { {77,68,86,73},
										{96,87,89,78},
										{70,90,86,81} };
	void(*processgrdes[4])(int[STUDENTS][EXAMS], int, int)
		= { printarray,minimum,maximum,average };

	int choice = 0;

	while (choice != 4) {
		do {
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4) {
			(*processgrdes[choice])(studentgrades, STUDENTS, EXAMS);
		}
		else {
			printf("\tprogram ended. \n");
		}
	}
	system("pause");
	return 0;
}

void minimum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;
	int lowgrade = 100;

	for (i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
				lowgrade = grades[i][j];
		}
	}
	printf("\n\t the lowest grade is %d", lowgrade);
	printf("\n");
}

void maximum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;
	int highgrade = 0;

	for (i = 0; i < pupils; i++)
	{
		

		
		{
			for (j = 0; j < tests; j++)
			{
				if (grades[i][j] > highgrade)
					highgrade = grades[i][j];
			}
		}
		
	}
	printf("\n\t the highest grade is %d", highgrade);
	printf("\n");
}

void average(int grades[][EXAMS], int pupils, int tests)
{
	int i, j, total;
	for (i = 0; i < pupils; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
	
	printf("\n\t the avreage grade for student %d is %.1f", i + 1, (double)total / tests);

	}
		printf("\n");
}

void printarray(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;

	printf("\n\t\t\t[0]    [1]    [2]     [3]");
	for (i = 0; i < pupils; i++)
	{
		printf("\n\tstudentgrade[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu()
{
	printf("\n");
	printf("\tenter a choice:\n");
	printf("\t0 print a array of grade\n");
	printf("\t1 find the minimum grades\n");
	printf("\t2 find the maximum grades\n");
	printf("\t3 print the average on all tests for each students\n");
	printf("\t4 end program\n");
	printf("choice:");

}

