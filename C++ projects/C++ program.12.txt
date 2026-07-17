//program.12: Write a program to prepare a class for the stack with expections; 1-Stack Overflow , 2-Stack Underflow//
#include <iostream>
using namespace std;

class StackOverflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Overflow!";
    }
};

class StackUnderflow : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow!";
    }
};

class Stack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int cap = 5) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int value) {
        if (top == capacity - 1) {
            throw StackOverflow();
        }
        arr[++top] = value;
    }
    
    int pop() {
        if (top == -1) {
            throw StackUnderflow();
        }
        return arr[top--];
    }
    
    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Stack s(3);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);  
    } catch (const StackOverflow& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const StackUnderflow& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
