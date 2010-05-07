/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer_test.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */

#include "lexer_test.h"

void test_match(){
	/* Lookahead wait a command */
	print_test_name("Match Token");
	change_standard_input(";");
	
	lookahead = T_CMDSEP;
	assert(match(';') && "test_match()");
	print_ok();
}

void test_get_token(){
	print_test_name("Get Space Token");
		
	assert(get_token() == T_CMDSEP && "test_get_token()");
	print_ok();
	
	
}
