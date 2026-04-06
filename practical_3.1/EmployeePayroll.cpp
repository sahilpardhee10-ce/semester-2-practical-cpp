#include <iostream>
#include "header.h"
using namespace std;
void EmployeePayroll::displayEmployeeDetails()
{
    cout << "Employee Name: " << name << endl;
    cout << "Employee Basic Salary: " << basic_salary << endl;
    cout << "Employee Bonus: " << bonus << endl;
    cout << "Total Salary: " << calculateTotalSalary() << endl;
}