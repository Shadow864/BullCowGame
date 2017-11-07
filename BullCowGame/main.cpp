
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();

FText GetGuess();
FText GetValidGuess();

FBullCowGame BCGame;

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can You guess a " << BCGame.GetHiddenWordLenght();
	std::cout << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();

	for (int32 i = 0; i < BCGame.GetMaxTries(); i++)
	{
        FText Guess = GetValidGuess();

        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

        std::cout << "Bulls: " << BullCowCount.Bulls << "\t";
        std::cout << "Cows: " << BullCowCount.Cows;

        std::cout << std::endl;
		std::cout << std::endl;
	}
}

bool AskToPlayAgain()
{
    FText Response;
	std::cout << "Do you want to play again (y/n): ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

FText GetValidGuess()
{
    FText Guess;
    EGuessResult Result;
    do
    {
        Guess = GetGuess();
        Result = BCGame.CheckGuessIsValid(Guess);

        switch (Result)
        {
        case EGuessResult::Not_Isogram:
            std::cout << "Word is not isogram. Try again.\n\n";
            break;
        case EGuessResult::Not_Lowercase:
            std::cout << "Word is not lowercase. Try again.\n\n";
            break;
        case EGuessResult::Wrong_Lenght:
            std::cout << "Wrong word lenght, it should contains " << BCGame.GetHiddenWordLenght() <<" letters. Try again.\n\n";
            break;
        case EGuessResult::Ok:
            break;
        }
    } 
    while (Result != EGuessResult::Ok);

    return Guess;
}

FText GetGuess()
{
    FText Guess;
    std::cout << "[" << BCGame.GetCurrentTry() <<"/" << BCGame.GetMaxTries() << "]";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}
