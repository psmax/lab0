// Task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"

void PrintFib(unsigned int Count)
{
	unsigned int FibPrev = 1;
	unsigned int FibCur = 1;
	unsigned int FibNext = 2;

	int FiveCounter = 2;

	printf("1, 1");
	while ((FibNext <= Count) && (FibNext <= INT_MAX))
	{
		FibPrev = FibCur;
		FibCur = FibNext;
		FibNext = FibPrev + FibCur;

		if (FiveCounter % 5 == 0)
		{
			printf(",\n");
		}
		else
		{
			if (FibCur <= Count)
			{
				printf(", ");
			}
		}
		printf("%d", FibCur);
		FiveCounter++;
	}
	if (FibNext > INT_MAX)
	{
		printf("; Int range exceeded!");
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc <= 1)
	{
		printf("Program prints all Fib numbers from 0 to the string parameter.\n");
		return 0;
	}
	else
	{
		int arg = atoi(argv[1]);
		if (arg > 0)
		{
			PrintFib(arg);
		}
		else
		{
			printf("Wrong parameter!\n");
		}
	}
	return 0;
}