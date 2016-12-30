#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	constexpr int32 DefaultCurrentTry = 1;
	constexpr int32 MaxTries = 5;

	Reset(DefaultCurrentTry, MaxTries);
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

void FBullCowGame::Reset(const int32 &DefaultCurrentTry, const int32 &MaxTries)
{
	MyCurrentTry = DefaultCurrentTry;
	MyMaxTries = MaxTries;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
}

// receives valid guess, increments turns, count bulls and cows
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn #
	MyCurrentTry++;

	// update return struct with bulls and cows count
	BullCowCount BullCowCount;

	return BullCowCount;
}
