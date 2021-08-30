#include <iostream>
#include <string>
#include <ctime>

void PlayGame(int Difficulty, bool& PlayerWon);
void PrintIntroduction(int Difficulty);
bool KeepPlaying();
int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    bool PlayAgain = true;
    bool PlayerWon = false;
    while (PlayAgain)
    {
        PlayGame(LevelDifficulty, PlayerWon);
        
        PlayAgain = KeepPlaying();

        if (PlayAgain && PlayerWon)
        {
            LevelDifficulty++;
        }

        if (LevelDifficulty > MaxDifficulty)
        {
            LevelDifficulty = MaxDifficulty;
        }
    }
    return 0;
}

void PlayGame(int Difficulty, bool& PlayerWon)
{
    PrintIntroduction(Difficulty);
    //variables to be used in the program
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product to the terminal
    std::cout << "There are 3 numbers in the code.\n";
    std::cout << "The codes add up to: " << CodeSum << std::endl;
    std::cout << "The codes multiply to: " << CodeProduct << std::endl;
    std::cout << "Enter your guesses: ";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You Entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct && GuessA == CodeA && GuessB == CodeB && GuessC == CodeC)
    {
        std::cout << "You're in!\n";
        PlayerWon = true;
    }
    else
    {
        std::cout << "ERROR!! ERROR!! CALL SECURITY!\n";
        PlayerWon = false;
    }
}

void PrintIntroduction(int Difficulty)
{
    //introductory statements
    std::cout << "You are a secret agent breakiong into a level " << Difficulty << std::endl;
    std::cout << "Enter the correct code to continue...\n";
}

bool KeepPlaying()
{
    std::string input;
    bool ReturnValue = false;
    std::cout << "Play again: ";
    std::cin >> input;

    if (input == "Y" || input == "y")
    {
        ReturnValue = true;
    }
    else if (input == "N" || input == "n")
    {
        ReturnValue = false;
    }
    else
    {
        KeepPlaying();
    }
    return ReturnValue;
}