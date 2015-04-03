SRCS = $(wildcard *.cc)
PROGS = $(patsubst %.cc,%,$(SRCS))
CFLAGS = -Wall -DDEBUG -g -std=c++11

all: $(PROGS)

%: %.cc
	g++ $(CFLAGS) -o $@ $<
