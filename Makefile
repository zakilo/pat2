SRCS = $(wildcard *.cc)
PROGS = $(patsubst %.cc,%,$(SRCS))
CFLAGS = -DDEBUG -g -std=c++11

all: $(PROGS)

%: %.cc
	g++ $(CFLAGS) -o $@ $<
