#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll> &arr, ll n){
   multiset<ll> towers;

  for(ll i=0;i<n;i++){
    ll curr=arr[i];
    if(towers.upper_bound(curr)!=towers.end()){
        towers.erase(towers.upper_bound(curr));
    }
    towers.insert(curr);
  }
  return towers.size();
}


int main(){
   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(ll i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<solve(arr,n)<<endl;
}