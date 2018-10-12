TARGET = program
CFLAGS = -g -Wall -g -Wextra
CC = gcc

$(TARGET): main.o  program.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o $(TARGET).o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

program.o: program.c
	$(CC) $(CFLAGS) -c -o $(TARGET).o $(TARGET).c

clean:
	rm *.o $(TARGET)

remake: clean $(TARGET)



