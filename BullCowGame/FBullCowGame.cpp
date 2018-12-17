#include "pch.h"
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() {
	MyCurrentTry = 666;
	MyMaxTries = 666;
}

void FBullCowGame::Reset()
{
	return;
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::CheckGuessValidity(std::string){	return false; }
