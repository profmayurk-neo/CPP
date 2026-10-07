/*
Q.7: hybrid inheritance
base class student
derived class virtual test and virtual sports
derived derived class Result
here test and sport both inherit from student virtuality
class test: virtual public student
class sports: virtual public student
therefore result gets only one copy of student and rollno is not ambiguous
this is the classic student->test, sports ->result example of virtual base class
*/

#include <iostream>
using namespace std;
class Student{
    protected:
        int rollno;
    public:
        void setRollNo(int r){
            rollno = r;
        }
        void displayRollNo(){
            cout << "Roll No: " << rollno << endl;
        }
};
class Test : virtual public Student{
    protected:
        float marks;
    public:
        void setMarks(float m){
            marks = m;
        }
        void displayMarks(){
            cout << "Marks: " << marks << endl;
        }
};
class Sports : virtual public Student{
    protected:
        float score;
    public:
        void setScore(float s){
            score = s;
        }
        void displayScore(){
            cout << "Score: " << score << endl;
        }
};
class Result : public Test, public Sports{
    public:
        void displayResult(){
            displayRollNo();
            displayMarks();
            displayScore();
        }
};
int main(){
    Result r;
    r.setRollNo(101);
    r.setMarks(85.5);
    r.setScore(9.5);
    r.displayResult();
    return 0;
}