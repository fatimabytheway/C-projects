//program.11:write a class to demonstrate polymorphism, whose base class shape is derived classes 1-rectangle, 2-circle.//
#include <iostream>
using namespace std;

// Base Class
class Shape {
public:
    virtual double area() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

// Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override { return length * width; }
    void display() override {
        cout << "Rectangle: " << length << " x " << width 
             << " = Area: " << area() << endl;
    }
};

// Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return 3.14159 * radius * radius; }
    void display() override {
        cout << "Circle: Radius = " << radius 
             << " Area: " << area() << endl;
    }
};

int main() {
    Shape* shapes[2];
    
    shapes[0] = new Rectangle(5, 3);
    shapes[1] = new Circle(4);
    
    // Polymorphism in action
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
    }
        
    return 0;
}
