#ifndef GLOBAL_MARCOS
#define GLOBAL_MARCOS

/* Rename global datatype*/
typedef int integer;
typedef char * string;
typedef float decimal;
typedef long long_number;

/**
 * struct data_info - created the sturct to store the argument entered
 * @arg: This is an argumen
*/
typedef struct data_into
{
	char **arv;
	char *arg_line;
	char **env;
	char **arry;
	int builtin;
	int intact;
	path_l *path;
	alias_list *list_alias;
	int status;
	pid_t pid;
	ssize_t len;
} data_list;

#define PLACEHOLDRS \
	{ NULL, NULL, 0, NULL, 0, NULL, NULL, NULL }

#define HEX {"0123456789abcdef"}
/**
 * BUFF_SIZE - This BUFF_SIZE reprsent the inital mememory to be allocated
*/
#define BUFF_SIZE 1024
#define NEW_LINE '\n'
#define DELIME_LIST " \t\n\a\r"

extern string *environ;

/**
 * 
*/
typedef struct buitin
{
    string cmd;
    integer (*fun)(data_list *ptr);
} builtin_fun;

/***/
typedef struct path
{
	string str_path;
	struct path *next;
} path_list;

/***/
typedef struct alias
{
	string name;
	string val;
	struct alias *next;
} alias_list;

#define BUITIN_FUNC {\
	{"cd", _cd},\
	{"env", _env},\
	{"setenv", _setenv},\
	{"unsetenv", _unsetenv},\
	{"exit", exit_fun},\
	{"alias", _alias},\
	{NULL, NULL}\
}
#endif
