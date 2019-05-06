#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
	// Print intro message
	std::cout << "\n\nYou are a agent breaking into a level " << Difficulty << " secure room...\n";
	std::cout << "Enter the correct code to continue:\n";
}

bool PlayGameAtDifficulty(int Difficulty)
{
	PrintIntro(Difficulty);

	Difficulty++;

	const int CodeA = rand() % (Difficulty + Difficulty);
	const int CodeB = rand() % (Difficulty + Difficulty);
	const int CodeC = rand() % (Difficulty + Difficulty);

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "-> There are three numbers in the code\n";
	std::cout << "-> The code adds up to " << CodeSum << std::endl;
	std::cout << "-> The code multiplies to " << CodeProduct << std::endl;

	//JunkLine
	std::cout << CodeA << "\n" << CodeB << "\n" << CodeC << "\n";

	int PlayerGuessA, PlayerGuessB, PlayerGuessC;

	std::cin >> PlayerGuessA >> PlayerGuessB >> PlayerGuessC;

	int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
	int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

	if (CodeSum == GuessSum && CodeProduct == GuessProduct)
	{
		std::cout << "Your guessed right!\n Next Level.\n\n";
		return true;
	}
	else
	{
		std::cout << "Your guessed wrong\nTry Again.\n\n";
		return false;
	}

}

int main()
{
	srand(time(NULL));

	int Difficulty = 1;
	int MaxDifficulty = 5;

	while (Difficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGameAtDifficulty(Difficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			Difficulty++;
		}
	}

	return 0;
}