#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

// Book data
string title[MAX_BOOKS];
string author[MAX_BOOKS];
string isbn[MAX_BOOKS];
bool isIssued[MAX_BOOKS];

int bookCount = 0;

// Function to add a book
void addBook()
{
    if (bookCount >= MAX_BOOKS)
    {
        cout << "? Library is full!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title[bookCount]);

    cout << "Enter Author Name: ";
    getline(cin, author[bookCount]);

    cout << "Enter ISBN Number: ";
    getline(cin, isbn[bookCount]);

    isIssued[bookCount] = false;
    bookCount++;

    cout << "? Book added successfully!\n";
}

// Function to display all books
void viewBooks()
{
    if (bookCount == 0)
    {
        cout << "?? No books available.\n";
        return;
    }

    cout << "\n------ LIBRARY BOOK LIST ------\n";
    for (int i = 0; i < bookCount; i++)
    {
        cout << "\nBook No: " << i + 1;
        cout << "\nTitle  : " << title[i];
        cout << "\nAuthor : " << author[i];
        cout << "\nISBN   : " << isbn[i];

        if (isIssued[i])
            cout << "\nStatus : Issued\n";
        else
            cout << "\nStatus : Available\n";
    }
}

// Function to search a book
void searchBook()
{
    string key;
    int found = 0;

    cin.ignore();
    cout << "Enter Title / Author / ISBN to search: ";
    getline(cin, key);

    for (int i = 0; i < bookCount; i++)
    {
        if (title[i] == key || author[i] == key || isbn[i] == key)
        {
            cout << "\n? Book Found!";
            cout << "\nTitle  : " << title[i];
            cout << "\nAuthor : " << author[i];
            cout << "\nISBN   : " << isbn[i];

            if (isIssued[i])
                cout << "\nStatus : Issued\n";
            else
                cout << "\nStatus : Available\n";

            found = 1;
            break;
        }
    }

    if (!found)
        cout << "? Book not found!\n";
}

// Function to checkout a book
void checkoutBook()
{
    int num;
    viewBooks();

    cout << "\nEnter Book Number to Checkout: ";
    cin >> num;

    if (num < 1 || num > bookCount)
    {
        cout << "? Invalid book number!\n";
        return;
    }

    if (isIssued[num - 1])
    {
        cout << "? Book already issued!\n";
    }
    else
    {
        isIssued[num - 1] = true;
        cout << "? Book checked out successfully!\n";
    }
}

// Function to return a book & calculate fine
void returnBook()
{
    int num, days;
    viewBooks();

    cout << "\nEnter Book Number to Return: ";
    cin >> num;

    if (num < 1 || num > bookCount)
    {
        cout << "? Invalid book number!\n";
        return;
    }

    if (!isIssued[num - 1])
    {
        cout << "? This book was not issued!\n";
        return;
    }

    cout << "Enter number of days late (0 if on time): ";
    cin >> days;

    if (days > 0)
    {
        int fine = days * 5;   // Rs.5 per day
        cout << "?? Fine Amount: Rs. " << fine << endl;
    }
    else
    {
        cout << "? No fine. Returned on time!\n";
    }

    isIssued[num - 1] = false;
    cout << "?? Book returned successfully!\n";
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====== LIBRARY MANAGEMENT SYSTEM ======\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            checkoutBook();
            break;
        case 5:
            returnBook();
            break;
        case 6:
            cout << "?? Exiting Library System. Thank you!\n";
            break;
        default:
            cout << "? Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
