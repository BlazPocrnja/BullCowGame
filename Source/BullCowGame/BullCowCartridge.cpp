// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            PrintLine(TEXT("Lost a life!"));
            PrintLine(TEXT("%i"), --Lives);
            
            if (Lives > 0) {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again!\nYou have %i lives remaining."), Lives);
                }
            }
            else {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
    }

    // Check if isogram
    // Prompt to Guess Again
    // Check if right number of characters
    // Prompt to Guess Again

    // Remove Life

    // Check if Lives > 0
    // If yes GuessAgain
    // Show lives left
    // If no show GameOver and HiddenWord?
    // Prompt to play again, Press enter to play again?
    // PlayAgain or Quit
}

void UBullCowCartridge::SetupGame() // When the player hits enter
{
    // Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and\npress enter to continue...")); // Prompt player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}
