#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int Factorial(int n)
{
	if (n == 0)
	{
		return n;
	}

	else if (n == 1)
	{
		return n;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

int SelectOperation();
bool ValidationOperation(char value[]);
bool ValidationNumber(char value[]);
double InputNumber();

float AlgebraicCalculation(double one, double two, int operation_index);

float SineCalculation(double x);
float CosineCalculation(double x);
float TanCalculation(double x);
float CotanCalculation(double x);

int main()
{
	double result = 0;
	double fNum; //first number
	double sNum; //second number

	int operation = SelectOperation();

	fNum = InputNumber();

	if (operation >= 1 && operation <= 3)
	{
		sNum = InputNumber();
		result = AlgebraicCalculation(fNum, sNum, operation);
	}
	else if (operation == 4)
	{
		result = SineCalculation(fNum);
	}
	else if (operation == 5)
	{
		result = CosineCalculation(fNum);
	}
	else if (operation == 6)
	{
		result = TanCalculation(fNum);
	}
	else if (operation == 7)
	{
		result = CotanCalculation(fNum);
	}

	printf("%f", result);
}

int SelectOperation()
{
	char inp_str[10];
	int input;
	printf("Input operation for calculator number:\nAlgebraic:\n\n1 - +\n2 - -\n3 - *\n\nTrigonometric:\n\n4 - sine\n5 - cosine\n6 - tan\n7 - cotan\n\n");

	while (true)
	{
		fflush(stdin);

		fgets(inp_str, 10, stdin);
		input = atof(inp_str);
		//printf("%d", input);
		
		if (ValidationOperation(inp_str)) {
			break;
		}
		else
		{
			printf("Invalid input. Needs to be in range of 1 to 7.\n");
		}
	}

	return input;
}

bool ValidationOperation(char value[])
{
	for (int i = 0; i < strlen(value) - 1; i++)
	{
		if (isdigit(value[i]) == 0)
		{
			return false;
		}
	}

	int integer = atof(value);
	return ((integer > 0) && (integer < 8));
}

double InputNumber()
{
	char inp_str[100];
	double input;
	printf("Input float number:");

	while (true)
	{
		fflush(stdin);
		fgets(inp_str, 100, stdin);
		input = atof(inp_str);
		if (ValidationNumber(inp_str)) {
			break;
		}
		else
		{
			printf("Invalid input. Needs to be float.");
		}
	}

	return input;
}

bool ValidationNumber(char value[])
{
	bool output = true;
	int dot_count = 0;

	for (int i = 0; i < strlen(value)-1; i++)
	{
		if (value[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
			{
				return false;
			}
		}
		if ((isdigit(value[i]) == 0) && (value[i] != '.'))
		{
			return false;
		}
	}

	return true;
}

float AlgebraicCalculation(double one, double two, int operation_index)
{
	double output;
	switch (operation_index)
	{
	case 1:
		output = one + two;
		break;
	case 2:
		output = one - two;
		break;
	case 3:
		output = one * two;
		break;
	}

	
	return output;
}

float SineCalculation(double x)
{
	double sum = 0.0;
	double eps = 0.00001;

	int i = 0;
	double buf = x;
	do
	{
		sum = sum + buf;
		i++;
		buf *= -x * x / ((2 * i) * (2 * i + 1));
	} while (fabs(buf) > eps);

	return sum;
}
float CosineCalculation(double x)
{
	double sum = 0.0;
	double eps = 0.00001;

	int i = 0;
	double buf = x;
	do
	{
		sum = sum + buf;
		i++;
		buf *= -x * x / ((2 * i - 1) * (2 * i));
	} while (fabs(buf) > eps);

	return sum;
}
float TanCalculation(double x)
{
	return SineCalculation(x)/CosineCalculation(x);
}

float CotanCalculation(double x)
{
	return CosineCalculation(x) / SineCalculation(x);
}