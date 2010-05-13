/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * help.h
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 *
 */

#ifndef HELP
#define HELP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

static int number_of_tests = 0;
static int buffer = 0;

void print_test_name(char *test_name);
void print_ok();
FILE *change_standard_input(const char input[]);

#endif /* HELP */

