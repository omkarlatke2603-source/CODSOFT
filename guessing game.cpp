// Number Guessing Game in C++

#include <iostream>   // For input and output
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()

using namespace std;

int main()
{
    // Step 1: Initialize random number generator
    srand(time(0));

    // Step 2: Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    // Step 3: Variable to store user's guess
    int guess = 0;

    // Step 4: Display instructions
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess the number." << endl;

    // Step 5: Loop until user guesses the correct number
    while (guess != randomNumber)
    {
        // Step 6: Take input from user
        cout << "Enter your guess: ";
        cin >> guess;

        // Step 7: Check if guess is too high
        if (guess > randomNumber)
        {
            cout << "Your guess is too high. Try again." << endl;
        }
        // Step 8: Check if guess is too low
        else if (guess < randomNumber)
        {
            cout << "Your guess is too low. Try again." << endl;
        }
        // Step 9: Correct guess
        else
        {
            cout << "Congratulations! You guessed the correct number." << endl;
        }
    }

    return 0;
}
