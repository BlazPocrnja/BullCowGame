// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug line
    
    // Welcoming The Player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));

    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking player guess

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The Hidden Word is %i characters Long, try again!"), HiddenWord.Len());
        }
        
        PrintLine(TEXT("You have lost!"));
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
    HiddenWord = TEXT("cake");
    Lives = 4;
}
