CC=gcc
CFLAGS=-Wall -Wextra -O2
SRC=main.c calendar.c
TARGET=build/main


all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
	rm -rf $(PDF_DIR)/build

.PHONY: all run clean