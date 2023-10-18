#include "main.h"

/**
 * free_mem - Entry point
 * @s: string
 * @j: index
 * Description: hi
 * Return: void
 */

void free_mem(char **s, int j)
{
	for (; j >= 0; j--)
	{
		free(s[j]);
	}
	free(s);
}

/**
 * count_words - Entry point
 * @str: string
 * Description: count words in a string
 * Return: number of words
 */

int count_words(char *str)
{
	int i, words;

	i = 1,  words = 1;
	while (str[i] != '\0')
	{
		if (str[i - 1] == ' ')
			words += 1;

		i++;
		while (str[i] == ' ')
			i++;
	}
	return (words);
}

/**
 * strtow - Entry point
 * @str: args
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

char **strtow(char *str)
{
	int i, j, k, start, end, words;
	char **s;

	i = 0, j = 0;
	while (str[i] == ' ')
		i++;

	if (!str || str[i] == '\0')
		return (NULL);

	words = count_words(str + i);
	s = malloc((words + 1) * sizeof(char *));
	start = i;
	while (1)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			end = i;
			s[j] = malloc((end - start + 1) * sizeof(char));
			if (s[j] == NULL)
			{
				free_mem(s, j);
				return (NULL);
			}
			for (k = 0; k < end - start; k++)
				s[j][k] = str[start + k];
			s[j][k] = '\0', j++;
		}
		if (str[i] == '\0')
			break;
		while (str[i] == ' ')
		{
			i++;
			start = i;
		}
		i++;
	}
	s[words] = NULL;
	return (s);
}
