#include <iostream>

class Bank_Account
{
    std::string account_holder_name;
    long double balance; 
    double acct_no; 
    public:
        Bank_Account()
        {
            account_holder_name="null";
            balance=0;
            acct_no=0;
        }
        Bank_Account(std::string name,long double bal)
        {
            account_holder_name=name;
            balance=bal;
            acct_no=number;
            std::cout << "Your Account Number is " << number << std::endl;
        }
        void withdraw();
        void deposit();
        void view_bal();
        int search_account(double);
        static int number;
};