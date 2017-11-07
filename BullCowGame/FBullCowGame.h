#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessResult
{
    Ok,
    Not_Isogram,
    Wrong_Lenght,
    Not_Lowercase
};

class FBullCowGame
{
public:
    FBullCowGame();
    ~FBullCowGame();

    void            Reset();
    bool            IsGameWon() const;
    int32	        GetMaxTries() const;
    int32	        GetCurrentTry() const;
    int32           GetHiddenWordLenght() const;
    
    FBullCowCount   SubmitGuess(const FString& guess);
    EGuessResult    CheckGuessIsValid(const FString& guess) const;

private:
    bool            IsLenghtValid(const FString& Guess) const;
    bool            IsLowercase(const FString& Guess) const;
    bool            IsIsogram(const FString& Guess) const;

private:
    int32           MyMaxTries;
    int32           MyCurrentTry;
    FString         MyHiddenWord;
};

