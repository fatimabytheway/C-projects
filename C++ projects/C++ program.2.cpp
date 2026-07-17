//program.2: Write a program that will take the salary, allowance and deduction of the person and will calculate the net salary of a person.//
#include <iostream>
using namespace std;

int main() {
    float basic, allowancePer, deductionPer;
    float netSalary;
    
    cout << "Enter Basic Salary: ";
    cin >> basic;
    cout << "Enter Allowance %: ";
    cin >> allowancePer;
    cout << "Enter Deduction %: ";
    cin >> deductionPer;
    
    netSalary = basic + (basic * allowancePer / 100) - (basic * deductionPer / 100);
    
    cout << "Net Salary = " << netSalary << endl;
    
    return 0;
}
