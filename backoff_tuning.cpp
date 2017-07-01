#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int index=0;
int n,maximum=10;


float selectCWValue()
{
int CW = rand()%((++index)*maximum/n);
index = index% n;
return CW;
}

int main()
{
cout<<"Enter the number of nodes\n";
cin>>n;
//Showing random selection of CW value
int j;
for(j=0;j<n;j++)
cout<<selectCWValue()<<"\n";

return 0;
}
