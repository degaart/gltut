.PHONY: all clean
.SUFFIXES:

PREFIX := $(HOME)/Desktop/OpenGL
CXXFLAGS := $(CXXFLAGS) -g -I$(PREFIX)/include -std=gnu++14
LDFLAGS := $(LDFLAGS) -g -L$(PREFIX)/lib \
	-framework OpenGL -framework Cocoa -framework IOKit \
	-framework AudioToolbox -framework CoreAudio -framework Carbon \
	-framework ForceFeedback -framework CoreVideo \
	-liconv -lm \
	-lGLEW -lSDL2

all: obj obj/gltut

obj:
	mkdir -p obj

obj/gltut: obj/main.o obj/display.o obj/shader.o
	c++ -o $@ $(LDFLAGS) $^

obj/main.o: main.cpp
	c++ -c -o $@ $(CXXFLAGS) $<

obj/display.o: display.cpp display.h
	c++ -c -o $@ $(CXXFLAGS) $<

obj/shader.o: shader.cpp shader.h
	c++ -c -o $@ $(CXXFLAGS) $<

clean:
	rm -rf obj

