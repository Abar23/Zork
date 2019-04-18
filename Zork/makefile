PRODUCT = main

BINDIR = Bin
INCDIR = Include
SRCDIR = Source
OBJDIR = Obj

CXX = g++
INCDIRS = -I$(INCDIR)
CXXFLAGS = -std=c++11 -Wall -g

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.0,$(SRCFILES))
DEPFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))

$(BINDIR)/$(PRODUCT): $(OBJFILES)
	$(CXX) $(CXXFILES) $^ -o $@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)