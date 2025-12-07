#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
using namespace std;

void hangmanGame();
void showHangmanMenu();
void singleplayerMode();
void multiplayerMode();
void playGame(string word);
void drawHangman(int wrongGuesses);
void displayWord(string word, vector<char> guessedLetters);
bool checkWin(string word, vector<char> guessedLetters);
bool alreadyGuessed(char letter, vector<char> guessedLetters);
bool isValidLetter(char letter);

#endif