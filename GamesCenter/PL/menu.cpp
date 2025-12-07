#include "menu.h"

Menu::Menu() {
    options = { {"Start Game", false}, {"Options", false}, {"Exit", false} };
    currentIndex = 0;
}

void Menu::Update() {
    if (IsKeyPressed(KEY_DOWN)) {
        currentIndex = (currentIndex + 1) % options.size();
    }
    if (IsKeyPressed(KEY_UP)) {
        currentIndex = (currentIndex - 1 + options.size()) % options.size();
    }
    if (IsKeyPressed(KEY_ENTER)) {
        options[currentIndex].selected = true;
    }
}

void Menu::Draw() {
    ClearBackground(DARKBLUE);

    DrawText("My Game Title", 200, 80, 50, RAYWHITE);

    for (int i = 0; i < options.size(); i++) {
        Rectangle button = { 250, 200 + i * 80, 300, 60 };
        Color bgColor = (i == currentIndex) ? GOLD : GRAY;
        DrawRectangleRec(button, bgColor);

        int textWidth = MeasureText(options[i].label.c_str(), 30);
        DrawText(options[i].label.c_str(),
            button.x + (button.width - textWidth) / 2, button.y + 15, 30, BLACK);
    }
}
