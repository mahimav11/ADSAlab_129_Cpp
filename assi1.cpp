/* Implement a problem of number of zeroes.   
Statement: Given an array of 1s and 0s which has all 1s first followed by all 0s? Find the number of 0s. Count the number of zeroes in the 
given array */


#include <iostream>
using namespace std;

int count_zeroes(int a[], int n)
{
    int low = 0, high = n - 1;
    int first_zero = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == 0)
        {
            first_zero = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (first_zero == -1)
        return 0; 
    else
        return n - first_zero;
}

int main()
{
    int n;
    int flag=0,valid=1;
    cout << "ENTER SIZE: ";
    cin >> n;

    int a[n];
    cout<< "enter 1s followed by 0s ";
    for (int i = 0; i < n; i++)
    {
        
        cin >> a[i];
        // input validation
        if(a[i]==0)
        {
            flag=1;
        }
        else if(flag==1 && a[i]==1)
        {
            valid=0;
        }
    }
    if(valid==0)
    {
        cout<<"invalid seq entered\n";
        return 0;
    }

    int c = count_zeroes(a, n);
    cout << "Number of zeroes: " << c << endl;
    return 0;
}

