OBJS = main.o

.PHONY: default
default: main

main.o: main.c
	gcc -Wall -c -g $<

main: $(OBJS)
	gcc -o ./bin/$@ $^

.PHONY: clean
clean:
	rm -f $(OBJS)
