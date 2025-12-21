#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(vector<ll> &arr,ll k,ll n){
    ll currXor=0;
    for(int i=0;i<k;i++){
        currXor^=arr[i];
    }
    ll ans=currXor;
    for(int i=k;i<n;i++){
        currXor^=arr[i-k];
        currXor^=arr[i];
        ans^=currXor;
    }
    cout<<ans<<endl;

}

int main(){
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+b)%c;
    }
    solve(arr,k,n);

    return 0;
}