#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../include/wordle.h"
using namespace std;

vector<string> wordleWords = {
    "crane", "slate", "crate", "prize", "shine",
    "track", "blaze", "flame", "grace", "space",
    "trade", "brake", "shake", "chase", "phase",
    "plant", "brand", "grand", "stand", "basic",
    "magic", "logic", "music", "toxic", "topic",
    "panel", "metal", "final", "legal", "royal",
    "ocean", "clean", "dream", "steam", "cream"
};

string toUpperCase(string str) {
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = result[i] - 32;
        }
    }
    return result;
}

string toLowerCase(string str) {
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = result[i] + 32;
        }
    }
    return result;
}

void displayWordleGuess(string guess, string target) {
    cout << "                ";
    for (int i = 0; i < 5; i++) {
        if (guess[i] == target[i]) {
            // Correct letter in correct position (Green)
            cout << "🟩 ";
        }
        else {
            // Check if letter exists elsewhere in target
            bool found = false;
            for (int j = 0; j < 5; j++) {
                if (guess[i] == target[j]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                // Correct letter, wrong position (Yellow)
                cout << "🟨 ";
            }
            else {
                // Letter not in word (Gray)
                cout << "⬜ ";
            }
        }
    }
    cout << "  " << toUpperCase(guess) << "\n";
}

void displayWordleBoard(vector<string> guesses, int currentGuess) {
    cout << "\n                ╔══════════════════════════╗\n";
    cout << "                ║        WORDLE            ║\n";
    cout << "                ╚══════════════════════════╝\n\n";

    for (int i = 0; i < 6; i++) {
        if (i < guesses.size()) {
            displayWordleGuess(guesses[i], guesses[guesses.size() - 1]);
        }
        else {
            cout << "                ⬜ ⬜ ⬜ ⬜ ⬜\n";
        }
    }
    cout << "\n";
}

bool isValidWordleWord(string word) {
    if (word.length() != 5) return false;

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}

void playWordle() {
    string target = wordleWords[rand() % wordleWords.size()];
    vector<string> guesses;
    int maxGuesses = 6;
    bool won = false;

    cout << "\n                ╔══════════════════════════════════╗\n";
    cout << "                ║    Guess the 5-letter word!      ║\n";
    cout << "                ║                                  ║\n";
    cout << "                ║  🟩 = Correct letter & position  ║\n";
    cout << "                ║  🟨 = Correct letter, wrong spot ║\n";
    cout << "                ║  ⬜ = Letter not in word         ║\n";
    cout << "                ╚══════════════════════════════════╝\n";

    for (int attempt = 0; attempt < maxGuesses; attempt++) {
        displayWordleBoard(guesses, attempt);

        cout << "                Attempt " << (attempt + 1) << "/" << maxGuesses << "\n";
        cout << "                Enter your guess: ";

        string guess;
        cin >> guess;
        guess = toLowerCase(guess);

        if (!isValidWordleWord(guess)) {
            cout << "\n                ❌ Invalid word! Must be 5 letters.\n";
            attempt--;
            continue;
        }

        guesses.push_back(guess);

        if (guess == target) {
            won = true;
            displayWordleBoard(guesses, attempt + 1);
            cout << "                🎉 Congratulations! You won!\n";
            cout << "                You guessed it in " << (attempt + 1) << " attempts!\n";
            break;
        }
    }

    if (!won) {
        displayWordleBoard(guesses, maxGuesses);
        cout << "                💀 Game Over!\n";
        cout << "                The word was: " << toUpperCase(target) << "\n";
    }
}

void wordleGame() {
    char playAgain = 'y';
    int gamesWon = 0;
    int gamesLost = 0;
    int totalGuesses = 0;

    while (playAgain == 'y' || playAgain == 'Y') {
        string target = wordleWords[rand() % wordleWords.size()];
        vector<string> guesses;
        int maxGuesses = 6;
        bool won = false;

        cout << "\n                ========= WORDLE GAME =========\n";
        cout << "                Score - Wins: " << gamesWon << " | Losses: " << gamesLost << "\n";

        if (gamesWon > 0) {
            cout << "                Average guesses per win: " << (totalGuesses / gamesWon) << "\n";
        }

        cout << "\n                ╔══════════════════════════════════╗\n";
        cout << "                ║    Guess the 5-letter word!      ║\n";
        cout << "                ║                                  ║\n";
        cout << "                ║  🟩 = Correct letter & position  ║\n";
        cout << "                ║  🟨 = Correct letter, wrong spot ║\n";
        cout << "                ║  ⬜ = Letter not in word         ║\n";
        cout << "                ╚══════════════════════════════════╝\n";

        for (int attempt = 0; attempt < maxGuesses; attempt++) {
            displayWordleBoard(guesses, attempt);

            cout << "                Attempt " << (attempt + 1) << "/" << maxGuesses << "\n";
            cout << "                Enter your guess: ";

            string guess;
            cin >> guess;
            guess = toLowerCase(guess);

            if (!isValidWordleWord(guess)) {
                cout << "\n                ❌ Invalid word! Must be 5 letters.\n";
                attempt--;
                continue;
            }

            guesses.push_back(guess);

            if (guess == target) {
                won = true;
                displayWordleBoard(guesses, attempt + 1);
                cout << "                🎉 Congratulations! You won!\n";
                cout << "                You guessed it in " << (attempt + 1) << " attempts!\n";
                gamesWon++;
                totalGuesses += (attempt + 1);
                break;
            }
        }

        if (!won) {
            displayWordleBoard(guesses, maxGuesses);
            cout << "                💀 Game Over!\n";
            cout << "                The word was: " << toUpperCase(target) << "\n";
            gamesLost++;
        }

        cout << "\n                Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\n                ========= FINAL SCORE =========\n";
    cout << "                Games Won: " << gamesWon << "\n";
    cout << "                Games Lost: " << gamesLost << "\n";
    if (gamesWon >