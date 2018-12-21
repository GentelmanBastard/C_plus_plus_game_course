#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();	// constructor
	void Reset();	// TODO make a more rich value
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const;	// TODO make a more rich value

	// provide a method for counting bulls and cows and incrementing try number
	FBullCowCount SubmitGuess(FString);

	bool CheckGuessValidity(std::string);

	// Please try and ignore this 
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram;
	FString MyHiddenWord;
};