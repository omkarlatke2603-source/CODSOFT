
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables to store numbers and user choice
    double number1, number2, result;
    int operation;
    char continueChoice;
    
    // Display welcome message
    cout << "========================================" << endl;
    cout << "     WELCOME TO SIMPLE CALCULATOR      " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Main loop to allow multiple calculations
    do {
        // Get first number from user
        cout << "Enter the first number: ";
        cin >> number1;
        
        // Get second number from user
        cout << "Enter the second number: ";
        cin >> number2;
        
        cout << endl;
        
        // Display menu of operations
        cout << "========================================" << endl;
        cout << "         SELECT AN OPERATION            " << endl;
        cout << "========================================" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> operation;
        
        cout << endl;
        cout << "========================================" << endl;
        
        // Perform operation based on user choice
        if (operation == 1) {
            // Addition operation
            result = number1 + number2;
            cout << "Operation: Addition" << endl;
            cout << number1 << " + " << number2 << " = " << result << endl;
        }
        else if (operation == 2) {
            // Subtraction operation
            result = number1 - number2;
            cout << "Operation: Subtraction" << endl;
            cout << number1 << " - " << number2 << " = " << result << endl;
        }
        else if (operation == 3) {
            // Multiplication operation
            result = number1 * number2;
            cout << "Operation: Multiplication" << endl;
            cout << number1 << " * " << number2 << " = " << result << endl;
        }
        else if (operation == 4) {
            // Division operation
            // Check if second number is zero to avoid division by zero error
            if (number2 != 0) {
                result = number1 / number2;
                cout << "Operation: Division" << endl;
                cout << number1 << " / " << number2 << " = " << result << endl;
            }
            else {
                // Display error message if user tries to divide by zero
                cout << "ERROR: Division by zero is not allowed!" << endl;
                cout << "Please enter a non-zero number for division." << endl;
            }
        }
        else {
            // Display error message for invalid operation choice
            cout << "ERROR: Invalid operation selected!" << endl;
            cout << "Please choose a number between 1 and 4." << endl;
        }
        
        cout << "========================================" << endl;
        cout << endl;
        
        // Ask user if they want to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueChoice;
        cout << endl;
        
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    // Display goodbye message
    cout << "========================================" << endl;
    cout << "   Thank you for using the calculator!  " << endl;
    cout << "========================================" << endl;
    
    return 0;
}


