TARGET   = zork

CC       = g++
CFLAGS   = -std=c++11

LINKER   = g++
LFLAGS   = -Wall -g

SRCDIR   = ../Source
INCDIR   = ../Include
OBJDIR   = ../Obj
BINDIR   = ../Bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linked!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<""

.PHONY: clean
clean: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rm) $(OBJECTS)
	@echo "All clean!"
