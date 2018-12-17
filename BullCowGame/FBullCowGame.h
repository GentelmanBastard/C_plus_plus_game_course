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
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);	// TODO make a more rich value

	// provide a method for counting bulls and cows and incrementing try number
	FBullCowCount SubmitGuess(FString);

	// Please try and ignore this 
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram;
	FString MyHiddenWord;
};