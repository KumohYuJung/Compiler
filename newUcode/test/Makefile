CC		= g++
STDLIB 	= c++0x
COMPILE = objects

labelTest : labelTest.o
	mkdir -p ../$(COMPILE)
	mv *.o ../$(COMPILE)	
	cd ../assembler; make
	cd ../$(COMPILE); $(CC) -o $@ $< label.o
labelTest.o : labelTest.cpp
	$(CC) -c -std=$(STDLIB) $<
