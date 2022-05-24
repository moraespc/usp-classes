MAIN = main.c
#Adicionar variáveis para outros arquivos .c que precisar na compilação
#Ex: STUDENT = Student.chec
FILEHANDLER = BinaryFileHandler.c
ALUNO = Aluno.c
BINARY = main
NAME = FILEFIELDS

#adicionar todos os .c que serão compilados ao lado do $(MAIN)
all:
	gcc -Wall -g $(MAIN) -o $(BINARY) $(FILEHANDLER) $(ALUNO)

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r $(NAME).zip *.c *.h Makefile

clean:
	@rm *.o