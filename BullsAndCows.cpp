#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrint();

int main()
{

	constexpr int NumberOfGuesses = 5;
	string Guess = "";

	PrintIntro();

	for (int i = 0; i < NumberOfGuesses; i++)
	{
		Guess = GetGuessAndPrint();
	}

	return 0;
}

void PrintIntro()
{
	// Intro to game and word length
	constexpr int WORD_LENGTH = 4;

	cout << "Welcome to Bulls and Cows" << endl;
	printf("Can you guess the %d letter isogram\n", WORD_LENGTH);

	cout << endl;

	return;
}

string GetGuessAndPrint()
{
	string Guess = "";

	// Input guess
	cout << "Enter your guess: ";
	getline(cin, Guess);

	cout << "You guessed " << Guess << endl;

	cout << endl;

	return Guess;
}
