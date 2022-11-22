CC      := gcc
CFLAGS  := -std=gnu11 -Wall -Wextra -g -fsanitize=address -fsanitize=leak 
LIB     := -lm -lraylib -lGL 

DIR_BIN := bin
DIR_SRC := src
DIR_INC := include
DIR_LIB := lib
CFLAGS  += -I$(DIR_INC) -L$(DIR_LIB)

EXE_MAIN := main

SOURCES = $(wildcard $(DIR_SRC)/*.c)
OBJECTS = $(patsubst $(DIR_SRC)/%.c, $(DIR_BIN)/%.o, $(SOURCES))

.PHONY: all clean prebuild run test

all: prebuild $(DIR_BIN)/$(EXE_MAIN)

run: all
	./$(DIR_BIN)/$(EXE_MAIN)

prebuild:
	@mkdir -p $(DIR_BIN)

clean:
	-rm $(DIR_BIN)/*

# BUILD MAIN EXECUTABLE
$(DIR_BIN)/$(EXE_MAIN): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIB)

# BUILD OBJECT FILES
$(DIR_BIN)/%.o: $(DIR_SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)
