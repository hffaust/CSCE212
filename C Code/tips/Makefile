CC = gcc

SRCDIR = src
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
BIN = $(foreach src, $(SRC), $(BINDIR)/$(notdir $(src:.c=)))

all: $(BIN)

$(BIN): $(SRC)
	$(CC) -o $@ $<

clean:
	rm $(BIN)

phony: all clean
