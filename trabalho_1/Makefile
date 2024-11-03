# List of applications to compile
RUNAPP ?= main
APPS ?= main app1 app2
ARGS ?= 

# Vars
CC = gcc
EXTSRC = c
EXTINC = h

# Flags
CFLAGS = -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDFLAGS = -lcrypt -lm

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
run: $(BINDIR)/$(RUNAPP)
	@ $(BINDIR)/$(RUNAPP) $(ARGS)


# Clean build files
.PHONY: clean
clean:
	@ rm -rf $(BUILDDIR)
