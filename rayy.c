#include "raylib.h"
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define TILE 40

int main(void)
{
    InitWindow(COLS * TILE, ROWS * TILE, "Minesweeper");
    SetTargetFPS(60);

    Texture2D flag = LoadTexture("flag.png"); // make sure it exists

    bool revealed[ROWS][COLS] = {0};
    bool flagged[ROWS][COLS] = {0};

    while (!WindowShouldClose())
    {
        Vector2 m = GetMousePosition();
        int col = (int)m.x / TILE;
        int row = (int)m.y / TILE;

        // Make sure the mouse is inside the grid
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
        {
            // LEFT CLICK -> reveal tile
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                revealed[row][col] = true;
                flagged[row][col] = false; // remove flag if revealed
            }

            // F KEY -> toggle flag on current tile
            if (IsKeyPressed(KEY_F) && !revealed[row][col])
            {
                flagged[row][col] = !flagged[row][col];
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw grid
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                Color tileColor = revealed[r][c] ? GRAY : BLUE;
                DrawRectangle(c*TILE, r*TILE, TILE, TILE, tileColor);
                DrawRectangleLines(c*TILE, r*TILE, TILE, TILE, BLACK);

                // draw flag if flagged
                if (flagged[r][c])
                {
                    DrawTexturePro(flag,
                                   (Rectangle){0,0,flag.width,flag.height},
                                   (Rectangle){c*TILE, r*TILE, TILE, TILE},
                                   (Vector2){0,0},
                                   0,
                                   WHITE);
                }
            }
        }

        EndDrawing();
    }

    UnloadTexture(flag);
    CloseWindow();
    return 0;
}
