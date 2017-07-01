#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <ctime>
using namespace std;
//Considering maximum backoff time as 4 
int arr01[10];
int arr02[10];
int arr11[10];
int arr12[10];
int n01,n02,n11,n12,c,c1,c2,coll;
int w1,w2,back1,back2,curr1,curr2;
int j;
int tune_backoff()
{
if(j==0)
return rand()%(3);
else
return rand()%(5);

if(j==0)
j=1;
else
j=0;

}
int pktreached=199;
int main()
{
srand ( time(NULL) );
cout<<"Simulation of Slotted_CS_Aloha\n";
int time1=0;


while(time1<=200)
{
cout<<"Time: "<<time1<<endl;
//Slot beginning- carrier sense through rts-cts
//For putting into second buffer and sending the first packet in buffer
if(c==0)
{
int i,temp=0;
for(i=0;i<n01;i++)
{
arr02[n02+i]=arr01[i];
arr01[i]=0;
temp++;
}
curr1=arr02[0];
n02=n02+temp;
if(n02>0)
c1=1;
n01=n01-temp;
temp=0;
for(i=0;i<n11;i++)
{
arr12[n12+i]=arr11[i];
arr11[i]=0;
temp++;
}
curr2=arr12[0];
n12=n12+temp;
n11=n11-temp;
if(n12>0&&c1==0)
c2=1;
if(c1==1||c2==1)
c=1;
}
//Checking transmission
if(c==1)
{
if(c1==1&&back1==0)
cout<<"Packet from node 0 is transmitting\n";
else if(c2==1&&back2==0)
cout<<"Packet from node 1 is transmitting\n";
else
pktreached--;
if(c1==1&&c2==1)
{
cout<<"COLLISION\n";
coll++;
}
}

/*
Adding packets to the buffer 1
*/
int p1=rand()%2;
int p2=rand()%2;
if(p1>0)
{
cout<<"Node 0 is waking up from sleep mode\n";
cout<<"Node 0 is adding a packet to buffer 1\n";
cout<<"Node 0 sleep mode\n";
arr01[n01]=p1;
n01++;
}
if(p2>0)
{
cout<<"Node 1 is waking up from sleep mode\n";
cout<<"Node 1 is adding a packet to buffer 1\n";
cout<<"Node 1 sleep mode\n";
arr11[n11]=p2;
n11++;
}
/*Adding packets over*/
//Adding loss of acknowledgements criteria
if(time1%25==0&&back1==0&&back2==0)
{
if(c1==1)
{
back1=tune_backoff(),w1=1;
c1=0;
arr02[0]=curr1;
cout<<"ACK for packet from node 0 not received\n";
}
if(c2==1)
{
back2=tune_backoff(),w2=1;
c2==0;
arr12[0]=curr2;
cout<<"ACK for packet from node 1 not received\n";

}
pktreached--;
time1++;
continue;
}

if(back1>0)
back1--;
if(back2>0)
back2--;

int j;

//Reducing transmission time
if(c1==1&&back1==0)
arr02[0]--;
if(c2==1&&back2==0)
arr12[0]--;
if(c1==1&&arr02[0]==0)
{
//Reducing the number of elements in the buffer
for(j=0;j<n02-1;j++)
arr02[j]=arr02[j+1];
n02--;
c1=0;
}
if(c2==1&&arr12[0]==0)
{
//Reducing the number of elements in the buffer
for(j=0;j<n12-1;j++)
arr12[j]=arr12[j+1];
n12--;
c2=0;
}
if(c1==0&&c2==0)
c=0;
time1++;
};
//cout<<"Collision ratio "<<(float)coll/100<<endl;
cout<<"Packets reached successfully are: "<<pktreached<<"\n";
return 0;
}
