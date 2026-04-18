# Compiler
CC = gcc

# Target executable
TARGET = program

# Static library name
LIB = librecursion.a

# Object files for library
LIBOBJ = string_module.o array_module.o

# Default rule
all: $(TARGET)

# Create executable
$(TARGET): main.o $(LIB)
	$(CC) main.o -L. -lrecursion -o $(TARGET)

# Create static library
$(LIB): $(LIBOBJ)
	ar rcs $(LIB) $(LIBOBJ)

# Compile main file
main.o: main.c
	$(CC) -c main.c

# Compile string module
string_module.o: string_module.c string_module.h
	$(CC) -c string_module.c

# Compile array module
array_module.o: array_module.c array_module.h
	$(CC) -c array_module.c

# Clean rule
clean:
	rm -f *.o *.a $(TARGET)
