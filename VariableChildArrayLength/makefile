SHELL = /bin/sh
CC = gcc
LIBS = -lm
FLAGS = -Wall -Wextra

OBJECTS = trie_ex.o trie_func.o trie_node.o example_data.o
TARGET = trie.out

all: FLAGS += -O3
all: $(TARGET)

debug: FLAGS += -g -ggdb
debug: $(TARGET)

debugOutput: FLAGS += -DDEBUG
debugOutput: debug

log: debug
log:
	./$(TARGET) > log

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)

shared:
	echo "Unimplemented"

trie_ex.o: trie_func.h trie_node.h
trie_func.o: trie_func.h trie_node.h
trie_node.o: trie_node.h
example_data.o: example_data.h

%.o : %.c
	$(CC) -c $(FLAGS) $<

.PHONY : clean
clean :
	rm -rf $(TARGET) $(OBJECTS) log