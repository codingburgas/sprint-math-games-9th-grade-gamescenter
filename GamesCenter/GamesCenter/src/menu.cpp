#include <iostream>
#include "../include/menu.h"
using namespace std;

void clearScreen() {
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void showMainMenu() {
    cout << "\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║                                    ║\n";
    cout << "                ║       🎮 GAME COLLECTION 🎮        ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╠════════════════════════════════════╣\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  1. 🎯 Hangman                     ║\n";
    cout << "                ║  2. 🟩 Wordle                      ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╠════════════════════════════════════╣\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  3. ℹ️  About                       ║\n";
    cout << "                ║  4. ❌ Exit                         ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╚════════════════════════════════════╝\n";
    cout << "\n";
    cout << "                Enter your choice: ";
}

void showAbout() {
    cout << "\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║            ABOUT                   ║\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  Game Collection v1.0              ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  A collection of classic console   ║\n";
    cout << "                ║  games built with C++              ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  Available Games:                  ║\n";
    cout << "                ║  • Hangman (Singleplayer & Multi)  ║\n";
    cout << "                ║  • Wordle (Word guessing game)     ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  Enjoy playing! 🎮                 ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╚════════════════════════════════════╝\n";
    cout << "\n                Press Enter to return to main menu...";
    cin.ignore();
    cin.get();
}