// C++ implementation of Radix Sort

#include <bits/stdc++.h>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i;
    vector<vector<int>> v(10);

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        v[(arr[i] / exp) % 10].push_back(arr[i]);

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
  

    // Build the output array
   
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    int k=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            arr[k]=v[i][j];
            k++;
        }
    }
    cout<<endl;
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    // Function Call
    radixsort(arr, n);
    print(arr, n);
    return 0;
}
