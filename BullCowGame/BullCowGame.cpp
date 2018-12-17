// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// instantiate a new game

// the entry point for our application
int main()
{	
	bool bPlayAgain = false;
	PrintIntro();
	do {
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // exit the application
}

void PrintIntro() 
{
	// prints intro of the game
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	// loop for number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++) {
		std::cout << "Your guess was: " << GetGuess() << std::endl;
		/* std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << endl;
		std::cout << endl; */
	}
}

std::string GetGuess() 
{
	// get a guess from the player
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Current Try: " << CurrentTry << std::endl;
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	getline(std::cin, Response);

	if (tolower(Response[0]) == 'y') {
		return true;
	}
	else {
		return false;
	}
}
