#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString);
	void Reset(const int32 &DefaultCurrentTry, const int32 &MaxTries);	
	BullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
