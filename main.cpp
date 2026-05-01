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
    cout << "\n====== AcademiCore ======\n";
    cout << "1. Add\n2. View\n3. Update\n4. Delete\n5. Show All\n6. Save\n7. Load\n8. Exit\n";
}

int getChoice() {
    int c;
    cout << "Choice: ";

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
            int id = getValidInt("ID: ");
            string name = getValidString("Name: ");
            int age = getValidInt("Age: ");
            string major = getValidString("Major: ");
            float gpa = getValidFloat("GPA: ");

            table.insert(Student(id, name, age, major, gpa));
        }

        else if (choice == 2) {
            int id = getValidInt("ID: ");
            table.search(id);
        }

        else if (choice == 3) {
            int id = getValidInt("ID: ");
            table.update(id);
        }

        else if (choice == 4) {
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
}
