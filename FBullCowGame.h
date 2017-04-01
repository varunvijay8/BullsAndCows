#pragma once

#include <string>
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};

enum class EResetStatus
{
	OK,
	No_Hidden_Word
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(const int32 &DefaultCurrentTry, const int32 &MaxTries);	
	FBullCowCount SubmitValidGuess(FString);
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameWon;
	
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
