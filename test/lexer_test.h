/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer_test.h
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
 
#ifndef LEXER_TEST_H
#define LEXER_TEST_H
 
#include <assert.h>
#include <stdbool.h>
#include "help.h"

#include "../src/lexer.h"

void test_match();
void test_get_token();
void test_get_output_token();
void test_get_output_append_token();

#endif /* LEXER_TEST_H */
