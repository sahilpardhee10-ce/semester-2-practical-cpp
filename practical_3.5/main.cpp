#include <iostream>
using namespace std;

int summation(int a)
{
    int sum=0;
    while(a!=0)
    {
        sum+=a%10;
        a/=10;
    }
    return sum;
}

int main()
{
    string number;
    int k;
    cout << "Please enter the number" << endl;
    cin >> number;
    cout << "Please enter number of times the input has to be concatenated" << endl;
    cin >> k;
    
    long long number_int=stoll(number);
    long long sum=number_int;
    while(sum>10)
    {
        sum=summation(sum);
    }

    string concat;
    for(int i=0;i<k;i++)
    {
        concat+=number;
    }
    cout << "Concatenated String" << endl << concat << endl;
    cout << "Value of Sum is " << sum*k << endl; 
}