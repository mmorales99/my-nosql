
FILES = main.c bool.h bool.c

make: $(FILES)
	gcc -Wall -Wextra -Wpedantic -ansi -M -Ofast -o my-nosql $(FILES)

debug: $(FILES)
	gcc -Wall -Wextra -Wpedantic -anis -M -Og -o my-nosql $(FILES)
