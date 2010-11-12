CC=gcc
CFLAGS=-c -Wall -O3 -std=c99
LDFLAGS=
OBJECTS=$(SOURCES:.c=.o)

all: rank unrank

unrank: common.o unrank.o
	$(CC) $(LDFLAGS) $^ -o $@

rank: common.o rank.o
	$(CC) $(LDFLAGS) $^ -o $@

common.o: common.c
	$(CC) $(CFLAGS) $^ -o $@

rank.o: rank.c
	$(CC) $(CFLAGS) $^ -o $@

unrank.o: unrank.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -fr *.o rank unrank
