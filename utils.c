#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - Entry point
 * @dest: string dest
 * @src: string src
 * Description: 'Check if a character is uppercase'
 * Return: Always 0 (Success)
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - Entry point
 * @str: string
 * Description: 'fill the first n bytes of s with b'
 * Return: Always 0 (Success)
 */

char *_strdup(char *str)
{
	char *s;
	unsigned int i, size;

	if (str == NULL)
	{
		return (NULL);
	}

	for (size = 0; str[size] != '\0'; size++)
	{
	}

	s = malloc((size * sizeof(char)) + 1);
	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		*(s + i) = *(str + i);
	}
	s[i] = '\0';
	return (s);
}

/**
 * _strlen - Entry point
 * @s: pointer to n address
 * Description: 'Check if a character is uppercase'
 * Return: Always 0 (Success)
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}

	return (i);
}


/**
 * _strcmp - Entry point
 * @s1: string dest
 * @s2: string src
 * Description: 'Check if a character is uppercase'
 * Return: Always 0 (Success)
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((int) s1[i] - s2[i]);
		}
	}
	return ((int) s1[i] - s2[i]);
}
