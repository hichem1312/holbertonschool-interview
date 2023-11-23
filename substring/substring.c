#include "substring.h"
/**
 *find_substring - a function that finds all the possible substrings
 *@s: the string to scan
 *@words: the array of words all substrings must be a concatenation arrangement
 *@nb_words: the number of elements in the array words
 *@n: holds the address at which to store the number of elements
 * Return: 0 or 1
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int string_len, word_len, i = 0, j, k;
	int *find, *substrings;

	if (!s)
		return (NULL);

	*n = 0;
	string_len = strlen(s);
	word_len = strlen(words[0]);

	find = malloc(nb_words * sizeof(int));
	substrings = malloc(string_len * sizeof(int));

	while (i <= string_len - nb_words * word_len)
	{
		for (j = 0; j < nb_words; j++)
			find[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (find[k] == 0 && strncmp(s + i + j *
					word_len, words[k], word_len) == 0)
				{
					find[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			substrings[(*n)++] = i;
		i++;
	}
	free(find);
	return (substrings);
}