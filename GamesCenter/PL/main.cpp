#include "raylib.h"
#include <vector>
#include <string>

struct MenuOption {
    std::string label;
    bool selected;
    Color currentColor;
};

Color LerpColor(Color a, Color b, float t) {
    return {
        (unsigned char)(a.r + (b.r - a.r) * t),
        (unsigned char)(a.g + (b.g - a.g) * t),
        (unsigned char)(a.b + (b.b - a.b) * t),
        (unsigned char)(a.a + (b.a - a.a) * t)
    };
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib Stylish Menu");
    SetTargetFPS(60);

    std::vector<MenuOption> options = {
        {"Games", false, WHITE},
        {"How to Play", false, WHITE},
        {"About Us", false, WHITE},
        {"Exit", false, WHITE}
    };

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();

        for (int i = 0; i < options.size(); i++) {
            Rectangle button = { 250, 200 + i * 90, 300, 70 };
            bool hovered = CheckCollisionPointRec(mousePos, button);
            Color targetColor = hovered ? ORANGE : WHITE;
            options[i].currentColor = LerpColor(options[i].currentColor, targetColor, 0.1f);

            if (hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                options[i].selected = true;
            }
        }

        BeginDrawing();

        for (int y = 0; y < screenHeight; y++) {
            Color rowColor = Color{ (unsigned char)(20 + y / 15), (unsigned char)(40 + y / 20), 100, 255 };
            DrawLine(0, y, screenWidth, y, rowColor);
        }

        DrawText("Game Menu", screenWidth / 2 - MeasureText("Game Menu", 50) / 2, 80, 50, DARKBLUE);

        for (int i = 0; i < options.size(); i++) {
            Rectangle button = { 250, 200 + i * 90, 300, 70 };
            DrawRectangleRounded(button, 0.3f, 10, options[i].currentColor);

            int textWidth = MeasureText(options[i].label.c_str(), 28);
            DrawText(options[i].label.c_str(),
                button.x + (button.width - textWidth) / 2,
                button.y + 20,
                28,
                BLACK);
        }

        EndDrawing();

        if (options[0].selected) {
        }
        if (options[1].selected) {
        }
        if (options[2].selected) {
        }
        if (options[3].selected) {
            CloseWindow();
        }
    }

    CloseWindow();
    return 0;
}
