#include "headerHungman.h"

headerHungman::headerHungman() { Reset(); }//construct
int headerHungman::GetCurentTry() const { return CurrentTry; }
int headerHungman::GetMaxTries() const { return MaxTries; }
int headerHungman::GetRightLetter() const { return LetterFound; }

bool headerHungman::IsGameWon() 
{
    if (LetterFound == SecretWord.length())
    {
        return GameIsWon = true;
    } 
    else 
    {
        return GameIsWon = false;
    }
}

void headerHungman::Reset()
{
    CurrentTry = 0;
    LetterFound = 0;
    CounterTry = 0;
    GameIsWon = false;
}

std::string headerHungman::GetSecretWord() 
{
    std::cout << "\nType the secret word\nEverything lowercase: ";
    getline(std::cin, SecretWord);
    return SecretWord;
}

std::string headerHungman::InitializeCensoredWord()
{
    //initialize the secret word and print
    int WordLenght = SecretWord.length();
    std::cout << "The secret word is about " << WordLenght << " letters.\n";
    for (int i = 0; i < WordLenght; i++)
    {
        CensoredWord[i] = '-'; 
        std::cout << CensoredWord[i];
    }
    std::cout << std::endl;
    return CensoredWord;
}

HungmanStatus headerHungman::CheckGuessValidity(std::string Guess)
{
    if (!IsLowercase(Guess))
    {
        return HungmanStatus::NotLowercase;
    }
    else if (!AlreadyTyped(Guess))
    {
        return HungmanStatus::LetterTyped;
    }
    else
    {
        return HungmanStatus::OK;
    }
}

bool headerHungman::IsLowercase(std::string Word)
{
        if (!islower(Word[0]))
        {
            return false;
        }
    return true;
}

bool headerHungman::AlreadyTyped(std::string Word)
{
    int WordLenght = SecretWord.length();
    for (int i = 0; i < WordLenght; i++)
    {
        if (Word[0] == CensoredWord[i])
        {
            return false;
        }
    }
    for (int i = 0; i < CounterTry; i++)
    {
        if (Word[0] == LettersTyped[i])
        {
            return false;
        }
    }
    return true;
}

int headerHungman::SubmitValidGuess(std::string Guess)
{
    int WordLenght = SecretWord.length();
    int Counter = 0;

    for (int i = 0; i < WordLenght; i++)
    {
        if (Guess[0] == SecretWord[i])
        {
            LetterFound++;
        }
        else 
        {
            Counter++;
        }
    }
    if (Counter == WordLenght)
    {
    return CurrentTry++;
    }
    return LetterFound;
}

void headerHungman::Gallows()
{
    switch(CurrentTry)
    {
        case 0:
            std::cout << " _________\n"
                        "  |      |\n"
                        "  |     \n"
                        "  |     \n"
                        "  |     \n"
                        " .|...........\n"
                        " /|\\      /|\\ \n\n";
            break;
        case 1:
            std::cout << " _________\n"
                         "  |      |\n"
                         "  |      o\n"
                         "  |     \n"
                         "  |     \n"
                         " .|...........\n"
                         " /|\\      /|\\ \n\n";
            break;
        case 2:
            std::cout << " _________\n"
                         "  |      |\n"
                         "  |      o\n"
                         "  |      | \n"
                         "  |        \n"
                         " .|...........\n"
                         " /|\\      /|\\ \n\n";
            break;
        case 3:
            std::cout << " _________\n"
                        "  |      |\n"
                        "  |      o\n"
                        "  |     /|\n"
                        "  |       \n"
                        " .|...........\n"
                        " /|\\      /|\\ \n\n";
            break;
        case 4:
            std::cout << " _________\n"
                        "  |      |\n"
                        "  |      o\n"
                        "  |     /|\\ \n"
                        "  |       \n"
                        " .|...........\n"
                        " /|\\      /|\\ \n\n";
            break;
        case 5:
            std::cout << " _________\n"
                         "  |      |\n"
                         "  |      o\n"
                         "  |     /|\\ \n"
                         "  |     / \n"
                         " .|...........\n"
                         " /|\\      /|\\ \n\n";
            break;
        case 6:
            std::cout << " _________\n"
                         "  |      |\n"
                         "  |      o\n"
                         "  |     /|\\ \n"
                         "  |     / \\ \n"
                         " .|...........\n"
                         " /|\\      /|\\ \n\n";
            break;
    }
}

std::string headerHungman::WordLetters(std::string Word)
{
    int WordLenght = SecretWord.length();

    for (int i = 0; i < WordLenght; i++)
    {
        if (Word[0] == SecretWord[i])
        {
            CensoredWord[i] = SecretWord[i];
            std::cout << CensoredWord[i] << " ";
        }
        else 
        {
            std::cout << CensoredWord[i] << " ";
        }
    }
    std::cout << "\n\n";
    return CensoredWord;
}

std::string headerHungman::WrongLettersGuess(std::string Word)
{
    int WordLenght = SecretWord.length();

    //counter for wrong letters
    int counterLetters = 0;

    for (int i = 0; i < WordLenght; i++)
    {
        if (Word[0] != SecretWord[i])
        {
            counterLetters++;  
            if (counterLetters == WordLenght)
                {
                    LettersTyped[CounterTry] = Word[0];
                    CounterTry++;
                }
        }
    }
    std::cout << "Hai inserito le lettere: ";
    for (int i = 0; i < CounterTry; i++)
    {
        std::cout << LettersTyped[i] << " ";
    }
    std::cout << std::endl;
    return LettersTyped;
}
