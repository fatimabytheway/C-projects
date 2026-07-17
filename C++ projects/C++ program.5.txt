//program.5: Write a program that will take a number form the user as input and will reverse the number. If the number is reversed then it is called a palindrome and if it doesn't reversed then it is not palindrome.//
#include <iostream>
using namespace std;

int main() {
    int num, reversed = 0, original, remainder;
    
    cout << "Enter a number: ";
    cin >> num;
    
    original = num;
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }
    
    cout << "Reversed: " << reversed << endl;
    
    if (original == reversed) {
        cout << original << " is a palindrome" << endl;
    } else {
        cout << original << " is not a palindrome" << endl;
    }
    
    return 0;
}
