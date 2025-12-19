CC = gcc
CFLAGS = -Wall -std=c11 -IE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/include
LIBS = -LE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = main.c
OUT = shrey_mine.exe

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run: $(OUT)
	./$(OUT)

clean:
	del $(OUT)
