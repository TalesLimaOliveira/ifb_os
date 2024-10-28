# Variables
CC = gcc
CFLAGS = -Wall -Wextra

# File extensions
EXTSRC = c
EXTINC = h
APP ?= main

# Directories
APPDIR = app
SRCDIR = src
INCDIR = inc
LIBDIR = lib
BINDIR = bin
OBJDIR = obj

# Application name verification
ifeq ($(APP),)
$(error No app specified. Use: make APP=<app_name>)
endif

# Find all source files (.$(EXTSRC))
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/$(APP).$(EXTSRC))

# Generate a list of object files (.o) from the source file names
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES))) \
           $(patsubst $(APPDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(APPDIR)/%.$(EXTSRC), $(SOURCES)))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: clean folder exe

#Create directory
folder:
ifeq ($(OS),Windows_NT)
	@ if not exist $(BINDIR) mkdir $(BINDIR)
	@ if not exist $(OBJDIR) mkdir $(OBJDIR)
else
	@ if [ ! -d "$(BINDIR)" ]; then mkdir -p $(BINDIR); fi
	@ if [ ! -d "$(OBJDIR)" ]; then mkdir -p $(OBJDIR); fi
endif

# Compile exe
exe:  $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -I $(INCDIR) -o $(BINDIR)/$(APP)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Run exe
run:
	$(BINDIR)/$(APP)

# Clean BUILD files
.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	@ if exist "$(BINDIR)" rd /s /q $(BINDIR)
	@ if exist "$(OBJDIR)" rd /s /q $(OBJDIR)
else
	@ if [ -d "$(BINDIR)" ]; then rm -rf $(BINDIR); fi
	@ if [ -d "$(OBJDIR)" ]; then rm -rf $(OBJDIR); fi
endif
