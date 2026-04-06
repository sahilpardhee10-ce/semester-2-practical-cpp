#include <iostream>
using namespace std;
class EmployeePayroll
{
    string name;
    float basic_salary;
    float bonus;
    public:
        EmployeePayroll()
        {
            bonus=10000;
        }
        EmployeePayroll(string emp,float basic,float bonus_amt)
        {
            name = emp;
            basic_salary = basic;
            bonus = bonus_amt;
        }
        float calculateTotalSalary()
        {
            return basic_salary + bonus;
        }
        void getName()
        {
            cout << name << endl;
        }
        void displayEmployeeDetails();
};