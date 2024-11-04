# Apps names
MAINAPP ?= main
EXAMPLEAPP ?= exemplos
APPS ?= main exemplos

# Vars
CC = gcc
EXTSRC = c
EXTINC = h

# Flags
CFLAGS = -O0 -Wall
# LDFLAGS = -lcrypt

# Directories
APPDIR = app
INCDIR = include
LIBDIR = lib
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Find all source files in SRCDIR and APPDIR for each app
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: clean folder $(APPS)


# Create directory
.PHONY: folder
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile each application
$(APPS): %: $(OBJDIR)/%.o $(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJDIR)/$*.o $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) $(LDFLAGS) -o $(BINDIR)/$*

# Compile individual object files for each application in APPDIR
$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Compile common source files in SRCDIR
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(SOURCES))
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@


# Run main application with arguments
.PHONY: run
run: $(BINDIR)/$(MAINAPP)
	@ $(BINDIR)/$(MAINAPP)

.PHONY: examples
examples: $(BINDIR)/$(MAINAPP)
	@ $(BINDIR)/$(MAINAPP)


# Clean build files
.PHONY: clean
clean:
	@ rm -rf $(BUILDDIR)
