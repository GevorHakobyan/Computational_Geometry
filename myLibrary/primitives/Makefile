# Compiler
CXX = g++

# Compiler flags (added -g for gdb debugging)
CXXFLAGS = -Wall -Wextra -std=c++20 -g

# Include directories (include 2D and primitives directories)
INCLUDES = -I../2D -I.

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
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Compile .cpp files into .o files
%.o: %.cpp Vector.h Vector.inl Point.h Point.inl Line.h Line.inl ../2D/Polygon.h ../2D/Polygon.inl
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# PHONY targets are not actual files
.PHONY: all clean



