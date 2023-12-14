#include "shell.h"

/**
 * _strdup - copy of the string in a newly allocated space in memory
 * @str: char type pointer
 * Return: pointer to the string
 */

char *_strdup(char *str)
{
	char *new;
	int i, len;

	if (str == 0)
		return (NULL);

	i = len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (*str)
	{
		new[i++] = *str++;
	}
	new[i] = '\0';
	return (new);
}

/**
 * *_strcpy - copy string fro src to dest
 * @dest: char type input
 * @src: char type input
 * Return: dust.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcat - concatenates two strings.
 * @dest: char type pointer
 * @src: char type pointer
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}

/**
 * _itoa - int to ascii convertion
 * @n: integer
 *
 * Return: ascii
 */

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	_reverse(buffer, i);

	return (_strdup(buffer));
}

/**
 * _reverse - reverse a string
 * @str: the string to reverse
 * @len: length of the string
 */

void _reverse(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		str++;
		end--;
	}
}
