#pragma once

#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(FString);
	void Reset(const int32 &DefaultCurrentTry, const int32 &MaxTries);
	// TODO provide a method to count bulls and cows and increment "MyCurrentTry"

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};
