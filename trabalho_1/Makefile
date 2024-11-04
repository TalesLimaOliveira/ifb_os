# Vars
APP ?= main
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
all: clean folder exe

# Create directory
.PHONY: folder
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile exe
exe:  $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) $(LIBRARIES) -o $(BINDIR)/$(APP)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	$(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Run the application with arguments
.PHONY: run
run: $(BINDIR)/$(APP)
	@ $(BINDIR)/$(APP) $(ARGS)

# Clean build files
.PHONY: clean
clean:
	@ rm -rf $(BUILDDIR)
