#include "shell.h"
/***/
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	/*** initizaled the variables **/
	char *new_node;
	unsigned int i;

	if (ptr == NULL)
	{
		ptr = malloc(n_size);
		return (ptr);
	}

	if (o_size == n_size)
		return (ptr);

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/** Allocate the new size */
	new_node = malloc(n_size);
	if (new_node == NULL)
		return (NULL);

	/** Increament the size **/
	for (i = 0; i < n_size && i < o_size; i++)
		;
	memcpy(new_node, ptr, i);
	free(ptr);

	return (new_node);
}
/***/
void _memcpy(void *des, const void *src, unsigned int size)
{
	char *ptr = (char *)src;
	char *new_node = (char *)des;
	unsigned int i;

	for (i = 0; i < size; i++)
		new_node[i] = ptr[i];
}
/***/
void insert_line(char **lineptr, size_t *num, char *buff, size_t size)
{
	if (*lineptr == NULL || *num < size)
	{
		if (size > BUFF_SIZE)
			*num = size;
		else
			*num = BUFF_SIZE;
		*lineptr = buff;
	}
	else
	{
		_strcpy(*lineptr, buff);
		free(buff);
	}
}
/***/
void reverse_str(char * str)
{
	int i, j, k;
	char tmp;

	for (i = 0; str[i] != '\0'; i++)
		;

	for (j = 0; j < (i - 1); j++)
	{
		for (k = j + 1; k > 0; k--)
		{
			tmp = str[k];
			str[k] = str[k - 1];
			str[k - 1] = tmp;
		}
	}
}
