#include "pch.h"
#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
//	return;
}



// receives a valid guess, increments try and returns count 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	// loop through all letters in a hidden word
	int32 WordLength = MyHiddenWord.length();	// assuming same length as guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess word
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
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
	if (BullCowCount.Bulls == WordLength){
		bGameIsWon = true;
	}else{ bGameIsWon = false; }
	return BullCowCount;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))	// if the guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}else if (!IsLowercase(Guess))	// if the quess is not a lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}else if (Guess.length() != GetHiddenWordLength())	// if the guess is wrong length
	{
		return EGuessStatus::Wrong_Length;
	}else{

		return EGuessStatus::OK;
	}
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if(Word.length() <= 1){ return true; }
	TMap<char, bool> LetterSeen;	// set up our map
	for (auto Letter : Word){	// for all the letter of the word
		Letter = tolower(Letter);
		if (LetterSeen[Letter]){
			return false;	// we do NOT have an isogram
		} else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const {
	for (auto Letter : Word){
		if(!islower(Letter)){
			return false;
		}
	}
	return true;
}
