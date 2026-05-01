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
        if (cin >> value) return value;

        cout << "Invalid input. Enter a number.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

float getValidFloat(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;

        cout << "Invalid input. Enter a valid number.\n";
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
    cout << "\n=================================\n";
    cout << "         ACADEMICORE SYSTEM       \n";
    cout << "=================================\n";
    cout << " 1. Add Student Record\n";
    cout << " 2. Search Student\n";
    cout << " 3. Update Student Record\n";
    cout << " 4. Delete Student Record\n";
    cout << " 5. Display All Students\n";
    cout << " 6. Save to File\n";
    cout << " 7. Load from File\n";
    cout << " 8. Exit\n";
    cout << "---------------------------------\n";
}

int getChoice() {
    int c;
    cout << "Enter choice: ";

    if (!(cin >> c)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return c;
}

int main() {
    HashTable table;
    int choice;

    do {
        menu();
        choice = getChoice();

        if (choice == -1) continue;

        if (choice == 1) {
            cout << "\n--- Add Student ---\n";
            int id = getValidInt("ID: ");
            string name = getValidString("Name: ");
            int age = getValidInt("Age: ");
            string major = getValidString("Major: ");
            float gpa = getValidFloat("GPA: ");

            table.insert(Student(id, name, age, major, gpa));
        }

        else if (choice == 2) {
            cout << "\n--- Search Student ---\n";
            int id = getValidInt("ID: ");
            table.search(id);
        }

        else if (choice == 3) {
            cout << "\n--- Update Student ---\n";
            int id = getValidInt("ID: ");
            table.update(id);
        }

        else if (choice == 4) {
            cout << "\n--- Delete Student ---\n";
            int id = getValidInt("ID: ");
            table.remove(id);
        }

        else if (choice == 5) {
            table.displayAll();
        }

        else if (choice == 6) {
            table.saveToFile("students.txt");
        }

        else if (choice == 7) {
            table.loadFromFile("students.txt");
        }

    } while (choice != 8);

    return 0;
}
