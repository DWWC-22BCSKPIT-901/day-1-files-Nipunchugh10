#include<iostream>
using namespace std;

double CalculateArea(double radius){
    const double PI = 3.14159;
    return PI * radius * radius;
}

int CalculateArea(int length, int breadth){
    return length * breadth;
}

int CalculateArea(double base, double height){
    return 0.5 * base * height;
}

int main () {
    double radius;
    cout<<"Enter Radius: ";
    cin>>radius;

    int length , breadth;
    cout<<"Enter Length and Breadth: ";
    cin>>length>>breadth;

    double base, height;
    cout<<"Enter Base and Height: ";
    cin>>base>>height;

    cout<<" Area of the Circle: "<<CalculateArea(radius)<<endl;
    cout<<" Area of the Rectangle: "<<CalculateArea(length,breadth)<<endl;
    cout<<" Area of the Rectangle: "<<CalculateArea(base, height)<<endl;

    return 0;
}