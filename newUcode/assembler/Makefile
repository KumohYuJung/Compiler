CC		= g++
STDLIB  = c++0x
COMPILE = objects

assemble: Label.o Assembler.o
	mkdir -p ../$(COMPILE)
	mv *.o ../$(COMPILE)

Label.o : Label.cpp
	$(CC) -c -std=$(STDLIB) $<

Assembler.o : Assembler.cpp
	$(CC) -c -std=$(STDLIB) $<
