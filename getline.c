#include "shell.h"
ssize_t _getline(char **buff, size_t *num, FILE *stream)
{
	char *buff_size, ch = 'c';
	size_t size;
	int fd;
	static ssize_t line;
	ssize_t n;

	/** Allocate space to store the command line **/
	buff_size = malloc(sizeof(char) * BUFF_SIZE);
	if (buff_size == NULL)
		return (-1);
	fd = fileno(stream);

	while (ch != NEW_LINE)
	{
		n = read(fd, &ch, 1);
		if ((n == 0 && line == 0) || n == -1)
		{
			free(buff_size);
			return (-1);
		}
		if (n == 0 && line != 0)
		{
			line++;
			break;
		}
		if (line >= BUFF_SIZE)
			_realloc(buff_size, line, line + 1);

		buff_size[line] = ch;
		line++;
	}
	insert_line(buff, num, buff_size, line);
	size = line;
	if (n != 0)
		line = 0;
	return (size);
}
/***/
char **get_cmd(data_list *list_t, char *buff, size_t num)
{
	ssize_t i = 0, n;
	size_t j = 0;
	char *token;
	char **idx_arr= NULL;

	/** Get the input command **/
	n = _getline(&buff, &n, stdin);
	if (n == -1)/* if the function failed */
	{
		free(buff);
		list_t->intact = 3;
		return (idx_arr);
	}

	/* Remove comment and return the number of idexs */
	n = remove_comments(&buff);
	if (n == 0) /* if failed */
		return (NULL);

	while (i < n)
	{
		if (buff[i] == ' ' || buff[i] == '\n' || buff[i] == '\t' ||
				buff[i] == '\r' || buff[i] == '\a')
			j++;
		else
			continue;
		i++;
	}
	/** Alocate space to stroe the command */
	idx_arr = malloc(sizeof(string) * (j + 1));
	token = _strtoken(buff, DELIME_LIST);
	i = 0;

	while (token != NULL)
	{
		idx_arr[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(idx_arr[i], token);
		token = _strtoken(NULL, DELIME_LIST);
		i++;
	}

	idx_arr[i] = NULL;
	free(buff);

	return (idx_arr);
}
/***/
int _set(data_list *list_t)
{
	char **nevn;
	int i, j, k = 0, num, chk = 0;

	/* Get the total len of the env **/
	for (i = 0; list_t->env[i]; i++)
		;
	/* check if the fiest index or second index is NULL */
	if (list_t->arry[1] == NULL || list_t->arry[2] == NULL)
		return (cmd_cd_err(list_t, 2));

	/* Allocate a new evn node **/
	nevn = malloc(sizeof(char *) * (i + 2));
	if (nevn == NULL)
		return (12);

	/** Loop and insert **/
	for (i = 0; list_t->env[i]; i++)
	{
		/* initaize the second index and the checker */
		j = 0, num = 0;
		while (list_t->env[i][j] != '=' && list_t->arry[1][j] != '\0')
		{
			if (list_t->env[i][j] != list_t->arry[1][j])
				num = 1;
			j++;
		}
		/* Each if checking index is 0 */
		if (num = 0)
		{
			nevn[k] = modify_env(list_t);
			k++, chk = 1;
			continue;
		}
		nevn[k] = _strdup(list_t->env[i]);
		k++;
	}
	if (chk == 0)
	{
		nevn[k] = modify_env(list_t);
		nevn[k + 1] = NULL;
	}
	else
		nevn[k] = NULL;
	free_arr_ptr(list_t->env);
	list_t->env = nevn;

	return (0);
}
int _unset(data_list *list_t)
{
	char **nevn;
	int i, j, k = 0, num, chk = 0;

	/** Get the total len of the env **/
	for (i = 0; list_t->env[i]; i++)
		;
	if (list_t->arry[1] == NULL)
		return (cmd_cd_err(list_t, 3));

	/* Allocate spave for the env */
	nevn = malloc(sizeof(string) * (i + 1));
	if (nevn == NULL)
		return (12);
	/* Run the loop */
	for (i = 0; list_t->env[i]; i++)
	{
		j = 0, num = 0;
		while (list_t->env[i][j] != '=' && list_t->arry[1][j] != '\0')
		{
			if (list_t->env[i][j] != list_t->arry[1][j])
				num = 1;
			j++;
		}
		if (num == 0)
		{
			chk = 1;
			continue;
		}
		nevn[k] = _strdup(list_t->env[i]);
		k++;
	}
	nevn[k] = NULL;
	if (chk == 0)
	{
		perror("Environment variable does not exist\n");
		free_arr_ptr(nevn);
		return (6);
	}
	free_arr_ptr(list_t->env);
	list_t->env = nevn;

	return (0);
}
