#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// traffice_lights , lenght of the street and no of lights
void solve(vector<ll> &arr, ll x, ll n){
    multiset<ll>segments={x};
    set<ll> lights={0,x};
    for(ll pos : arr){
        auto upper = lights.upper_bound(pos);
        auto lower = prev(upper);

        segments.erase(segments.find(*upper-*lower));

        segments.insert(pos-*lower);
        segments.insert(*upper-pos);
        lights.insert(pos);
        cout<<*segments.rbegin()<<" ";
    }

}


int main(){
   ll x,n;
   cin>>x>>n;
   vector<ll> arr(n);
   for(ll i=0;i<n;i++){
    cin>>arr[i];
   }
   solve(arr,x,n);
}