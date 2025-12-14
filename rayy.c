#include "raylib.h"

#define ROWS 10
#define COLS 10
#define CELL_SIZE 40

int main(void)
{
    const int screenWidth = COLS * CELL_SIZE;
    const int screenHeight = ROWS * CELL_SIZE;

    InitWindow(screenWidth, screenHeight, "Minesweeper Grid");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLUE);

        // Draw vertical grid lines
        for (int i = 0; i <= COLS; i++)
        {
            DrawLine(
                i * CELL_SIZE, 0,
                i * CELL_SIZE, screenHeight,
                DARKBLUE
            );
        }

        // Draw horizontal grid lines
        for (int j = 0; j <= ROWS; j++)
        {
            DrawLine(
                0, j * CELL_SIZE,
                screenWidth, j * CELL_SIZE,
                DARKBLUE
            );
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
