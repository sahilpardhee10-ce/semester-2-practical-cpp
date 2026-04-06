#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
T maxim(T arr[], int n)
{
    T max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
void rev(T arr[], int n)
{
    reverse(arr, arr + n);
}

template <typename T>
void display(T arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void leader(T arr[], int n)
{
    T max = arr[n-1];
    cout << max << " ";

    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] >= max)
        {
            max = arr[i];
            cout << max << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {16,17,4,3,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maximum_val = maxim(arr, n);
    cout << "Max: " << maximum_val << endl;

    rev(arr, n);
    display(arr, n);

    leader(arr, n);

    return 0;
}