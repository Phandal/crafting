CC = clang
CFLAGS = -Wall -Wextra

build: bin/munit bin/dll

test: build
	./bin/dll

debug: CFLAGS += -glldb
debug: all

bin/munit:
	mkdir bin/munit

bin/dll: bin/main.o bin/list.o bin/munit/munit.o
	$(CC) $(CFLAGS) -o $@ $^

bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	@rm -rf bin/*
