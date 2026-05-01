/*run the following to run the program: 
g++ main.cpp -o AcademiCore*/


#include <iostream>
#include <limits>
#include "HashTable.cpp"
using namespace std;

int getValidInt(string prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value && value >= 0) {
            return value;
        }

        cout << "Please enter a valid number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

float getValidFloat(string prompt) {
    float value;

    while (true) {
        cout << prompt;

        if (cin >> value && value >= 0 && value <= 4.0) {
            return value;
        }

        cout << "Enter a GPA between 0.0 and 4.0.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string getValidString(string prompt) {
    string value;
    cout << prompt;
    cin >> value;
    return value;
}

void menu() {
    cout << "\n============================\n";
    cout << "      AcademiCore Menu\n";
    cout << "============================\n";
    cout << "1. Add Student\n";
    cout << "2. Search Student\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Show All Students\n";
    cout << "6. Save\n";
    cout << "7. Load\n";
    cout << "8. Exit\n";
}

int getChoice() {
    int choice;

    cout << "\nChoose option: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

int main() {
    HashTable db;
    int choice;

    do {
        menu();
        choice = getChoice();

        if (choice == -1) continue;

        if (choice == 1) {
            cout << "\nAdding student...\n";

            int id = getValidInt("ID: ");
            string name = getValidString("Name: ");
            int age = getValidInt("Age: ");
            string major = getValidString("Major: ");
            float gpa = getValidFloat("GPA: ");

            db.insert(Student(id, name, age, major, gpa));
        }

        else if (choice == 2) {
            int id = getValidInt("Enter ID: ");
            db.search(id);
        }

        else if (choice == 3) {
            int id = getValidInt("Enter ID: ");
            db.update(id);
        }

        else if (choice == 4) {
            int id = getValidInt("Enter ID: ");
            db.remove(id);
        }

        else if (choice == 5) {
            db.displayAll();
        }

        else if (choice == 6) {
            db.saveToFile("students.txt");
        }

        else if (choice == 7) {
            db.loadFromFile("students.txt");
        }

    } while (choice != 8);

    cout << "\nGoodbye.\n";
    return 0;
}
