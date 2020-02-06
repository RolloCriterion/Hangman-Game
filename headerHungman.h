#include <iostream>
#include <string>

enum class HungmanStatus
{
    OnGallows,
    NotLowercase,
    LetterTyped,
    OK
};

class headerHungman
{
    public:

        headerHungman();//construct declaration
        //game start
        void Reset();

        int GetMaxTries() const;
        int GetCurentTry () const;
        int GetRightLetter() const;
        bool IsGameWon();

        //input the word to guess and initialize and print the censured letter
        std::string GetSecretWord();
        std::string InitializeCensoredWord();

        //check if the letter is valid
        HungmanStatus CheckGuessValidity(std::string);

        //send and return the draw and letters
        int SubmitValidGuess(std::string);

        //draw of the gallows
        void Gallows();

        //print the letters found and not found
        std::string WordLetters(std::string);

        //print the wrong letters
        std::string WrongLettersGuess(std::string);

    private:

        std::string SecretWord;
        std::string CensoredWord;
        std::string LettersTyped;
        int CurrentTry;
        int MaxTries = 5;
        int LetterFound;
        int CounterTry;
        bool GameIsWon;

        bool IsLowercase(std::string);
        bool AlreadyTyped(std::string);
};
