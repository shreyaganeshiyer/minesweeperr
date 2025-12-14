CC = gcc
CFLAGS = -Wall	-I$(RAYLIB_PATH)/include
LIBS = -L$(RAYLIB_PATH)/lib	-lraylib -lopengl32 -lgdi32 -lwinmm

# default output = a.exe
all:
	$(CC) square.c $(CFLAGS) $(LIBS)

# output as filename.exe
named:
	$(CC) square.c -o square.exe $(CFLAGS) $(LIBS)

run:
	./a.exe

run_named:
	./main.exe

clean:
	del a.exe main.exe