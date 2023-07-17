#ifndef SHELL_PROJECT
#define SHELL_PROJECT

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include "global_marcos.h"

/*** PROTOTYPES ***/

/*** SHELL_LOOP.C FILE ****/
void shell_loop(data_list *list_t);
#endif
