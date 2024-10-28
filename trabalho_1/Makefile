# Variables
CC = gcc
CFLAGS = -Wall -Wextra

# File extensions
EXTSRC = c
EXTINC = h

# Directories
APPDIR = app
SRCDIR = src
INCDIR = inc
LIBDIR = lib
BLDDIR = build
BINDIR = $(BLDDIR)/bin
OBJDIR = $(BLDDIR)/obj

# Main application to run
MAINAPP ?= main

# Find all source files in APPDIR with the extension $(EXTSRC)
APPS := $(basename $(notdir $(wildcard $(APPDIR)/*.$(EXTSRC))))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: clean folder $(APPS)

# Create directory
folder:
	@ mkdir -p $(BLDDIR) $(BINDIR) $(OBJDIR)
# Compile each app as a separate executable
$(APPS): %: $(APPDIR)/%.$(EXTSRC) $(filter $(SRCDIR)/*.$(EXTSRC), $(wildcard $(SRCDIR)/*.$(EXTSRC)))
	$(CC) $(CFLAGS) -I $(INCDIR) $^ $(LIBRARIES) -o $(BINDIR)/$@

# Run only the main application
run: $(MAINAPP)
	$(BINDIR)/$(MAINAPP)

# Clean BUILD files
.PHONY: clean
clean:
	@ if [ -d "$(BLDDIR)" ]; then rm -rf $(BLDDIR); fi
