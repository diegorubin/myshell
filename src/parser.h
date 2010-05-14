/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * parser.h
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 *
 */
#ifndef PARSER_H
#define PARSER_H
#define MAX_ARGS 20

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <glob.h>
#include <sys/wait.h>

typedef struct command_struct type_command;
struct command_struct {
        int argc;
        char *args[MAX_ARGS];
        char *output;
        int output_mode;
        char *input;
};

struct command_struct *first_command;

void command_line();
type_command *new_command();
int run_command(type_command *cmd);
void fill_args();

/* intenal commands */
int builtin_cd(type_command *cmd);
int builtin_pwd(type_command *cmd);
int builtin_exit(type_command *cmd);

#endif /* PARSER_H */

