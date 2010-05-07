# Makefile para o projeto MyShell
# Escrito por Diego Rubin <rubin.diego@gmail.com>

SRC_DIR=src
TEST_DIR=test

C_SOURCES=$(wildcard $(SRC_DIR)/*.c)
C_OBS=$(C_SOURCES:.c=.o)

TEST_SOURCES=$(wildcard $(TEST_DIR)/*.c)
C_FLAGS= -std=c99 -Wall

all: myshell

myshell: $(C_SOURCES:.c=.o)
	@echo Construindo Projeto
	gcc -o $@ $^ 

test: $(TEST_SOURCES:.c=.o)
	@echo Construindo testes
	gcc -std=c99 -o myshell_test $^ $(C_OBS:$(SRC_DIR)/main.o=)
	./myshell_test

clean:
	@echo Limpando arquivos
	rm -f $(SRC_DIR)/*.o $(TEST_DIR)/*.o myshell myshell_test *~

%.o: %.c
	@echo Compilando $@
	gcc -c $< $(C_FLAGS) -o $@

