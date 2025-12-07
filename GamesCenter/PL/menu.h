#pragma once
#include <string>
#include <vector>
#include "raylib.h"

struct MenuOption {
    std::string label;
    bool selected;
};

class Menu {
public:
    std::vector<MenuOption> options;  
    int currentIndex;                 

    Menu();

    void Update();

    void Draw();
};
