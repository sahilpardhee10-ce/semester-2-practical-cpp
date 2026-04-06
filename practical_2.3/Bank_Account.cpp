#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int Bank_Account::search_account(double account_no_input)
{
        if(acct_no==account_no_input)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Bank_Account::withdraw()
{
    long double withdraw=0;
    cout << "Enter Amount to withdraw" << endl;
    cin >> withdraw;
    if((withdraw<balance) && withdraw > 0)
    {
        balance -= withdraw;
    }
    else
    {
        cout << "Insufficient Funds" << endl;
    }
}

void Bank_Account::deposit()
{
    long double deposit=0;
    cout << "Enter Amount to deposit" << endl;
    cin >> deposit;
    if(deposit > 0)
    {
        balance += deposit;
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }
}

void Bank_Account::view_bal()
{
    cout << "User's Name is " << account_holder_name << endl;
    cout << "User's Balance is Rupees " << balance << endl;
}

