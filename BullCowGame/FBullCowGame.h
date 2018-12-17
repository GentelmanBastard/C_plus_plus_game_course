#pragma once
#include <string>


class FBullCowGame {
public:
	FBullCowGame();	// constructor
	void Reset();	// TODO make a more rich value
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);	// TODO make a more rich value

	// Please try and ignore this 
private:
	int MyCurrentTry = 1;
	int MyMaxTries =  5;
	bool IsIsogram;
};