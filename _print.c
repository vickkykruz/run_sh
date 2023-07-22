#include "shell.h"
/**
 * printerr_ch - This is a function that display an array of chars in stderr
 * to the command line
 * @str: This is an argument that represent the given sting passed
 * 
 * Return: This function return the total number of bytes in the string
*/
integer printerr_ch(string str)
{
    integer len = 0;

    len = _strlen(str); /*Get the total len of the string*/

    return (write(STDERR_FILENO, str, len));
}
/**
 * print - This is a function that print the chars in stdout in the command line
 * @str: This is an arguent that represent the string pased
 * 
 * Return: This function return the total number of chars passed otherwise -1 (error)
*/
integer print(string str)
{
    integer len = 0;

    len = _strlen(str);

    return (write(STDOUT_FILENO, str, len));
}
/**
 * print_alias - This is a function that display the alias
 * @list_t: This is an argument that represent the data_list struct
 * 
 * Return: This function return an int (0) as sucess and (1) fauilure
*/
integer print_alias_list(data_list *list_tr)
{
	alias_list *tmp;
	int len1, len2;
	char *ptr;

	tmp = list_t->list_alias;

	if (tmp == NULL)
		return (0);

	while (tmp)
	{
		len1 = _strlen(tmp->str);
		len2 = _strlen(tmp->val);
		ptr = malloc(sizeof(char) * (len1 + len2 + 2));
		if (ptr == NULL)
			return (12);

		_strcpy(ptr, tmp->str);
		_strcat(ptr, "=");
		_strcat(ptr, tmp->val);

		write(STDOUT_FILENO, ptr, len1 + len2 + 1);
		write(STDOUT_FILENO, "\n", 1);

		free(ptr);
		tmp = tmp->next;
	}
	return (0);
}
/***
 */
int print_alias(data_list *list_t, char *str)
{
	alias_list *tmp;
	int len1, len2;
	char *ptr = NULL;

	tmp = list_t->list_alias;
	if (tmp == NULL)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "not found\n", 11);
		return (1);
	}
	while (tmp)
	{
		if (_strcmp(str, tmp->str) == 0)
		{
			len1 = _strlen(tmp->str);
			len2 = _strlen(tmp->val);
			ptr = malloc(sizeof(char) * (len1 + len2 + 2));
			if (ptr == NULL)
				return (12);
			_strcpy(ptr, tmp->str);
			_strcat(ptr, "=");
			_strcat(ptr, tmp->val);

			write(STDOUT_FILENO, ptr, len1 + len2 + 1);
			write(STDOUT_FILENO, "\n", 1);
			free(ptr);
		}
		tmp = tmp->next;
	}
	return (0);
}
