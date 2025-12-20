CC = gcc
CFLAGS = -Wall -IE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/include
LIBS = -LE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = main.c
OUT = main.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LIBS)

named:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LIBS)

run:
	./a.exe

run_named:
	./$(OUT)

clean:
	del a.exe main.exe
