/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * help.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
#include <stdio.h>
#include "help.h"

void print_test_name(char *test_name){
	number_of_tests++;
	printf("Test %d -> %s:",number_of_tests,test_name);
}

void print_ok(){
	printf(" Ok\n");
}
