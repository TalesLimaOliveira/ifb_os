# App name (default to 'main' if not specified)
APP ?= main

# Vars
CC = gcc
EXTSRC = c
EXTINC = h

# Flags
CFLAGS = -O0 -Wall

# Directories
APPDIR = app
INCDIR = include
LIBDIR = lib
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Find all source files in SRCDIR
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(SOURCES))

# Executes make
.PHONY: all
all: clean folder $(APP)

# Create directory
.PHONY: folder
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile the specified application
$(APP): $(OBJDIR)/$(APP).o $(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJDIR)/$(APP).o $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) $(LDFLAGS) -o $(BINDIR)/$(APP)

# Compile individual object file for the application in APPDIR
$(OBJDIR)/$(APP).o: $(APPDIR)/$(APP).$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Compile common source files in SRCDIR
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Run the application with arguments
.PHONY: run
run: $(BINDIR)/$(APP)
	@ $(BINDIR)/$(APP)

# Clean build files
.PHONY: clean
clean:
	@ rm -rf $(BUILDDIR)
