# ------------------------------------------------
# Makefile for fileIO project
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = bin/fileO

# compiler
CC       = gcc

# compiling flags
CFLAGS   =  -Wall -I.

# linker
LINKER   = gcc -o 

# linking flags
LFLAGS   = -Wall -I.

# directories where files should reside
SRCDIR   = src
OBJDIR   = objects
INCDIR   = include
BINDIR   = bin

# grouping files into labels from each directory
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS) -lm
    
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# cleans object files and executable binaries	
clean:
	rm $(OBJECTS) $(TARGET) 
	@echo "Executable removed objects cleaned!"

