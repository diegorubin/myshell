/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * myshell_test.c
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 * Arquivo principal dos testes unitarios.
 */
 
 #include <stdio.h>
 
 #include "lexer_test.h"
 
 int main(){
 	printf("----------------------");
 	printf("|  Executanto Testes Unitarios  |");
 	printf("----------------------");
 	printf("\n");
 	
 	test_get_token();
 	
 	return 0;
 }
