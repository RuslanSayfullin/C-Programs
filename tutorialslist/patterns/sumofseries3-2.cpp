#include<iostream>
#include<math.h>
using namespace std;

void main(){
long i,n,x,sum=1;

cout<<“1+x+x^2+……+x^n”;
cout<<“nnEnter the value of x and n:”;
cin>>x>>n;

for(i=1;i<=n;++i)
sum+=pow(x,i);
cout<<“nSum=”<<sum;
}
