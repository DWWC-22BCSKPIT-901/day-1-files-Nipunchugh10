#include <iostream>
using namespace std;

class Shape {
public:
    virtual void calculateArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void calculateArea() override {
        const double PI = 3.14159;
        double area = PI * radius * radius;
        cout << "Area of Circle: " << area << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;
public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    void calculateArea() override {
        double area = length * breadth;
        cout << "Area of Rectangle: " << area << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void calculateArea() override {
        double area = 0.5 * base * height;
        cout << "Area of Triangle: " << area << endl;
    }
};

int main() {
    double radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;
    Circle circle(radius);

    double length, breadth;
    cout << "Enter length and breadth of the rectangle: ";
    cin >> length >> breadth;
    Rectangle rectangle(length, breadth);

    double base, height;
    cout << "Enter base and height of the triangle: ";
    cin >> base >> height;
    Triangle triangle(base, height);

    Shape* shapes[3] = { &circle, &rectangle, &triangle };

    for (int i = 0; i < 3; ++i) {
        shapes[i]->calculateArea();
    }

    return 0;
}
