
#include <iostream>
#include <fstream>
#include <string>
#include "Z HUB.h"

using namespace std;

int main()
{
    User manager = {"manager", "manager123", "Manager"};
    User coordinator = {"coordinator", "coordinator123", "Coordinator"};
    User technician1 = {"tech1", "tech1pass", "Technician"};
    User technician2 = {"tech2", "tech2pass", "Technician"};
    users[0] = manager;
    users[1] = coordinator;
    users[2] = technician1;
    users[3] = technician2;
    userCount = 4;

    string loggedInUser;
    string role;

    loadInnovatorsFromFile();

    system("cls");

    displayLog();

    while (true) {
        cout << "ENTER YOUR SURNAME: ";
        cin >> loggedInUser;
        cout << "ENTER PASSWORD: ";
        string password;
        cin >> password;

        if (authenticateUser(loggedInUser, password, role)) {
            cout << "Welcome, " << role << " " << loggedInUser << "!" << endl;
            break;
        } else {
            cout << "Invalid credentials. Please try again." << endl;
        }
    }

    int choice;
    while (true) {
        displayMainMenu();
        cout << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (role == "Manager" || role == "Coordinator")
                    {
                    addInnovator();
                    saveInnovatorsToFile();
                    }
                     else
                    {
                    cout << "You do not have permission to add an innovator." << endl;
                    }
                break;
            case 2:
                if (role == "Manager" || role == "Coordinator") {
                    deleteInnovator();
                    saveInnovatorsToFile();
                } else {
                    cout << "You do not have permission to delete an innovator." << endl;
                }
                break;
            case 3:
                searchInnovator();
                break;
            case 4:
                if (role == "Manager" || role == "Coordinator") {
                    editInnovator();
                    saveInnovatorsToFile();
                } else {
                    cout << "You do not have permission to edit an innovator record." << endl;
                }
                break;
            case 5:
                displayByCategory();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

        system("cls");
    }

    return 0;
}
