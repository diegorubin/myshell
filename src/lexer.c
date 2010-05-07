/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lexer.h"

static bool is_special(int c)
{
	return c == T_SPACE
	    || c == T_PIPE
	    || c == T_INPUT
	    || c == T_OUTPUT
	    || c == T_CMDSEP
	    || c == T_BACKGROUND
	    || c == T_EOL
		|| c == EOF;
}

token_t get_token(){
	int c;
	
	while(true){
		c = getc(stdin);
		switch(c){
			case T_SPACE:
				continue;
			case ';':
				return T_CMDSEP; 
			case EOF:
				return EOF;
			case '\n':
				return T_EOL;
			case '>':
				return T_OUTPUT;
			default:{
				int i = 0;
       	 		do{
       				lexeme[i++] = c; 
	 			} while (!is_special(c = fgetc(stdin)));
       	 		lexeme[i] = '\0';
       	 		ungetc(c,stdin);
       	 		return T_ARGUMENT;
       	 	}
		}
	} 
}

int match(token_t expected)
{

   if (lookahead != expected) {
     fprintf (stderr, "Erro de sintaxe! %d:%c", lookahead, expected);
     return false;
   }
   lookahead = get_token();
   return true;
}

