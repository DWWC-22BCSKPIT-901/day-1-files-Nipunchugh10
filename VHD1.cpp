#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    Employee(string empName, int empId, int empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    virtual void calculateEarnings() = 0; // Pure virtual function

    virtual void displayDetails() const {
        cout << "Employee: " << name << " (ID: " << id << ")" << endl;
        cout << "Base Salary: " << salary << endl;
    }

    virtual ~Employee() {} // Virtual destructor
};

// Derived class: Manager
class Manager : public Employee {
private:
    int rating;

public:
    Manager(string empName, int empId, int empSalary, int empRating)
        : Employee(empName, empId, empSalary), rating(empRating) {}

    void calculateEarnings() override {
        double bonus = (rating * 0.1) * salary;
        displayDetails();
        cout << "Role: Manager" << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Earnings: " << salary + bonus << endl;
    }
};

// Derived class: Developer
class Developer : public Employee {
private:
    int extraHours;

public:
    Developer(string empName, int empId, int empSalary, int empExtraHours)
        : Employee(empName, empId, empSalary), extraHours(empExtraHours) {}

    void calculateEarnings() override {
        int overtimeCompensation = extraHours * 500;
        displayDetails();
        cout << "Role: Developer" << endl;
        cout << "Overtime Compensation: " << overtimeCompensation << endl;
        cout << "Total Earnings: " << salary + overtimeCompensation << endl;
    }
};

int main() {
    int empType;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> empType;

    if (empType == 1) {
        string name;
        int id, salary, rating;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Performance Rating (1-5): ";
        cin >> rating;

        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Please enter a value between 1 and 5." << endl;
            return 0;
        }

        Manager manager(name, id, salary, rating);
        manager.calculateEarnings();

    } else if (empType == 2) {
        string name;
        int id, salary, extraHours;

        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;

        if (extraHours < 0 || extraHours > 100) {
            cout << "Invalid hours. Please enter a value between 0 and 100." << endl;
            return 0;
        }

        Developer developer(name, id, salary, extraHours);
        developer.calculateEarnings();

    } else {
        cout << "Invalid employee type." << endl;
    }

    return 0;
}
