#include "shell.h"
int (*get_cmd_fun(char **arg))(data_list *)
{
	int i = 0;
	builtin_fun cmd_builtin[] = BUITIN_FUNC;

	if (arg != NULL)
	{
		for (i = 0; list_t[i].fun != NULL; i++)
		{
			if (_strcmp(list_t[i].cmd, arg[0]) == 0)
				return (list_t[i].fun);
		}
	}

	return (NULL);
}
