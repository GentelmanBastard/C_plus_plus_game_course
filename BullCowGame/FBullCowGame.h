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

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {
public:
	FBullCowGame();	// constructor
	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	// provide a method for counting bulls and cows and incrementing try number
	FBullCowCount SubmitValidGuess(FString);

	// Please try and ignore this 
private:
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
};