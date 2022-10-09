#include<bits/stdc++.h> 
using namespace std; 

int len(long long x)
{
	int c=0;
	while(x!=0)
	{
		c++;
		x=x/10;
	}
	return c;
}


long long km(long long a,long long b)
{

if((a<10) && b<10)
	return a*b;
	long long w=a/pow(10,len(a)/2);
	long long x=b/pow(10,len(b)/2);
	long long y=a%(int)pow(10,len(a)/2);
	long long z=b%(int)pow(10,len(b)/2);
	return pow(10,len(a))*km(w,x)+pow(10,len(a/2))*(km(w,z)+km(x,y))+km(y,z);
		
}



int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<km(a,b)<<endl;
	cout<<a*b<<endl;
}