#include "holberton.h"
/**
* _strlen - calculate length of string
* @s: text
* Return: integer
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
/**
 * Error - print error
 *
 */
void Error(void)
{
	int i;
	char text[] = "Error\n";

	for (i = 0; i <= 5; i++)
		_putchar(text[i]);
	exit(98);
}
/**
* isDigits - verify if num is a number
* @s: string
*/
void isDigits(char *s)
{
	int i;

	for (i = 0; i < _strlen(s); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			Error();
		}
	}
}
/**
* main - function
* @argc: number of args
* @argv: arguments
* Return: 0
 */
int main(int argc, char *argv[])
{
	int L1, L2, i, j, c = 0, carry, var = 0;
	int *result;
	char *str;

	if (argc - 1 != 2 || argv[1] == NULL || argv[2] == NULL)
	{
		Error();
	}

	isDigits(argv[1]);
	L1 = _strlen(argv[1]);
	isDigits(argv[2]);
	L2 = _strlen(argv[2]);

	result = malloc(sizeof(int) * (L1 + L2));
	for (i = L1 - 1; i >= 0; i--)
	{
		c = L1 - 1 - i;
		carry = 0;
		for (j = L2 - 1; j >= 0; j--, c++)
		{
			result[c] += (argv[1][i] - '0') * (argv[2][j] - '0') + carry;
			carry = result[c] / 10;
			result[c] %= 10;
		}
		if (carry)
			result[c++] = carry;
		if (result[c - 1])
			var = MAX(var, c - 1);
	}
	str = malloc(sizeof(char) * 1024);
	for (i = var; i >= 0; i--)
		str[var - i] = result[i] + '0';
	str[var + 1] = '\0';
	free(result);
	printf("%s\n", str);
	return (0);
}
