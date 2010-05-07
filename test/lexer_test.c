/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer_test.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "lexer_test.h"

void test_match(){
	/* Lookahead wait a command */
	print_test_name("Match Space Token");
	
	lookahead = T_CMDSEP;
	assert(match(';') && "test_match()");
	print_ok();
}

void test_get_token(){
	print_test_name("Get Space Token");
	static char input[] = "casa";
	
	/* change default input */
	int buffer = fmemopen (input, strlen(input), "r");
	close(0);
	dup2(buffer,0);
	
	assert(get_token() == T_CMDSEP && "test_get_token()");
	print_ok();
	
	
}
