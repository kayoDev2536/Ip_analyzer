CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/analyzer.c src/ipv4.c src/ipv6.c src/utils.c

OUT = ip-analyzer

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) 

clean:
	rm -f $(OUT)
