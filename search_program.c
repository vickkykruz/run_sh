#include "shell.h"
/***/
char *find_path(path_list *lists, char *f)
{
	struct stat s;
	path_list *tmp = lists;
	char *dir;

	/** Loop the system stuct to find a match **/
	while (tmp)
	{
		dir = malloc(sizeof(char) * (_strlen(tmp->str_path) + _strlen(f) + 2));
		if (f[0] == '/')
		{
			free(dir);
			if (stat(f, &s) == 0)
			{
				dir = _strdup(f);
				return (dir);
			}
			else
				return (NULL);
		}

		_strcpy(dir, tmp->str_path);
		_strcat(dir, "/");
		_strcat(dir, f);
		if (stat(dir, &s) == 0)
			return (dir);

		free(dir);
		tmp = tmp->next;
	}
	return (NULL);
}
