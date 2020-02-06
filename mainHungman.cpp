#include <iostream>
#include <string>
#include "headerHungman.h"

void PrintIntro();
void PlayGame();
std::string GetValidGuess();
void PrintSummary();
bool AskToPlayAgain();

headerHungman Game;

int main ()
{
    PrintIntro();
    do {
    Game.Reset();
    Game.GetSecretWord();
    PlayGame();
    } while (AskToPlayAgain());
}

void PrintIntro()
{
    std::cout << " _________\n"
                 "  |      |\n"
                 "  |      o\n"
                 "  |     /|\\ \n"
                 "  |     / \\ \n"
                 " .|...........\n"
                 " /|\\      /|\\ \n";
    std::cout << "Welcome to the Hungman Game!\n";
    std::cout << "Guess the secret word... you have five try for dont stay hung!\n\n";
}

void PlayGame()
{
    system("CLS");
    //initialized and print the censored word
    Game.Gallows();
    Game.InitializeCensoredWord();

    while(!Game.IsGameWon() && Game.GetCurentTry() <= Game.GetMaxTries())
    {
        std::string Guess = GetValidGuess();
        system("CLS");
        Game.SubmitValidGuess(Guess);
        Game.Gallows();
        Game.WordLetters(Guess);
        Game.WrongLettersGuess(Guess);
    }
    PrintSummary();
}

std::string GetValidGuess()
{
    HungmanStatus Status = HungmanStatus::OnGallows;
    std::string Guess;

    do
    {
        //get first
        std::cout << "\nGuess the letters: ";
        getline(std::cin, Guess);

        Status = Game.CheckGuessValidity(Guess);
        switch(Status)
        {
            case HungmanStatus::NotLowercase:
                std::cout << "You have to type a lower case letter.\n";
                break;
            case HungmanStatus::LetterTyped:
                std::cout << "You have already typed this letter!\n";
                break;
            default:
                //Valid letter typed
                break;
        }
    }while(Status != HungmanStatus::OK);
    return Guess;
}

void PrintSummary()
{
    if (Game.IsGameWon())
    {
        std::cout << "Well Done! You are free now!\n\n";
    }
    else
    {
        std::cout << "Game Over! You dead!";
    }
}

bool AskToPlayAgain() 
{
    std::string Response;
    do
    {
        std::cout << "\nDo you want to play again (y/n)?  ";
        getline(std::cin, Response);
        if ((Response[0] == 'y') || (Response[0] == 'Y'))
        {
            return true;
        }
        else if ((Response[0] == 'n') || (Response[0] == 'N'))
        {
            return false;
        }
    }while(Response[0] != 'y' || Response[0] != 'Y' || Response[0] != 'n' || Response[0] != 'N'); 
}