#include <iostream>
#include <string>
using namespace std;

int getValidInt(string prompt);
float getValidFloat(string prompt);
string getValidString(string prompt);

class Student {
private:
    int id;
    string name;
    int age;
    string major;
    float gpa;

public:
    Student() { id = -1; }

    Student(int i, string n, int a, string m, float g) {
        id = i; name = n; age = a; major = m; gpa = g;
    }

    int getID() { return id; }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nMajor: " << major
             << "\nGPA: " << gpa << endl;
    }

    void update() {
        name = getValidString("New name: ");
        age = getValidInt("New age: ");
        major = getValidString("New major: ");
        gpa = getValidFloat("New GPA: ");
    }

    string toFileString() {
        return to_string(id) + "," + name + "," +
               to_string(age) + "," + major + "," +
               to_string(gpa);
    }

    static Student fromString(string line) {
        int id, age;
        float gpa;
        string name, major;

        id = stoi(line.substr(0, line.find(",")));
        line.erase(0, line.find(",") + 1);

        name = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);

        age = stoi(line.substr(0, line.find(",")));
        line.erase(0, line.find(",") + 1);

        major = line.substr(0, line.find(","));
        line.erase(0, line.find(",") + 1);

        gpa = stof(line);

        return Student(id, name, age, major, gpa);
    }
};
