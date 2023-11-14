#include "regex.h"

/**
 * regex_match - function checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 or 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
		return (!*pattern || (pattern[1] == '*'
				&& regex_match(str, pattern + 2)));
	if (pattern[1] == '*')
	{
		if (*pattern == '.' || *str == *pattern)
		{
			return (regex_match(str + 1, pattern)
					|| regex_match(str, pattern + 2));
		}
		else
		{
			return (regex_match(str, pattern + 2));
		}
	}
	return ((*pattern == '.' || *pattern == *str)
	&& regex_match(str + 1, pattern + 1));
}
