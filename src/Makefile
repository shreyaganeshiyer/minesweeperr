CC = gcc

CFLAGS = -Wall -IE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/include
LIBS = -LE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

all:
	$(CC) main.c $(CFLAGS) $(LIBS)

# output as filename.exe
named:
	$(CC) main.c -o main.exe $(CFLAGS) $(LIBS)

run:
	./a.exe

run_named:
	./main.exe

clean:
	del a.exe main.exe

