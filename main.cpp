/*run the following to run the program: 
g++ main.cpp -o AcademiCore*/


#include <iostream>
#include <limits>
#include "HashTable.cpp"
using namespace std;

void menu() {
    cout << "\n1. Add\n2. View\n3. Update\n4. Delete\n5. Show All\n6. Save\n7. Load\n8. Exit\n";
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

        if (choice == 1) {
            int id, age; string name, major; float gpa;

            cout << "ID: "; cin >> id;
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Major: "; cin >> major;
            cout << "GPA: "; cin >> gpa;

            table.insert(Student(id, name, age, major, gpa));
        }

        else if (choice == 2) {
            int id; cout << "ID: "; cin >> id;
            table.search(id);
        }

        else if (choice == 3) {
            int id; cout << "ID: "; cin >> id;
            table.update(id);
        }

        else if (choice == 4) {
            int id; cout << "ID: "; cin >> id;
            table.remove(id);
        }

        else if (choice == 5) table.displayAll();
        else if (choice == 6) table.saveToFile("students.txt");
        else if (choice == 7) table.loadFromFile("students.txt");

    } while (choice != 8);

    return 0;
}