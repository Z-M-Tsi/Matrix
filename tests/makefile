# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -O2 -march=native -ffast-math -funroll-loops

# Target executable
MAIN_TARGET = MatrixTest
MULTIPLY_TARGET = testMultiply

# Source files
MAIN_SRCS = MatrixTest.cpp 
MULTIPLY_SRCS = testMultiply.cpp

# Object files
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
MULTIPLY_OBJS = $(MULTIPLY_SRCS:.cpp=.o)

# Default target
all: $(MAIN_TARGET) $(MULTIPLY_TARGET)

# Link object files to create the executable
$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(MAIN_OBJS) -o $(MAIN_TARGET)

$(MULTIPLY_TARGET): $(MULTIPLY_OBJS)
	$(CC) $(CFLAGS) $(MULTIPLY_OBJS) -o $(MULTIPLY_TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(MAIN_OBJS) $(MAIN_TARGET) $(MULTIPLY_OBJS) $(MULTIPLY_TARGET)

.PHONY: all clean