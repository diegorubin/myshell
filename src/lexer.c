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

token_t get_token(){
	char c;
	
	while(true){
		c = ';';
		switch(c){
			case T_SPACE:
				continue;
			case T_CMDSEP:
				return c;
		}
	} 
}

int match(token_t expected)
{

   if (lookahead != expected) {
     fprintf (stderr, "Erro de sintaxe!");
     return false;
   }
   lookahead = get_token();
   return true;
}

