#include "FBullCowGame.h"
#include <map>

#define TMap std::map

FBullCowGame::FBullCowGame()
{
    Reset();
}


FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 6;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
   
    MyCurrentTry = 1;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLenght() const
{
    return MyHiddenWord.size();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessResult FBullCowGame::CheckGuessIsValid(const FString& Guess) const
{
    if (!IsLenghtValid(Guess))
    {
        return EGuessResult::Wrong_Lenght;
    }
    else if (!IsLowercase(Guess))
    {
        return EGuessResult::Not_Lowercase;
    }
    else if (!IsIsogram(Guess))
    {
        return EGuessResult::Not_Isogram;
    }
	return EGuessResult::Ok;
}

FBullCowCount FBullCowGame::SubmitGuess(const FString& Guess)
{
    FBullCowCount BullCowCount;

    MyCurrentTry++;

    int32 HiddenWordLenght = MyHiddenWord.size();
    int32 GuessWordLenght = Guess.size();

    for (int32 i = 0;  i < HiddenWordLenght; i++)
    {
        for (int32 j = 0; j < GuessWordLenght; j++)
        {
            if (MyHiddenWord[i] == Guess[j])
            {
                if (i == j)
                    ++BullCowCount.Bulls;
                else
                    ++BullCowCount.Cows;
            }
        }
    }

    return BullCowCount;
}

bool FBullCowGame::IsLenghtValid(const FString& Guess) const
{
    return Guess.size() == GetHiddenWordLenght();
}

bool FBullCowGame::IsLowercase(const FString& Guess) const
{
    for (const auto& character : Guess)
    {
        if (!islower(character))
            return false;
    }

    return true;
}

bool FBullCowGame::IsIsogram(const FString& Guess) const
{

    TMap<char, int32> WordsSeen;

    for (const auto& character : Guess)
    {
        char letter = tolower(character);

        if (WordsSeen[letter])
            return false;
        else
            WordsSeen[letter] = true;
    }
   

    return true;
}