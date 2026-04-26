#include <iostream>
#include <limits>
using namespace std;

void displayMenu()
{
  cout << "\n=========================" << endl;
  cout << "      ACADEMICORE MENU       " << endl;
  cout << "===========================" << endl;
  cout << "1. Add Student Record" << endl;
  cout << "2. View Student Record (by ID)" << endl;
  cout << "3. Update Student Record" << endl;
  cout << "4. Delete Student Record" << endl;
  cout << "5. Exit System" << endl;
}

int getUserChoice() {
  int choice;
  
  cout << "\nEnter selection: ";
  
if (!(cin >> choice)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a number.\n";
    return -1;
  }
  
  return choice;
}

void runApplication() {
  int choice = 0;

do {
    displayMenu();
    choice = getUserChoice();

    if (choice == -1) continue;

    switch (choice) {
      
      case 1: 
        cout << "\n[ADD STUDENT RECORD]" << endl;
        cout << "Enter student ID and details when prompted by the system...\n";
        break;
      
      case 2:
        cout << "\n[VIEW STUDENT RECORD]" << endl;
        cout << "Enter Student ID to retrieve record...\n";
        break;
      
      case 3:
        cout << "\n[UPDATE STUDENT RECORD]" << endl;
        cout << "Enter Student ID to modify record...\n";
        break;
      
      case 4:
        cout << "\n[DELETE STUDENT RECORD]" << endl;
        cout << "Enter Student ID to remove record...\n";
        break;
      
      case 5:
        cout << "\nExiting AcademiCore system..." << endl;
        break;
      
      default:
        cout << "\nInvalid selection. Try again.\n" << endl;
      
    }
  } while (choice != 5);
  
}

int main() {
    runApplication();
    return 0;
}
