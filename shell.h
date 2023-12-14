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
int run_inpt(char **inpt, char **av, int id);
char *_gpath(char *inpt);
char *_genv(char *variable);
char *_itoa(int n);
void _reverse(char *str, int length);

/* string related funcitons */
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_itoa(int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

/* extra functions */
void free_adv(char **arr);
void free_null(char *str);
void _perror(char *name, char *cmd, int id);

#endif
