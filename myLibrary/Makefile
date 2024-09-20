# Compiler
CXX = g++

# Compiler flags (added -g for gdb debugging)
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Executable name
TARGET = program

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o files
%.o: %.cpp Vector.h Vector.inl Point.h Point.inl
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# PHONY targets are not actual files
.PHONY: all clean
