.PHONY: all clean
.SUFFIXES:

PREFIX := $(HOME)/Desktop/OpenGL
CXXFLAGS := $(CXXFLAGS) -g -I$(PREFIX)/include
LDFLAGS := $(LDFLAGS) -g -L$(PREFIX)/lib -framework OpenGL -lGLEW -lSDL2

all: obj obj/gltut

obj:
	mkdir -p obj

obj/gltut: obj/main.o
	c++ -o $@ $(LDFLAGS) $^

obj/main.o: main.cpp
	c++ -c -o $@ $(CXXFLAGS) $^

clean:
	rm -rf obj

