#ifndef Z_HUB_H_INCLUDED
#define Z_HUB_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DATABASE_FILE = "innovators.txt"; // File to store innovator records

struct Innovator {
    string nrcOrPassport;
    string firstName;
    string surname;
    int age;
    string innovationTitle;
    string dateSubmitted;
    string patentStatus;
    string innovationCategory;
};

struct User {
    string username;
    string password;
    string role;
};

const int MAX_INNOVATORS = 50;
Innovator innovators[MAX_INNOVATORS];
int innovatorCount = 0;

const int MAX_USERS = 10;
User users[MAX_USERS];
int userCount = 0;

// Define valid innovation categories
const string VALID_CATEGORIES[] = {"foodTech", "WoodTech", "MetalTech", "IT"};
const int NUM_CATEGORIES = 4;

void displayLog()
{
    cout<<"\t---------------------------------------------\n";
    cout<<"\t                WELCOME\n";
    cout<<"\t                  TO\n";
    cout<<"\t           Z-HUB INNOVATATION\n";
    cout <<"\t--------------------------------------------\n";

}

void displayMainMenu() {
    system("cls");
    cout << "Z-Hub Innovation Records Management System \n" << endl;
    cout << "\t 1. Add Innovator" << endl;
    cout << "\t 2. Delete Innovator Record" << endl;
    cout << "\t 3. Search for Innovator" << endl;
    cout << "\t 4. Edit Innovator Record" << endl;
    cout << "\t 5. Display Innovators by Innovation Category" << endl;
    cout << "\t 6. Exit" << endl;
}

// Function to authenticate users
bool authenticateUser(const string& username, const string& password, string& role) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            role = users[i].role;
            return true;
        }
    }
    return false;
}

// Function to add a new innovator
void addInnovator()
{
    system("cls");

    if (innovatorCount < MAX_INNOVATORS) {
        Innovator innovator;
        cout << "Enter NRC No / Passport No: ";
        getline(cin >>ws, innovator.nrcOrPassport);
        cout << "Enter First Name: ";
        getline(cin >> ws, innovator.firstName);
        cout << "Enter Surname: ";
        getline(cin >> ws, innovator.surname);
        cout << "Enter Age: ";
        cin >> innovator.age;
        cout << "Enter Title of Innovation: ";
        getline(cin >>ws, innovator.innovationTitle);
        cout << "Enter Date Submitted: ";
        getline(cin >>ws, innovator.dateSubmitted);
        cout << "Enter Patent Status (patented/in progress/not required): ";
        getline(cin >>ws, innovator.patentStatus);

        // Prompt the user to select an innovation category
        cout << "Select Innovation Category:" << endl;
        for (int i = 0; i < NUM_CATEGORIES; i++) {
            cout << i + 1 << ". " << VALID_CATEGORIES[i] << endl;
        }

        int categoryChoice;
        do {
            cout << "Enter the number corresponding to the category: ";
            cin >> categoryChoice;
        } while (categoryChoice < 1 || categoryChoice > NUM_CATEGORIES);

        innovator.innovationCategory = VALID_CATEGORIES[categoryChoice - 1];

        innovators[innovatorCount] = innovator;
        innovatorCount++;
        cout << "Innovator added successfully." << endl;
    } else {
        cout << "Maximum innovator limit reached." << endl;
    }
}

// Function to delete an innovator record
void deleteInnovator() {
    system("cls");

    string searchNrcOrPassport;
    cout << "Enter NRC No / Passport No to delete: ";
    cin >> searchNrcOrPassport;

    for (int i = 0; i < innovatorCount; i++) {
        if (innovators[i].nrcOrPassport == searchNrcOrPassport) {
            for (int j = i; j < innovatorCount - 1; j++) {
                innovators[j] = innovators[j + 1];
            }
            innovatorCount--;
            cout << "Innovator record deleted." << endl;
            return;
        }
    }

    cout << "Innovator not found." << endl;
}

// Function to search for an innovator by NRC/Passport
void searchInnovator() {
    // No need to clear the screen here
    string searchNrcOrPassport;
    cout << "Enter NRC No / Passport No to search: ";
    cin >> searchNrcOrPassport;

    for (int i = 0; i < innovatorCount; i++) {
        if (innovators[i].nrcOrPassport == searchNrcOrPassport) {
            cout << "Innovator Found:" << endl;
            cout << "NRC/Passport: " << innovators[i].nrcOrPassport << endl;
            cout << "First Name: " << innovators[i].firstName << endl;
            cout << "Surname: " << innovators[i].surname << endl;
            cout << "Age: " << innovators[i].age << endl;
            cout << "Innovation Title: " << innovators[i].innovationTitle << endl;
            cout << "Date Submitted: " << innovators[i].dateSubmitted << endl;
            cout << "Patent Status: " << innovators[i].patentStatus << endl;
            cout << "Innovation Category: " << innovators[i].innovationCategory << endl;
        }
    }

    cout << "Innovator not found." << endl;
}

// Function to edit an innovator record
void editInnovator() {
    system("cls");

    string searchNrcOrPassport;
    cout << "Enter NRC No / Passport No to edit: ";
    cin >> searchNrcOrPassport;

    for (int i = 0; i < innovatorCount; i++) {
        if (innovators[i].nrcOrPassport == searchNrcOrPassport) {
            Innovator& innovator = innovators[i];
            cout << "Enter New Data for Innovator " << searchNrcOrPassport << ":" << endl;
            cout << "Enter First Name: ";
            cin >> innovator.firstName;
            cout << "Enter Surname: ";
            cin >> innovator.surname;
            cout << "Enter Age: ";
            cin >> innovator.age;
            cout << "Enter Title of Innovation: ";
            cin >> innovator.innovationTitle;
            cout << "Enter Date Submitted: ";
            cin >> innovator.dateSubmitted;
            cout << "Enter Patent Status (patented/in progress/not required): ";
            cin >> innovator.patentStatus;
            cout << "Enter Innovation Category (foodTech/WoodTech/MetalTech/IT): ";
            cin >> innovator.innovationCategory;
            cout << "Innovator " << searchNrcOrPassport << " updated successfully." << endl;
            return;
        }
    }

    cout << "Innovator not found." << endl;
}

// Function to display innovators by innovation category
void displayByCategory() {
    // No need to clear the screen here
    string category;
    cout << "Enter Innovation Category to display (foodTech/WoodTech/MetalTech/IT): ";
    cin >> category;

    cout << "Innovators in Category '" << category << "':" << endl;
    for (int i = 0; i < innovatorCount; i++) {
        if (innovators[i].innovationCategory == category) {
            cout << "NRC/Passport: " << innovators[i].nrcOrPassport << endl;
            cout << "First Name: " << innovators[i].firstName << endl;
            cout << "Surname: " << innovators[i].surname << endl;
            cout << "Age: " << innovators[i].age << endl;
            cout << "Innovation Title: " << innovators[i].innovationTitle << endl;
            cout << "Date Submitted: " << innovators[i].dateSubmitted << endl;
            cout << "Patent Status: " << innovators[i].patentStatus << endl;
            cout << "Innovation Category: " << innovators[i].innovationCategory << endl;
            cout << "---------------------" << endl;
        }
    }
}

// Function to save innovator records to a file
void saveInnovatorsToFile() {
    ofstream file(DATABASE_FILE.c_str()); // Open for writing
    if (file.is_open()) {
        file << innovatorCount << endl;
        for (int i = 0; i < innovatorCount; i++) {
            file << innovators[i].nrcOrPassport << endl;
            file << innovators[i].firstName << endl;
            file << innovators[i].surname << endl;
            file << innovators[i].age << endl;
            file << innovators[i].innovationTitle << endl;
            file << innovators[i].dateSubmitted << endl;
            file << innovators[i].patentStatus << endl;
            file << innovators[i].innovationCategory << endl;
        }
        file.close();
    } else {
        cout << "Failed to save innovator records to the file." << endl;
    }
}

// Function to load innovator records from a file
void loadInnovatorsFromFile() {
    ifstream file(DATABASE_FILE.c_str()); // Open for reading
    if (file.is_open()) {
        file >> innovatorCount;
        file.ignore(); // Consume the newline character
        for (int i = 0; i < innovatorCount; i++) {
            getline(file, innovators[i].nrcOrPassport);
            getline(file, innovators[i].firstName);
            getline(file, innovators[i].surname);
            file >> innovators[i].age;
            file.ignore(); // Consume the newline character
            getline(file, innovators[i].innovationTitle);
            getline(file, innovators[i].dateSubmitted);
            getline(file, innovators[i].patentStatus);
            getline(file, innovators[i].innovationCategory);
        }
        file.close();
    } else {
        cout << "No Previous Records Found. Starting With An Empty Database." << endl;
    }
}


#endif // Z_HUB_H_INCLUDED
