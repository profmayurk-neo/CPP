/*
Q.5:  Employee Management System
Problem statement
Develop a menu-driven Employee Management system using c++
create a class named Employee with the following data members:
Employee Id, employee name, department, basic salary, years of experience
The class should contain:
-A default constructor to initialize employee data.
-A parametrized constructor to initialize an employee with given values.
-A destructor to display a message when an employee object is destroyed
-A member fuction input() to accept employee details
-A member function display() to display employee details
-A member function to calculate the gross salary
-A member function to search for an Employee using employee Id
use an array of objects to store multiple employee records
Menu options:
the program should provide:
add employee
display all employees
search employee
calcualte gross salary
*/

#include<iostream>
using namespace std;

class Employee {
    int empId,exp;
    string empName, department;
    float basicSalary;
    public:
        Employee(){empId=0; empName=""; department=""; basicSalary=0.0; exp=0;}
        Employee(int id, string name, string dept, float salary, int experience);
        ~Employee();
        void input(){
            cout<<"Enter Employee Id: "; cin>>empId;
            cout<<"Enter Employee Name: "; cin.ignore(); getline(cin, empName);
            cout<<"Enter Department: "; getline(cin, department);
            cout<<"Enter Basic Salary: "; cin>>basicSalary;
            cout<<"Enter Years of Experience: "; cin>>exp;
        }
        void display(){
            cout<<"Employee Id: "<<empId<<endl;
            cout<<"Employee Name: "<<empName<<endl;
            cout<<"Department: "<<department<<endl;
            cout<<"Basic Salary: "<<basicSalary<<endl;
            cout<<"Years of Experience: "<<exp<<endl;
        }
        float calculateGrossSalary(){
            return basicSalary + (basicSalary * 0.1 * exp); // Assuming 10% increment per year of experience
        }
        int getEmpId(){
            return empId;
        }
        void searchEmployee(int id){
            if(empId == id){
                display();
            } else {
                cout<<"Employee with Id "<<id<<" not found."<<endl;
            }
        }
};
int main() {
    Employee emp[10];
    int choice, n=0, id;
    do {
        cout<<"\n1. Add Employee\n2. Display All Employees\n3. Search Employee\n4. Calculate Gross Salary\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                if(n<10) {
                    emp[n].input();
                    n++;
                } else {
                    cout<<"Maximum number of employees reached."<<endl;
                }
                break;
            case 2:
                for(int i=0; i<n; i++) {
                    emp[i].display();
                }
                break;
            case 3:
                cout<<"Enter Employee Id to search: ";
                cin>>id;
                for(int i=0; i<n; i++) {
                    emp[i].searchEmployee(id);
                }
                break;
            case 4:
                cout<<"Enter Employee Id to calculate gross salary: ";
                cin>>id;
                for(int i=0; i<n; i++) {
                    if(emp[i].getEmpId() == id) {
                        cout<<"Gross Salary: "<<emp[i].calculateGrossSalary()<<endl;
                        break;
                    }
                }
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }
    } while(choice != 5);
    return 0;
}