#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	constexpr int DefaultCurrentTry = 1;
	constexpr int MaxTries = 5;

	Reset(DefaultCurrentTry, MaxTries);
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

void FBullCowGame::Reset(const int &DefaultCurrentTry, const int &MaxTries)
{
	MyCurrentTry = DefaultCurrentTry;
	MyMaxTries = MaxTries;
}
