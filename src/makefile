# Shamelessly stolen from: https://stackoverflow.com/a/42357205
# Thank you :)



# SECTION: Stuff that means little to me

# The name of the executable
EXE = run

# Flags for compilation (adding warnings are always good)
CFLAGS = -Wall

# Flags for linking (none for the moment)
LDFLAGS =

# Libraries to link with (none for the moment)
LIBS =

# Use the GCC frontend program when linking
LD = gcc

# Use GCC for compilation too
CC = gcc

# This creates a list of object files from the source files
OBJECTS = $(SOURCES:%.c=%.o)

# The first target, this will be the default target if none is specified
# This target tells "make" to make the "all" target
default: all

# Having an "all" target is customary, so one could write "make all"
# It depends on the executable program
all: $(EXE)

# This will link the executable from the object files
# $(LD) $(LDFLAGS) $(OBJECTS) -o  $(EXE) $(LIBS)
# gcc $(CFLAGS) $(SOURCES) -o $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXE)

# This is a target that will compiler all needed source files into object files
# We don't need to specify a command or any rules, "make" will handle it automatically
# NOTE: Default dependency is that a .o file depends on its corresponding .c and .h files.
# [1.]
%.o: %.c %.h

# Target to clean up after us
# Not working on my machine. Oh well. I hate Windows
clean:
	-rm -f $(EXE)
	-rm -f $(OBJECTS)



# SECTION: Stuff that means lots to me

# The name of the source files
SOURCES = main.c general_linear_structures/static/array.c general_linear_structures/static/test/testArray.c algos/search/linsearch.c algos/search/test/testLinsearch.c algos/search/binsearch.c algos/search/test/testBinsearch.c general_linear_structures/dynamic/linkedList.c general_linear_structures/dynamic/test/testLinkedList.c helpful.c helpful.h general_linear_structures/dynamic/extensibleList.c general_linear_structures/dynamic/test/testExtensibleList.c
#SOURCES = *.c

# Finally we need to tell "make" what source and header file each object file depends on
# NOTE: Due to rule [1.] above, we don't need to explicitly list these below (I think).
