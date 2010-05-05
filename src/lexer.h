/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer.h
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
 
#ifndef LEXER_H
#define LEXER_H 
 
typedef int token_t;

enum {
	T_SPACE = ' ',
};

token_t lookahead;

token_t get_token();
void match(token_t token);

#endif /* LEXER_H */
