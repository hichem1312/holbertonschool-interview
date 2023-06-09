#include "palindrome.h"
/**
 * is_palindrome - a function that checks whether or not a given unsigned integer is a palindrome
 * @n: integer
 * Return: EXIT_SUCCESS
 */
int is_palindrome(unsigned long n)
{
	unsigned long a = 0, b, c;

	c = n;
	while (n != 0)
	{
		b = n % 10;
		a = a * 10 + b;
		n /= 10;
	}
	return (c == a);
}