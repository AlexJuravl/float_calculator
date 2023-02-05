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

void SelectOperation();
bool ValidationOperation(char value[]);
bool ValidationNumber(char value[]);
double InputNumber();
void OutputResult();

float AlgebraicCalculation(double one, double two, int operation_index);

float SineCalculation(double x);
float CosineCalculation(double x);
float TanCalculation(double x);
float CotanCalculation(double x);

double result = 0.0;
double fNum = 0.0; //first number
double sNum = 0.0; //second number
int operation;


int main()
{
	SelectOperation();

	OutputResult();
}

void SelectOperation()
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

	operation = input;

	fNum = InputNumber();

	if (operation >= 1 && operation <= 3)
	{
		sNum = InputNumber();
		result = AlgebraicCalculation(fNum, sNum, operation);
	}
	else
	{
		switch (operation)
		{
		case 4:
			result = SineCalculation(fNum);
			break;
		case 5:
			result = CosineCalculation(fNum);
			break;
		case 6:
			result = TanCalculation(fNum);
			break;
		case 7:
			result = CotanCalculation(fNum);
			break;
		}
	}
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

void OutputResult()
{
	printf("%f", result);
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