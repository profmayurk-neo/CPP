/*
Q.6: Create a base class Person containing name and age. Derive two classes, Student and
Employee, from Person.
Then create a class TeachingAssistant that inherits from both Student and Employee. The
TeachingAssistant should store student roll number and employee ID and display all available
information.
Use virtual inheritance to avoid ambiguity caused by the diamond structure.
Inheritance type: Hybrid inheritance
Classes:
Person
/ \
Student Employee
\ /
TeachingAssistant
Example Input:
Name: Rahul
Age: 22
Roll No: 101
Employee ID: TA501
*/
#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}
};

class Student : virtual public Person {
protected:
    int rollNo;
public:
    Student() : rollNo(0) {}
    Student(string n, int a, int roll) : Person(n, a), rollNo(roll) {}
};

class Employee : virtual public Person {
protected:
    string employeeId;
public:
    Employee() : employeeId("") {}
    Employee(string n, int a, string id) : Person(n, a), employeeId(id) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n, int a, int roll, string id) : Person(n, a), Student(n, a, roll), Employee(n, a, id) {}
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};
int main() {
    string name, employeeId;
    int age, rollNo;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Employee ID: ";
    cin.ignore();
    getline(cin, employeeId);

    TeachingAssistant ta(name, age, rollNo, employeeId);
    ta.displayInfo();

    return 0;
}