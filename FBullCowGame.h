#pragma once

#include <string>

class FBullCowGame {
public:
	int GetCurrentTry();
	int GetMaxTries();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);
	void Reset();

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
