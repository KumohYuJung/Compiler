CC = gcc
LIBS = -ll -ly
LEX = flex
YACC = bison
all : minic
debug : minic.c minic.tab.c minic_ast.c
	$(CC) -g -o $@ $^ $(LIBS)
minic: minic.c minic.tab.c minic_ast.c ucode_gen.c
	$(CC) -o $@ $^ $(LIBS)
minic.tab.c: minic.y
	$(YACC) -d $^
minic.c: minic.l
	$(LEX) -t $^ > $@
