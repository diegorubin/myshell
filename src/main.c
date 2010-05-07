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

int main(int argc, char *argv[]) {
	do {
		printf("[]$ ");
		lookahead = get_token();
	} while (lookahead != EOF);
	return 0;
}
