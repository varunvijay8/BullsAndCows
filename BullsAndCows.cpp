#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame(const int &NumberOfGuesses);
string GetGuess();
void PrintGuess(string Guess);
bool AskToPlayAgain();

int main()
{

	constexpr int NumberOfGuesses = 5;
	bool ContinuePlaying = false;
	
	PrintIntro();

	PlayGame(NumberOfGuesses);

	ContinuePlaying = AskToPlayAgain();

	cout << "So we are going to continue? " << ContinuePlaying << endl;
	cout << endl;

	return 0;
}

void PlayGame(const int &NumberOfGuesses)
{
	string Guess = "";

	for (int i = 0; i < NumberOfGuesses; i++)
	{
		Guess = GetGuess();
		PrintGuess(Guess);
	}
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

string GetGuess()
{
	string Guess = "";

	// Input guess
	cout << "Enter your guess: ";
	getline(cin, Guess);	

	return Guess;
}

void PrintGuess(string Guess)
{
	cout << "You guessed " << Guess << endl;

	cout << endl;
}

bool AskToPlayAgain()
{
	string Response = "";
	cout << "Do you want to play again(y/n): ";
	getline(cin, Response);

	cout << endl;

	return (tolower(Response[0]) == 'y' ? true : false);
}
