//program.8: Write a program that will take the take the number, roll no and marks of three subjects form the user and will calculate the grade by calculating the percentage and will tell the grade of the student.
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks[3];
    
    void calculateGrade() {
        float total = marks[0] + marks[1] + marks[2];
        float percentage = (total / 300) * 100;
        
        cout << "\nStudent Result" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Total: " << total << "/300" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        
        if (percentage >= 90) cout << "Grade: A (Excellent)" << endl;
        else if (percentage >= 80) cout << "Grade: B (Very Good)" << endl;
        else if (percentage >= 70) cout << "Grade: C (Good)" << endl;
        else if (percentage >= 60) cout << "Grade: D (Average)" << endl;
        else if (percentage >= 50) cout << "Grade: E (Pass)" << endl;
        else cout << "Grade: F (Fail)" << endl;
    }
};

int main() {
    Student s;
    
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter marks in 3 subjects: ";
    cin >> s.marks[0] >> s.marks[1] >> s.marks[2];
    
    s.calculateGrade();
    
    return 0;
}
