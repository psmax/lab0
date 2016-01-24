// Task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"

int SumDigits(int Number)
{
	int sum = 0;
	while (Number != 0)
	{
		sum += Number % 10;
		Number /= 10;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Enter only one number!");
	}
	else
	{
		int arg = atoi(argv[1]);
		int i;
		printf("1");

		for (i = 2; i <= arg; ++i)
		{
			if (i % SumDigits(i) == 0)
			{
				printf(", %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}