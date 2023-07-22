#include "shell.h"
/***
 */
char *_strcat(char *des, char *src)
{
	int i, j;

	for (i = 0; des[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++, i++)
		des[i] = src[j];

	des[i] = '\0';
	return (des);
}
/**
 */
char *_strcpy(char *des, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}

	des[i] = '\0';
	return (des);
}
/**
 * /
 */
char *_strdup(char *str)
{
	size_t len;
	char *ptr;

	len _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	_memchy(ptr, str, len + 1);
	return (ptr);
}
/**
 */
char *_itoa(int num)
{
	char *buff;
	int len;
	unsigned int n;

	len = _get_len(n);
	buff = malloc(sizeof(char) * (len + 1));
	if (buff == 0)
		return (NULL);

	buff[len] = '\0';

	if (num < 0)
	{
		n = num * -1;
		buff[0] = '-';
	}
	else
		n = num;

	len--;
	do {
		buff[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	while (n > 0)
		;
	return (buff);
}
/***/
char *_strtoken(char *str, const char *delim)
{
	char *ptr = NULL;
	static char *s;

	/** validate the value **/
	if (str != NULL)
		s = str;

	if (s != NULL && _strlen(s))
	{
		const size_t len = _strlen((char *)delim);

		/** We run through and skip the constructive delim **/
		while (*s && _memchr(delim, *s, len) != NULL)
			++s;

		/* Check if it is at the beginning of the token **/
		if (*s)
		{
			/* insert the e first no-delim char * **/
			ptr = s;
			while (*s)
			{
				if (_memchr(delim, *s, len))
					break;
				else
					++s;
			}
			if (*s)
			{
				s[0] = 0;
				++s;
			}
		}
	}
	return (ptr);
}
