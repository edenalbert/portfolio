CFLAGS  = -g -Wall

# the build target executable:
TARGET = connectFourMain

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
