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
 * print_err - This is a function that display the char in stderr in the command line
 * @statusCode: This is an argument that represent the error statuscode passed
 * @prt: This is an argument that represnt the struct of the data_list of the data stored
 * 
 * Return: This function return the total number of chars passed otherwise -1 (error) 
*/
integer print_err(integer statusCode, data_list *ptr)
{
	char arr[10] = {'\0'};

	convertstr((long_number) ptr->count, arr, 10);

	if (statusCode ==  127)
	{
		printerr_ch(ptr->arg);
		printerr_ch(": ");
		printerr_ch(arr);
		printerr_ch(": ");
		printerr_ch(ptr->cmd);
		printerr_ch(": not found\n");
	}
	else if(statusCode == 126)
	{
		printerr_ch(ptr->arg);
		printerr_ch(": ");
		printerr_ch(arr);
		printerr_ch(": ");
		printerr_ch(ptr->cmd);
		printerr_ch(": Permission denied\n");
	}
	else if (statusCode == 2 || statusCode == 3)
	{
		printerr_ch(ptr->arg);
		printerr_ch(": ");
		printerr_ch(arr);
		printerr_ch(": ");
		printerr_ch(ptr->segment[0]);
		if (statusCode != 2)
			printerr_ch(": can't cd to");
		else
			printerr_ch(": Illegal number: ");
		printerr_ch(ptr->segment[1]);
		printerr_ch("\n");
	}

	return (0);
}
/**
 * _print_alias - This is a function that display the alias
 * @str: This is an argument that represent the name of the
 * alias to be displayed
 * @ptr: This is an argument that represent the data_list struct
 * 
 * Return: This function return an int (0) as sucess and (1) fauilure
*/
integer _print_alias(data_list *ptr, string str)
{
    char buff[250] = {'\0'};
    integer i = 0, k, len;

    if (ptr->list)
    {
        len = _strlen(str);

        while (ptr->list[i])
        {
            if (str == NULL || (_strcomp(ptr->list[i], str, len) && ptr->list[i][len] == '='))
            {
                for (k = 0; ptr->list[i][k]; k++)
                {
                    buff[k] = ptr->list[i][k];
                    if (ptr->list[i][k] == '=')
                        break;
                }
                buff[k + 1] = '\0';
                buff_add(buff, "'");
                buff_add(buff, ptr->list[i] + k + 1);
                buff_add(buff, "'\n");
                print(buff);
            }
            i++;
        }
    }
    return (0);
}
/**
 * print_env - This is a function that print the env
 * @ptr: This is an argument that reprsent the data list struct
 * 
 * Return: This function return a void
*/
void print_env(data_list *ptr)
{
	integer i = 0;

	while (ptr->env[i])
	{
		print(ptr->env[i]);
		print("\n");
	}
}
