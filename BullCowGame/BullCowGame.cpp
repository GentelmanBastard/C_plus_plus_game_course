// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* This is the console executable that makes use of the BullCow class
This acts as the view in the MVC pattern and is responsible for
all user int32eraction. For game logic see the FBullCowGame class.
*/

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
int32 GetHiddenWordLength();
EGuessStatus CheckGuessValidity();
void PrintGameSummary();
FBullCowGame BCGame;	// instantiate a new game

// the entry point32 for our application
int main()
{	
	bool bPlayAgain = false;
	do {
	    PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();

	} while (bPlayAgain);

	return 0; // exit the application
}

void PrintIntro() 
{
	// prints intro of the game
	std::cout << "Welcome to Bulls and Cows, a fun word game";
	std::cout << std::endl;
	std::cout << "          }   {             _____           " << std::endl;
	std::cout << "          (o o)             (o o)           " << std::endl;
	std::cout << R"(    /------\ /               \ /-------\ )" << std::endl;
	std::cout << R"(   / | BULL |0                0| COW |  \)" << std::endl;
	std::cout << "  *  |-,--- |                  |-----|      " << std::endl;
	std::cout << "     ^      ^                  ^     ^      " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
//	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Your maximum number of tries is: " << MaxTries << std::endl;
	// loop for number of turns asking for guesses

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
        FText Guess = GetValidGuess();

        // Submit valid guess to the game
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
        std::cout << "Cows = " << BullCowCount.Cows << std::endl;
	}
	// summarize game
	PrintGameSummary();
//	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess;
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Current Try: " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: " << std::endl;
		// std::cout << "Enter your guess: ";
		
		getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters!\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word in lowercase.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		default:
			break;
		}
		
	} while (Status != EGuessStatus::OK);	// keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word? (y/n)";
	FText Response;
	getline(std::cin, Response);

	if (tolower(Response[0]) == 'y') {  //    return tolower(Response[0]) == 'y';
		return true;
	}
	else {
		return false;
	}
}

void PrintGameSummary() {
	if(BCGame.IsGameWon()){
		std::cout << "Congrats. You won!\n";
	}else{ std::cout << "Better luck next time!\n"; }
}
