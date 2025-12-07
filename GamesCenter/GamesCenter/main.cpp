#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<string> words = {
    "programming", "algorithm", "developer", "encryption",
    "database", "framework", "compiler", "debugging",
    "interface", "repository", "javascript", "python",
    "architecture", "optimization", "virtualization",
    "authentication", "cybersecurity", "blockchain",
    "artificial", "intelligence", "networking", "protocol"
};

void clearScreen() {
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void drawHangman(int wrongGuesses) {
    cout << "\n                _____ \n";
    cout << "                |   | \n";

    if (wrongGuesses >= 1) cout << "                |   O \n";
    else cout << "                |     \n";

    if (wrongGuesses >= 2) {
        cout << "                |  ";
        if (wrongGuesses >= 3) cout << "/";
        else cout << " ";
        cout << "|";
        if (wrongGuesses >= 4) cout << "\\ \n";
        else cout << "  \n";
    }
    else {
        cout << "                |     \n";
    }

    if (wrongGuesses >= 5) {
        cout << "                |  / ";
        if (wrongGuesses >= 6) cout << "\\ \n";
        else cout << "  \n";
    }
    else {
        cout << "                |     \n";
    }

    cout << "                |     \n";
    cout << "              __|__   \n\n";
}

void displayWord(string word, vector<char> guessedLetters) {
    cout << "\n                Word: ";
    for (int i = 0; i < word.length(); i++) {
        bool found = false;
        for (int j = 0; j < guessedLetters.size(); j++) {
            if (word[i] == guessedLetters[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << word[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << "\n\n";
}

bool checkWin(string word, vector<char> guessedLetters) {
    for (int i = 0; i < word.length(); i++) {
        bool found = false;
        for (int j = 0; j < guessedLetters.size(); j++) {
            if (word[i] == guessedLetters[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool alreadyGuessed(char letter, vector<char> guessedLetters) {
    for (int i = 0; i < guessedLetters.size(); i++) {
        if (guessedLetters[i] == letter) {
            return true;
        }
    }
    return false;
}

bool isValidLetter(char letter) {
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
}

void playGame(string word) {
    vector<char> guessedLetters;
    int wrongGuesses = 0;
    int maxWrong = 6;

    while (wrongGuesses < maxWrong) {
        drawHangman(wrongGuesses);
        displayWord(word, guessedLetters);

        if (checkWin(word, guessedLetters)) {
            cout << "                🎉 Congratulations! You won!\n";
            cout << "                The word was: " << word << "\n";
            return;
        }

        cout << "                Guessed letters: ";
        for (int i = 0; i < guessedLetters.size(); i++) {
            cout << guessedLetters[i] << " ";
        }
        cout << "\n";

        cout << "                Wrong guesses: " << wrongGuesses << "/" << maxWrong << "\n";
        cout << "                Enter a letter: ";

        char guess;
        cin >> guess;

        if (!isValidLetter(guess)) {
            cout << "\n                Please enter a valid letter (a-z)!\n";
            continue;
        }

        if (guess >= 'A' && guess <= 'Z') {
            guess = guess + 32;
        }

        if (alreadyGuessed(guess, guessedLetters)) {
            cout << "\n                You already guessed that letter! Try again.\n";
            continue;
        }

        guessedLetters.push_back(guess);

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                correct = true;
                break;
            }
        }

        if (correct) {
            cout << "\n                ✓ Correct!\n";
        }
        else {
            cout << "\n                ✗ Wrong!\n";
            wrongGuesses++;
        }
    }

    if (wrongGuesses >= maxWrong) {
        drawHangman(wrongGuesses);
        cout << "\n                💀 Game Over! You've been hanged!\n";
        cout << "                The word was: " << word << "\n";
    }
}

void singleplayerMode() {
    char playAgain = 'y';
    int gamesWon = 0;
    int gamesLost = 0;

    while (playAgain == 'y' || playAgain == 'Y') {
        string word = words[rand() % words.size()];

        cout << "\n                ========= SINGLEPLAYER MODE =========\n";
        cout << "                The computer has chosen a word!\n";
        cout << "                Score - Wins: " << gamesWon << " | Losses: " << gamesLost << "\n";

        vector<char> guessedLetters;
        int wrongGuesses = 0;
        int maxWrong = 6;

        while (wrongGuesses < maxWrong) {
            drawHangman(wrongGuesses);
            displayWord(word, guessedLetters);

            if (checkWin(word, guessedLetters)) {
                cout << "                🎉 Congratulations! You won!\n";
                cout << "                The word was: " << word << "\n";
                gamesWon++;
                break;
            }

            cout << "                Guessed letters: ";
            for (int i = 0; i < guessedLetters.size(); i++) {
                cout << guessedLetters[i] << " ";
            }
            cout << "\n";

            cout << "                Wrong guesses: " << wrongGuesses << "/" << maxWrong << "\n";
            cout << "                Enter a letter: ";

            char guess;
            cin >> guess;

            if (!isValidLetter(guess)) {
                cout << "\n                Please enter a valid letter (a-z)!\n";
                continue;
            }

            if (guess >= 'A' && guess <= 'Z') {
                guess = guess + 32;
            }

            if (alreadyGuessed(guess, guessedLetters)) {
                cout << "\n                You already guessed that letter! Try again.\n";
                continue;
            }

            guessedLetters.push_back(guess);

            bool correct = false;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess) {
                    correct = true;
                    break;
                }
            }

            if (correct) {
                cout << "\n                ✓ Correct!\n";
            }
            else {
                cout << "\n                ✗ Wrong!\n";
                wrongGuesses++;
            }
        }

        if (wrongGuesses >= maxWrong) {
            drawHangman(wrongGuesses);
            cout << "\n                💀 Game Over! You've been hanged!\n";
            cout << "                The word was: " << word << "\n";
            gamesLost++;
        }

        cout << "\n                Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\n                ========= FINAL SCORE =========\n";
    cout << "                Games Won: " << gamesWon << "\n";
    cout << "                Games Lost: " << gamesLost << "\n";
}

void multiplayerMode() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "\n                ========= MULTIPLAYER MODE =========\n";
        cout << "                Player 1: Enter a word for Player 2 to guess\n";
        cout << "                Word: ";

        string word;
        cin >> word;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = word[i] + 32;
            }
        }

        clearScreen();

        cout << "\n                ========= MULTIPLAYER MODE =========\n";
        cout << "                Player 2: Try to guess the word!\n";

        playGame(word);

        cout << "\n                Play again? (y/n): ";
        cin >> playAgain;
    }
}

void showMenu() {
    cout << "\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║        HANGMAN GAME MENU           ║\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  1. Singleplayer                   ║\n";
    cout << "                ║  2. Multiplayer                    ║\n";
    cout << "                ║  3. Exit                           ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╚════════════════════════════════════╝\n";
    cout << "\n";
    cout << "                Enter your choice: ";
}

int main() {
    srand(time(0));

    while (true) {
        showMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            singleplayerMode();
        }
        else if (choice == 2) {
            multiplayerMode();
        }
        else if (choice == 3) {
            cout << "\n                Thanks for playing! Goodbye!\n";
            break;
        }
        else {
            cout << "\n                Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
