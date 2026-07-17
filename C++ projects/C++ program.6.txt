//program.6: Write a program will take the numbers in the array as an input and the it will create the average of the numbers in the array.//
#include <iostream>
using namespace std;

int main() {
    int n;
    float sum = 0, average;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    float arr[n];
    
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    average = sum / n;
    
    cout << "Average = " << average << endl;
    
    return 0;
}
