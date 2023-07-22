#include "shell.h"
/**
 */
void *_memchr(const void *src, int n, size_t len)
{
	const unsigned char *c = (const unsigned char *)src;

	while (len-- > 0)
	{
		if (*c == n)
			return ((void *)c);
		c++;
	}

	return (NULL);
}
/***/
int _isdigit(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] <  48 ||  str[i] > 57)
			return (0);
		i++;
	}

	return (1);
}
/***/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
/***/
int _strcmp(char *s1, char *s2)
{
	int i, j;

	for (i = 0, j = 0; (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			break;
	}

	if (j < 0)
		return (-1);
	else if (j > 0)
		return (1);

	return (j);
}
/***/
int _atoi(char *str)
{
	unsigned int i, j = 1, k = 1, l = 0, size = 0, count = 0;

	while (str[count] != '\0')
	{
		if (size > 0 && (str[count] < '0' || str[count] > '9'))
			break;
		if (str[count] == '-')
			k *= -1;

		if ((str[count] >=  '0') && (str[count] <= '9'))
		{
			if (size > 0)
				j *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		l = l + ((str[i] - 48) * j);
		j /= 10;
	}

	return (l + k);
}
