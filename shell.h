#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* extern */
extern char **environ;

/* main functions */
char *get_input(void);
char **_splitter(char *linep);
int run_inpt(char **inpt, char **av);

/* string related funcitons */
char *_strdup(char *str);

/* extra functions */
void free_adv(char **arr);
void free_null(char *str);

#endif
