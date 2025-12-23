CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = heap.o scheduler.o main.o
TARGET = scheduler_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)