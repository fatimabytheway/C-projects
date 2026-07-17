//program.10: Write a program that will calculate the monthly salary of the fulltime employee and part time employee.//
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Employee {
protected:
    int id;
    string name;
    
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual double calculateSalary() = 0;
    virtual void display() {
        cout << "ID: " << id << ", Name: " << name;
    }
    virtual ~Employee() {}
};

// Full-Time Employee
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;
    
public:
    FullTimeEmployee(int i, string n, double salary) 
        : Employee(i, n), monthlySalary(salary) {}
    
    double calculateSalary() override {
        return monthlySalary;
    }
    
    void display() override {
        Employee::display();
        cout << ", Type: Full-Time, Salary: $" << monthlySalary << endl;
    }
};

// Part-Time Employee
class PartTimeEmployee : public Employee {
private:
    double dailyWage;
    int daysWorked;
    
public:
    PartTimeEmployee(int i, string n, double wage, int days) 
        : Employee(i, n), dailyWage(wage), daysWorked(days) {}
    
    double calculateSalary() override {
        return dailyWage * daysWorked;
    }
    
    void display() override {
        Employee::display();
        cout << ", Type: Part-Time, Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    Employee* employees[3];
    
    employees[0] = new FullTimeEmployee(101, "John Doe", 5000);
    employees[1] = new PartTimeEmployee(102, "Jane Smith", 200, 15);
    employees[2] = new FullTimeEmployee(103, "Bob Johnson", 6000);
    
    cout << "Employee Details:" << endl;
       
    for (int i = 0; i < 3; i++) {
        employees[i]->display();
    }
    
       return 0;
}
