// Task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#include <math.h>
#include <iostream>

using namespace std;

double StringToDouble(const char * str, bool & err)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

double CalcDistance(double v0, double a0)
{
	const double g = 9.8;
	return (v0 * v0) * sin(2 * a0) / g;
}
int _tmain(int argc, _TCHAR* argv[])
{
	while (1 == 1)
	{
		bool err;
		char inpstr[80];
		cout << "Enter v0 or type exit: ";
		cin >> inpstr;
		double v0 = StringToDouble(inpstr, err);
		if (err == 1)
		{
			if (strcmp(inpstr, "exit") == 0)
			{
				cout << "Goodbye";
				return 0;
			}
			else
			{
				cout << "Wrong parameter!";
				return 0;
			}
		}
		cout << "Enter a0 or type exit: ";
		cin >> inpstr;
		double a0 = StringToDouble(inpstr, err);
		if (err == 1)
		{
			if (strcmp(inpstr, "exit") == 0)
			{
				cout << "Goodbye";
				return 0;
			}
			else
			{
				cout << "Wrong parameter!";
				return 0;
			}
		}
		a0 *= 3.14159265358979323846 / 180.0;
		double result = CalcDistance(v0, a0);
		cout << "Result is " << result << "\n";
	}
}
