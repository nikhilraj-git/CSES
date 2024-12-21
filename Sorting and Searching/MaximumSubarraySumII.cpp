#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  int n,a,b;
  cin>>n>>a>>b;
  vector<ll> arr(n);
  for(auto &x:arr) cin>>x;

  vector<ll> pref(n);
  pref[0]=arr[0];
  for(int i=1;i<n;i++)
  {
    pref[i]=arr[i]+pref[i-1];
  }
  cout<<"prefix sum array is: \n";
  for(auto x:pref)
  {
    cout<<x<<" ";
  }
  cout<<"\n";
  multiset<ll> ms;
  ll ans=LLONG_MIN;
  for(int i=a-1;i<b;i++)
  {
    ms.insert(pref[i]);
    ans = max(ans,*ms.rbegin());
  }
  cout<<"Multiset after first loop\n";
  for(auto x:ms)
  {
    cout<<x<<" "; 
  }
  cout<<"\n";

  for(int i=a;i<n;i++)
  {
    cout<<"pref[i-1] - "<<pref[i-1]<<"\n";
    ms.erase(ms.find(pref[i-1]));
      cout<<"i+b-a - "<<i+b-a<<"\n";
    if(i+b-a<n)
    { 
      cout<<"pref[i+b-a] - "<<pref[i+b-a]<<"\n";
      ms.insert(pref[i+b-a]);
    }
    cout<<"pref[i-a] - "<<pref[i-a]<<"\n";
    ans =max(ans,*ms.rbegin()-pref[i-a]);
    cout<<"Ans - "<<ans<<"\n";
  }
  cout<<ans<<"\n";
}