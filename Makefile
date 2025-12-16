CC = gcc
CFLAGS = -Wall -IE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/include
LIBS = -LE:/raylib-5.5_win64_mingw-w64/raylib-5.5_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

# default output = a.exe
all:
	$(CC) lynxlyy.c $(CFLAGS) $(LIBS)

# output as filename.exe
named:
	$(CC) lynxlyy.c -o lynxlyy.exe $(CFLAGS) $(LIBS)

run:
	./a.exe

run_named:
	./lynxlyy.exe

clean:
	del a.exe lynxlyy.exe