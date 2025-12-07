#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../include/menu.h"
#include "../include/hangman.h"
#include "../include/wordle.h"
using namespace std;

int main() {
    srand(time(0));

    cout << "\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║                                    ║\n";
    cout << "                ║         WELCOME TO THE             ║\n";
    cout << "                ║       🎮 GAME COLLECTION 🎮        ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╚════════════════════════════════════╝\n";
    cout << "\n                Press Enter to continue...";
    cin.get();

    while (true) {
        showMainMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            hangmanGame();
        }
        else if (choice == 2) {
            wordleGame();
        }
        else if (choice == 3) {
            showAbout();
        }
        else if (choice == 4) {
            cout << "\n";
            cout << "                ╔════════════════════════════════════╗\n";
            cout << "                ║                                    ║\n";
            cout << "                ║   Thanks for playing! Goodbye! 👋  ║\n";
            cout << "                ║                                    ║\n";
            cout << "                ╚════════════════════════════════════╝\n";
            cout << "\n";
            break;
        }
        else {
            cout << "\n                ❌ Invalid choice! Please enter 1-4.\n";
            cout << "\n                Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}