// Task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"

enum action
{
	idle,
	plus,
	minus,
	multiply,
	divide
};

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

action SetAction(char * arg, bool &err)
{
	err = 0;
	if (arg[0] == '+')
	{
		return plus;
	}
	if (arg[0] == '-')
	{
		return minus;
	}
	if (arg[0] == '/')
	{
		return divide;
	}
	if (arg[0] == '*')
	{
		return multiply;
	}
	err = 1;
	return idle;
}

double DoAction(double param1, double act, double param2, bool &err)
{
	err = 0;
	if (act == plus)
	{
		return param1 + param2;
	}
	if (act == minus)
	{
		return param1 - param2;
	}
	if (act == multiply)
	{
		return param1 * param2;
	}
	if (act == divide)
	{
		if (param2 == 0)
		{
			err = 1;
		}
		return param1 / param2;
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates the input string.\n");
		return 0;
	}

	action act;
	act = idle;
	bool err;
	double param = StringToDouble(argv[1], err);
	double result = param;
	if (err)
	{
		printf("Argument 1 is not a number!\n");
		return 1;
	}
	printf("%s ", argv[1]);
	for (int i = 2; i < argc; i++)
	{
		if (act == idle)
		{
			act = SetAction(argv[i], err);
			if (err == 1)
			{
				printf("Missing math operator!\n");
				return 1;
			}
		}
		else
		{
			double param = StringToDouble(argv[i], err);
			{
				result = DoAction(result, act, param, err);
				if (err == 1)
				{
					printf("Division by zero!");
					return 1;
				}
				act = idle;
			}
		}
		printf("%s ", argv[i]);
	}
	printf("= %.7f", result);
	return 0;
}

