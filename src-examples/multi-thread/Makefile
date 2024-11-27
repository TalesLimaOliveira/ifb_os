# Run args: make run-app arg1 arg2

# Compiler selection
CC = g++
EXT = cpp

# Compilation flags
CFLAGS ?= -Wall -Wextra -O0
LDFLAGS ?= -lglut -lGL -lGLU -lm

# Directories
APP_DIR = app
SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.$(EXT))
OBJECTS = $(patsubst $(SRC_DIR)/%.$(EXT), $(OBJ_DIR)/%.o, $(SOURCES))
# LIBRARIES = $(wildcard $(LIB_DIR)/*)

# Applications
APPS = $(patsubst $(APP_DIR)/%.$(EXT), $(BIN_DIR)/%, $(wildcard $(APP_DIR)/*.$(EXT)))

# Default target: Build all applications
all: $(APPS) | $(BIN_DIR) $(OBJ_DIR)
	@echo "Build complete."

# Create build and bin directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

# Compile sources: Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Link applications: Link object files and source files into executables
$(BIN_DIR)/%: $(APP_DIR)/%.$(EXT) $(OBJECTS) | $(BIN_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $< $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Compiled $(notdir $@)"

# Run application: Run the specified application with arguments
run-%:
	@$(BIN_DIR)/$* $(filter-out $@,$(MAKECMDGOALS))

run:
	@$(BIN_DIR)/*

# Clean build files: Remove build directory and object files
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete."

.PHONY: all clean run run-%
.PRECIOUS: $(OBJECTS)
