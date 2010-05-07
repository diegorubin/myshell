/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * lexer.h
 * Copyright (C) Diego Rubin 2010 <rubin.diego@gmail.com>
 * 
 */
 
#ifndef LEXER_H
#define LEXER_H 

char lexeme[1024];
typedef int token_t;

enum {
        T_SPACE = ' ',
        T_PIPE = '|',
        T_INPUT = '<',
        T_OUTPUT = '>',
        T_CMDSEP = ';',
        T_BACKGROUND = '&',
        T_EOL = '\n',
        T_ARGUMENT = 1024,
};


token_t lookahead;

token_t get_token();
int match(token_t expected);

#endif /* LEXER_H */
