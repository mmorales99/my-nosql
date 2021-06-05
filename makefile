CC = gcc
OPTS = -Wextra -Wall -Wpedantic -g
COMP = $(CC) $(OPTS)

EXENAME = main

HFILES = util.h cabinet.h
CFIELS = util.c cabinet.c

FILES = main.c $(HFILES)

make: $(FILES)
	$(COMP) -o $(EXENAME) $(FILES)

run: $(EXENAME)
	./$(EXENAME)

clean:
	rm *.o
	rm $(EXENAME)

util.o: util.c util.h
#	$(COMP) -c util.c
	$(COMP) -o util util.h util.c

cabinet.o: cabinet.c cabinet.h
#	$(COMP) -c cabinet.c
	$(COMP) -o cabinet cabinet.h cabinet.c

