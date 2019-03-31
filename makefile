CC=gcc
CFLAGS= -c -Wall
LDFLAGS=
SOURCES= connectFourMain.c
OBJECTS= $(SOURCES:.c=.o)
EXECUTABLE= p2
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -	o $@
.c.o:
			$(CC) $(CFLAGS) $(OBJECTS) $< -	o $@
