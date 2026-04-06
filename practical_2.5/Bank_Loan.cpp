#include <iostream>
#include <string>
#include "header.h"
#include <cmath>

using namespace std;

float Bank_Loan::EMI()
{
    return (loan_amount * interest_rate * (pow(1+interest_rate,tenure)))/(pow(1+interest_rate,tenure)-1);
}
void Bank_Loan::display()
{
    cout << "User Name: " << name << endl;
    cout << "Loan ID: " << loan_id << endl;
    cout << "Loan Principal Amount: " << loan_amount << endl;
    cout << "Loan Tenure: " << tenure << endl;
    cout << "Interest Rate: " << interest_rate << endl;
    cout << "Loan EMI: " << EMI() << endl;
}

