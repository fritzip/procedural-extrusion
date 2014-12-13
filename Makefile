# ------------------------------------------------
# Makefile
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = extru

# compiler
CC       = g++

# compiling flags here
CFLAGS   = -Wall -g -std=c++11
#-I.

# linking flags here
LFLAGS   = -Wall -I. -g 

# using OpenGL lib
#GL_INCLUDE    = -I/usr/include/GL
GL_LIBDIR    = -L. -L/usr/X11R6/lib
GL_LIBRARIES = -lglut -lGL -lGLU -lGLEW -lm
#-lXmu -lXext -lXi -lX11

# Add objectiveC library for MacOSX.
ifneq ($(strip $(shell $(CC) -v 2>&1 | grep -i "Apple")),)
 GL_INCLUDE    = -I/usr/X11R6/include
 GL_LIBRARIES += -lobjc
 BROWSER = dillo
 OS = "osx"
endif
# Nothing to be done for Linux :o)
ifneq ($(strip $(shell $(CC) -v 2>&1 | grep -i "Linux")),)
 OS = "linux"
 BROWSER = mozilla
endif

# change these to set the proper directories where each files shoould be
SRCDIR   = SRC
OBJDIR   = OBJ
BINDIR   = BIN
DOCDIR   = DOC

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f
ln       = ln -sf


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CC) $(LFLAGS) $(OBJECTS) $(GL_LIBDIR) $(GL_LIBRARIES) -o $@ 
	@echo "Linking complete !"
	@$(ln) $(BINDIR)/$(TARGET)
	@echo "You can now run ./"$(TARGET)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(GL_INCLUDE) -c $< -o $@
	@echo "Successfully compiled "$<

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete !"

remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed !"

dox:
	@$(rm) $(DOCDIR)
	doxygen Doxyfile
	@echo "Doc generated !"
