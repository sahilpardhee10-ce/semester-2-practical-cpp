#include <iostream>
#include "header.h"
using namespace std;
int Bank_Account::number=0;
int main()
{
    int choice,i,no;
    double acct_no;
    string name;
    long double balance;
    Bank_Account user= new Bank_Account[10];
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
            user[Bank_Account::number] = Bank_Account(name,balance);
            Bank_Account::number++;    
            goto menu;
        case 2:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=Bank_Account::number;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].view_bal();
                    break;
                }
            }
            if(i==Bank_Account::number)
                {
                    cout << "Account not found!" << endl;
                }              
            goto menu;
        case 3:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=Bank_Account::number;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].deposit();
                    break;
                }
            }
            if(i==Bank_Account::number)
                {
                    cout << "Account not found!" << endl;
                }  
            goto menu;
        case 4:
            cout << "Please enter your account number" << endl;
            cin >> acct_no;
            for(i=0;i<=Bank_Account::number;i++)
            {
                if(user[i].search_account(acct_no)==1)
                {
                    user[i].withdraw();
                    break;
                }           
            }
            if(i==Bank_Account::number)
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