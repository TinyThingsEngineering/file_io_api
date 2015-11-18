# ------------------------------------------------
# Makefile for fileIO project
# ------------------------------------------------
ifneq (,$(findstring /cygdrive/,$(PATH)))
    UNAME := Cygwin
	TARGET   = bin/fileO.exe
	@echo "cy"
else
ifneq (,$(findstring WINDOWS,$(PATH)))
    UNAME := Windows
	TARGET   = bin/fileO.exe
	@echo "win"
else
    UNAME := $(shell uname -s)
	TARGET   = bin/fileO
endif
endif
# project name (generate executable with this name)
#TARGET   = bin/fileO.exe

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

