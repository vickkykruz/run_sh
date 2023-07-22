#include "shell.h"
int (*get_cmd_fun(char **arg))(data_list *)
{
	int i = 0;
	builtin_fun cmd_builtin[] = BUITIN_FUNC;

	if (arg != NULL)
	{
		for (i = 0; cmd_builtin[i].fun != NULL; i++)
		{
			if (_strcmp(cmd_builtin[i].cmd, arg[0]) == 0)
				return (cmd_builtin[i].fun);
		}
	}

	return (NULL);
}
