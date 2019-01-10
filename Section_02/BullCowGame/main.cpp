/*
This is the console executable that makes use of the BullCow class.
This acts as the view in the MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "fBullCowGame.h"

// To make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText Guess);
bool AskToPlayAgain();
void PrintGameSummery();


FBullCowGame BCGame; // Instantiate a new game


// The Entrypoint for the Application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	std::cout << std::endl;
	return 0;
}



void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game!\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram word I am thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop asking for guesseswhile the game id NOT won
	// and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); 

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;

		//PrintGuess(Guess);
		std::cout << std::endl;
	}

	PrintGameSummery();

	return;

}

// Loop continuelly until the user gives a valid guess
FText GetValidGuess() 
{
	FText Guess = "";
	
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ": Guess the word: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " length word.\n\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please use no repeating letters word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please only use lowercase.\n\n";
			break;
		default:
			// Assuming guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;

}

void PrintGuess(FText Guess)
{
	std::cout << "Your guess was: " << Guess << std::endl;

	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again With the same word? (y/n) ";
	FText Responce = "";
	std::getline(std::cin, Responce);

	return (Responce[0] == 'y') || (Responce[0] == 'Y');

	return false;
}

void PrintGameSummery()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well Done, You Win!\n";
	}
	else
	{
		std::cout << "Better Luck Next Time\n";
	}
}
