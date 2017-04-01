#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	constexpr int32 DefaultCurrentTry = 1;
	constexpr int32 MaxTries = 5;

	Reset(DefaultCurrentTry, MaxTries);
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{ 
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::Reset(const int32 &DefaultCurrentTry, const int32 &MaxTries)
{
	const FString HIDDEN_WORD = "planets";

	MyCurrentTry = DefaultCurrentTry;
	MyMaxTries = MaxTries;
	MyHiddenWord = HIDDEN_WORD;
	bGameWon = false;

	return;
}

// receives valid guess, increments turns, count bulls and cows
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	// update return struct with bulls and cows count
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GuessChar = 0; GuessChar < GuessLength; GuessChar++)
		{
			if (MyHiddenWord[MHWChar] == Guess[GuessChar])
			{
				if (MHWChar == GuessChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	bGameWon = BullCowCount.Bulls == HiddenWordLength ? true : false;

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// If word length is 0 or 1 return true
	if (Word.length() < 2) { return true; }

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}

	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (isupper(Letter)) { return false; }
	}

	return true;
}
