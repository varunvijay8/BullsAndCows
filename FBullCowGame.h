#pragma once

#include <string>

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int GetCurrentTry() const;
	int GetMaxTries() const;
	bool IsGameWon() const;
	
	bool CheckGuessValidity(std::string);
	void Reset(const int &DefaultCurrentTry, const int &MaxTries);
	// TODO provide a method to count bulls and cows and increment "MyCurrentTry"

private:
	int MyCurrentTry;
	int MyMaxTries;
};
