#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void execmd(char **argv, char **envp);
char *get_path(char *com);
char **tokenize_input(char *line, const char *dlim);
void free_cmd_argv(char **cmd_argv);
int process_input(char *line, const char *dlim, char **envp);

#endif
