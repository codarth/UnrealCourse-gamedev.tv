/* The game code (no view code or user interaction)

*/
#pragma once

#include <string>

using FString = std::string;
using int32 = int;

enum class EGuessStatus
{
	Invalid_Status,
	OK, 
	Not_Isogram, 
	Wrong_Length, 
	Not_Lowercase
};

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const; // This const does not allow this function to change any variables.
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
	EGuessStatus CheckGuessValidity(FString Guess) const; 

	void Reset(); 

	FBullCowCount SubmitValidGuess(FString Guess);

private:
	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;

	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};