CC = gcc
LIBS = -ll
LEX = flex
YACC = bison
all : minic
minic: minic.c minic.tab.c
	$(CC) -o $@ $^ $(LIBS)
minic.tab.c: minic.y
	$(YACC) -d $^
minic.c: minic.l
	$(LEX) -t $^ > $@
