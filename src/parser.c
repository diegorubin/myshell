/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * parser.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 *
 */
#include "parser.h"
#include "lexer.h"

extern token_t lookahead;
int pd[2];

/* Interpreta o comando digitado */
void command_line()
{
    command = new_command(false);
    if (lookahead == T_EOL) {
      if (strcmp(command->args[0],"cd") == 0){
        builtin_cd(command);
      } else if (strcmp(command->args[0],"pwd") == 0){
        builtin_pwd(command);
      } else if (strcmp(command->args[0],"exit") == 0){
        builtin_exit(command);
      } else {
        run_command(command);
      }
    }
}

/* Cria na memória a estrutura que guardará o comando a ser executado */
type_command *new_command(int is_pipe){
    type_command *new = calloc(1, sizeof(type_command));
    new->argc = 0;
    new->output = NULL;
    new->input = NULL;
    new->next = NULL;

    do {
        new->args[new->argc] = strdup(lexeme);
		new->argc++;
		match(T_ARGUMENT);

     } while(lookahead == T_ARGUMENT);

     if (lookahead == T_PIPE){
        new->next = new_command(true);
        match(T_PIPE);
     }

     if (lookahead == T_INPUT && !is_pipe){
        match(T_INPUT);
        new->input = strdup(lexeme);
        match(T_ARGUMENT);
     }

     if ((lookahead == T_OUTPUT || lookahead == T_OUTPUT_APPEND) && new->next == NULL){
     	if(lookahead == T_OUTPUT){
			match(T_OUTPUT);
			new->output_mode = O_WRONLY | O_CREAT;
		}
		else{
			match(T_OUTPUT_APPEND);
			new->output_mode = O_WRONLY | O_APPEND | O_CREAT;
		}
		new->output = strdup(lexeme);
		match(T_ARGUMENT);
	  }

     new->args[new->argc] = NULL;

     return new;
}

/* Executa um comando */
int run_command(type_command *cmd){
	int lastchild;
	int pid;

	pid = fork();
	if (pid < 0) {
		perror("fork");
		exit(1);
	} else if (pid > 0){
		lastchild = pid;
	} else {
	    if(cmd->input != NULL){
	        int file_input = open(cmd->input, O_RDONLY);
	        close(0);
	        dup2(file_input,0);
	        close(file_input);
	    }
		if(cmd->output != NULL) {
			int file_output = open(cmd->output, cmd->output_mode, 0666);
			close(1);
			dup2(file_output,1);
			close(file_output);
		}
		if(cmd->next != NULL){
            /* código para a pipeline complexa */
            /* o algoritimo ainda esta sendo construido */
            dup2(pd[1], 1);
            close(pd[1]);
			run_command(cmd->next);
		}
		execvp(cmd->args[0],cmd->args);
		perror(cmd->args[0]);
		exit(3);
	}

   int status;
   waitpid(lastchild,&status,0);
   return status;

}

int builtin_cd (type_command *cmd){
  if (cmd->argc > 2) {
	fprintf(stderr, "o comando cd só aceita um argumento.\n");
	return 1;
  } else if (cmd->argc == 2) {
	int ret = chdir(cmd->args[1]);
	if (ret < 0) perror("chdir");
	return ret;
  } else {
	fprintf(stderr, "cd\n Uso: cd <caminho_do_diretorio>\n");
	return 1;
  }

}

int builtin_pwd (type_command *cmd){
  if (cmd->argc > 1) {
	fprintf(stderr, "o comando pwd não aceita argumentos\n");
	return 1;
  } else {
	char ret[1024];
	if (getcwd(ret, sizeof(ret)) != NULL) {
		printf("%s\n", ret);
		return 0;
	} else {
		perror("getcwd");
		return 1;
	}
  }
}

int builtin_exit (type_command *cmd){
  if (cmd->argc > 1) {
	fprintf(stderr, "o comando exit não aceita argumentos\n");
	return 1;
  } else {
	exit(0);
  }

}

