/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lexer.h"
#include "parser.h"

void line(){
	char ret[1024];
	getcwd(ret, sizeof(ret));
	printf("[myshell:%s]$ ",ret);
}

int main(int argc, char *argv[]) {
	do {
		line();
		lookahead = get_token();
		if(lookahead != EOF)
			command_line();
		else
			printf("\n");
	} while (lookahead != EOF);
	return 0;
}
