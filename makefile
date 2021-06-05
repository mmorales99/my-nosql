CC = gcc
OPTS = -Wextra -Wall -Wpedantic -g -o bin/
COMP = CC OPTS

EXENAME = main

FILES = main.c util.o cabinet.o
HFILES = util.h cabinet.h
CFIELS = util.c cabinet.c

make: FILES
	$(COMP) $(EXENAME) $(FILES)

run: EXENAME
	./$(EXENAME)

clean:
	rm *.o
	rm $(EXENAME)
	rm -rf bin/

cabinet.o:
	$(COMP) cabinet.o cabinet.h cabinet.c
	$(COMP) cabinet cabinet.h cabinet.c

