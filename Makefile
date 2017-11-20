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

SRCS := $(wildcard *.cpp)
HDRS := $(wildcard *.h)
OBJS := $(patsubst %.cpp,obj/%.cpp.o,$(SRCS))

all: obj obj/gltut

obj:
	mkdir -p obj

-include obj/Depends.mk

obj/Depends.mk:
	CXXFLAGS="$(CXXFLAGS)" ./makedepend.sh $(SRCS)

obj/gltut: $(OBJS)
	c++ -o $@ $(LDFLAGS) $^

obj/%.cpp.o:
	c++ -c -o $@ $(CXXFLAGS) $*.cpp

clean:
	rm -rf obj

