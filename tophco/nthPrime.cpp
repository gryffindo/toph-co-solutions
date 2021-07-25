#include<bits/stdc++.h>
using namespace std;
const int n=1e7;
bool isPrime[n];
int main()
{
  int k,counter=1;
  cin>>k;
  for (int i=3; i*i<=n; i+=2)
  {
    if (!isPrime[i])
    {
      for (int j=i*i; j<=n; j+=i)
      {
        isPrime[j]=1;
      }
    }
  }
  for (int i=3; i<=n; i+=2)
  {
    if (k==1) {cout<<2; break;}
    if (!isPrime[i])
    {
      counter++;
      if (k==counter) {cout<<i<<'\n'; break;}
    }
  }


  return 0;
}