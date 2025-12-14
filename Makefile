CC = gcc
SRC = rayy.c
TARGET = rayy

CFLAGS = -Wall -I$(RAYLIB_PATH)/include
LIBS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm

all:
	$(CC) $(SRC) -o $(TARGET).exe $(CFLAGS) $(LIBS)

clean:
	rm -f *.exe *.o
