.PHONY: clean
IDIR=./include
CXX=g++
CXXFLAGS=-I$(IDIR) -std=c++11 #-L$(LDIR)

ODIR=./src/obj
LDIR=/usr/local/Cellar/sfml/2.5.1_1/lib
TDIR=./bin/main

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

_DEPS = *.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o Level.o Asteroid.o Player.o Game.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

all: main run

main: $(OBJ)
	@echo "Compiling changed files..."
	$(CXX) -o $(TDIR) $^ $(CXXFLAGS) $(LIBS)
	@echo "Done."

run:
	@echo "Running program..."
	@./bin/./main

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~