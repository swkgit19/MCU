/*
===============================================================================
 Name        : Lab7.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <stdio.h>

struct result
{
	int score;
	char grade;
};

int main(void)
{

	//Section 2.5
	/*
	struct result StudentResult[2];

	printf("Enter the Score and Grade for Student 1\n");
	printf("Score: ");
	scanf("%d, &StudentResult[0].score");
	printf("Grade: ");
	scanf("%c, &StudentResult[0].grade");

	printf("Enter the Score and Grade for Student 2\n");
	printf("Score: ");
	scanf("%d, &StudentResult[1].score");
	printf("Grade: ");
	scanf("%c, &StudentResult[1].grade");

	printf("Student 1 is getting %d, %c\n", StudentResult[0].score,
			StudentResult[0].grade);
	printf("Student 2 is getting %d, %c\n", StudentResult[1].score,
				StudentResult[1].grade);
	*/

	//Section 3.5
	//Part 1
	/*
	int a = 0x12, b = 0x34, c = 0x56, d = 0x78, e = 0x90;
	int result;
	result = a + b;
	printf("Result 1 = %p\n", result);
	result--;
	printf("Result 2 = %p\n", result);
	result = result & c;
	printf("Result 3 = %p\n", result);
	result += d;
	printf("Result 4 = %p\n", result);
	result = result << 8;
	printf("Result 5 = %p\n", result);
	result = result & 0x0F00;
	printf("Result 6 = %p\n", result);
	printf("Result 7 = %p\n", result > e);
	*/


	//Section 3.5
	//Part 3


	int colour = 0x53CDCD96;
	int mask = 0x00FFFF00;
	int cyan1 = colour & mask;
	int cyan;

	cyan = cyan1 >> 8;
	printf("Hexadecimal Value for Cyan is %p", cyan);

	//Section 5.5
	//String and Pointer
	/*
#include <string.h>

	char string1[30] = {};
	char *ptrArray;

	printf("Enter up to 30 characters with spaces\n");
	gets(string1);

	printf("You have entered a string: ");
	puts(string1);
	ptrArray = string1;

	printf("The length of your string is %d.\n", strlen(string1));
	printf("The first element address of your string is %p.\n", &string1[0]);
	printf("The first element of your string is %c.\n", string1[0]);
	printf("The address stored inside pointer ptrArray %p.\n", ptrArray);
	printf("The data pointer by ptrArray %c.\n", *ptrArray);

	*/

    return 0 ;

	//Section 6.1
	//Function Declaration and Arguments
	/*
	void display(char str[]);
	int multiply(int x, int y);
	int cube(int y);

	int main(void)
	{
		char msg[50] = "My First Program with Functions";
		int num;
		display[msg];
		num = multiply(12,7);
		printf("12 x 7 = %d\n", num);
		printf("8 x 8 x 8 = %d\n", cube(8));
		return 0;
	}
	void display(char str[])
	{
		printf("%s\n", str);
	}
	int multiply(int x, int y)
	{
		return(x*y);
	}
	int cube(int y)
	{
		return(y*y)*y;
	}
	*/

	//Section 6.4
	/*
#include <string.h>

	struct employee
	{
		int id;
		char name[10];
		float salary;
	};

	void processEmp(struct employee *);

	int main(void)
	{
		struct employee emp1 = {};
		struct employee *ptrEmp;

		ptrEmp = &emp1;
		ProcessEmp(ptrEmp);

		printf("ID: %d\n", ptrEmp->id);
		printf("Name: %s\n", ptrEmp->name);
		printf("Salary: $%.2f\n", ptrEmp->salary);
		return 0;
	}


	void processEmp(struct employee *e)
	{
		e->id = 123;
		strcpy(e->name, "Shelia");
		e->salary = 65000.00;
	}
	 */


}
