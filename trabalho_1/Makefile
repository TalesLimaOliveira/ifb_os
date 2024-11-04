# Vars
APPS = main exemplos
ARGS ?= 
CC = gcc
EXTSRC = c
EXTINC = h

# Flags
CFLAGS = -O0 -Wall
#LDFLAGS = -lcrypt -lm

# Directories
APPDIR = app
INCDIR = inc
LIBDIR = lib
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Find all source files (.$(EXTSRC))
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/$(APP).$(EXTSRC))

# Generate a list of object files (.o) from the source file names
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES))) \
           $(patsubst $(APPDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(APPDIR)/%.$(EXTSRC), $(SOURCES)))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: folder $(APPS)

# Create directory
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Link object files to create the executables
$(APPS): %: folder $(OBJECTS) $(OBJDIR)/%.o
	$(CC) $(OBJECTS) $(OBJDIR)/$@.o $(LDFLAGS) -o $(BINDIR)/$@
	@ echo "App Compiled"

# Run targets with arguments
run-%: %
	./$(BINDIR)/$* $(ARGS)

# Clean build files
clean:
	@ rm -rf $(BUILDDIR)
	@ echo "Cleaned build files"
