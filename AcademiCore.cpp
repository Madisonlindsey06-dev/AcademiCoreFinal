#include <iostream>
#include <limits>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    string major;
    float gpa;

public:
    Student() {
        id = -1;
    }

    Student(int i, string n, int a, string m, float g) {
        id = i;
        name = n;
        age = a;
        major = m;
        gpa = g;
    }

    int getID() {
        return id;
    }

    void display() {
        cout << "\n--- Student Info ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Major: " << major << endl;
        cout << "GPA: " << gpa << endl;
    }

    void update() {
        cout << "\nUpdating student...\n";

        cout << "New name: ";
        cin >> name;

        cout << "New age: ";
        cin >> age;

        cout << "New major: ";
        cin >> major;

        cout << "New GPA: ";
        cin >> gpa;
    }
};

class HashTable {
private:
    Student* table;
    int capacity;

public:
    HashTable(int size = 10) {
        capacity = size;
        table = new Student[capacity];
    }

    int hash(int key) {
        return key % capacity;
    }

    void add(Student s) {
        int index = hash(s.getID());

        while (table[index].getID() != -1) {
            index = (index + 1) % capacity;
        }

        table[index] = s;
        cout << "Student added.\n";
    }

    Student* find(int id) {
        int index = hash(id);
        int start = index;

        while (table[index].getID() != -1) {
            if (table[index].getID() == id) {
                return &table[index];
            }

            index = (index + 1) % capacity;

            if (index == start) break;
        }

        return nullptr;
    }

    void remove(int id) {
        Student* s = find(id);

        if (!s) {
            cout << "Couldn’t find that student.\n";
            return;
        }

        *s = Student();
        cout << "Student removed.\n";
    }

    void edit(int id) {
        Student* s = find(id);

        if (!s) {
            cout << "Student not found.\n";
            return;
        }

        s->update();
        cout << "Updated successfully.\n";
    }
};

void showMenu() {
    cout << "\n=========================\n";
    cout << "     ACADEMICORE MENU    \n";
    cout << "=========================\n";
    cout << "1. Add Student\n";
    cout << "2. View Student\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Exit\n";
}

int getChoice() {
    int choice;

    cout << "\nPick an option: ";

    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number.\n";
        return -1;
    }

    return choice;
}

void runApp() {
    HashTable db(10);
    int choice;

    do {
        showMenu();
        choice = getChoice();

        if (choice == -1) continue;

        if (choice == 1) {
            int id, age;
            string name, major;
            float gpa;

            cout << "\nAdd student\n";

            cout << "ID: ";
            cin >> id;

            cout << "Name: ";
            cin >> name;

            cout << "Age: ";
            cin >> age;

            cout << "Major: ";
            cin >> major;

            cout << "GPA: ";
            cin >> gpa;

            db.add(Student(id, name, age, major, gpa));
        }

        else if (choice == 2) {
            int id;
            cout << "\nEnter ID: ";
            cin >> id;

            Student* s = db.find(id);

            if (s)
                s->display();
            else
                cout << "No record found.\n";
        }

        else if (choice == 3) {
            int id;
            cout << "\nEnter ID to update: ";
            cin >> id;

            db.edit(id);
        }

        else if (choice == 4) {
            int id;
            cout << "\nEnter ID to delete: ";
            cin >> id;

            db.remove(id);
        }

        else if (choice == 5) {
            cout << "\nGoodbye\n";
        }

        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);
}

int main() {
    runApp();
    return 0;
}