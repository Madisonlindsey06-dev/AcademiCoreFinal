#include "Student.cpp"
#include <iostream>
#include <fstream>
using namespace std;

class HashTable {
private:
    static const int SIZE = 20;
    Student table[SIZE];

public:
    int hashFunction(int key) {
        return key % SIZE;
    }

    int findIndex(int id) {
        int index = hashFunction(id);
        int start = index;

        while (table[index].getID() != -1) {
            if (table[index].getID() == id) return index;

            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        return -1;
    }

    void insert(Student s) {
        if (findIndex(s.getID()) != -1) {
            cout << "ID already exists.\n";
            return;
        }

        int index = hashFunction(s.getID());

        while (table[index].getID() != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = s;
        cout << "Added.\n";
    }

    void search(int id) {
        int index = findIndex(id);
        if (index == -1) cout << "Not found.\n";
        else table[index].display();
    }

    void update(int id) {
        int index = findIndex(id);
        if (index == -1) { cout << "Not found.\n"; return; }
        table[index].update();
    }

    void remove(int id) {
        int index = findIndex(id);
        if (index == -1) { cout << "Not found.\n"; return; }
        table[index] = Student();
    }

    void displayAll() {
        for (int i = 0; i < SIZE; i++)
            if (table[i].getID() != -1)
                table[i].display();
    }

    void saveToFile(string filename) {
        ofstream file(filename);
        for (int i = 0; i < SIZE; i++)
            if (table[i].getID() != -1)
                file << table[i].toFileString() << endl;
        cout << "Saved.\n";
    }

    void loadFromFile(string filename) {
        ifstream file(filename);
        string line;

        while (getline(file, line))
            insert(Student::fromString(line));

        cout << "Loaded.\n";
    }
};
