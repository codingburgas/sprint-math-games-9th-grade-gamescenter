#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// ==================== HANGMAN GAME CODE ====================

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

void showHangmanMenu() {
    cout << "\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║        HANGMAN GAME MENU           ║\n";
    cout << "                ╔════════════════════════════════════╗\n";
    cout << "                ║                                    ║\n";
    cout << "                ║  1. Singleplayer                   ║\n";
    cout << "                ║  2. Multiplayer                    ║\n";
    cout << "                ║  3. Back to Main Menu              ║\n";
    cout << "                ║                                    ║\n";
    cout << "                ╚════════════════════════════════════╝\n";
    cout << "\n";
    cout << "                Enter your choice: ";
}

void hangmanGame() {
    while (true) {
        showHangmanMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            singleplayerMode();
        }
        else if (choice == 2) {
            multiplayerMode();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "\n                Invalid choice! Please enter 1, 2, or 3.\n";
        }
    }
}

// ==================== WORDLE GAME CODE ====================

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
        if (!isValidLetter(word[i])) {
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
    if (gamesWon > 0) {
        cout << "                Average guesses: " << (totalGuesses / gamesWon) << "\n";
    }
}

// ==================== MAIN MENU ====================

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

// ==================== MAIN FUNCTION ====================

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