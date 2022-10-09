#include <bits/stdc++.h>

using namespace std;

struct student{
    string name;
    string roll;
    int ma211;
    int ma219;
    int ma213;
};

int main()
{
    struct student arr[5];
    for(int i=0;i<5;i++)
    {
        cout<<"Information of student "<<i+1<<":";
        cout<<"Name: ";
        cin>>arr[0].name;
        cout<<"Roll: ";
        cin>>arr[0].roll;
        cout<<"Marks in MA211: ";
        cin>>arr[0].ma211;
        cout<<"Marks in MA219: ";
        cin>>arr[0].ma219;
        cout<<"Marks in MA213: ";
        cin>>arr[0].ma213;
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
            }
            int mn;
            for(int i=0;i<n;i++)
            {
                mn=i;
                for(int j=i+1;j<n;j++)
                {
                    if(v[j]<v[mn])
                        mn=j;
                }
                swap(v[mn],v[i]);
                            }
}