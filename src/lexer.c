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
	char c = getc(stdin);
	
	if(c == ' ')
		return T_SPACE;
	return 0; 
}
