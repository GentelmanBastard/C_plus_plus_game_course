#include "pch.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const { return false; }

// receives a valid guess, increments try and returns count 
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the try number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in a guess
		// compare letters against the hidden word 
	return BullCowCount;
}

bool FBullCowGame::CheckGuessValidity(std::string){	return false; }
