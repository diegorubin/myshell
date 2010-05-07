/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * parser.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
#include "parser.h"
#include "lexer.h"

extern token_t lookahead;

void command_line()
{
    first_command = new_command();
    if (lookahead == T_EOL) {
      if (strcmp(first_command->args[0],"cd") == 0){
        builtin_cd(first_command);
      } else if (strcmp(first_command->args[0],"pwd") == 0){
        builtin_pwd(first_command);
      } else if (strcmp(first_command->args[0],"exit") == 0){
        builtin_exit(first_command);
      } else { 
        run_command(first_command);
      }
      match(T_EOL);
    }
    

}

type_command *new_command(){
         type_command *new = calloc(1, sizeof(type_command));
         new->argc = 0;
         new->output = NULL;

         do {
			/* arguments */
			new->args[new->argc] = strdup(lexeme);
			new->argc++;
			match(T_ARGUMENT);

         } while(lookahead == T_ARGUMENT);

         new->args[new->argc] = NULL;  
		
         return new;
}

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
		if(cmd->output != NULL) { 
			int f = open(cmd->output, O_WRONLY | O_CREAT, 0666);
			close(1);
			dup2(f,1);
			close(f);
		}
		execvp(cmd->args[0],cmd->args);
		perror("exec");
		exit(127);
	}
	 
   int status;
   waitpid(lastchild,&status,0);
   return status;

}

int builtin_cd (type_command *cmd){
  if (cmd->argc > 2) { 
	fprintf(stderr, "cd: argumentos demais\n"); 
	return 1; 
  } else if (cmd->argc == 2) { 
	int ret = chdir(cmd->args[1]); 
	if (ret < 0) perror("chdir"); 
	return ret; 
  } else { 
	fprintf(stderr, "cd: falta argumento\n"); 
	return 1; 
  }

}

int builtin_pwd (type_command *cmd){
  if (cmd->argc > 1) { 
	fprintf(stderr, "pwd: argumentos demais\n"); 
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
	fprintf(stderr, "exit: argumentos demais\n"); 
	return 1; 
  } else { 
	exit(0); 
  } 

}

