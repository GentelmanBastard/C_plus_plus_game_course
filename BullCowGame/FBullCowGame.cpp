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
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
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

bool FBullCowGame::CheckGuessValidity(std::string){	return false; }
