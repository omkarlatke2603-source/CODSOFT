#include <iostream>
#include <string>
using namespace std;

// Maximum number of tasks
const int MAX_TASKS = 100;

// Arrays to store tasks and their status
string tasks[MAX_TASKS];
bool completed[MAX_TASKS];

// Number of tasks
int taskCount = 0;

// Function to add a task
void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "? Task list is full!\n";
        return;
    }

    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, tasks[taskCount]);

    completed[taskCount] = false;
    taskCount++;

    cout << "? Task added successfully!\n";
}

// Function to view tasks
void viewTasks()
{
    if (taskCount == 0)
    {
        cout << "?? No tasks available.\n";
        return;
    }

    cout << "\n----- TO-DO LIST -----\n";
    for (int i = 0; i < taskCount; i++)
    {
        cout << i + 1 << ". " << tasks[i];

        if (completed[i])
            cout << "  [Completed]\n";
        else
            cout << "  [Pending]\n";
    }
}

// Function to mark task as completed
void markTaskCompleted()
{
    int taskNumber;
    viewTasks();

    cout << "\nEnter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "? Invalid task number!\n";
        return;
    }

    completed[taskNumber - 1] = true;
    cout << "? Task marked as completed!\n";
}

// Function to remove a task
void removeTask()
{
    int taskNumber;
    viewTasks();

    cout << "\nEnter task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "? Invalid task number!\n";
        return;
    }

    for (int i = taskNumber - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
        completed[i] = completed[i + 1];
    }

    taskCount--;
    cout << "?? Task removed successfully!\n";
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====== TO-DO LIST MENU ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            markTaskCompleted();
            break;

        case 4:
            removeTask();
            break;

        case 5:
            cout << "?? Exiting To-Do List. Goodbye!\n";
            break;

        default:
            cout << "? Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
