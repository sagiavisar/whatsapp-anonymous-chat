CFLAGS = -ansi -Wall -pedantic
TARGET = wa

all: $(TARGET)

$(TARGET): $(TARGET).o
	gcc $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
	gcc $(CFLAGS) -c $(TARGET).c

clean:
	rm -f *.o $(TARGET)