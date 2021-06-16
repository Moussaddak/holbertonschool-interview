#include "palindrome.h"

/**
 * is_palindrome - checks unsigned integer is a palindrome.
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long tmp, nrev = 0;
	tmp = n;

	while (tmp > 0)
	{
		nrev *= 10;
		nrev += tmp % 10;
		tmp /= 10;
	}
	return (n == nrev);
}