#include <iostream>
#include <string>

using namespace std;


class Employee {
protected:
	
    int emp_id;
    string name;
    double sal;

public:
    void getEmployeeData(int id, string empName, double salary) {
        emp_id = id;
        name = empName;
        sal = salary;
    }
};


class Bonus : public Employee {
private:
    int att_days;
    double bonus_amt;
    double net_sal;

public:
    void calculateNetSalary(int days) {
        att_days = days;

       
        if (att_days < 200) {
            bonus_amt = sal * 0.10; 
        }
		else {
            bonus_amt = sal * 0.065; 
        }


        net_sal = sal + bonus_amt;
    }

    void displayDetails() {
        cout << " Employee " << endl;
        cout << "Employee ID : " << emp_id << endl;
        cout << "Name        : " << name << endl;
        cout << "Base Salary : " << sal << endl;
        cout << "Attendance  : " << att_days << " days" << endl;
        cout << "Bonus: " << bonus_amt << endl;
        cout << "Net Salary  : " << net_sal << endl;
    }
};

int main() {
    Bonus emp;
    
   
    emp.getEmployeeData(101, "Rahul Gandhi", 40000.0);
    
   
    emp.calculateNetSalary(185);
    
  
    emp.displayDetails();

    return 0;
}