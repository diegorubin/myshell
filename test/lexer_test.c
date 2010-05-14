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
	print_test_name("Get Command Sep Token");
	FILE *new_in = change_standard_input(";");

	assert(get_token(new_in) == T_CMDSEP && "test_get_token()");
	print_ok();
}

void test_get_output_token(){
	print_test_name("Get Output Token");
	FILE *new_in = change_standard_input(">");

	assert(get_token(new_in) == T_OUTPUT && "test_get_output_token()");
	print_ok();
}

void test_get_output_append_token(){
	print_test_name("Get Append Output Token");
	FILE *new_in = change_standard_input(">>");

	assert(get_token(new_in) == T_OUTPUT_APPEND && "test_get_output_append_token()");
	print_ok();
}

