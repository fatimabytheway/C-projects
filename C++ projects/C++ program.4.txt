//program.4: Write a program that will take a year as an input from the user and will tell if the year is a leap year or not.//
#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }
    
    return 0;
}
