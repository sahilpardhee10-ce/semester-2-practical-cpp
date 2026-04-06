#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    int choice,i,no;
    int t=0;
    double acct_no;
    string name;
    long double balance;
    Bank_Account user[10];
    menu:
    cout << "Welcome to the Bank!" << endl
         << "1. Create Account" << endl
         << "2. View Account Balance" << endl
         << "3. Deposit Money" << endl
         << "4. Withdraw Money" << endl
         << "5. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            cout << "Enter User's Name" << endl;
            cin.ignore();
            getline(cin,name);
            cout << "Enter User's Balance" << endl;
            cin >> balance;
            user[t] = Bank_Account(name,balance,t);
            t++;    
            goto menu;
        case 2:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].view_bal();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }              
            goto menu;
        case 3:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].deposit();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }  
            goto menu;
        case 4:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=t;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].withdraw();
                    break;
                }           
            }
            if(i==t)
                {
                    cout << "Account not found!" << endl;
                }            
            goto menu;
        case 5:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }

    cout << "Visit Again!" << endl;
}