# What compiler should be used?
CC = g++

# CXX Flags are defined here.
DEBUG_FLAGS = -g
OPTIMIZATION_FLAGS = -O2
STANDARD = --std=c++20
WARNING_FLAGS = -Wall -Wextra -Wpedantic -Wnon-virtual-dtor -Wold-style-cast -Wuninitialized -Winit-self -Wparentheses -Wdangling-else
CXXFLAGS = $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(STANDARD) $(WARNING_FLAGS)

# Directorys are defined here.
INCLUDE_DIR = ./include
SOURCE_DIR = ./src
OBJ_DIR = ./obj

# Output source files here:
SOURCES = $(SOURCE_DIR)/main.cpp
SOURCES += $(SOURCE_DIR)/filereader/FileReader.cpp
SOURCES += $(SOURCE_DIR)/lexer/Lexer.cpp
SOURCES += $(SOURCE_DIR)/token/Token.cpp
SOURCES += $(SOURCE_DIR)/tokentype/TokenType.cpp

OBJS = $(SOURCES:$(SOURCE_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Handles different Operating System commands.
ifeq ($(OS),Windows_NT)
    RM_CMD = del /Q /F
    OUT = kilo.exe
else
    RM_CMD = rm -rf
    OUT = kilo
endif

# Actions:

.PHONY: all clean

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $@

# Output build commands here:
$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(CXXFLAGS) $< -o $@ -I$(INCLUDE_DIR)

# Makes the objs folder.
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM_CMD) $(OBJ_DIR) $(OUT)
