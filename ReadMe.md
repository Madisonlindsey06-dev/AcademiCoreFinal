# AcademiCore

**Author:** Sharif, Aadarsha, ila, Madison
**Course:** CSC 307 Data Structures and Algorithm Analysis
**Semester:** Spring 2026

---

## 1. Prerequisites & Environment

Before running this project, make sure you have:

* **Operating System:** Windows, macOS, or Linux
* **Compiler:** g++ (GCC)

---

## 2. Installation & Setup

1. Download all project files:

   * `main.cpp`
   * `HashTable.cpp`
   * `Student.cpp`

2. Place all files in the same folder.

---

## 3. Build Instructions

Open a terminal in the project folder and run:

```bash
g++ main.cpp -o AcademiCore
```

---

## 4. Execution Guide

Run the program:

```bash
./AcademiCore
```

On Windows:

```bash
AcademiCore.exe
```

---

## 5. Features

* Add a student record
* Search for a student by ID
* Update student information
* Delete a student record
* Display all student records
* Save records to a file
* Load records from a file

---

## 6. Data Structure Used

This project uses a **hash table with linear probing**.

* Hash function: `key % table size`
* Handles collisions using linear probing
* Average time complexity: **O(1)** for insert, search, delete

---

## 7. How It Works

* Each student is stored using a unique ID
* The hash table maps the ID to an index
* If a collision occurs, the program checks the next available slot

---

## 8. Example Usage

1. Select option `1` to add a student
2. Enter student details
3. Select option `2` to search by ID
4. Use options `3` and `4` to update or delete records

---

## 9. Known Limitations

* Names and majors do not support spaces
* Table size is fixed (20 students max)
* No resizing of the hash table

---

## 10. Notes

* This project was developed as part of a Data Structures course
* It demonstrates the use of hash tables for efficient data storage and retrieval
