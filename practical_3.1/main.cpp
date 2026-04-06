#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    int choice,t=0,id;
    string name;
    float salary,bonus;
    EmployeePayroll employee[10];
    start:
    cout << "Welcome to Employee Payroll!" << endl;
    cout << "1. Add Employee" << endl
         << "2. Employee List" << endl
         << "3. View Employee Details" << endl
         << "4. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Employee Name: " << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Employee Basic Salary: " << endl;
            cin >> salary;
            cout << "Employee Bonus: " << endl;
            cin >> bonus;
            employee[t] = EmployeePayroll(name,salary,bonus);
            cout << "Employee ID is " << t << endl;
            t++;
            goto start;

        case 2:
            for(int i=0;i<t;i++)
            {
                cout << "Employee ID: " << i << endl;
                cout << "Employee Name: ";
                employee[i].getName();
                cout << endl;
            }
            goto start;
        case 3:
            cout << "Please enter ID of employee you wish to see" << endl;
            cin >> id;
            employee[id].displayEmployeeDetails();
            goto start;
        case 4:
            cout << "Exiting.." << endl;
    }
    return 0;
}