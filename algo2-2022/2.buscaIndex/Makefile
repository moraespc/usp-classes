MAIN = main.c
#Adicionar variáveis para outros arquivos .c que precisar na compilação
#Ex: STUDENT = Student.chec
INDEX = IndexHandler.c
ALUNO = Aluno.c
BINARY = main
NAME = BUSCAINDICEPRIMARIO

#adicionar todos os .c que serão compilados ao lado do $(MAIN)
all:
	gcc -Wall -g $(MAIN) -o $(BINARY) $(ALUNO) $(INDEX)

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r $(NAME).zip *.c *.h Makefile

clean:
	@rm *.o