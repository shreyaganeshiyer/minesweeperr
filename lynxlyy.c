#include "raylib.h"
#include <math.h>

#define MAX_PARTICLES 200

typedef struct Particle {
    Vector2 pos;
    Vector2 vel;
    float life;
    Color color;
} Particle;

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib | modern demo");
    SetTargetFPS(60);

    // Player
    Vector2 player = { 0, 0 };
    float speed = 300.0f;

    // Camera
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    // Particles
    Particle particles[MAX_PARTICLES] = { 0 };

    bool paused = false;
    bool showFPS = true;
    float hue = 0.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Input
        if (IsKeyPressed(KEY_P)) paused = !paused;
        if (IsKeyPressed(KEY_F)) showFPS = !showFPS;

        if (!paused)
        {
            if (IsKeyDown(KEY_W)) player.y -= speed * dt;
            if (IsKeyDown(KEY_S)) player.y += speed * dt;
            if (IsKeyDown(KEY_A)) player.x -= speed * dt;
            if (IsKeyDown(KEY_D)) player.x += speed * dt;

            hue += 60.0f * dt;
            if (hue > 360) hue = 0;

            // Emit particles
            for (int i = 0; i < MAX_PARTICLES; i++)
            {
                if (particles[i].life <= 0)
                {
                    particles[i].pos = player;
                    particles[i].vel = (Vector2){
                        GetRandomValue(-100, 100) / 50.0f,
                        GetRandomValue(-100, 100) / 50.0f
                    };
                    particles[i].life = GetRandomValue(30, 60) / 60.0f;
                    particles[i].color = ColorFromHSV(hue, 0.8f, 1.0f);
                    break;
                }
            }

            // Update particles
            for (int i = 0; i < MAX_PARTICLES; i++)
            {
                if (particles[i].life > 0)
                {
                    particles[i].life -= dt;
                    particles[i].pos.x += particles[i].vel.x * 100 * dt;
                    particles[i].pos.y += particles[i].vel.y * 100 * dt;
                }
            }
        }

        camera.target = player;
        camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };

        // Draw
        BeginDrawing();
        ClearBackground((Color){ 20, 20, 25, 255 });

        BeginMode2D(camera);

        // World grid
        for (int x = -2000; x <= 2000; x += 100)
            DrawLine(x, -2000, x, 2000, DARKGRAY);
        for (int y = -2000; y <= 2000; y += 100)
            DrawLine(-2000, y, 2000, y, DARKGRAY);

        // Particles
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            if (particles[i].life > 0)
                DrawCircleV(particles[i].pos, 4, particles[i].color);
        }

        // Player
        DrawCircleV(player, 18, RAYWHITE);
        DrawCircleV(player, 10, ColorFromHSV(hue, 0.8f, 1.0f));

        EndMode2D();

        // UI
        DrawRectangle(10, 10, 270, 110, Fade(BLACK, 0.6f));
        DrawText("WASD  - Move", 20, 20, 18, RAYWHITE);
        DrawText("P     - Pause", 20, 45, 18, RAYWHITE);
        DrawText("F     - Toggle FPS", 20, 70, 18, RAYWHITE);
        DrawText(paused ? "PAUSED" : "RUNNING", 20, 95, 18, paused ? RED : GREEN);

        if (showFPS) DrawFPS(screenWidth - 100, 10);

        EndDrawing();
    }

    CloseWindow();
    return 0;

}
