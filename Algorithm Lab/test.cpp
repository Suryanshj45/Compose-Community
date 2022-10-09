#include <bits/stdc++.h>

using namespace std;

int n;
	
int fun(int ar[],int br[],int l,int r,int l1,int r1)
{
	if(r==l)
		return min(ar[l],br[l1]);
	if(ar[(l+r)/2]<br[(l1+r1)/2])
		return fun(ar,br,(l+r)/2+1,r,l1,(l1+r1)/2);
		else
		return fun(ar,br,l,(l+r)/2,(l1+r1)/2+1,r1);	
}
int main()
{
	cin>>n;
	int ar[n+1];
	int br[n+1];
	for(int i=1;i<n+1;i++)
		cin>>ar[i];
	for(int i=1;i<n+1;i++)
		cin>>br[i];
	cout<<fun(ar,br,0,n,0,n);
}