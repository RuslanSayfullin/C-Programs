#include<iostream>
using namespace std;
int main()
{
  int a[100],i,n,sum=0;
  
 cout<<"Enter The Size of Array\n";
  cin>>n;

  cout<<"Enter The Element\n";
  for(i=0;i<n;i++)
  {
   cin>>a[i];
  }
  cout<<"Elment in Array is Given Below\n";
  for(i=0;i<n;i++)
  {
   if(i%2==0)
   cout<<"Evenness  \n"<<a[i]<<"  ";
   else
   cout<<"Oddness  \n"<<a[i]<<"  ";
  }
 return 0;

}

