# Compiler
CC = gcc

# Directories
INCLUDE_DIRS = -I./inc
LIB_DIRS = -L./lib
OBJ_DIR = obj
SRC_DIR = src

# Source Files
C_SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
C_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(C_SRC_FILES:.c=.o)))

# Output Executable
OUT_EXE = main

# Libraries
LIBS = 
# Add more libraries as needed, and make sure the library files are in the lib folder.

CFLAGS = -Wall -std=c11

all: $(OUT_EXE)

$(OUT_EXE): $(C_OBJ_FILES)
	$(CC) $(CFLAGS) $(LIB_DIRS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

exec: $(OUT_EXE)
	./$(OUT_EXE)

clean:
	rm -rf $(OBJ_DIR) $(OUT_EXE)

.PHONY: all clean exec