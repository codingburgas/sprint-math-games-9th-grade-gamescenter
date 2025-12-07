#ifndef WORDLE_H
#define WORDLE_H

#include <string>
#include <vector>
using namespace std;

void wordleGame();
void playWordle();
void displayWordleGuess(string guess, string target);
void displayWordleBoard(vector<string> guesses, int currentGuess);
bool isValidWordleWord(string word);
string toUpperCase(string str);
string toLowerCase(string str);

#endif