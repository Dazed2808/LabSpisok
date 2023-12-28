CC = g++
CFLAGS = -std=c++11
SRCS = $(wildcard *.cpp)
EXES = $(patsubst %.cpp,%,$(SRCS))

all: $(EXES)

%: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXES)
