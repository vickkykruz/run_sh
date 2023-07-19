#include "shell.h"
char *is_shell(data_list *list_t)
{
	char *dir;
	integer(*builtin_cmd_fun(char **))(data_list *list_t);

	list_t->arry = get_cmd(list_t, list_t->arg_line, list_t->len);
	/* To eveloute this content passed */
	if (!list_t->arry)
	{
		free(list_t->arry);
		return (NULL);
	}
	validate_alias(list_t);
	expand_variable(list_t);
	builtin_cmd_fun = get_cmd_fun(list_t);

	/* If the argument passed has a builtin func */
	if (builtin_cmd_fun != NULL)
	{
		list_t->status = builtin_cmd_fun(list_t);
		if (list_t->arry != NULL)
			free_arr_ptr(list_t->arry);
		list_t->builtin = 1;
		return (NULL);
	}

	/* else we check if the argument is a system program */
	dir = find_path(list_t->path, list_t->arry[0]);

	/* If failed */
	if (!dir)
	{
		write(STDERR_FILENO, list_t->arv[0], _strlen(list_t->arv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, list_t->arry[0], _strlen(list_t->arry[0]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		list_t->status = 2;
		free_arr_ptr(list_t->arry);
		free(dir);
		return (NULL);
	}

	return (dir);
}
/**
 * shell_loop - This is a function that loop the program after an exection
 * has been made.
 * @prompt: This is an argument that showcase the prompot to the user
 * @prt: This is an argument that reprsent the struct the data_list use to store
 * the data or responsd passed
 * 
 * Return: This function return a void (nothing)
*/
void shell_loop(data_list *list_t)
{
  string pth;
  
  if (list_t->arv[1])
    exit (98);
  else if (!isatty(STDIN_FILENO))
     solo_shell(list_t);
  else
    {
      for (; ;)
	{
	  print("($) ");
	  fflush(stdout);
	  pth = is_shell(list_t);
	  if (!pth)
	    continue;
	  list_t->pid = fork();
	  if (list_t->pid == 0)
	    {
	      list_t->status = execve(path, list_t->arry, list_t->env);
	      if (list_t->status == -1)
		{
		  write(STDERR_FILENO, shell->av[0], my
			_strlen(shell->av[0]));
		  write(STDERR_FILENO, ": ", 2);
		  write(STDERR_FILENO, shell->arr[0], m
			y_strlen(shell->arr[0]));
		  write(STDERR_FILENO, ": Permission de
nied\n", 20);
		  free(pth);
		  list_t->status = 13;
		  call_exit(shell);
		}
	    }
	  else
	    {
	      wait(&list_t->status);
	      list_t->status = WEXITSTATUS(list_t->status);
	    }
	  free_arr2(list_t->arry);
	  free(pth);
	}
    }
}
