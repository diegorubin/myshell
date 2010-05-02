# Makefile para o projeto MyShell
# Escrito por Diego Rubin <rubin.diego@gmail.com>

LOCAL_DIR=
SRC_DIR=src
TEST_DIR=test

C_SOURCES=$(wildcard $(SRC_DIR)/*.c)
C_FLAGS= -Wall

all: myshell test

myshell: $(C_SOURCES:.c=.o)
	@echo Construindo Projeto
	gcc -o $@ $^ 

clean:
	@echo Limpando arquivos
	rm -f $(SRC_DIR)/*.o myshell *~

%.o: %.c
	gcc -c $< $(C_FLAGS) -o $@

