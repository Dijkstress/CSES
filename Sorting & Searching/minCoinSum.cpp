#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll> &arr, ll n){
    sort(arr.begin(),arr.end());
    ll smallest=1;
    for(auto it : arr){
        if(it<=smallest){
            smallest+=it;
        }else{
            return smallest;
        }
       
    }
    return smallest;
}


int main(){
   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<solve(arr,n)<<endl;
}