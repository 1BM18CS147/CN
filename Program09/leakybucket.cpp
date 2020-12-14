#include<bits/stdc++.h>

using namespace std;

int bucketSize=256;

void delay(int delay){
int now=time(NULL);
int later=now+delay;
while(now<=later)now=time(NULL);
}

void LeakyBucket(int x,int y) {
 if(x>bucketSize) {
  cout<<"\n\t\tBucket overflow";
 }
 else {
 delay(2);
 while(x>y){
   cout<<"\n\t\t"<<y<<" bytes outputted.";
   x-=y;
   delay(2);
  }
 
  if(x>0) {
  cout<<"\n\t\tLast "<<x<<" bytes sent\t";
  }
 
  cout<<"\n\t\tBucket output successful";
 }
 
}

int main() {
  int outputrate, packetsize,packet_num;
  cout<<"Enter output rate : ";
  cin>>outputrate;
  packet_num=5;
  for(int i=1;i<=5;i++){
    delay(2);
    srand((unsigned int)time(NULL));
    packetsize=rand() % 1000;
    cout<<"\nPacket no "<<i<<"\tPacket size = "<<packetsize;
    LeakyBucket(packetsize,outputrate);
    cout<<"\n";
  }
  return 0;
} 


