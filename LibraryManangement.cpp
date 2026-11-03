/*1.	Mini Project: Library Book Management System
Problem Statement
Develop a Library Book Management System in C++ using Object-Oriented Programming (OOP) concepts.
The system should allow a librarian to store and manage information about books in a library. Each book should have details such as book ID, title, author, and availability status.
Create a class named Book with appropriate data members and member functions.
Requirements
Your program should:
•	Create a Book class containing:
o	bookId
o	title
o	author
o	isAvailable
•	Implement:
1.	Default constructor to initialize a book with default values.
2.	Parameterized constructor to initialize book details when an object is created.
3.	Destructor that displays a message when a book object is destroyed.
4.	A function displayBook() to display book information.
5.	A function issueBook() to issue a book if it is available.
6.	A function returnBook() to mark an issued book as available.
*/

#include<iostream>
using namespace std;

class Book{
    int bookId;
    string title, author;
    bool isAvailable;
    public:
        Book(){bookId=0; title=""; author=""; isAvailable=true;}
        ~Book(){cout<<"Book object destroyed."<<endl;}
        Book(int id, string t, string a, bool status){
            bookId=id, title=t, author=a, isAvailable=status;
        }
        void displayBook(){
            cout<<"\nBook ID: "<<bookId;
            cout<<"\nTitle: "<<title;
            cout<<"\nAuthor: "<<author;
            cout<<"\nAvailability: "<<(isAvailable ? "Available" : "Issued")<<endl;
        }
        void issueBook(){
            if(isAvailable){
                isAvailable=false;
                cout<<"\nBook issued successfully!"<<endl;
            } else {
                cout<<"\nBook is already issued!"<<endl;
            }
        }
        void returnBook(){
            if(!isAvailable){
                isAvailable=true;
                cout<<"\nBook returned successfully!"<<endl;
            } else {
                cout<<"\nBook is already available!"<<endl;
            }
        }
};

int main(){
    Book b1;
    Book b2(101, "The Great Gatsby", "F. Scott Fitzgerald", true);
    b1.displayBook();
    b2.displayBook();
    b2.issueBook();
    b2.displayBook();
    b2.returnBook();
    b2.displayBook();
    return 0;
}