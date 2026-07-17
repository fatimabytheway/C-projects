//program.1: Make a program that will take the radius input from the user and will show the value of the area.//
#include <iostream>
using namespace std;

int main() {
    float r, area;
    cout << "Enter radius: ";
    cin >> r;
    area = 3.14159 * r * r;
    cout << "Area = " << area << endl;
    return 0;
}
