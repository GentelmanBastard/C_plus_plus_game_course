#include "pch.h"
#include "FBullCowGame.h"
#include <iostream>

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::IsGameWon() const { return false; }

// receives a valid guess, increments try and returns count 
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the try number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in a guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
				// if any letter returned by running the incremented index-number lookup on the Guess word(e.g. Guess[2]) 
				// matches any letter returned by doing the same to the Hidden word, proceed to the following conditions
			{
				if (MHWChar == GChar){				
					BullCowCount.Bulls++;	// increment bulls if they're in the same place
				}else{
					BullCowCount.Cows++;	//must be a cow

				}
			}
		}
	}
	return BullCowCount;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)	// if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}else if (false)	// if the quess is not a lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}else if (Guess.length() != GetHiddenWordLength())	// if the guess is wrong length
	{
		return EGuessStatus::Wrong_Length;
	}else{

		return EGuessStatus::OK;
	}
} // TODO Make actual error
